import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from std_msgs.msg import Float32
import scipy.signal as signal
from datetime import datetime
import os

class SonarFilterNode(Node):
    def __init__(self):
        super().__init__('sonar_filter_node')

        # Parameters
        self.declare_parameter('cutoff_frequency', 1.0)  # Cutoff frequency in Hz
        self.declare_parameter('sampling_rate', 100.0)  # Sampling rate of sonar data in Hz
        self.declare_parameter('save_directory', '~/ros_logs/sonar')  # Default directory to save files

        # Get parameters
        self.cutoff_frequency = self.get_parameter('cutoff_frequency').value
        self.sampling_rate = self.get_parameter('sampling_rate').value
        self.save_directory = os.path.expanduser(self.get_parameter('save_directory').value)

        # Ensure save directory exists
        if not os.path.exists(self.save_directory):
            os.makedirs(self.save_directory)

        # Design the low-pass filter
        nyquist_rate = 0.5 * self.sampling_rate
        normalized_cutoff = self.cutoff_frequency / nyquist_rate
        self.b, self.a = signal.butter(4, normalized_cutoff, btype='low', analog=False)

        # Initialize to None, to set on the first callback
        self.filtered_state = None
        self.first_measurement_received = False

        # Timestamped file names for raw and filtered data
        current_time = datetime.now().strftime("%Y%m%d_%H%M%S")
        self.raw_data_file = os.path.join(self.save_directory, f'raw_sonar_{current_time}.txt')
        self.filtered_data_file = os.path.join(self.save_directory, f'filtered_sonar_{current_time}.txt')

        # Subscribers and publishers
        self.subscription = self.create_subscription(
            LaserScan,
            'scan/front',
            self.sonar_callback,
            10)
        self.publisher = self.create_publisher(Float32, 'filtered_sonar_data', 10)

    def sonar_callback(self, msg):
        # Get the first range value
        if len(msg.ranges) > 0:
            distance_value = msg.ranges[0]

            # Save raw data to file
            with open(self.raw_data_file, 'a') as raw_file:
                raw_file.write(f'{distance_value}\n')

            # Initialize filter state with the first measurement if not set
            if not self.first_measurement_received:
                # Initialize filter state based on the first distance measurement
                self.filtered_state = signal.lfilter_zi(self.b, self.a) * distance_value
                self.first_measurement_received = True

            # Apply the low-pass filter using lfilter with state
            filtered_value, self.filtered_state = signal.lfilter(
                self.b, self.a, [distance_value], zi=self.filtered_state
            )

            # Save filtered data
            with open(self.filtered_data_file, 'a') as filtered_file:
                filtered_file.write(f'{filtered_value[0]}\n')

            # Publish the filtered data
            filtered_msg = Float32()
            filtered_msg.data = filtered_value[0]
            self.publisher.publish(filtered_msg)
            self.get_logger().info(f'Raw data: {distance_value:.2f}, Filtered data: {filtered_value[0]:.2f}')

def main(args=None):
    rclpy.init(args=args)
    sonar_filter_node = SonarFilterNode()
    rclpy.spin(sonar_filter_node)
    sonar_filter_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

