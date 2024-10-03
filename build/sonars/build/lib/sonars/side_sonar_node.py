import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan, PointCloud2
from std_msgs.msg import Header
import serial
import time
import struct
from sensor_msgs_py import point_cloud2 as pc2
#import sensor_msgs.point_cloud2 as pc2

class SonarPublisher(Node):
    def __init__(self):
        super().__init__('sonar_publisher')
        self.laser_publisher = self.create_publisher(LaserScan, '/scan/left', 10)
        self.point_cloud_publisher = self.create_publisher(PointCloud2, '/scan/left/points', 10)
        self.timer = self.create_timer(0.1, self.timer_callback)
        self.ser = serial.Serial('/dev/ttyUSB1', 115200, timeout=1)
        self.COM = 0x55
        self.buffer_RTT = [0, 0, 0, 0]
        self.Distance = 0

    def timer_callback(self):
        self.ser.write(bytes([self.COM]))
        time.sleep(0.1)
        if self.ser.in_waiting > 0:
            time.sleep(0.004)
            if self.ser.read() == b'\xff':
                self.buffer_RTT[0] = 0xff
                for i in range(1, 4):
                    self.buffer_RTT[i] = ord(self.ser.read())
                CS = (self.buffer_RTT[0] + self.buffer_RTT[1] + self.buffer_RTT[2]) % 256
                if self.buffer_RTT[3] == CS:
                    self.Distance = (self.buffer_RTT[1] << 8) + self.buffer_RTT[2]
                    distance_in_meters = self.Distance / 1000.0

                    # Publish LaserScan message
                    laser_msg = LaserScan()
                    laser_msg.header.stamp = self.get_clock().now().to_msg()
                    laser_msg.header.frame_id = 'left_sonar'
                    laser_msg.angle_min = -0.0872665  # -5 degrees in radians
                    laser_msg.angle_max = 0.0872665   # 5 degrees in radians
                    laser_msg.angle_increment = 0.174533  # 10 degrees in radians
                    laser_msg.time_increment = 0.0
                    laser_msg.scan_time = 0.1
                    laser_msg.range_min = 0.02  # 2 cm
                    laser_msg.range_max = 6.0   # 600 cm
                    laser_msg.ranges = [distance_in_meters,distance_in_meters]
                    self.laser_publisher.publish(laser_msg)

                    # Publish PointCloud2 message
                    header = Header()
                    header.stamp = self.get_clock().now().to_msg()
                    header.frame_id = 'left_sonar'
                    points = [(distance_in_meters, 0.0, 0.0)]
                    point_cloud_msg = pc2.create_cloud_xyz32(header, points)
                    self.point_cloud_publisher.publish(point_cloud_msg)

                    #self.get_logger().info(f'Distance: {distance_in_meters:.3f}m')

def main(args=None):
    rclpy.init(args=args)
    sonar_publisher = SonarPublisher()
    rclpy.spin(sonar_publisher)
    sonar_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

