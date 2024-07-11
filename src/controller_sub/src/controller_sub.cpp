// This code is for HW03

#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "std_msgs/msg/float64.hpp"  // Include the correct message type

using std::placeholders::_1;

class Sensors : public rclcpp::Node
{
public:
  Sensors()
  : Node("sensor_subscriber")
  {
    // Publisher for servo commands
    servo_pub_ = this->create_publisher<std_msgs::msg::Float64>("servo_command", 1);

    joy_subscriber_ = this->create_subscription<sensor_msgs::msg::Joy>(
      "joy", 1, std::bind(&Sensors::joy_callback, this, _1));
  }


private:
  void joy_callback(const sensor_msgs::msg::Joy & msg) const
  {
    
    if (msg.buttons.size() >= 2) {
      bool buttonX = msg.buttons[0];
      bool buttonO = msg.buttons[1];
      //std_msgs::msg::Float64 servo_msg; // Msg for servo_node
      //RCLCPP_INFO(this->get_logger(), "[JOY] Button X: %d, Button O: %d", buttonA, buttonB);
      
      // Your logic based on button presses goes here
      if (buttonX) {
        RCLCPP_INFO(this->get_logger(), "Button X pressed");
        
	std_msgs::msg::Float64 servo_msg; // Creates msg
        servo_msg.data = .9;  // Send .9 for servo command
        servo_pub_->publish(servo_msg);

      }
      if (buttonO) {
        RCLCPP_INFO(this->get_logger(), "Button O pressed");
        
	std_msgs::msg::Float64 servo_msg;
        servo_msg.data = -1.0;  // Send -1.0 for servo command
        servo_pub_->publish(servo_msg);      
      }
    } else {
      RCLCPP_WARN(this->get_logger(), "[JOY] Message does not contain enough buttons.");
    	}  	  
  }

  rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr joy_subscriber_;
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr servo_pub_;

};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Sensors>());
  rclcpp::shutdown();
  return 0;
}
