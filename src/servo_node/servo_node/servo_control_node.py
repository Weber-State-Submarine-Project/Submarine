# File: servo_control_node.py
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64
import RPi.GPIO as GPIO
import time

class ServoControlNode(Node):
    def __init__(self):
        super().__init__('servo_control_node')
        self.publisher = self.create_publisher(Float64, 'servo_position', 10)
        self.subscription = self.create_subscription(
            Float64,
            'servo_command',
            self.servo_callback,
            10)

        # Initialize GPIO
        GPIO.setmode(GPIO.BCM)
        self.servo_pin = 12  # BCM GPIO pin 12 (PWM pin)
        GPIO.setup(self.servo_pin, GPIO.OUT)

        # Setup PWM
        self.pwm = GPIO.PWM(self.servo_pin, 50)  # PWM frequency: 50 Hz
        self.pwm.start(0)  # Start PWM with 0% duty cycle initially
        self.servo_position = 0.0

    def servo_callback(self, msg):
        self.servo_position = msg.data
        self.get_logger().info(f'Received servo command: {self.servo_position}')

        # Convert position (-1 to 1) to duty cycle (2.5% to 12.5%)
        duty_cycle = 2.5 + (self.servo_position + 1.0) * 5.0
        self.pwm.ChangeDutyCycle(duty_cycle)
        time.sleep(0.5)  # Give time for servo to reach position

        # Publish current servo position
        msg = Float64()
        msg.data = self.servo_position
        self.publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    servo_control_node = ServoControlNode()
    try:
        rclpy.spin(servo_control_node)
    except KeyboardInterrupt:
        pass
    finally:
        # Cleanup GPIO and shutdown ROS
        servo_control_node.pwm.stop()
        GPIO.cleanup()
        servo_control_node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()


