import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan, PointCloud2, PointField
from std_msgs.msg import Header
import numpy as np
import struct
import sys
import site
import time
from nav_msgs.msg import Odometry
site.addsitedir('/home/submarine/.local/share/pipx/venvs/bluerobotics-ping/lib/python3.12/site-packages')

from brping import Ping1D

class PingSonarNode(Node):
    def __init__(self):
        super().__init__('ping_sonar_node')
        self.scan_publisher = self.create_publisher(LaserScan, '/scan/front', 10)
        self.pointcloud_publisher = self.create_publisher(PointCloud2, '/scan/front/points', 10)
        self.odom_publisher = self.create_publisher(Odometry, 'odom', 10)
        
        self.distance_holder = []
        self.prev_time = self.get_clock().now()

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
        gain_setting = 6  # Index for the gain value (0 corresponds to 0.6)
        # function only returns if false
        if not self.ping.set_gain_setting(gain_setting):
            self.get_logger().error("Failed to set gain setting.")
        else:
            self.get_logger().info(f"Gain setting set to {gain_setting} successfully!")

        # Set the range 0.5-30m
        range_start = 0  # Minimum range in millimeters
        range_end = 100000  # Maximum range in millimeters
        # function only returns if false
        if not self.ping.set_range(range_start, range_end):
            self.get_logger().error("Failed to set range.")
        else:
            self.get_logger().info(f"Range set to {range_start} - {range_end} millimeters successfully!")

        self.get_logger().info(f"Gain Val: {self.ping.get_gain_setting()}")
        self.get_logger().info(f"Range Val: {self.ping.get_range()}")
        
        self.timer = self.create_timer(0.01, self.timer_callback)
    
    def timer_callback(self):
        data = self.ping.get_distance()
        if data:
            distance = data['distance'] / 1000.0  # Convert mm to meters
            self.publish_scan(distance)
            self.publish_pointcloud(distance)
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

