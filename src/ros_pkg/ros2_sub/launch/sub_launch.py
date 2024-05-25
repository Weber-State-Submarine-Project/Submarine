from launch import LaunchDescription
from launch_ros.actions import Node,SetParameter
from ament_index_python.packages import get_package_share_directory
from launch.actions import IncludeLaunchDescription, SetEnvironmentVariable, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_xml.launch_description_sources import XMLLaunchDescriptionSource
import os

def generate_launch_description():
    pkg_ros_gz_sim = get_package_share_directory('ros_gz_sim')
    sub_path = get_package_share_directory('ros2_sub')

    gz_sim = IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
            os.path.join(pkg_ros_gz_sim, 'launch', 'gz_sim.launch.py')),
            launch_arguments={'gz_args': '-r '+os.path.join(sub_path,'worlds/plugin/custom_sensor_system/sub.sdf'+' -s --headless-rendering')}.items(),
        )
    odom_convert = Node(
        package='ros2_sub',
        executable='odom',
        name='odom',
        output='screen'
    )

    octo = Node(
        package='ros2_sub',
        executable='octo',
        name='octo',
        output='screen'
    )


    web_link = IncludeLaunchDescription(
        XMLLaunchDescriptionSource(
        os.path.join(get_package_share_directory('rosbridge_server'), 'launch', 'rosbridge_websocket_launch.xml')),
        )

    
    control = Node(
        package='ros2_sub',
        executable='controller',
        name='controller',
        output='screen'
    )

    ros_bt = Node(
        package='ros_bt',
        executable='sub_exec',
        name='exec_node',
        output='screen'
    )


    bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=[
            '/imu@sensor_msgs/msg/Imu[gz.msgs.IMU',
            '/scan/left@sensor_msgs/msg/LaserScan[gz.msgs.LaserScan',
            '/scan/left/points@sensor_msgs/msg/PointCloud2[gz.msgs.PointCloudPacked',
            '/scan/down@sensor_msgs/msg/LaserScan[gz.msgs.LaserScan',
            '/scan/down/points@sensor_msgs/msg/PointCloud2[gz.msgs.PointCloudPacked',
            '/scan/front@sensor_msgs/msg/LaserScan[gz.msgs.LaserScan',
            '/scan/front/points@sensor_msgs/msg/PointCloud2[gz.msgs.PointCloudPacked',
            '/model/tethys/joint/propeller_joint/ang_vel@std_msgs/msg/Float64[gz.msgs.Double',
            '/model/tethys/joint/propeller_joint/cmd_thrust@std_msgs/msg/Float64]gz.msgs.Double',
            '/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock',
            '/angular_vel@std_msgs/msg/Float64]gz.msgs.Double',
            '/odometer@geometry_msgs/msg/Vector3[gz.msgs.Vector3d'
            ],
            output='screen'
    )

    keyboard = Node(
        package='teleop_twist_keyboard',
        executable='teleop_twist_keyboard',
        output='screen',
        prefix='xterm -e'
    )

    rviz_config = os.path.join(
        get_package_share_directory('ros2_sub'),
        'rviz',
        'sub.rviz'
    )
    rviz = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        arguments=['-d',rviz_config]
    )
    
    delayed_rviz_launch = TimerAction(
        period=10.0,  # Delay time in seconds
        actions=[rviz]
    )

    ekf = Node(
        package='robot_localization',
        executable='ekf_node',
        name='ekf_filter_node',
        output='screen',
        parameters=[os.path.join(sub_path, 'config','ekf.yaml')]
    )
    nav2 = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
        os.path.join(get_package_share_directory('ros2_sub'), 'launch', 'navigation_launch.py')),
        )

    slam = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
        os.path.join(get_package_share_directory('ros2_sub'),'launch','online_async_launch.py')),
    )

   
    sdf_file = os.path.join(sub_path,
        'models', 'tethys', 'model.sdf')
    with open(sdf_file, 'r') as infp:
        sub_desc = infp.read()

    sub_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='both',
        parameters=[
            {'robot_description':sub_desc},
            {'use_sim_time': True},
        ]
    )

    grid_map = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
        os.path.join(get_package_share_directory('grid_map_pcl'),'launch','grid_map_pcl_loader_launch.py')),
    )

    octomap = IncludeLaunchDescription(
                XMLLaunchDescriptionSource(
                    os.path.join(get_package_share_directory('ros2_sub'), 'launch', 'octomap_mapping.launch.xml')),
            )
            
    # Define a TimerAction for the first octomap
    delayed_octomap = TimerAction(
    	period=30.0,  # Delay time in seconds for the first octomap
    	actions=[octomap]
    )

    # Define a TimerAction for the second octomap (if needed)
    delayed_octo= TimerAction(
    	period=30.0,  # Delay time in seconds for the second octomap
    	actions=[octo]
    )
    


    
    return LaunchDescription([
        SetEnvironmentVariable(name='GZ_SIM_RESOURCE_PATH', value=sub_path),
        SetParameter(name='use_sim_time',value=True),
        gz_sim,
        sub_state_publisher,
        bridge,
        odom_convert,
        #nav2,
        slam,
        ekf,
       #keyboard,
       #control,
        web_link,
        ros_bt,
        rviz,
        #grid_map,
        octomap,
        octo
        ])