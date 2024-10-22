import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
import serial
import time

class VelocitySensor(Node):
    def __init__(self):
        super().__init__('velocity_sensor')
        self.publisher_ = self.create_publisher(Odometry, 'odom', 10)
        self.serial_port = serial.Serial('/dev/ttyUSB3', 9600, timeout=1)
        self.last_received_time = time.time()
        self.timeout_duration = 0.1  # Duration in seconds to wait before publishing zero
        self.timer = self.create_timer(0.01, self.timer_callback)  # Reduced timer interval for more frequent checks

    def timer_callback(self):
        current_time = time.time()
        if self.serial_port.in_waiting > 0:
            try:
                line = self.serial_port.readline().decode('utf-8').strip()
                x_velocity = float(line)
                self.last_received_time = current_time
                odom_msg = Odometry()
                odom_msg.header.stamp = self.get_clock().now().to_msg()
                odom_msg.header.frame_id = "odom"
                odom_msg.child_frame_id = "base_link"
                odom_msg.twist.twist.linear.x = -x_velocity
                self.publisher_.publish(odom_msg)
            except ValueError:
                self.get_logger().warn('Received invalid data from UART')
        elif current_time - self.last_received_time > self.timeout_duration:
            x_velocity = 0.0
            odom_msg = Odometry()
            odom_msg.header.stamp = self.get_clock().now().to_msg()
            odom_msg.header.frame_id = "odom"
            odom_msg.child_frame_id = "base_link"
            odom_msg.twist.twist.linear.x = x_velocity
            self.publisher_.publish(odom_msg)

def main(args=None):
    rclpy.init(args=args)
    node = VelocitySensor()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

