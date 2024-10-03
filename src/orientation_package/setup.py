from setuptools import find_packages, setup

package_name = 'orientation_package'

setup(
    name=package_name,
    version='0.0.1',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Ryan Le',
    maintainer_email='ryanhaile10@gmail.com',
    description='Package used to publish the data from Adafruit 9-DOF Orientation IMU Fusion Breakout - BNO085 to a topic',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'orientation_publisher = orientation_package.orientation_publisher:main',
            'imu = orientation_package.imu:main'
            ],
    },
)
