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


namespace chr = std::chrono;
using namespace BT;
using GetMap = nav_msgs::srv::GetMap;
using geometry_msgs::msg::Pose;
using namespace std::literals::chrono_literals;
using OccupancyGrid = nav_msgs::msg::OccupancyGrid;

int test = 0;
int pressed_stop = 0;

// SyncActionNode (synchronous action) with an input port.
/*
   a SyncActionNode can only return SUCCESS or FAILURE
   it cannot return RUNNING. so it is only good for simple, fast operations
 */
// SyncActionNode (synchronous action) with an input port.


class CheckFront : public RosTopicSubNode<sensor_msgs::msg::LaserScan>
{
public:
    CheckFront(const std::string& name, const NodeConfiguration& config, const RosNodeParams& params)
        : RosTopicSubNode<sensor_msgs::msg::LaserScan>(name, config, params)
    {}
    
    // It is mandatory to define this STATIC method.
    static PortsList providedPorts()
    {
	    return {};
    }
    // Override the virtual function tick()
    NodeStatus onTick(const std::shared_ptr<sensor_msgs::msg::LaserScan>& latest_distance) override
    {
        auto dist = latest_distance->ranges[0];
        //may need to change min distance to fit hardware turn radius
        if(dist >16){
            std::cout << "Distance from front wall is good: "<<dist << "\n";
            return NodeStatus::SUCCESS;
        } else {
            std::cout<<"FAIL DIST: " << dist <<"\n";
            test = 1;
            return NodeStatus::FAILURE;
        }
    }
};

class CheckSide : public RosTopicSubNode<sensor_msgs::msg::LaserScan>
{
public:
    CheckSide(const std::string& name, const NodeConfiguration& config, const RosNodeParams& params)
        : RosTopicSubNode<sensor_msgs::msg::LaserScan>(name, config, params)
    {}
    
    // It is mandatory to define this STATIC method.
    static PortsList providedPorts()
    {
    	return {OutputPort<std::shared_ptr<sensor_msgs::msg::LaserScan>>("scan")};
    }
    // Override the virtual function tick()
    NodeStatus onTick(const std::shared_ptr<sensor_msgs::msg::LaserScan>& latest_distance) override
    {
        setOutput("scan",latest_distance);
        return NodeStatus::SUCCESS;    
    }
};

//The IMU from GZ sim uses Quaternions measurement, so this function will likely need to be rewritten to work properly with our hardware IMU
class CheckOdom : public RosTopicSubNode<sensor_msgs::msg::Imu>
{
public:
    CheckOdom(const std::string& name, const NodeConfiguration& config, const RosNodeParams& params)
        : RosTopicSubNode<sensor_msgs::msg::Imu>(name, config, params)
    {}
    
    // It is mandatory to define this STATIC method.
    static PortsList providedPorts()
    {
    	return {OutputPort<std::shared_ptr<sensor_msgs::msg::Imu>>("odom")};
    }
    // Override the virtual function tick()
    NodeStatus onTick(const std::shared_ptr<sensor_msgs::msg::Imu>& odometry) override
    {
        std::cout<<"Got IMU\n";
        setOutput("odom", odometry);
        return NodeStatus::SUCCESS;
    }
};

//check if start button has been pressed on the web UI
class CheckStart : public RosTopicSubNode<std_msgs::msg::Int32>
{
public:
    CheckStart(const std::string& name, const NodeConfiguration& config, const RosNodeParams& params)
        : RosTopicSubNode<std_msgs::msg::Int32>(name, config, params)
    {}
    
    // It is mandatory to define this STATIC method.
    static PortsList providedPorts()
    {
    	return {};
    }
    // Override the virtual function tick()
    NodeStatus onTick(const std::shared_ptr<std_msgs::msg::Int32>& start) override
    {
        if(start->data == 0){
            std::cout<<"Waiting for user to start navigation\n";
            pressed_stop = 1;
            return NodeStatus::FAILURE;
        }
        else if(start->data == 1){
            std::cout<<"User started navigation\n";
            pressed_stop = 0;
            return NodeStatus::SUCCESS;
        }
        else{
            std::cout<<"Error, unable to get user input from website\n";
            pressed_stop = 0;
            return NodeStatus::FAILURE;
        }
            
    }
};


class CheckVel : public RosTopicSubNode<nav_msgs::msg::Odometry>
{
public:
    CheckVel(const std::string& name, const NodeConfiguration& config, const RosNodeParams& params)
        : RosTopicSubNode<nav_msgs::msg::Odometry>(name, config, params)
    {}
    
    // It is mandatory to define this STATIC method.
    static PortsList providedPorts()
    {
    	return {OutputPort<std::shared_ptr<nav_msgs::msg::Odometry>>("vel")};
    }
    // Override the virtual function tick()
    NodeStatus onTick(const std::shared_ptr<nav_msgs::msg::Odometry>& odometry) override
    {
        std::cout<<"Got Velocity\n";
        setOutput("vel", odometry);
        return NodeStatus::SUCCESS;
    }
};

class Turn90Degrees : public SyncActionNode
{
public:
    Turn90Degrees(const std::string& name, const NodeConfiguration& config)
        : SyncActionNode(name, config),
          node_(rclcpp::Node::make_shared("turn_90_degrees_node"))
    {
        publisher_ = node_->create_publisher<std_msgs::msg::Float64>("/angular_vel", 10);
    }
    // It is mandatory to define this STATIC method.
    static PortsList providedPorts()
    {
        return {InputPort<std::shared_ptr<sensor_msgs::msg::Imu>>("odom")};
    }

    NodeStatus tick() override    
    {   
        Expected<std::shared_ptr<sensor_msgs::msg::Imu>> msg = getInput<std::shared_ptr<sensor_msgs::msg::Imu>>("odom");
        if (!msg) {
            return NodeStatus::FAILURE;
        }
        auto current_orientation = msg.value()->orientation;
        tf2::Quaternion current_quaternion(current_orientation.x, current_orientation.y, current_orientation.z, current_orientation.w);

        // Convert the current orientation quaternion to roll, pitch, yaw
        double roll, pitch, yaw;
        tf2::Matrix3x3(current_quaternion).getRPY(roll, pitch, yaw);

        // Calculate the target yaw by subtracting pi/2 from the current yaw
        if(target_yaw == 0){
            // Calculate the target yaw by subtracting pi/2 from the current yaw
            target_yaw = yaw - M_PI_2;
	    // Ensure the target yaw is within the range [-pi, pi]
	    if (target_yaw < -M_PI)
	    	target_yaw = M_PI_2;
	    else if (target_yaw > M_PI)
	    	target_yaw -= 2 * M_PI;
        }

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
    double target_yaw;
    const double angle_tolerance_ = 0.02; // radians
};

class AdjustDistance : public SyncActionNode
{
public:
    AdjustDistance(const std::string& name, const NodeConfiguration& config)
        : SyncActionNode(name, config),
          node_(rclcpp::Node::make_shared("adjust_distance_node"))
    {
        publisher_ = node_->create_publisher<std_msgs::msg::Float64>("/angular_vel", 10);
    }
    // It is mandatory to define this STATIC method.
    static PortsList providedPorts()
    {
        return {InputPort<std::shared_ptr<sensor_msgs::msg::LaserScan>>("scan")};
    }

    NodeStatus tick() override    
    {   
        Expected<std::shared_ptr<sensor_msgs::msg::LaserScan>> latest_distance = getInput<std::shared_ptr<sensor_msgs::msg::LaserScan>>("scan");
        std_msgs::msg::Float64 val;
        val.data = -0.3; // Adjust this value for hardware if necessary
        std_msgs::msg::Float64 val2;
        val2.data = 0.3; // Adjust this value for hardware if necessary
        std_msgs::msg::Float64 val3;
        val3.data = 0; 

        auto dist = latest_distance.value()->ranges[5];
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
};


//will likely need adjustment for hardware, the simulation propeller is controlled by a float, this may not be the case for the motor
class Forward : public SyncActionNode
{
public:
    Forward(const std::string& name, const NodeConfiguration& config)
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
    Stop(const std::string& name, const NodeConfiguration& config)
        : SyncActionNode(name, config),
          node_(rclcpp::Node::make_shared("stop_node"))
    {
        publisher_ = node_->create_publisher<std_msgs::msg::Float64>("/model/tethys/joint/propeller_joint/cmd_thrust", 10); 
        publisher2_ = node_->create_publisher<std_msgs::msg::Float64>("/angular_vel", 10);
        publisher3_ = node_->create_publisher<std_msgs::msg::Int32>("/done", 10); 
    }
    // It is mandatory to define this STATIC method.
    static PortsList providedPorts()
    {
	    return {InputPort<std::shared_ptr<nav_msgs::msg::Odometry>>("vel")};
    }

    NodeStatus tick() override    
    { 
        std_msgs::msg::Float64 val2;
        val2.data = 0; 

        std_msgs::msg::Int32 val3;
        val3.data = 1;
    
        publisher3_->publish(val3);
        publisher2_->publish(val2);

        Expected<std::shared_ptr<nav_msgs::msg::Odometry>> velocity_in = getInput<std::shared_ptr<nav_msgs::msg::Odometry>>("vel");
        double velocity = velocity_in.value()->twist.twist.linear.x;
        std_msgs::msg::Float64 val;
        if(std::abs(velocity) > 0.02){
            std::cout<<"Slowing Down\n";
            val.data = 10;
            publisher_->publish(val);//speed is hardcoded for ease of simulation, will need to be changed for hardware    
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
    MapFinished(const std::string& name, const NodeConfig& config)
        : SyncActionNode(name, config), tf_buffer_(std::make_shared<rclcpp::Clock>(RCL_SYSTEM_TIME)),
          tf_listener_(tf_buffer_),
          node_(rclcpp::Node::make_shared("stop_node"))
    {
        publisher_ = node_->create_publisher<std_msgs::msg::Int32>("/done", 10); 
        // Initialize the starting position
        starting_position_ = Pose();
    }

    static PortsList providedPorts()
    {
        return { 
            InputPort<OccupancyGrid>("map"),
            InputPort<Pose>("starting_position")
        };
    }

    NodeStatus tick() override
    {
        // Get the inputs
        auto map_input = getInput<OccupancyGrid>("map");
        auto starting_position_input = getInput<Pose>("starting_position");
        std_msgs::msg::Int32 val;
        val.data = 0;

        if (!map_input)
        {
            throw RuntimeError("missing required input [map]: ", map_input.error());
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
        if (isApproximatelyEqual(current_pose.pose, starting_position_) && test == 1)
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
        WaitForSeconds(const std::string& name, const NodeConfiguration& config)
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

class StartPos: public RosServiceNode<GetMap>
{
    public:
        StartPos(const std::string& name,
                const NodeConfig& conf,
                const RosNodeParams& params)
            : RosServiceNode<GetMap>(name, conf, params)
        {
            // Initialize the starting position
            starting_position_ = Pose();
        }
        static PortsList providedPorts()
        {
            return providedBasicPorts({OutputPort<OccupancyGrid>("map"),
            OutputPort<Pose>("starting_position")});
        }
        bool setRequest(Request::SharedPtr& request) override
        {
            request = std::make_shared<GetMap::Request>();
            return true;
        }
        NodeStatus onResponseReceived(const Response::SharedPtr& response) override
        {
            RCLCPP_INFO(node_->get_logger(), "Got a map!!!!!");
            setOutput("map",response->map);
            
            // Extract the starting position from the map metadata
            starting_position_.position.x = response->map.info.origin.position.x;
            starting_position_.position.y = response->map.info.origin.position.y;

            // Set the output starting position
            setOutput("starting_position", starting_position_);
            return NodeStatus::SUCCESS;
        }
        virtual NodeStatus onFailure(ServiceNodeErrorCode error) override
        {
            RCLCPP_ERROR(node_->get_logger(), "Error: %d", error);
            return NodeStatus::FAILURE;
        }
    private:
        Pose starting_position_;
};

class MapService: public RosServiceNode<GetMap>
{
    public:
        MapService(const std::string& name,
                const NodeConfig& conf,
                const RosNodeParams& params)
            : RosServiceNode<GetMap>(name, conf, params)
        {}
        static PortsList providedPorts()
        {
            return providedBasicPorts({OutputPort<OccupancyGrid>("map")});
        }
        bool setRequest(Request::SharedPtr& request) override
        {
            request = std::make_shared<GetMap::Request>();
            return true;
        }
        NodeStatus onResponseReceived(const Response::SharedPtr& response) override
        {
            RCLCPP_INFO(node_->get_logger(), "Got a map!!!!!");
            setOutput("map",response->map);
          
            return NodeStatus::SUCCESS;
        }
        virtual NodeStatus onFailure(ServiceNodeErrorCode error) override
        {
            RCLCPP_ERROR(node_->get_logger(), "Error: %d", error);
            return NodeStatus::FAILURE;
        }
};

class PublishLog : public SyncActionNode
{
public:
    PublishLog(const std::string& name, const NodeConfiguration& config)
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
            <WaitForSeconds seconds="30"/>
            <StartPos map = "{map}" starting_position="{starting_pos}"/>
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
                                    <CheckOdom odom = "{odometry}"/>
                                    <WaitForSeconds seconds="1"/>
                                    <Turn90Degrees odom = "{odometry}"/>
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
                            	<MapService map = "{map}"/>
                    		    <MapFinished map = "{map}" starting_position="{starting_pos}"/>	
                                <Inverter>
                                    <CheckStart/>
                                </Inverter>
                            </Sequence>
                            <Sequence>
                                <CheckSide scan = "{current_left_scan}"/>
                                <WaitForSeconds seconds="1"/>
                                <AdjustDistance scan = "{current_left_scan}"/>
                            </Sequence>
                        </Fallback>
                    </RetryUntilSuccessful>
                    <Forward/>

                    <WaitForSeconds seconds="1"/>
                    <MapService map = "{map}"/>
                    <Fallback>
                        <Inverter>
                            <CheckStart/>
                        </Inverter>
                        <MapFinished map = "{map}" starting_position="{starting_pos}"/>
                    </Fallback>
                </Sequence>
            </RetryUntilSuccessful>
            <RetryUntilSuccessful num_attempts = "200">
                <Sequence>
                    <CheckVel vel = "{velocity}"/>
                    <WaitForSeconds seconds="1"/>
                    <Stop vel = "{velocity}"/>
                </Sequence>
            </RetryUntilSuccessful>
            <MapService map = "{map}"/>
            <PublishLog message="place holder"/>
            <SaySomething   message="mission completed!" />
        </Sequence> 
     </BehaviorTree>
 </root>
 )";

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    
    // Initialize the BehaviorTreeFactory
    BehaviorTreeFactory factory;
    factory.registerNodeType<WaitForSeconds>("WaitForSeconds");
    factory.registerNodeType<SaySomething>("SaySomething");
    factory.registerNodeType<MapFinished>("MapFinished");
    factory.registerNodeType<Turn90Degrees>("Turn90Degrees");
    factory.registerNodeType<AdjustDistance>("AdjustDistance");
    factory.registerNodeType<Forward>("Forward");
    factory.registerNodeType<Stop>("Stop");
    factory.registerNodeType<PublishLog>("PublishLog");
        
    // Register the map service node
    auto map_service_node = std::make_shared<rclcpp::Node>("get_map_client");
    RosNodeParams map_service_params; 
    map_service_params.nh = map_service_node;
    map_service_params.default_port_value = "slam_toolbox/dynamic_map";
    factory.registerNodeType<MapService>("MapService", map_service_params);
    
    auto start_pose_node = std::make_shared<rclcpp::Node>("start_pos_client");
    RosNodeParams start_pose_params; 
    start_pose_params.nh = start_pose_node;
    start_pose_params.default_port_value = "slam_toolbox/dynamic_map";
    factory.registerNodeType<StartPos>("StartPos", start_pose_params);

    auto front = std::make_shared<rclcpp::Node>("check_front");
    RosNodeParams front_params;
    front_params.nh = front;
    front_params.default_port_value ="/scan/front";
    factory.registerNodeType<CheckFront>("CheckFront", front_params);

    auto odom_node = std::make_shared<rclcpp::Node>("check_odom");
    RosNodeParams odom_params;
    odom_params.nh = odom_node;
    odom_params.default_port_value ="/imu";
    factory.registerNodeType<CheckOdom>("CheckOdom", odom_params);

    auto side_node = std::make_shared<rclcpp::Node>("check_side");
    RosNodeParams side_params;
    side_params.nh = side_node;
    side_params.default_port_value ="/scan/left";
    factory.registerNodeType<CheckSide>("CheckSide", side_params);
    
    auto vel_node = std::make_shared<rclcpp::Node>("check_vel");
    RosNodeParams vel_params;
    vel_params.nh = vel_node;
    vel_params.default_port_value ="/odom";
    factory.registerNodeType<CheckVel>("CheckVel", vel_params);

    auto start_node = std::make_shared<rclcpp::Node>("check_start");
    RosNodeParams start_params;
    start_params.nh = start_node;
    start_params.default_port_value ="/start";
    factory.registerNodeType<CheckStart>("CheckStart", start_params);
    
    

    // Create the behavior tree from the XML text
    auto tree = factory.createTreeFromText(xml_text);

    // Behavior tree execution loop
    NodeStatus status = tree.tickOnce();
    while(status == NodeStatus::RUNNING) 
    {
        tree.sleep(std::chrono::milliseconds(100));
        status = tree.tickOnce();
    }

    return 0;
}

