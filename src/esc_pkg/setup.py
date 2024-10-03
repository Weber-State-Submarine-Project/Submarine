from setuptools import setup, find_packages

package_name = 'esc_pkg'

setup(
    name=package_name,
    version='0.0.1',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Ryan Le',
    maintainer_email='ryanhaile10@gmail.com',
    description='Package to control 2 ESCs through a PWM hat, listening to the esc_topic topic',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'esc_subscriber = esc_pkg.esc_subscriber:main',  # Points to the main function in esc_subscriber.py
            'esc_publisher = esc_pkg.esc_publisher:main',    # Points to the main function in esc_publisher.py
        ],
    },
)

