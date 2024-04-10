#!/usr/bin/python3

# sample script to read range values from Maxbotix ultrasonic rangefinder

from time import sleep
import maxSonarTTY as ms

serialPort = "/dev/ttyAMA0"
maxRange = 5000  # change for 5m vs 10m sensor
sleepTime = 5
minMM = 9999
maxMM = 0

while True:
    try:
        mm = ms.measure(serialPort)
        if mm >= maxRange:
            print("no target")
            sleep(sleepTime)
            continue
        if mm < minMM:
            minMM = mm
        if mm > maxMM:
            maxMM = mm

        print("distance:", mm, "  min:", minMM, "max:", maxMM)
        sleep(sleepTime)
    except:
        print("exception occured")
