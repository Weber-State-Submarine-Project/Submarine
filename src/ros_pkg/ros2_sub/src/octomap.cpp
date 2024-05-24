#include "rclcpp/rclcpp.hpp"
#include "octomap_msgs/msg/octomap.hpp"
#include "octomap/octomap.h"
#include "octomap_msgs/conversions.h"
#include "nav_msgs/msg/occupancy_grid.hpp"


class OctomapProcessingNode : public rclcpp::Node
{
public:
    OctomapProcessingNode()
    : Node("octomap_processing_node"),
      publisher_(this->create_publisher<octomap_msgs::msg::Octomap>("/octomap_new", 10)),max_x_(0),max_y_(0)
    {
        subscription_ = this->create_subscription<octomap_msgs::msg::Octomap>(
            "/octomap_binary", 10,
            std::bind(&OctomapProcessingNode::octomapCallback, this, std::placeholders::_1));
        map_subscription_ = this->create_subscription<nav_msgs::msg::OccupancyGrid>(
            "/map", 10,
            std::bind(&OctomapProcessingNode::mapCallback, this, std::placeholders::_1));
    }

private:
    void octomapCallback(const octomap_msgs::msg::Octomap::SharedPtr octo_msg)
    {
        if (!octo_msg) {
            RCLCPP_ERROR(this->get_logger(), "Received a null octomap pointer.");
            return;
        }

        // Process the octomap message
        auto tree = std::unique_ptr<octomap::OcTree>(dynamic_cast<octomap::OcTree*>(octomap_msgs::binaryMsgToMap(*octo_msg)));
        if (!tree) {
            RCLCPP_ERROR(this->get_logger(), "Conversion from message to OcTree failed.");
            return;
        }
        //convert to meters and adjust for proper starting pos
        double max_x = max_x_*resolution_ + start_x_;
        double max_y = max_y_*resolution_ + start_y_;
 
        auto result = findZValuesForX(tree, max_x);
        std::vector<std::pair<double, double>> xz_values = result.first;
        size_t num_elements = result.second;
        if(!num_elements){
            RCLCPP_ERROR(this->get_logger(), "Error, no depth values were found.");
            return;
        }

        // Add data to the octomap
        for(size_t i = 0; i < num_elements; i++){
            double x = xz_values[i].first;
            double z = xz_values[i].second;
            for(double y = start_y_; y < max_y; y+=0.04){
                if (!addDataToOctomap(tree, x, y, z)) {
                    RCLCPP_ERROR(this->get_logger(), "Failed to add data to the octomap.");
                    return;
                }
            }
        }
        // Create a new Octomap message for publishing
        octomap_msgs::msg::Octomap updated_octomap_msg;

        // Copy the header from the original message
        updated_octomap_msg.header = octo_msg->header;

        // Update the timestamp in the header (optional)
        updated_octomap_msg.header.stamp = this->get_clock()->now();

        // Serialize the modified octomap into the message
        octomap_msgs::binaryMapToMsg(*tree, updated_octomap_msg);

        // Publish the updated octomap message with the header
        publisher_->publish(updated_octomap_msg);
    }

    bool addDataToOctomap(std::unique_ptr<octomap::OcTree>& tree, double x, double y, double z)
    {
        octomap::point3d point(x, y, z);
        tree->updateNode(point, true); // Set to 'true' to mark as occupied
        tree->updateInnerOccupancy();

        // Check if the node exists
        octomap::OcTreeNode* node = tree->search(point);
        if (node) {
            return true;
        } else {
            return false;
        }
    }
    
    // Function to find the z value for each x coordinate
    std::pair<std::vector<std::pair<double, double>>, size_t> findZValuesForX(std::unique_ptr<octomap::OcTree>& tree, double max_x) {
        std::vector<std::pair<double, double>> xz_values; // Vector to store x and z pairs
        double last_y = std::numeric_limits<double>::lowest(); // Initialize with the lowest possible value

        // Iterate over leaf nodes (occupied cells)
        for (octomap::OcTree::leaf_iterator it = tree->begin_leafs(), end=tree->end_leafs(); it != end; ++it) {
            if (tree->isNodeOccupied(*it)) {
                double x = it.getX();
                double y = it.getY();
                double z = it.getZ();

                // Check if the x coordinate is within the range we are interested in
                if (x >= start_x_ && x < max_x) {
                    // Check if the y value is different from the last y value added
                    if (y != last_y) {
                        // Save the x and z values as a pair
                        xz_values.push_back(std::make_pair(x, z));
                        last_y = y; // Update the last y value
                    }
                }
            }
        }

        // Return the vector and its size as a pair
        return std::make_pair(xz_values, xz_values.size());
    }

    
    void mapCallback(const nav_msgs::msg::OccupancyGrid::SharedPtr map_msg)
    {
        if (!map_msg) {
            RCLCPP_ERROR(this->get_logger(), "Received a null map pointer.");
            return;
        }

        // Process the map message
        max_x_ = map_msg->info.width;
        max_y_ = map_msg->info.height;
        resolution_ = map_msg->info.resolution;
        // Extract the starting position from the map metadata
        start_x_ = map_msg->info.origin.position.x;
        start_y_ = map_msg->info.origin.position.y;
    }

    rclcpp::Subscription<octomap_msgs::msg::Octomap>::SharedPtr subscription_;
    rclcpp::Subscription<nav_msgs::msg::OccupancyGrid>::SharedPtr map_subscription_;
    rclcpp::Publisher<octomap_msgs::msg::Octomap>::SharedPtr publisher_;
    double max_x_;
    double max_y_;
    double resolution_;
    double start_x_;
    double start_y_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<OctomapProcessingNode>());
    rclcpp::shutdown();
    return 0;
}

