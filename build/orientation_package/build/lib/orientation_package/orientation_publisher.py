#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from orientation_msg.msg import Orientation
import board
import busio
from adafruit_bno08x.i2c import BNO08X_I2C
import adafruit_bno08x
import time

class OrientationPublisher(Node):
    def __init__(self):
        super().__init__('orientation_publisher')

        # Initialize I2C bus and BNO08x sensor
        self.i2c = busio.I2C(board.SCL, board.SDA)
        self.bno = BNO08X_I2C(self.i2c)

        # Enable features
        self.bno.enable_feature(adafruit_bno08x.BNO_REPORT_ACCELEROMETER)
        self.bno.enable_feature(adafruit_bno08x.BNO_REPORT_GYROSCOPE)
        self.bno.enable_feature(adafruit_bno08x.BNO_REPORT_MAGNETOMETER)
        self.bno.enable_feature(adafruit_bno08x.BNO_REPORT_LINEAR_ACCELERATION)
        self.bno.enable_feature(adafruit_bno08x.BNO_REPORT_ROTATION_VECTOR)
        #self.bno.enable_feature(adafruit_bno08x.BNO_REPORT_RAW_ACCELEROMETER)
        #self.bno.enable_feature(adafruit_bno08x.BNO_REPORT_RAW_GYROSCOPE)
        #self.bno.enable_feature(adafruit_bno08x.BNO_REPORT_RAW_MAGNETOMETER)

        self.publisher_ = self.create_publisher(Orientation, 'orientation_topic', 1)
        self.timer = self.create_timer(.1, self.timer_callback)

    def timer_callback(self):
        try:
            # Read sensor data
            accel_x, accel_y, accel_z = self.bno.acceleration
            gyro_x, gyro_y, gyro_z = self.bno.gyro
            mag_x, mag_y, mag_z = self.bno.magnetic
            linear_accel_x, linear_accel_y, linear_accel_z = self.bno.linear_acceleration
            quat_x, quat_y, quat_z, quat_w = self.bno.quaternion
            #raw_accel_x, raw_accel_y, raw_accel_z = self.bno.raw_acceleration
            #raw_gyro_x, raw_gyro_y, raw_gyro_z = self.bno.raw_gyro
            #raw_mag_x, raw_mag_y, raw_mag_z = self.bno.raw_magnetic

            # Create and populate the ROS 2 message
            msg = Orientation()
            msg.acc_x = accel_x
            msg.acc_y = accel_y
            msg.acc_z = accel_z
            msg.gyro_x = gyro_x
            msg.gyro_y = gyro_y
            msg.gyro_z = gyro_z
            msg.mag_x = mag_x
            msg.mag_y = mag_y
            msg.mag_z = mag_z
            msg.lin_acc_x = linear_accel_x
            msg.lin_acc_y = linear_accel_y
            msg.lin_acc_z = linear_accel_z
            msg.quat_x = quat_x
            msg.quat_y = quat_y
            msg.quat_z = quat_z
            msg.quat_w = quat_w
            #msg.raw_acc_x = str(raw_accel_x)
            #msg.raw_acc_y = str(raw_accel_y)
            #msg.raw_acc_z = str(raw_accel_z)
            #msg.raw_gyro_x = str(raw_gyro_x)
            #msg.raw_gyro_y = str(raw_gyro_y)
            #msg.raw_gyro_z = str(raw_gyro_z)
            #msg.raw_mag_x = str(raw_mag_x)
            #msg.raw_mag_y = str(raw_mag_y)
            #msg.raw_mag_z = str(raw_mag_z)

            # Publish the message
            self.publisher_.publish(msg)
            #self.get_logger().info(f'Publishing: {msg}')

        except RuntimeError as e:
            pass
            self.get_logger().error(f"Runtime error: {e}")
        except Exception as e:
            pass
            self.get_logger().error(f"Error: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = OrientationPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

