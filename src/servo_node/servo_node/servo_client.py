#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64

class ServoClient(Node):
    def __init__(self):
        super().__init__('servo_client')
        self.publisher = self.create_publisher(Float64, '/servo_command', 10)
        self.subscription = self.create_subscription(
            Float64,
            '/servo_position',
            self.servo_position_callback,
            10)
        self.current_position = None

    def servo_position_callback(self, msg):
        self.current_position = msg.data
        self.get_logger().info(f'Received servo position: {self.current_position}')

    def send_command(self, command):
        msg = Float64()
        msg.data = command
        self.get_logger().info(f'Sending servo command: {command}')
        self.publisher.publish(msg)

    def run(self):
        while rclpy.ok():
            command_str = input('Enter servo command (-1.0 to 1.0, q to quit): ')
            if command_str.lower() == 'q':
                break
            try:
                command = float(command_str)
                if command < -1.0 or command > 1.0:
                    print('Command must be between -1.0 and 1.0')
                    continue
                self.send_command(command)
            except ValueError:
                print('Invalid input. Please enter a number between -1.0 and 1.0 or q to quit')

        self.destroy_node()
        rclpy.shutdown()

def main():
    rclpy.init()
    servo_client = ServoClient()
    servo_client.run()

if __name__ == '__main__':
    main()

