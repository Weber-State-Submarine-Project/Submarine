import rclpy
from rclpy.node import Node
from orientation_msg.msg import Esc  # Import your custom message

class EscPublisher(Node):
    def __init__(self):
        super().__init__('esc_publisher')
        
        # Create a publisher on the 'esc_topic'
        self.publisher_ = self.create_publisher(Esc, 'esc_topic', 10)

    def publish_message(self, motor_selection, power_percentage):
        # Create a new Esc message
        msg = Esc()
        
        # Set the motor selection and power percentage based on user input
        msg.motor_selection = motor_selection
        msg.power_percentage = power_percentage

        # Log the message being published
        self.get_logger().info(f'Publishing: Motor "{msg.motor_selection}", Power {msg.power_percentage}%')
        
        # Publish the message to the topic
        self.publisher_.publish(msg)


def main(args=None):
    rclpy.init(args=args)

    # Create the publisher node
    esc_publisher = EscPublisher()

    try:
        while rclpy.ok():
            # Get motor selection input from the user
            motor_selection = input("Enter motor selection (Left, Right, Arm): ").capitalize()

            # Validate motor selection input
            if motor_selection not in ['Left', 'Right', 'Arm']:
                print("Invalid motor selection. Please enter 'Left', 'Right', or 'Arm'.")
                continue

            # Get power percentage input from the user (only for Left/Right motors)
            if motor_selection in ['Left', 'Right']:
                try:
                    power_percentage = int(input("Enter power percentage (-100 to 100): "))
                    
                    # Validate power percentage input
                    if not (-100 <= power_percentage <= 100):
                        print("Invalid power percentage. Must be between -100 and 100.")
                        continue
                except ValueError:
                    print("Invalid input. Please enter a valid integer for power percentage.")
                    continue
            else:
                # If the motor is "Arm", power percentage doesn't matter; set it to 0
                power_percentage = 0

            # Publish the message with the user inputs
            esc_publisher.publish_message(motor_selection, power_percentage)

    except KeyboardInterrupt:
        pass

    # Cleanup
    esc_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

