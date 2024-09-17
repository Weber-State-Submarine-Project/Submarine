#include "rclcpp/rclcpp.hpp"
#include "octomap_msgs/msg/octomap.hpp"
#include "octomap/octomap.h"
#include "octomap_msgs/conversions.h"
#include "nav_msgs/msg/occupancy_grid.hpp"
#include "std_msgs/msg/int32.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <set>


class OctomapProcessingNode : public rclcpp::Node
{
public:
    OctomapProcessingNode()
    : Node("octomap_processing_node"),
      publisher_(this->create_publisher<octomap_msgs::msg::Octomap>("/octomap_new", 10)), pointcloud_publisher_(this->create_publisher<sensor_msgs::msg::PointCloud2>("/octomap_pointcloud", 10)), done_(0),max_x_(0),max_y_(0)
    {
        done_subscription_ = this->create_subscription<std_msgs::msg::Int32>(
            "/done", 10,
            std::bind(&OctomapProcessingNode::doneCallback, this, std::placeholders::_1));
        subscription_ = this->create_subscription<octomap_msgs::msg::Octomap>(
            "/octomap_binary", 10,
            std::bind(&OctomapProcessingNode::octomapCallback, this, std::placeholders::_1));
        map_subscription_ = this->create_subscription<nav_msgs::msg::OccupancyGrid>(
            "/map", 10,
            std::bind(&OctomapProcessingNode::mapCallback, this, std::placeholders::_1));
            timer_ = this->create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&OctomapProcessingNode::publish_pointcloud, this)
        );
    }

private:
    void doneCallback(const std_msgs::msg::Int32::SharedPtr msg){
        if(msg)
            done_ = msg->data;
    }

    void octomapCallback(const octomap_msgs::msg::Octomap::SharedPtr octo_msg)
    {
        if(done_){
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
            double max_x = max_x_*resolution_+start_x_;
            double max_y = max_y_*resolution_+start_y_;
            float z_min;
            RCLCPP_INFO(this->get_logger(), "Adding data to the octomap starting at x: %f y: %f to x: %f y: %f", start_x_, start_y_, max_x, max_y);
     
            auto result = findZValuesForX(tree);
            std::vector<std::pair<float, float>> xz_values = result.first;
            size_t num_elements = result.second;
            if(!num_elements){
                RCLCPP_ERROR(this->get_logger(), "Error, no depth values were found.");
                return;
            }
            RCLCPP_INFO(this->get_logger(), "Completed getting %ld depth values and started interpolating data\n",num_elements);
            // Add data to the octomap for the floor
            for(size_t i = 0; i < num_elements; i++){
                for(float y = start_y_; y <= max_y; y+= .04){
                    octomap::point3d point(xz_values[i].first, y, xz_values[i].second);
                    tree->updateNode(point, true); // Set to 'true' to mark as occupied
                }
            }
            
            //fill in any missing x along the floor
            std::set<float> x_set;
            // Insert only the x values into the set
            for (const auto& pair : xz_values) {
                x_set.insert(pair.first);
            }
            //store the x values that are not in the original pair list
            std::vector<float> new_x;

            // Iterate through the range and save missing x
            for(float x = start_x_; x <= max_x; x += .04) {
                if (x_set.find(x) == x_set.end()) {
                    new_x.push_back(x);
                }
            }

            for(float x : new_x) {
               float z = findZForX(xz_values,x); 
               for(float y = start_y_; y <= max_y; y+= .04){
                    octomap::point3d point(x, y, z);
                    tree->updateNode(point, true); // Set to 'true' to mark as occupied
                }

            }

            //top wall for starting x
            z_min = findZForX(xz_values, start_x_);
            if (!std::isnan(z_min)) { // Check if z_min is not NaN
                for(float y = start_y_; y <= max_y; y+=.04){
                    for(float z = 0; z >= z_min; z-=0.04){
                        octomap::point3d point(start_x_, y, z);
                        tree->updateNode(point, true); // Set to 'true' to mark as occupied
                    }
                }
            }
            else
                RCLCPP_ERROR(this->get_logger(), "Error, no depth values were found for the top wall\n.");

            //side wall for starting y
            for(float x = start_x_; x <= max_x; x+= .04){
                z_min = findZForX(xz_values, x);
                if (!std::isnan(z_min)) { // Check if z_min is not NaN
                    for(float z = 0; z >= z_min; z-=0.04){
                        octomap::point3d point(x, start_y_, z);
                        tree->updateNode(point, true); // Set to 'true' to mark as occupied
                    }
                }
                else
                    RCLCPP_ERROR(this->get_logger(), "Error, no depth values were found for the left wall\n.");
            }
            

            //bottom wall for ending x
            z_min = findZForX(xz_values, max_x);
            if (!std::isnan(z_min)) { // Check if z_min is not NaN
                for(float y = start_y_; y <= max_y; y+=.04){
                    for(float z = 0; z >= z_min; z-=0.04){
                        octomap::point3d point(max_x, y, z);
                        tree->updateNode(point, true); // Set to 'true' to mark as occupied
                    }
                }
            }
            else
                RCLCPP_ERROR(this->get_logger(), "Error, no depth values were found for the bottom wall\n.");

            //side wall for ending y
            for(float x = start_x_; x <= max_x; x+= .04){
                z_min = findZForX(xz_values, x);
                if (!std::isnan(z_min)) { // Check if z_min is not NaN
                    for(float z = 0; z >= z_min; z-=0.04){
                        octomap::point3d point(x, max_y, z);
                        tree->updateNode(point, true); // Set to 'true' to mark as occupied
                    }
                }
                else
                    RCLCPP_ERROR(this->get_logger(), "Error, no depth values were found for the right wall\n.");
            }
            
            tree->updateInnerOccupancy();
            RCLCPP_INFO(this->get_logger(),"Completed map!\n");
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
            
            // Convert the octomap to a PointCloud2 message
            pcl::PointCloud<pcl::PointXYZ> pcl_cloud;
            for (octomap::OcTree::leaf_iterator it = tree->begin_leafs(), end = tree->end_leafs(); it != end; ++it) {
                if (tree->isNodeOccupied(*it)) {
                    pcl_cloud.push_back(pcl::PointXYZ(it.getX(), it.getY(), it.getZ()));
                }
            }

            pcl::toROSMsg(pcl_cloud, cloud_msg_);
            cloud_msg_.header.frame_id = "map";  // Set the appropriate frame ID
            cloud_msg_.header.stamp = this->get_clock()->now();
            done_ = 0;
        }
    }    
    
    void publish_pointcloud()
    {
        cloud_msg_.header.stamp = this->get_clock()->now();  // Update the timestamp
        pointcloud_publisher_->publish(cloud_msg_);
    }

    // Function to find the z value for each x coordinate
    std::pair<std::vector<std::pair<float, float>>, size_t> findZValuesForX(std::unique_ptr<octomap::OcTree>& tree) {
        std::vector<std::pair<float, float>> xz_values; // Vector to store x and z pairs
        std::set<float> unique_x; // Set to store unique x values

        // Iterate over leaf nodes (occupied cells)
        for (octomap::OcTree::leaf_iterator it = tree->begin_leafs(), end=tree->end_leafs(); it != end; ++it) {
            if (tree->isNodeOccupied(*it)) {
                float x = it.getX();
                float z = it.getZ();
                // Check if the x value is already present in the set
                if (unique_x.find(x) == unique_x.end()) {
                    // Save the x and z values as a pair
                    xz_values.push_back(std::make_pair(x, z));
                    unique_x.insert(x); // Add the x value to the set
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
    
    // Function to find the z value for a given x coordinate
    float findZForX(const std::vector<std::pair<float, float>>& xz_values, float x) {
        const float tolerance = 2.0f; // Define a tolerance range of 1 meters
        for (const auto& xz_pair : xz_values) {
            if (std::abs(xz_pair.first - x) <= tolerance) {
                return xz_pair.second; // Return the z value if x is within the tolerance range
            }
        }
        return std::numeric_limits<float>::quiet_NaN(); // Return NaN if x is not found within the range
    }



    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr done_subscription_;
    rclcpp::Subscription<octomap_msgs::msg::Octomap>::SharedPtr subscription_;
    rclcpp::Subscription<nav_msgs::msg::OccupancyGrid>::SharedPtr map_subscription_;
    rclcpp::Publisher<octomap_msgs::msg::Octomap>::SharedPtr publisher_;
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr pointcloud_publisher_;
    sensor_msgs::msg::PointCloud2 cloud_msg_;
    rclcpp::TimerBase::SharedPtr timer_;
    int done_;
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

