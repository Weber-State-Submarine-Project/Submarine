#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "std_msgs/msg/float64.hpp"

class SubmarineController : public rclcpp::Node
{
public:
    SubmarineController() : Node("submarine_controller")
    {
        // Subscriber to cmd_vel
        cmd_vel_subscription_ = this->create_subscription<geometry_msgs::msg::Twist>(
            "cmd_vel", 10, std::bind(&SubmarineController::cmdVelCallback, this, std::placeholders::_1));

        // Publishers for linear and angular velocities
        linear_pub_ = this->create_publisher<std_msgs::msg::Float64>("/model/tethys/joint/propeller_joint/cmd_thrust", 10);
        angular_pub_ = this->create_publisher<std_msgs::msg::Float64>("angular_vel", 10);
    }

private:
    void cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg)
    {
        // Check if the submarine is moving forward/backward
        bool is_moving = msg->linear.x != 0.0;

        // Convert and publish linear velocity
        std_msgs::msg::Float64 linear_msg;
        linear_msg.data = std::clamp(-msg->linear.x, -30.0, 30.0);
        linear_pub_->publish(linear_msg);

        // Convert and publish angular velocity if moving
        if (is_moving)
        {
            std_msgs::msg::Float64 angular_msg;
            angular_msg.data = std::clamp(msg->angular.z, -0.5, 0.5);
            angular_pub_->publish(angular_msg);
        }
    }

    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_subscription_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr linear_pub_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr angular_pub_;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SubmarineController>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

