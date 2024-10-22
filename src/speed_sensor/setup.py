from setuptools import find_packages, setup

package_name = 'speed_sensor'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='submarine',
    maintainer_email='benjamin.l.stone2@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'velocity_sensor = speed_sensor.velocity_sensor:main',
            'ping_velocity = speed_sensor.ping_to_vel:main',
        ],
    },
)
