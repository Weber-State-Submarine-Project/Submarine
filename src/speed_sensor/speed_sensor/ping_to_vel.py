import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from nav_msgs.msg import Odometry
from std_msgs.msg import Float32

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
            Float32,  
            '/turning',
            self.turning_callback,
            10)
        
        self.prev_distance = None
        self.prev_time = self.get_clock().now()
        
        # Publisher for Odometry message
        self.odom_publisher = self.create_publisher(Odometry, 'odom', 10)

        self.noise_threshold = 0.1       # Noise threshold to filter small changes (meters)
        self.max_jump_threshold = 5.0    # Jumpy threshold to filter out large charges (meters)

        # Moving average buffer and size
        self.distance_buffer = []
        self.buffer_size = 5  # Number of readings for averaging

        self.turn_status = 0

    def turning_callback(self, msg):
        self.turn_status = msg.data

    def scan_callback(self, msg):
        
        latest_distance = msg.ranges[0]
        current_time = self.get_clock().now()
        
        # Calculate time difference (in seconds)
        time_diff = (current_time - self.prev_time).nanoseconds * 1e-9
        

        # Outlier detection: Check if the latest distance is an outlier based on the max_jump_threshold
        if self.prev_distance is not None and abs(latest_distance - self.prev_distance) > self.max_jump_threshold:
            self.get_logger().warn(f'Outlier detected! Ignoring distance reading of {latest_distance} meters')
            return  # Skip the current iteration

        # Add the latest distance to the buffer
        self.distance_buffer.append(latest_distance)

        # Limit Buffer Size
        if len(self.distance_buffer) > self.buffer_size:
            self.distance_buffer.pop(0)

        # Calculate the average distance from the buffer
        avg_distance = sum(self.distance_buffer) / len(self.distance_buffer)
        
        # Calculate velocity if we have a previous distance and time difference
        if self.prev_distance is not None and time_diff > 0:
            # Calculate the difference
            avg_distance_diff = avg_distance - self.prev_distance
            
            # Apply noise threshold
            if abs(avg_distance_diff) < self.noise_threshold or self.turn_status == 1:
                velocity = 0.0  # No significant movement or turning
            else:
                # Calculate velocity using the average distance
                velocity = avg_distance_diff / time_diff

            self.get_logger().info(f'Latest avg distance: {avg_distance:.2f} m, Velocity: {velocity:.2f} m/s')
            self.publish_odom(velocity)
        
        # Update previous values
        self.prev_distance = avg_distance
        self.prev_time = current_time

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

