import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan, PointCloud2, PointField
from std_msgs.msg import Header
import numpy as np
import struct
import sys
import site
import time
from std_msgs.msg import Int32
from nav_msgs.msg import Odometry
site.addsitedir('/home/submarine/.local/share/pipx/venvs/bluerobotics-ping/lib/python3.12/site-packages')

import board
import busio
import adafruit_lidarlite

from brping import Ping1D

class PingSonarNode(Node):
    def __init__(self):
        super().__init__('ping_sonar_node')
        self.scan_publisher = self.create_publisher(LaserScan, '/scan', 10)
        self.turning_subscriber = self.create_subscription(
            Int32,
            '/turning',
            self.turning_callback,
            10)

        self.distance_buffer = [] # List of 5 valid Distance Data values
        self.BUFFER_SIZE = 5
        self.MAX_DISTANCE_JUMP = 1          # Meters
        self.STUCK_COUNT_LIMIT = 10
        self.prev_distance = 0
        self.turn_state = 0
        self.stuck_count = 0

        # Create library object using our Bus I2C port
        i2c = busio.I2C(board.SCL, board.SDA)

        # Default configuration, with only i2c wires
        self.sensor = adafruit_lidarlite.LIDARLite(i2c)

        self.timer = self.create_timer(0.01, self.timer_callback)
    
    def turning_callback(self,msg):
        self.turn_state = msg.data
        

    def timer_callback(self):
        try:
            distance = self.sensor.distance
        except RuntimeError as e:
            return

        if distance:
            distance = distance / 100.0  # Convert cm to meters
            prev_distance_lower = self.prev_distance - self.MAX_DISTANCE_JUMP
            prev_distance_upper = self.prev_distance + self.MAX_DISTANCE_JUMP
           
            # Reset Values when turning
            if self.turn_state == 1:
                self.distance_buffer = []
                self.prev_distance = 0
                return

            # Logic to determine if valid data
            if prev_distance_lower < distance < prev_distance_upper or self.prev_distance == 0:
                self.distance_buffer.append(distance)
            else:
                #self.get_logger().warn(f"Distance out of range --- Distance_read: {distance}  Previous_Distance: {self.prev_distance} Max_Jump: {self.MAX_DISTANCE_JUMP}")
                self.stuck_count += 1

            # Corner Case: If sonar reads bad data for STUCK_COUNT_LIMIT, it will reset itself based on new distance
            if self.stuck_count >= self.STUCK_COUNT_LIMIT:
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
                #self.get_logger().info(f'Raw_distance: {distance} Avg_Distance {avg_distance}')
        #else:
            #self.get_logger().warn("Failed to get distance data from Ping2!")

    def publish_scan(self, distance):
        scan_msg = LaserScan()
        scan_msg.header.stamp = self.get_clock().now().to_msg()
        scan_msg.header.frame_id = 'front_sonar'
        scan_msg.angle_min = 0.0
        scan_msg.angle_max = 0.0
        scan_msg.angle_increment = 0.0
        scan_msg.time_increment = 0.0
        scan_msg.scan_time = 0.1
        scan_msg.range_min = 0.5  
        scan_msg.range_max = 100.0  
        scan_msg.ranges = [distance]
        scan_msg.intensities = []
        
        self.scan_publisher.publish(scan_msg)
    
def main(args=None):
    rclpy.init(args=args)
    node = PingSonarNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

