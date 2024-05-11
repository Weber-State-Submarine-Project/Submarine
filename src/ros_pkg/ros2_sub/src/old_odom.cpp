#include <memory>
#include <tf2/LinearMath/Quaternion.h>
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "std_msgs/msg/float64.hpp"
#include "sensor_msgs/msg/imu.hpp"

using std::placeholders::_1;
using namespace std::chrono_literals;

class OdomNode : public rclcpp::Node
{
public:
  OdomNode()
  : Node("odom_node"), fin_dir_(0),last_distance_(0.0), last_time_(this->now()), current_time_(this->now())
  {
    subscription2_ = this->create_subscription<sensor_msgs::msg::Imu>(
      "/imu", 10, std::bind(&OdomNode::ang_vel_callback, this, _1));
    subscription3_ = this->create_subscription<std_msgs::msg::Float64>(
      "/angular_vel", 10, std::bind(&OdomNode::fin_callback, this, _1));
    subscription4_ = this->create_subscription<std_msgs::msg::Float64>(
      "/odometer", 10, std::bind(&OdomNode::odom_callback, this, _1));


    publisher_ = this->create_publisher<nav_msgs::msg::Odometry>("odom", 10);
    timer_ = this->create_wall_timer(
      400ms, std::bind(&OdomNode::calculate_velocity, this));
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
        odom_msg.header.stamp = current_time_;
        odom_msg.header.frame_id = "odom";
        odom_msg.child_frame_id = "base_link";
        float y_vel;
        const double ramp_up_duration = 100.0; 

        if(last_distance_ >= 0){
            double time_difference = (current_time_ - last_time_).seconds();
            double distance_difference =  current_distance_ - last_distance_;
            // Calculate velocity (m/s)
            double velocity = 0.0;
            if (time_difference > 0) {
                velocity = distance_difference / time_difference;
            }

            // Publish the velocity in an Odometry message
            double thrust_direction = (std::abs(yaw_) >= M_PI_2) ? 1 : -1;
            odom_msg.twist.twist.linear.x = -velocity;
            static int now = 0;
            if(std::abs(fin_dir_) <= 0.1){
                y_vel = 0;
                now = 0;
            }
            else if(std::abs(fin_dir_)  <= 0.25){
                y_vel = -0.1;
                now = 0;
            }   
        
            //velocity when turning
            else if(std::abs(fin_dir_) <= 0.35){
                double ramp_down_factor = std::max(0.0, (ramp_up_duration - now) / ramp_up_duration);
                now++;
                y_vel = -0.1 * ramp_down_factor; 
            }

            odom_msg.twist.twist.linear.y = y_vel;
            publisher_->publish(odom_msg);
        }
        // Update last distance and time
        last_distance_ = current_distance_;
        last_time_ = current_time_;
    
  }
 
  void odom_callback(const std_msgs::msg::Float64::SharedPtr msg){
    current_distance_ = msg->data;
    current_time_ = this->now();
  }

  rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr subscription2_;
  rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr subscription3_;
  rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr subscription4_;
  rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr publisher_;
  float fin_dir_;
  double last_distance_;
  rclcpp::Time last_time_;
  rclcpp::Time current_time_;
  double current_distance_;
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



