#!/usr/bin/env python

import rclpy
from rclpy.node import Node
from orientation_msg.msg import Esc  # Import your custom message
from adafruit_servokit import ServoKit
import time

class EscSubscriber(Node):

    left_esc = 0
    right_esc = 1

    def __init__(self):
        super().__init__('esc_subscriber')

        self.kit = ServoKit(channels=16)
        self.kit.servo[self.left_esc].set_pulse_width_range(1000, 2000)  # Typical range for ESCs
        self.kit.servo[self.right_esc].set_pulse_width_range(1000, 2000)  # Typical range for ESCs

        # Create a subscriber for the 'esc_topic' topic
        self.subscription = self.create_subscription(
            Esc,
            'esc_topic',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning
        self.arm_esc()

    # Callback function for when a message is received

    def arm_esc(self):
        
        self.get_logger().info('[ARM - ESC] Arming both ESCs')
       
        # Step 1: Power on the ESC (ensure it's powered up and ready)
        
        # Step 2: Set throttle to maximum (2ms pulse width for full speed)
        self.get_logger().info('[ARM - ESC] Setting Max speed (2ms pulse)')
        self.kit.servo[self.left_esc].angle = 180  # 180 degrees corresponds to maximum throttle (2ms pulse)
        self.kit.servo[self.right_esc].angle = 180
        time.sleep(2)  # Wait for 2 seconds

        # Step 3: Set throttle to neutral (1.5ms pulse width to stop)
        self.get_logger().info('[ARM - ESC] Setting throttle to neutral (1.5ms pulse)')
        self.kit.servo[self.left_esc].angle = 90  # 90 degrees corresponds to neutral (1.5ms pulse)
        self.kit.servo[self.right_esc].angle = 90
        time.sleep(2)  # Wait for 2 seconds to ensure ESC recognizes the signal
        
        self.get_logger().info('[ARM - ESC] ESCs should now both be armed!!!')

    def disable_esc(self):
        self.get_logger().info('[DISABLE - ESC] Disabling both ESCs')

        # Set to neutral (stop) and disable PWM signal
        self.kit.servo[self.left_esc].angle = 90  # 1.5ms (neutral)
        self.kit.servo[self.right_esc].angle = 90
        time.sleep(1)  # Wait for the ESC to recognize neutral
        self.kit.servo[self.left_esc].angle = None  # Disable the PWM signal
        self.kit.servo[self.right_esc].angle = None

    def listener_callback(self, msg):
        #self.get_logger().info(f'[ESC - CALLBACK] Received motor selection: "{msg.motor_selection}"')
        
        motor_selected = msg.motor_selection
        power_selected = msg.power_percentage

        # Converts Percentage given to pwm pulse
        if -100 <= power_selected <= 100:
            # Map throttle percentage to angle:
            # -100% -> 1ms (full reverse), 0% -> 1.5ms (neutral), 100% -> 2ms (full forward)
            angle = 90 + (power_selected * 90 / 100)  # Map -100 to 100% to 0-180 degrees
        else:
            return

        # Sends pulse to selected motor
        if motor_selected == 'Left':
            #self.get_logger().info(f'[ESC - CONTROL] Left Motor Set to "{power_selected}"')
            self.kit.servo[self.left_esc].angle = angle

        elif motor_selected == 'Right':
            #self.get_logger().info(f'[ESC - CONTROL] Right Motor Set to "{power_selected}"')
            self.kit.servo[self.right_esc].angle = angle

        elif motor_selected == 'Arm':
            self.get_logger().info('Arming Both ESCs')
            self.arm_esc()

        else:
            self.get_logger().info(f'The following is a invalid option: "{motor_selected}"')

def main(args=None):
    rclpy.init(args=args)
    esc_subscriber = EscSubscriber()
    
    try:
        rclpy.spin(esc_subscriber)
    except KeyboardInterrupt:
        pass
    
    esc_subscriber.disable_esc()
    esc_subscriber.destroy_node()
    rclpy.shutdown()
    


if __name__ == '__main__':
    main()

