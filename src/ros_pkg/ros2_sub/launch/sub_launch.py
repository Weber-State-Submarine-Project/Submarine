from launch import LaunchDescription
from launch_ros.actions import Node,SetParameter
from ament_index_python.packages import get_package_share_directory
from launch.actions import IncludeLaunchDescription, SetEnvironmentVariable, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_xml.launch_description_sources import XMLLaunchDescriptionSource
import os

def generate_launch_description():
    sub_path = get_package_share_directory('ros2_sub')

    octo = Node(
        package='ros2_sub',
        executable='octo',
        name='octo',
        output='screen'
    )

    foxglove_bridge = IncludeLaunchDescription(
        XMLLaunchDescriptionSource(
            os.path.join(get_package_share_directory('foxglove_bridge'), 'launch', 'foxglove_bridge_launch.xml')
        ),
        launch_arguments={'port': '8765'}.items()
    ) 
    
    ros_bt = Node(
        package='ros_bt',
        executable='sub_exec',
        name='exec_node',
        output='screen'
    )
    
    ekf = Node(
        package='robot_localization',
        executable='ekf_node',
        name='ekf_filter_node',
        output='screen',
        parameters=[os.path.join(sub_path, 'config','ekf.yaml')]
    )

    slam = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
        os.path.join(get_package_share_directory('ros2_sub'),'launch','online_async_launch.py')),
    )


    nav2 = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
        os.path.join(get_package_share_directory('nav2_bringup'), 'launch', 'navigation_launch.py')),
    )

    sdf_file = os.path.join(sub_path, 'models', 'tethys', 'model.sdf')
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

    octomap = IncludeLaunchDescription(
        XMLLaunchDescriptionSource(
            os.path.join(get_package_share_directory('ros2_sub'), 'launch', 'octomap_mapping.launch.xml')),
    )

    #/scan/down
    #/scan/down/points
    down_sonar = Node(
        package='sonars',
        executable='sonar_node',
        name='down_sonar',
        output='screen',
        )
    
    #/scan/left
    #/scan/left/points
    side_sonar = Node(
        package='sonars',
        executable='side_sonar_node',
        name='side_sonar',
        output='screen',
        )

    #/scan/front
    #/scan/front/points
    front_sonar = Node(
        package='sonars',
        executable='front_sonar_node',
        name='front_sonar',
        output='screen',
        )

    #/odom
    speed_sensor = Node(
        package='speed_sensor'
        executable='velocity_sensor'
        name='speed_sensor'
        output='screen',
        )

    #/imu
    orientation_sensor = Node(
        package='',
        executable='',
        name='',
        output='',
        )

    #add motor controller here

    
    return LaunchDescription([
        sub_state_publisher,
        slam,
        ekf,
        ros_bt,
        octomap,
        octo,
        #nav2,
        foxglove_bridge,
        down_sonar,
        side_sonar,
        speed_sensor,
        ])
