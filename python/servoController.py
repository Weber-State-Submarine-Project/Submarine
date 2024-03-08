from gpiozero import Servo as s
from time import sleep
import threading

class ServoController:
    def moveServo(servo, position):
        ''' Moves a servo given a position '''
        ''' Position: -1 (min) to 1 (max)'''
        ''' Please note that -1 to 1 is based on the library gpiozero'''
    
        servo.value = position

    def turnHardLeft():
        return

    def turnSoftLeft():
        return

    def turnHardRight():
        return

    def turnSoftRight():
        return

    def staightenUp():
        ''' return servos to neautral to swim straight '''
        servo.value = 0 # Assuming 0 is neutral
        return
