#!/usr/bin/env python

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from orientation_msg.msg import Esc

class JoyToEsc(Node):

    def __init__(self):
        super().__init__('joy_to_esc')

        # Create subscriber to the 'joy' topic
        self.subscription = self.create_subscription(
            Joy,
            'joy',
            self.joy_callback,
            10)

        # Create publisher to send motor commands
        self.publisher = self.create_publisher(Esc, 'esc_topic', 10)

    def joy_callback(self, msg):
        # Assuming the left joystick's vertical axis is axis[1] and horizontal axis is axis[0]
        left_vertical = msg.axes[1]  # Forward/backward control (-1 to 1)
        left_horizontal = msg.axes[0]  # Left/right control (-1 to 1)

        # Max motor power (adjust this based on your motor range)
        max_power = 50

        # Corrected motor speeds based on both axes
        # Left motor should move forward (positive) on right turns, and backward (negative) on left turns
        left_motor_power = (left_vertical - left_horizontal) / 2 * max_power
        # Right motor should move backward (negative) on right turns, and forward (positive) on left turns
        right_motor_power = (left_vertical + left_horizontal) / 2 * max_power

        # Normalize the motor values if they exceed max range (-50 to 50)
        left_motor_power = max(min(left_motor_power, max_power), -max_power)
        right_motor_power = max(min(right_motor_power, max_power), -max_power)

        # Convert motor powers to integers to match the expected message type
        left_motor_power = int(left_motor_power)
        right_motor_power = int(right_motor_power)

        # Create and publish the message to control ESCs
        esc_msg = Esc()
        esc_msg.motor_selection = 'Left'
        esc_msg.power_percentage = left_motor_power
        self.publisher.publish(esc_msg)

        esc_msg.motor_selection = 'Right'
        esc_msg.power_percentage = right_motor_power
        self.publisher.publish(esc_msg)
        
        self.get_logger().info(f'Published left motor: {left_motor_power}, right motor: {right_motor_power}')


def main(args=None):
    rclpy.init(args=args)
    node = JoyToEsc()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

