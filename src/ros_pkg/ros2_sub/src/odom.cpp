#include <memory>
#include <tf2/LinearMath/Quaternion.h>
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "std_msgs/msg/float64.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "geometry_msgs/msg/vector3.hpp"

using std::placeholders::_1;
using namespace std::chrono_literals;

class OdomNode : public rclcpp::Node
{
public:
  OdomNode()
  : Node("odom_node"), fin_dir_(0),last_distance_x_(0.0),last_distance_y_(0.0), last_time_(this->now()), current_time_(this->now())  {
    subscription2_ = this->create_subscription<sensor_msgs::msg::Imu>(
      "/imu", 10, std::bind(&OdomNode::ang_vel_callback, this, _1));
    subscription3_ = this->create_subscription<std_msgs::msg::Float64>(
      "/angular_vel", 10, std::bind(&OdomNode::fin_callback, this, _1));
    subscription4_ = this->create_subscription<geometry_msgs::msg::Vector3>(
      "/odometer", 10, std::bind(&OdomNode::odom_callback, this, _1));


    publisher_ = this->create_publisher<nav_msgs::msg::Odometry>("odom", 10);
    timer_ = this->create_wall_timer(
      500ms, std::bind(&OdomNode::calculate_velocity, this));
  }

private:
    void fin_callback(const std_msgs::msg::Float64::SharedPtr msg){
       fin_dir_ = msg->data;
    }

    void ang_vel_callback(const sensor_msgs::msg::Imu::SharedPtr msg)
    {
        auto current_orientation = msg->orientation;
        tf2::Quaternion current_quaternion(current_orientation.x, current_orientation.y, current_orientation.z, current_orientation.w);

        // Convert the current orientation quaternion to roll, pitch, yaw
        double roll, pitch;
        tf2::Matrix3x3(current_quaternion).getRPY(roll, pitch, yaw_);
    }

    void calculate_velocity() {
        auto odom_msg = nav_msgs::msg::Odometry();
        odom_msg.header.stamp = this->now();
        odom_msg.header.frame_id = "odom";
        odom_msg.child_frame_id = "base_link";
        odom_msg.pose.pose.position.x = pose_.x - 23;
        odom_msg.pose.pose.position.y = pose_.y + 12.3;     

        double time_difference = (current_time_ - last_time_).seconds();
        double distance_difference_x = current_distance_x_ - last_distance_x_;
        double distance_difference_y = current_distance_y_ - last_distance_y_;

        // Calculate velocity in the world frame (m/s)
        double velocity_x_world = distance_difference_x*1.3 / time_difference;
        double velocity_y_world = distance_difference_y*1.3 / time_difference;

        // Rotate the velocity vector from the world frame to the submarine's frame
        double velocity_x_sub = velocity_x_world * cos(yaw_) + velocity_y_world * sin(yaw_);
        double velocity_y_sub = -velocity_x_world * sin(yaw_) + velocity_y_world * cos(yaw_);

        // Publish the velocity in an Odometry message
        odom_msg.twist.twist.linear.x = velocity_x_sub;
        odom_msg.twist.twist.linear.y = velocity_y_sub;

        publisher_->publish(odom_msg);

        // Update last distance and time
        last_distance_x_ = current_distance_x_;
        last_distance_y_ = current_distance_y_;
        last_time_ = current_time_;
    }

 
  void odom_callback(const geometry_msgs::msg::Vector3::SharedPtr msg){
    current_distance_x_ = msg->x;
    current_distance_y_ = msg->y;
    pose_= *msg;
    current_time_ = this->now();
  }

  rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr subscription2_;
  rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr subscription3_;
  rclcpp::Subscription<geometry_msgs::msg::Vector3>::SharedPtr subscription4_;
  rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr publisher_;
  float fin_dir_;
  double last_distance_x_;
  double last_distance_y_;  
  rclcpp::Time last_time_;
  rclcpp::Time current_time_;
  double current_distance_x_;
  double current_distance_y_;  
  geometry_msgs::msg::Vector3 pose_;
  rclcpp::TimerBase::SharedPtr timer_;
  double direction_;
  double yaw_;
  };

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<OdomNode>());
  rclcpp::shutdown();
  return 0;
}



