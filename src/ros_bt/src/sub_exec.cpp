#include <tf2/LinearMath/Quaternion.h>
#include <iomanip>
#include <chrono>
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include "behaviortree_ros2/bt_topic_sub_node.hpp"
#include "behaviortree_cpp/bt_factory.h"
#include "behaviortree_ros2/bt_action_node.hpp"
#include "behaviortree_ros2/bt_service_node.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "nav2_msgs/action/wait.hpp"
#include "nav_msgs/srv/get_map.hpp"
#include "nav_msgs/msg/occupancy_grid.hpp"
#include "std_msgs/msg/float64.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "rclcpp/node_interfaces/node_base_interface.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "nav2_util/robot_utils.hpp"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/int32.hpp"
#include <thread>


namespace chr = std::chrono;
using namespace BT;
using GetMap = nav_msgs::srv::GetMap;
using geometry_msgs::msg::Pose;
using namespace std::literals::chrono_literals;
using OccupancyGrid = nav_msgs::msg::OccupancyGrid;

int check_start = 0;
int pressed_stop = 0;

// SyncActionNode (synchronous action) with an input port.
/*
   a SyncActionNode can only return SUCCESS or FAILURE
   it cannot return RUNNING. so it is only good for simple, fast operations
 */
// SyncActionNode (synchronous action) with an input port.

class Front : public rclcpp::Node
{
public:
    Front() : Node("front_node")
    {
        subscription_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
            "/scan/front", 10,
            std::bind(&Front::topic_callback, this, std::placeholders::_1));
    }

    float get_latest_distance() const
    {
        return latest_distance_;
    }

private:
    void topic_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg)
    {
        latest_distance_ = msg->ranges[0];
    }

    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr subscription_;
    float latest_distance_;
};

class CheckFront : public SyncActionNode
{
public:
    CheckFront(const std::string &name, const NodeConfig &config, std::shared_ptr<Front> front_node)
        : SyncActionNode(name, config), front_node_(front_node)
    {
    }

    static PortsList providedPorts()
    {
        return {};
    }

    NodeStatus tick() override
    {
        // May need to change min distance to fit hardware turn radius
        if (front_node_->get_latest_distance() > 16)
        {
            std::cout << "Distance from front wall is good: " << front_node_->get_latest_distance() << "\n";
            return NodeStatus::SUCCESS;
        }
        else
        {
            std::cout << "FAIL DIST: " << front_node_->get_latest_distance() << "\n";
            return NodeStatus::FAILURE;
        }
    }

private:
    std::shared_ptr<Front> front_node_;
};

class Side : public rclcpp::Node
{
public:
    Side() : Node("side_node")
    {
        subscription_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
            "/scan/left", 10,
            std::bind(&Side::topic_callback, this, std::placeholders::_1));
    }

    float get_latest_distance() const
    {
        return latest_distance_;
    }

private:
    void topic_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg)
    {
        latest_distance_ = msg->ranges[5];
    }

    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr subscription_;
    float latest_distance_;
};

class Odom : public rclcpp::Node
{
public:
    Odom() : Node("odom_node")
    {
        subscription_ = this->create_subscription<sensor_msgs::msg::Imu>(
            "/imu", 10,
            std::bind(&Odom::topic_callback, this, std::placeholders::_1));
    }

    std::shared_ptr<sensor_msgs::msg::Imu> get_latest_imu() const
    {
        return latest_imu_;
    }

private:
    void topic_callback(const sensor_msgs::msg::Imu::SharedPtr msg)
    {
        latest_imu_ = msg;
    }

    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr subscription_;
    std::shared_ptr<sensor_msgs::msg::Imu> latest_imu_;
};

//check if start button has been pressed on the web UI
class Start: public rclcpp::Node
{
public:
    Start() : Node("start_node")
    {
        subscription_ = this->create_subscription<std_msgs::msg::Int32>(
            "/start", 10,
            std::bind(&Start::topic_callback, this, std::placeholders::_1));
    }

    int get_latest_start() const
    {
        return latest_start_;
    }

private:
    void topic_callback(const std_msgs::msg::Int32::SharedPtr msg)
    {
        latest_start_ = msg->data;
    }

    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_;
    int latest_start_ = 0;
};

class CheckStart : public SyncActionNode
{
public:
    CheckStart(const std::string &name, const NodeConfig &config, std::shared_ptr<Start> start_node)
        : SyncActionNode(name, config), start_node_(start_node)
    {
    }

    static PortsList providedPorts()
    {
        return {};
    }

    NodeStatus tick() override
    {
        int start = start_node_->get_latest_start();
        if (start == 0) {
            std::cout << "Waiting for user to start navigation\n";
            return NodeStatus::FAILURE;
        } else if (start == 1) {
            std::cout << "User started navigation\n";
            return NodeStatus::SUCCESS;
        } else {
            std::cout << "Error, unable to get user input from website\n";
            return NodeStatus::FAILURE;
        }
    }

private:
    std::shared_ptr<Start> start_node_;
};

class Velocity : public rclcpp::Node
{
public:
    Velocity() : Node("velocity_node")
    {
        subscription_ = this->create_subscription<nav_msgs::msg::Odometry>(
            "/odom", 10,
            std::bind(&Velocity::topic_callback, this, std::placeholders::_1));
    }

    std::shared_ptr<nav_msgs::msg::Odometry> get_latest_velocity() const
    {
        return latest_velocity_;
    }

private:
    void topic_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
    {
        latest_velocity_ = msg;
    }

    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr subscription_;
    std::shared_ptr<nav_msgs::msg::Odometry> latest_velocity_;
};

class Map : public rclcpp::Node
{
public:
    Map()
        : Node("map_node")
    {
        subscription_ = this->create_subscription<nav_msgs::msg::OccupancyGrid>(
            "/map", 10,
            std::bind(&Map::topic_callback, this, std::placeholders::_1));
    }

    std::shared_ptr<nav_msgs::msg::OccupancyGrid> get_latest_map() const
    {
        return latest_map_;
    }

private:
    void topic_callback(const nav_msgs::msg::OccupancyGrid::SharedPtr msg)
    {
        latest_map_ = msg;
    }

    rclcpp::Subscription<nav_msgs::msg::OccupancyGrid>::SharedPtr subscription_;
    std::shared_ptr<nav_msgs::msg::OccupancyGrid> latest_map_;
};

class Turn90Degrees : public SyncActionNode
{
public:
    Turn90Degrees(const std::string& name, const NodeConfig& config, std::shared_ptr<Odom> odom_node)
        : SyncActionNode(name, config),
          node_(rclcpp::Node::make_shared("turn_90_degrees_node")),
          odom_node_(odom_node)
    {
        publisher_ = node_->create_publisher<std_msgs::msg::Float64>("/angular_vel", 10);
    }
    
    static PortsList providedPorts()
    {
        return {};
    }

    NodeStatus tick() override    
    {   
        auto msg = odom_node_->get_latest_imu();
        if (!msg) {
            return NodeStatus::FAILURE;
        }
        auto current_orientation = msg->orientation;
        tf2::Quaternion current_quaternion(current_orientation.x, current_orientation.y, current_orientation.z, current_orientation.w);

        // Convert the current orientation quaternion to roll, pitch, yaw
        double roll, pitch, yaw;
        tf2::Matrix3x3(current_quaternion).getRPY(roll, pitch, yaw);

        // Calculate the target yaw by subtracting pi/2 from the current yaw
        if(target_yaw == 0){
            target_yaw = yaw - M_PI_2;
            // Ensure the target yaw is within the range [-pi, pi]
            if (target_yaw < -M_PI)
                target_yaw = M_PI_2;
            else if (target_yaw > M_PI)
                target_yaw -= 2 * M_PI;
        }
        
        //enable the behavior tree to start checking if we are back at the start pos,
        //this is an easy way to prevent it from detecting that we are at the start pos on starting navigation
        check_start = 1;

        // Calculate the angle difference between the current yaw and the target yaw
        double angle_difference = std::atan2(std::sin(yaw - target_yaw), std::cos(yaw - target_yaw));
        
        if(std::fabs(angle_difference) < angle_tolerance_) {
            std_msgs::msg::Float64 val;
            val.data = 0;
            publisher_->publish(val);
            std::cout << "Turn Completed\n";
            target_yaw = 0;
            return NodeStatus::SUCCESS;
        }
        else{
            std_msgs::msg::Float64 val;
            val.data = -0.3; // Adjust this value for hardware if necessary
            publisher_->publish(val);
            std::cout << "Current angle: "<<yaw<<", target angle: " << target_yaw << "\n";
            std::cout << "Angle Difference: " << angle_difference << "\n";
            return NodeStatus::FAILURE;
        }
    }

private:
    rclcpp::Node::SharedPtr node_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_;
    std::shared_ptr<Odom> odom_node_;
    double target_yaw = 0;
    const double angle_tolerance_ = 0.02; // radians
};

class AdjustDistance : public SyncActionNode
{
public:
    AdjustDistance(const std::string& name, const NodeConfig& config, std::shared_ptr<Side> side_node)
        : SyncActionNode(name, config),
          node_(rclcpp::Node::make_shared("adjust_distance_node")),
          side_node_(side_node)
    {
        publisher_ = node_->create_publisher<std_msgs::msg::Float64>("/angular_vel", 10);
    }
    // It is mandatory to define this STATIC method.
    static PortsList providedPorts()
    {
        return {};
    }

    NodeStatus tick() override    
    {   
        auto dist = side_node_->get_latest_distance();
        std_msgs::msg::Float64 val;
        val.data = -0.3; // Adjust this value for hardware if necessary
        std_msgs::msg::Float64 val2;
        val2.data = 0.3; // Adjust this value for hardware if necessary
        std_msgs::msg::Float64 val3;
        val3.data = 0; 
        
        if(dist < 1)
        {     
            std::cout <<"DIST: " << dist <<"\n";
            std::cout << "Adjusting right\n";
            publisher_->publish(val);
            return NodeStatus::FAILURE;
        }
        else if(dist > 2.5)
        {
            std::cout <<"DIST: " << dist <<"\n";
            std::cout << "Adjusting left\n";
            publisher_->publish(val2);
            return NodeStatus::FAILURE;

        }
        else
        {
            std::cout << "Distance from side wall is good: "<< dist <<"\n";
            publisher_->publish(val3);
            return NodeStatus::SUCCESS;
        }
    }

private:
    rclcpp::Node::SharedPtr node_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_;
    std::shared_ptr<Side> side_node_;
};


//will likely need adjustment for hardware, the simulation propeller is controlled by a float, this may not be the case for the motor
class Forward : public SyncActionNode
{
public:
    Forward(const std::string& name, const NodeConfig& config)
        : SyncActionNode(name, config),
          node_(rclcpp::Node::make_shared("forward_node"))
    {
        publisher_ = node_->create_publisher<std_msgs::msg::Float64>("/model/tethys/joint/propeller_joint/cmd_thrust", 10); // Create a publisher to control fin angle
    }
    // It is mandatory to define this STATIC method.
    static PortsList providedPorts()
    {
	    return {};
    }

    NodeStatus tick() override    
    {   
        std_msgs::msg::Float64 val;
        std::cout << "Moving Forward\n";
        val.data = -1;
        publisher_->publish(val);//speed is hardcoded for ease of simulation, will need to be changed for hardware
        return NodeStatus::SUCCESS;
    }

private:
    rclcpp::Node::SharedPtr node_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_; // Add a publisher member
};

class Stop : public SyncActionNode
{
public:
    Stop(const std::string& name, const NodeConfig& config, std::shared_ptr<Velocity> velocity_node)
        : SyncActionNode(name, config),
          node_(rclcpp::Node::make_shared("stop_node")),
          velocity_node_(velocity_node)
    {
        publisher_ = node_->create_publisher<std_msgs::msg::Float64>("/model/tethys/joint/propeller_joint/cmd_thrust", 10); 
        publisher2_ = node_->create_publisher<std_msgs::msg::Float64>("/angular_vel", 10);
        publisher3_ = node_->create_publisher<std_msgs::msg::Int32>("/done", 10); 
    }
    
    static PortsList providedPorts()
    {
        return {};
    }

    NodeStatus tick() override    
    { 
        std_msgs::msg::Float64 val2;
        val2.data = 0; 

        std_msgs::msg::Int32 val3;
        val3.data = 1;
    
        publisher3_->publish(val3);
        publisher2_->publish(val2);

        auto velocity_msg = velocity_node_->get_latest_velocity();
        if (!velocity_msg) {
            return NodeStatus::FAILURE;
        }
        double velocity = velocity_msg->twist.twist.linear.x;
        std_msgs::msg::Float64 val;
        if(std::abs(velocity) > 0.02){
            std::cout<<"Slowing Down\n";
            val.data = 10;
            publisher_->publish(val); // speed is hardcoded for ease of simulation, will need to be changed for hardware    
            return NodeStatus::FAILURE;
        }  
        else{
            val3.data = 0;
    
            publisher3_->publish(val3);

            std::cout<<"Stop Complete";
            val.data = 0;
            publisher_->publish(val);
            return NodeStatus::SUCCESS;
        }
    }

private:
    rclcpp::Node::SharedPtr node_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_; 
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher2_; 
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher3_; 
    std::shared_ptr<Velocity> velocity_node_;
};

class SaySomething : public SyncActionNode
{
    public:
        // If your Node has ports, you must use this constructor signature 
        SaySomething(const std::string& name, const NodeConfig& config)
            : SyncActionNode(name, config)
        { }

        // It is mandatory to define this STATIC method.
        static PortsList providedPorts()
        {
            // This action has a single input port called "message"
            return { InputPort<std::string>("message") };
        }

        // Override the virtual function tick()
        NodeStatus tick() override
        {
            Expected<std::string> msg = getInput<std::string>("message");
            // Check if expected is valid. If not, throw its error
            if (!msg)
            {
                throw RuntimeError("missing required input [message]: ", 
                        msg.error() );
            }
            // use the method value() to extract the valid message.
            std::cout << "Robot says: " << msg.value() << std::endl;
            return NodeStatus::SUCCESS;
        }
};

class MapFinished : public SyncActionNode
{
public:
    MapFinished(const std::string& name, const NodeConfig& config, std::shared_ptr<Map> map_node)
    : SyncActionNode(name, config),
      node_(rclcpp::Node::make_shared("stop_node")),
      tf_buffer_(std::make_shared<rclcpp::Clock>(RCL_SYSTEM_TIME)),
      tf_listener_(tf_buffer_),
      map_node_(map_node)
    {
        publisher_ = node_->create_publisher<std_msgs::msg::Int32>("/done", 10); 
        // Initialize the starting position
        starting_position_ = Pose();
    }

    static PortsList providedPorts()
    {
        return {
            InputPort<Pose>("starting_position")
        };
    }

    NodeStatus tick() override
    {
        // Get the inputs
        auto map_input = map_node_->get_latest_map();
        auto starting_position_input = getInput<Pose>("starting_position");
        std_msgs::msg::Int32 val;
        val.data = 0;

        if (!map_input)
        {
            throw RuntimeError("missing required input [map]: ");
        }

        if (!starting_position_input)
        {
            throw RuntimeError("missing required input [starting_position]: ", starting_position_input.error());
        }

        // Update the starting position
        starting_position_ = starting_position_input.value();

        // Get the current pose of the robot
        geometry_msgs::msg::PoseStamped current_pose;
        
        // Wait for the transform to be available
        if(!tf_buffer_.canTransform("map", "base_link", tf2::TimePointZero, tf2::durationFromSec(1.0)))
        {
            std::cout << "Waiting for transform...\n";
            publisher_->publish(val);
            return NodeStatus::FAILURE;
        }

        if(nav2_util::getCurrentPose(current_pose, tf_buffer_, "map", "base_link", tf2::Duration(30s).count()))
        {
            // current_pose now contains the pose of the robot in the map frame
            // You can use current_pose for your purposes here
            std::cout << "Current pose retrieved successfully.\n";
        }
        else
        {
            // Handle the case where the current pose could not be retrieved
            std::cout << "Failed to retrieve current pose.\n";
            publisher_->publish(val);
            return NodeStatus::FAILURE;
        }

        // Check if the current position is approximately equal to the starting position
        if (isApproximatelyEqual(current_pose.pose, starting_position_) && check_start == 1)
        {
            val.data = 1;
            std::cout << "We are back at the starting position!\n";
            publisher_->publish(val);
            return NodeStatus::SUCCESS;
        }
        else
        {
            std::cout << "Current Pose X: "<< current_pose.pose.position.x << " Y: " << current_pose.pose.position.y << "\nStart POS X: "<< starting_position_.position.x << " Y: " << starting_position_.position.y <<"\n";
            publisher_->publish(val);
            return NodeStatus::FAILURE;
        }
    }

private:
    rclcpp::Node::SharedPtr node_;
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_; 
    Pose starting_position_;
    rclcpp::Clock::SharedPtr clock_;
    tf2_ros::Buffer tf_buffer_;
    tf2_ros::TransformListener tf_listener_;
    std::shared_ptr<Map> map_node_;

    bool isApproximatelyEqual(const Pose& pos1, const Pose& pos2)
    {
        // Define a small threshold for position comparison
        const double THRESHOLD = 10; // meters

        // Use the TF2 library to calculate the difference between the two poses
        tf2::Transform tf1, tf2;
        tf2::fromMsg(pos1, tf1);
        tf2::fromMsg(pos2, tf2);

        // Calculate the distance between the two positions
        double distance = tf2::tf2Distance(tf1.getOrigin(), tf2.getOrigin());
        std::cout << "Distance to start pos: "<<distance<<"\n";

        // Check if the distance is within the threshold
        return distance < THRESHOLD;
    }
};


class WaitForSeconds : public StatefulActionNode
{
    public:
        WaitForSeconds(const std::string& name, const NodeConfig& config)
            : StatefulActionNode(name, config)
        {}
        static PortsList providedPorts()
        {
            return{ InputPort<unsigned>("seconds") };
        }
        NodeStatus onStart() override;
        NodeStatus onRunning() override;
        void onHalted() override;
    private:
        unsigned _seconds;
        chr::system_clock::time_point _completion_time;
};
NodeStatus WaitForSeconds::onStart()
{
    if ( !getInput<unsigned>("seconds", _seconds))
    {
        throw RuntimeError("missing required input [seconds]");
    }
    printf("[ WaitForSeconds: ] seconds = %d\n",_seconds);
    _completion_time = chr::system_clock::now() + chr::milliseconds(_seconds*1000);
    return NodeStatus::RUNNING;
}

NodeStatus WaitForSeconds::onRunning()
{
    std::this_thread::sleep_for(chr::milliseconds(1000));
    if(chr::system_clock::now() >= _completion_time)
    {
        std::cout << "[ WaitForSeconds: FINISHED ]" << std::endl;
        return NodeStatus::SUCCESS;
    }
    return NodeStatus::RUNNING;
}
void WaitForSeconds::onHalted()
{
    printf("[ WaitForSeconds: ABORTED ]");
}

class StartPos : public SyncActionNode
{
public:
    StartPos(const std::string& name, const NodeConfig& config, std::shared_ptr<Map> map_node)
        : SyncActionNode(name, config),
          map_node_(map_node)
    {
        // Initialize the starting position
        starting_position_ = Pose();
    }

    static PortsList providedPorts()
    {
        return {OutputPort<Pose>("starting_position")};
    }

    NodeStatus tick() override
    {
        auto latest_map = map_node_->get_latest_map();
        if (!latest_map) {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "No map received!");
            return NodeStatus::FAILURE;
        }

        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Processing the map!");

        // Extract the starting position from the map metadata
        starting_position_.position.x = latest_map->info.origin.position.x;
        starting_position_.position.y = latest_map->info.origin.position.y;

        // Set the output starting position
        setOutput("starting_position", starting_position_);
        return NodeStatus::SUCCESS;
    }

private:
    std::shared_ptr<Map> map_node_;
    Pose starting_position_;
};



class PublishLog : public SyncActionNode
{
public:
    PublishLog(const std::string& name, const NodeConfig& config)
        : SyncActionNode(name, config),
          node_(rclcpp::Node::make_shared("publish_log_node"))
    {
        publisher_ = node_->create_publisher<std_msgs::msg::String>("/web_message", 10);
    }
    // It is mandatory to define this STATIC method.
    static PortsList providedPorts()
    {
	    return {InputPort<std::string>("message")};
    }

    NodeStatus tick() override    
    { 
        
        Expected<std::string> msg = getInput<std::string>("message");

        auto now = std::chrono::system_clock::now();
        auto now_c = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;

        if(msg.value() == "place holder"){
            if(pressed_stop){
                ss << std::put_time(std::localtime(&now_c), "%F %T") << " - User canceled navigation";
                std_msgs::msg::String message;
                message.data = ss.str();
                publisher_->publish(message); 
                return NodeStatus::SUCCESS;
            }
            else{
                ss << std::put_time(std::localtime(&now_c), "%F %T") << " - The submarine has completed mapping!";
                std_msgs::msg::String message;
                message.data = ss.str();
                publisher_->publish(message); 
                return NodeStatus::SUCCESS;
            }
        
        }
        else{
            ss << std::put_time(std::localtime(&now_c), "%F %T") << msg.value();
            std_msgs::msg::String message;
            message.data = ss.str();
            publisher_->publish(message); 
            return NodeStatus::SUCCESS;
        }      
    }

private:
    rclcpp::Node::SharedPtr node_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_; 
};

static const char* xml_text = R"(
<root BTCPP_format="4" >
     <BehaviorTree ID="MainTree">
        <Sequence>
            <WaitForSeconds seconds="20"/>
            <StartPos starting_position="{starting_pos}"/>
            <!--Loop until user presses start on the website-->
            <RetryUntilSuccessful num_attempts="20000">
                <Sequence>
                    <WaitForSeconds seconds="1"/>
                    <CheckStart/>
                </Sequence>
            </RetryUntilSuccessful>
            <PublishLog message=" - User pressed start, navigation has begun."/>
            <SaySomething message="mission started..." />
            <RetryUntilSuccessful num_attempts="5000">
                <Sequence>
                    <RetryUntilSuccessful num_attempts="200">
                    	<Sequence>
                    	    <Fallback name="turn">
                                <CheckFront/>
                                <Sequence>
                                    <WaitForSeconds seconds="1"/>
                                    <Turn90Degrees/>
                                </Sequence>
                            </Fallback>
                        </Sequence>
                    </RetryUntilSuccessful>
                    <RetryUntilSuccessful num_attempts="200">
                        <Fallback>
                            <Inverter>
                                <CheckFront/>
                            </Inverter>
                            <Sequence>
                    		<MapFinished starting_position="{starting_pos}"/>	
                                <Inverter>
                                    <CheckStart/>
                                </Inverter>
                            </Sequence>
                            <Sequence>
                                <WaitForSeconds seconds="1"/>
                                <AdjustDistance/>
                            </Sequence>
                        </Fallback>
                    </RetryUntilSuccessful>
                    <Forward/>
                    <Fallback>
                        <Inverter>
                            <CheckStart/>
                        </Inverter>
                        <MapFinished starting_position="{starting_pos}"/>
                    </Fallback>
                </Sequence>
            </RetryUntilSuccessful>
            <RetryUntilSuccessful num_attempts = "200">
                <Sequence>
                    <WaitForSeconds seconds="1"/>
                    <Stop/>
                </Sequence>
            </RetryUntilSuccessful>
            <PublishLog message="place holder"/>
            <SaySomething   message="mission completed!" />
        </Sequence> 
     </BehaviorTree>
 </root>
 )";


void spin_node(std::shared_ptr<rclcpp::Node> node) {
    rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();
}


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    
    auto front_node = std::make_shared<Front>();
    std::thread front_spin(spin_node, front_node);
    
    auto side_node = std::make_shared<Side>();
    std::thread side_spin(spin_node, side_node);
    
    auto odom_node = std::make_shared<Odom>();
    std::thread odom_spin(spin_node, odom_node);
    
    auto start_node = std::make_shared<Start>();
    std::thread start_spin(spin_node, start_node);
    
    auto velocity_node = std::make_shared<Velocity>();
    std::thread velocity_spin(spin_node, velocity_node);
        
    auto map_node = std::make_shared<Map>();
    std::thread map_spin(spin_node, map_node);
    
    // Initialize the BehaviorTreeFactory
    BehaviorTreeFactory factory;
    factory.registerNodeType<WaitForSeconds>("WaitForSeconds");
    factory.registerNodeType<SaySomething>("SaySomething");
    factory.registerNodeType<MapFinished>("MapFinished",map_node);
    factory.registerNodeType<Turn90Degrees>("Turn90Degrees",odom_node);
    factory.registerNodeType<AdjustDistance>("AdjustDistance",side_node);
    factory.registerNodeType<Forward>("Forward");
    factory.registerNodeType<Stop>("Stop",velocity_node);
    factory.registerNodeType<PublishLog>("PublishLog");
    factory.registerNodeType<CheckFront>("CheckFront",front_node); 
    factory.registerNodeType<CheckStart>("CheckStart",start_node); 
    factory.registerNodeType<StartPos>("StartPos",map_node); 

    // Create the behavior tree from the XML text
    auto tree = factory.createTreeFromText(xml_text);

    // Behavior tree execution loop
    NodeStatus status = tree.tickOnce();
    while(status == NodeStatus::RUNNING) 
    {
        tree.sleep(std::chrono::milliseconds(100));
        status = tree.tickOnce();
    }
    
    rclcpp::shutdown();
    front_spin.join();
    side_spin.join();
    odom_spin.join();
    start_spin.join();
    velocity_spin.join();
    map_spin.join();

    return 0;
}

