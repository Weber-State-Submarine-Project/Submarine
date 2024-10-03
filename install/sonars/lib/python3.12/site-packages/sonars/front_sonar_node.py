import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan, PointCloud2, PointField
from std_msgs.msg import Header
import numpy as np
import struct
import sys
import site
site.addsitedir('/home/submarine/.local/share/pipx/venvs/bluerobotics-ping/lib/python3.12/site-packages')

from brping import Ping1D

class PingSonarNode(Node):
    def __init__(self):
        super().__init__('ping_sonar_node')
        self.scan_publisher = self.create_publisher(LaserScan, '/scan/front', 10)
        self.pointcloud_publisher = self.create_publisher(PointCloud2, '/scan/front/points', 10)
        
        self.ping = Ping1D()
        self.ping.connect_serial('/dev/ttyUSB0', 115200)
        
        if self.ping.initialize() is False:
            self.get_logger().error("Failed to initialize Ping2!")
            exit(1)
        
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

