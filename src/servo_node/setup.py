from setuptools import find_packages, setup

package_name = 'servo_node'

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
    maintainer='cyphr',
    maintainer_email='ryanhaile10@gmail.com',
    description='Node to control GPIO ports of pi',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'talker = servo_node.publisher_member_function:main',
            'servo = servo_node.servo_control_node:main',
            'servo_client = servo_node.servo_client:main',
        ],
    },
)
