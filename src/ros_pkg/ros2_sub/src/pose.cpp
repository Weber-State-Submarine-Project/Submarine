#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2/LinearMath/Matrix3x3.h"
#include "nav_msgs/msg/odometry.hpp"
#include "std_msgs/msg/int32.hpp"

class PoseNode : public rclcpp::Node
{
public:
    PoseNode()
    : Node("pose_node")
    {
        // Subscribe to the scan/front topic
        scan_sub_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
            "/scan/front", 10, std::bind(&PoseNode::scanCallback, this, std::placeholders::_1));

        // Subscribe to the /imu topic
        imu_sub_ = this->create_subscription<sensor_msgs::msg::Imu>(
            "/imu", 10, std::bind(&PoseNode::imuCallback, this, std::placeholders::_1));
        
        turn_sub_ = this->create_subscription<std_msgs::msg::Int32>(
            "/turning", 10, std::bind(&PoseNode::turnCallback, this, std::placeholders::_1));

        odom_pub_ = this->create_publisher<nav_msgs::msg::Odometry>("/odom", 10);
    }

private:
    void scanCallback(const sensor_msgs::msg::LaserScan::SharedPtr msg)
    {
        dist_ = msg->ranges[0];
        if(!got_origin_){
          origin_dist_ = dist_; 
          got_origin_ = true;
        }
        calcPose();
    }

    void imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg)
    {
        tf2::Quaternion quat(msg->orientation.x, msg->orientation.y, msg->orientation.z, msg->orientation.w);
        tf2::Matrix3x3 m(quat);
        double roll, pitch, yaw;
        m.getRPY(roll, pitch, yaw);
        
        if (!yaw_initialized_) {
            initial_yaw_ = yaw;
            yaw_initialized_ = true;
        }
        // Raw yaw
        yaw_ = yaw;
        // yaw_scaled should always be 0 to pi/2 and be with respect to the wall it is following
        yaw_scaled_ = std::abs(std::abs(yaw) - std::abs(initial_yaw_));
    }

    void turnCallback(const std_msgs::msg::Int32::SharedPtr msg)
    {
        turn_ = msg->data;
        // Comes from behavior tree, true when we are turning 90 degrees, stays on for [3] seconds after turn to allow sensors to correct
        if(turn_){
            turning_ = true;
        }
        // Should be true once 3 seconds after the boat has finished turning 90 degree, resets origin to be the new "start pos"s
        if(!turn_ && turning_){
            got_origin_ = false;
            yaw_initialized_ = false;
            turning_ = false;
            origin_x_ = x_;
            origin_y_ = y_;
        }
    }

    void calcPose()
    {
        float delta_dist = origin_dist_ - dist_;
        if((yaw_ > M_PI_4 && yaw_ < 3*M_PI_4) || (yaw_ < -M_PI_4 && yaw_ > -3*M_PI_4)){ 
            x_ = (std::sin(yaw_) * delta_dist) + origin_x_;
            y_ = (std::cos(yaw_) * delta_dist) + origin_y_;
        }

        else if((std::abs(yaw_) >= 3*M_PI_4) || (std::abs(yaw_) <= M_PI_4)){
            x_ = (std::cos(yaw_) * delta_dist) + origin_x_;
            y_ = (std::sin(yaw_) * delta_dist) + origin_y_;
        }

        if(yaw_ >= 0){
            y_ = -y_;
        }

        if(std::abs(yaw_) <= M_PI_2){
            x_ = -x_;
        }
        if(!turning_){
            RCLCPP_INFO(this->get_logger(), "delta_d: %f, x:%f, y:%f, origin_x_: %f, origin_y_: %f yaw_: %f, scaled_yaw_: %f, initial_yaw_: %f, og_dist %f", delta_dist,x_,y_,origin_x_,origin_y_,yaw_,yaw_scaled_,initial_yaw_,origin_dist_);
            auto odom_msg = nav_msgs::msg::Odometry();
            odom_msg.header.stamp = this->now();
            odom_msg.header.frame_id = "odom";
            odom_msg.child_frame_id = "base_link";

            odom_msg.pose.pose.position.x = x_;  
            odom_msg.pose.pose.position.y = y_;
            odom_pub_->publish(odom_msg);
       }
    }

    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr scan_sub_;
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub_;    
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr turn_sub_;    
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_pub_;
    float dist_ = 0.;
    float initial_yaw_ = 0;
    float yaw_ = 0.;
    float yaw_scaled_ = 0;
    float origin_dist_ = 0.;
    bool got_origin_ = false;
    bool yaw_initialized_ = false;
    bool turning_ = false;
    int turn_;
    float x_ = 0;
    float y_ = 0;
    float origin_x_= 0;
    float origin_y_ = 0;

};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PoseNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

