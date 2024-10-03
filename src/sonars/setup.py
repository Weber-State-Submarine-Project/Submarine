from setuptools import find_packages, setup

package_name = 'sonars'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools', 'brping'],
    zip_safe=True,
    maintainer='submarine',
    maintainer_email='benjamin.l.stone2@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'down_sonar_node = sonars.down_sonar_node:main',
            'side_sonar_node = sonars.side_sonar_node:main',
            'front_sonar_node = sonars.front_sonar_node:main',
        ],
    },
)
