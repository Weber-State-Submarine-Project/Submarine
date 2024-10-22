import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from orientation_msg.msg import Orientation
import numpy as np

class VelocitySensor(Node):
    def __init__(self):
        super().__init__('velocity_sensor')
        self.subscription = self.create_subscription(
            Orientation,
            'orientation_topic',
            self.listener_callback,
            10)
        self.publisher_ = self.create_publisher(Odometry, 'odom', 10)
        # Initialize data arrays
        self.acceleration_data = []
        self.time_data = []

    def listener_callback(self, msg):
        current_time = self.get_clock().now().to_msg().sec
        self.acceleration_data.append(msg.lin_acc_x)
        self.time_data.append(current_time)
        x_velocity = 0.
        # Integrate using trapezoidal rule
        if len(self.acceleration_data) > 1:
            x_velocity = np.trapz(self.acceleration_data, self.time_data)

        if np.abs(msg.lin_acc_x) < 0.01:    
            self.time_data = []
            self.acceleration_data = []
            x_velocity = 0.

        odom_msg = Odometry()
        odom_msg.header.stamp = self.get_clock().now().to_msg()
        odom_msg.header.frame_id = "odom"
        odom_msg.child_frame_id = "base_link"
        odom_msg.twist.twist.linear.x = -x_velocity
        self.publisher_.publish(odom_msg)
            
def main(args=None):
    rclpy.init(args=args)
    node = VelocitySensor()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

