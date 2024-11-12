import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from nav_msgs.msg import Odometry
from std_msgs.msg import Int32

class LaserScanVelocitySubscriber(Node):
    def __init__(self):
        super().__init__('laser_scan_velocity_subscriber')
        
        self.scan_subscriber = self.create_subscription(
            LaserScan,
            '/scan/front',
            self.scan_callback,
            10
        )
        self.turning_subscriber = self.create_subscription(
            Int32,  
            '/turning',
            self.turning_callback,
            10
        )
        
        self.prev_distance = None

        # Publisher for Odometry message
        self.odom_publisher = self.create_publisher(Odometry, 'odom', 10)

        self.noise_threshold = 0.001       # Noise threshold to filter small changes (meters)

        # Moving average buffer and size
        self.distance_buffer = []
        self.buffer_size = 5  # Number of readings for averaging

        self.turn_status = 0

        # Timer callback at a fixed interval
        self.timer_period = 1.2  # Timer period in seconds
        self.create_timer(self.timer_period, self.timer_callback)

    def turning_callback(self, msg):
        self.turn_status = msg.data

    def scan_callback(self, msg):
        latest_distance = msg.ranges[0]

        # Add the latest distance to the buffer
        self.distance_buffer.append(latest_distance)

        # Limit Buffer Size
        if len(self.distance_buffer) > self.buffer_size:
            self.distance_buffer.pop(0)

    def timer_callback(self):
        if len(self.distance_buffer) == 0:
            return

        avg_distance = sum(self.distance_buffer) / len(self.distance_buffer)

        # Calculate velocity if we have a previous distance
        if self.prev_distance is not None:
            # Time difference is constant and equal to self.timer_period
            avg_distance_diff = avg_distance - self.prev_distance
            
            # Apply noise threshold
            if abs(avg_distance_diff) < self.noise_threshold or self.turn_status == 1:
                velocity = 0.0  # No significant movement or turning
            else:
                # Calculate velocity using the average distance
                velocity = avg_distance_diff / self.timer_period

            self.get_logger().info(f'Latest avg distance: {avg_distance:.2f} m, '
                                   f'Velocity: {velocity:.2f} m/s')
            self.publish_odom(velocity)
        
        # Update previous distance
        self.prev_distance = avg_distance

        if self.turn_status == 1:
            self.prev_distance = None

    def publish_odom(self, velocity):
        # Create an Odometry message to publish velocity
        odom_msg = Odometry()
        odom_msg.header.stamp = self.get_clock().now().to_msg()
        odom_msg.header.frame_id = 'odom'
        odom_msg.child_frame_id = 'base_link'
        odom_msg.twist.twist.linear.x = velocity
        
        # Publish the Odometry message
        self.odom_publisher.publish(odom_msg)

def main(args=None):
    rclpy.init(args=args)
    node = LaserScanVelocitySubscriber()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

