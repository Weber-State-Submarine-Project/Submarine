from gpiozero import Servo as s
from time import sleep
import threading

SW_Version = 1.0

class ServoController:
    def moveServo(servo, position):
        ''' Moves a servo given a position '''
        ''' Position: -1 (min) to 1 (max)'''
        ''' Please note that -1 to 1 is based on the library gpiozero'''
    
        servo.value = position

    ''' The following functions will need to be modified once Hardware aquired '''
    def turnHardLeft(left_servo, right_servo):
        ''' Turns Submarine Hard Right '''
        
        left = 1 # CHANGE WHEN HARDWARE IS AQUIRED
        
        moveServo(left_servo, left)
        moveServo(right_servo, left)
        

    def turnSoftLeft(left_servo, right_servo):
        ''' Turns Submarine Soft Left'''
        
        left = .5 # CHANGE WHEN HARDWARE IS AQUIRED
        
        moveServo(left_servo, left)
        moveServo(right_servo, left)

    def turnHardRight(left_servo, right_servo):
        ''' Turns Submarine Hard Right '''

        right = -1 # CHANGE WHEN HARDWARE IS AQUIRED
        
        moveServo(left_servo, right)
        moveServo(right_servo, right)

    def turnSoftRight(left_servo, right_servo):
        ''' Turns Submarine Soft Right '''
        
        right = -.5 # CHANGE WHEN HARDWARE IS AQUIRED
        
        moveServo(left_servo, right)
        moveServo(right_servo, right)

    def staightenUp(left_servo, right_servo):
        ''' return servos to neautral to swim straight '''
        
        straight = 0 # Assuming 0 is neutral

        moveServo(left_servo, straight)
        moveServo(right_servo, straight)
