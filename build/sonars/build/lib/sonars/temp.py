#!/usr/bin/env python

#simplePingExample.py
from brping import Ping1D
import time
import argparse
import struct
import numpy as np

from builtins import input

##Parse Command line options
############################

parser = argparse.ArgumentParser(description="Ping python library example.")
parser.add_argument('--device', action="store", required=False, type=str, help="Ping device port. E.g: /dev/ttyUSB0")
parser.add_argument('--baudrate', action="store", type=int, default=115200, help="Ping device baudrate. E.g: 115200")
parser.add_argument('--udp', action="store", required=False, type=str, help="Ping UDP server. E.g: 192.168.2.2:9090")
args = parser.parse_args()
if args.device is None and args.udp is None:
    parser.print_help()
    exit(1)

# Make a new Ping
myPing = Ping1D()
if args.device is not None:
    myPing.connect_serial(args.device, args.baudrate)
elif args.udp is not None:
    (host, port) = args.udp.split(':')
    myPing.connect_udp(host, int(port))

if myPing.initialize() is False:
    print("Failed to initialize Ping!")
    exit(1)

print("------------------------------------")
print("Starting Ping..")
print("Press CTRL+C to exit")
print("------------------------------------")

input("Press Enter to continue...")

# Read and print distance measurements with confidence
while True:
    #data = myPing.get_distance()
    data = myPing.get_profile()
    if data:
        print("Distance: %s\tConfidence: %s%%\tProfile: %s" % (data["distance"], data["confidence"], data["profile_data"]))
        profile_data = data["profile_data"]
        # Convert profile data to intensity values
        intensity_values = struct.unpack(f'{len(profile_data)}B', profile_data)

        # Example to find peaks (you can adjust the threshold)
        threshold = 0
        peaks = intensity_values[0]

        # Convert peaks to distances (example conversion, adjust based on your settings)
        speed_of_sound = 1500  # m/s in water
        sampling_interval = 0.001  # seconds
        distances = peaks * speed_of_sound * sampling_interval / 2

        print("Detected distances:", distances)

    else:
        print("Failed to get distance data")
    time.sleep(0.1)
