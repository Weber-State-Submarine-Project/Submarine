from setuptools import find_packages
from setuptools import setup

setup(
    name='orientation_msg',
    version='0.0.0',
    packages=find_packages(
        include=('orientation_msg', 'orientation_msg.*')),
)
