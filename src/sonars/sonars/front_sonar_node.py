import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan, PointCloud2, PointField
from std_msgs.msg import Header
import numpy as np
import struct
import sys
import site
import time
from std_msgs.msg import Float32
from nav_msgs.msg import Odometry
site.addsitedir('/home/submarine/.local/share/pipx/venvs/bluerobotics-ping/lib/python3.12/site-packages')

from brping import Ping1D

class PingSonarNode(Node):
    def __init__(self):
        super().__init__('ping_sonar_node')
        self.scan_publisher = self.create_publisher(LaserScan, '/scan/front', 10)
        self.pointcloud_publisher = self.create_publisher(PointCloud2, '/scan/front/points', 10)
        self.odom_publisher = self.create_publisher(Odometry, 'odom', 10)
        self.turning_subscriber = self.create_subscription(
            Float32,
            '/turning',
            self.turning_callback,
            10)

        self.distance_buffer = [] # List of 5 valid Distance Data values
        self.BUFFER_SIZE = 5
        self.MAX_DISTANCE_JUMP = 1  # Meter
        self.prev_distance = 0
        self.turn_state = 0
        self.stuck_count = 0

        self.ping = Ping1D()
        while True:
            self.get_logger().info("Attempting to connect to Ping2...")
            self.ping.connect_serial('/dev/ttyUSB0', 115200)
            if self.ping.initialize():
                self.get_logger().info("Successfully initialized Ping2.")
                break
            else:
                self.get_logger().error("Failed to initialize Ping2! Retrying...")

            time.sleep(5)  # Wait for 5 seconds before retrying

        # Ping needs to be in manual to set the gain and range
        self.ping.set_mode_auto(1)

        # Set the gain setting
        #gain_setting = 6  # Index for the gain value (0 corresponds to 0.6)
        # function only returns if false
        #if not self.ping.set_gain_setting(gain_setting):
        #    self.get_logger().error("Failed to set gain setting.")
        #else:
        #    self.get_logger().info(f"Gain setting set to {gain_setting} successfully!")

        # Set the range 0.5-30m
        #range_start = 0  # Minimum range in millimeters
        #range_end = 100000  # Maximum range in millimeters
        # function only returns if false
        #if not self.ping.set_range(range_start, range_end):
        #    self.get_logger().error("Failed to set range.")
        #else:
        #    self.get_logger().info(f"Range set to {range_start} - {range_end} millimeters successfully!")

        #self.get_logger().info(f"Gain Val: {self.ping.get_gain_setting()}")
        #self.get_logger().info(f"Range Val: {self.ping.get_range()}")
        
        self.timer = self.create_timer(0.01, self.timer_callback)
    
    def turning_callback(self,msg):
        self.turn_state = msg.data
        

    def timer_callback(self):
        data = self.ping.get_distance()
        if data:
            distance = data['distance'] / 1000.0  # Convert mm to meters
            prev_distance_lower = self.prev_distance - self.MAX_DISTANCE_JUMP
            prev_distance_upper = self.prev_distance + self.MAX_DISTANCE_JUMP
           
            # Reset Values when turning
            if self.turn_state == 1:
                self.distance_buffer = []
                return

            # Logic to determine if valid data
            if prev_distance_lower < distance < prev_distance_upper or self.prev_distance == 0:
                self.distance_buffer.append(distance)
            else:
                self.get_logger().warn(f"Distance out of range --- Distance_read: {distance}  Previous_Distance: {self.prev_distance} Max_Jump: {self.MAX_DISTANCE_JUMP}")
                self.stuck_count += 1

            # Corner Case: If sonar reads bad data for over 3 seconds, it will reset itself based on new distance
            if self.stuck_count >= 300:
                self.distance_buffer = []
                self.stuck_count = 0
                self.prev_distance = distance

            # Limits Buffer Size
            if len(self.distance_buffer) > self.BUFFER_SIZE:
                self.distance_buffer.pop(0)

            # Logic to avg distance
            if len(self.distance_buffer) == self.BUFFER_SIZE:
                avg_distance = sum(self.distance_buffer) / self.BUFFER_SIZE
                self.prev_distance = avg_distance
                self.publish_scan(avg_distance)
                self.publish_pointcloud(avg_distance)
                self.get_logger().info(f'Raw_distance: {distance} Avg_Distance {avg_distance}')
        else:
            self.get_logger().warn("Failed to get distance data from Ping2!")

    def publish_scan(self, distance):
        scan_msg = LaserScan()
        scan_msg.header.stamp = self.get_clock().now().to_msg()
        scan_msg.header.frame_id = 'front_sonar'
        scan_msg.angle_min = 0.0
        scan_msg.angle_max = 0.0
        scan_msg.angle_increment = 0.0
        scan_msg.time_increment = 0.0
        scan_msg.scan_time = 0.1
        scan_msg.range_min = 0.5  # Updated based on Ping2 specs
        scan_msg.range_max = 100.0  # Updated based on Ping2 specs
        scan_msg.ranges = [distance]
        scan_msg.intensities = []
        
        self.scan_publisher.publish(scan_msg)
    
    def publish_pointcloud(self, distance):
        header = Header()
        header.stamp = self.get_clock().now().to_msg()
        header.frame_id = 'front_sonar'
        
        points = np.array([[distance, 0.0, 0.0]], dtype=np.float32)
        
        pointcloud_msg = PointCloud2()
        pointcloud_msg.header = header
        pointcloud_msg.height = 1
        pointcloud_msg.width = points.shape[0]
        pointcloud_msg.fields = [
            PointField(name='x', offset=0, datatype=PointField.FLOAT32, count=1),
            PointField(name='y', offset=4, datatype=PointField.FLOAT32, count=1),
            PointField(name='z', offset=8, datatype=PointField.FLOAT32, count=1),
        ]
        pointcloud_msg.is_bigendian = False
        pointcloud_msg.point_step = 12
        pointcloud_msg.row_step = pointcloud_msg.point_step * points.shape[0]
        pointcloud_msg.is_dense = True
        pointcloud_msg.data = np.asarray(points, np.float32).tobytes()
        
        self.pointcloud_publisher.publish(pointcloud_msg)

def main(args=None):
    rclpy.init(args=args)
    node = PingSonarNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

