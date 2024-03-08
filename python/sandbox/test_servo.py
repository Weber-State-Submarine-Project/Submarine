''' This is code to attempt to get a servo working with the rasberry pi '''

from gpiozero import Servo as s
from time import sleep
import threading

def MinToMaxExample(servo):
    ''' Function moves a single servo from min to max position '''

    try:
        while(True):
            servo.min()
            sleep(.5)
            servo.mid()
            sleep(.5)
            servo.max()
            sleep(.5)
    except KeyboardInterrupt:
        print('Program Stopped Via Keyboard')

def twoServoExample(servo_one, servo_two):
    ''' Function moves both servos given from minToMax at the same time ''' 
    
    thread1 = threading.Thread(target=MinToMaxExample, args=(servo_one,))
    thread2 = threading.Thread(target=MinToMaxExample, args=(servo_two,))
    
    thread1.start()
    sleep(.5)
    thread2.start()

def moveServo(servo, position):
    ''' Moves a servo given a position '''
    ''' Position: -1 (min) to 1 (max)'''
    ''' Please note that -1 to 1 is based on the library gpiozero'''
    servo.value = position

def moveServoExample(servo):
    val = -1

    try:
        while True:
            servo.value = val
            sleep(0.1)
            val = val + 0.1
            if val > 1:
                val = -1
    except KeyboardInterrupt:
            print("Program stopped")


def main():
    
    servo_one = s(25) # 25 indicates pin GPIO 25
    servo_two = s(12) # 12 indicates pin GPIO 12 (PWM0)
    
    ''' Testing Functions '''
    #MinToMaxExample(servo_two)
    #twoServoExample(servo_one,servo_two)
    #moveServo(servo_two, -1)
    #sleep(5)
    #moveServo(servo_two, 1)
    #sleep(5)
    #moveServo(servo_two, -1)
    moveServoExample(servo_one)


if __name__ == "__main__":
    main()
