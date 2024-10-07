from setuptools import find_packages, setup

package_name = 'joy_controller_to_esc'

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
    description='ROS2 package node that subscribes to joy node, and depending on the left joy stick will publish proper speeds to the left and right esc of the boat',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'joy_controller = joy_controller_to_esc.joy_controller:main', 
        ],
    },
)
