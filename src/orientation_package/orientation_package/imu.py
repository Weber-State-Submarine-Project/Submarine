

import rclpy
from rclpy.node import Node
from orientation_msg.msg import Orientation
from sensor_msgs.msg import Imu
import numpy as np

class OrientationToImu(Node):
    def __init__(self):
        super().__init__('orientation_to_imu')
        self.subscription = self.create_subscription(
            Orientation,
            'orientation_topic',
            self.listener_callback,
            10)
        self.publisher_ = self.create_publisher(Imu, '/imu', 10)
        self.last_time = self.get_clock().now()

    def listener_callback(self, msg):
        current_time = self.get_clock().now()
        dt = (current_time - self.last_time).nanoseconds / 1e9
        self.last_time = current_time

        imu_msg = Imu()
        imu_msg.header.stamp = current_time.to_msg()
        imu_msg.header.frame_id = 'imu'

        # Populate IMU message with orientation data
        imu_msg.linear_acceleration.x = msg.lin_acc_x
        imu_msg.linear_acceleration.y = msg.lin_acc_y
        imu_msg.linear_acceleration.z = msg.lin_acc_z
        imu_msg.angular_velocity.x = msg.gyro_x
        imu_msg.angular_velocity.y = msg.gyro_y
        imu_msg.angular_velocity.z = msg.gyro_z
        imu_msg.orientation.x = msg.quat_x
        imu_msg.orientation.y = msg.quat_y
        imu_msg.orientation.z = msg.quat_z
        imu_msg.orientation.w = msg.quat_w

        self.publisher_.publish(imu_msg)
        #lf.get_logger().info(f'Publishing IMU data: {imu_msg}')

def main(args=None):
    rclpy.init(args=args)
    node = OrientationToImu()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
