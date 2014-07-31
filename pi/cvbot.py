#Commands:
#	w-Move forward
#	a-Move left
#	d-Move right
#	s-Move back
#	x-Stop
#	t-Increase speed
#	g-Decrease Speed

import time
from BrickPi import *   #import BrickPi.py file to use BrickPi operations

speed=200		#initial speed
motor1=PORT_B	# motor1 is on PORT_B
motor2=PORT_C	# motor2 is on PORT_C	

def fwd():
	BrickPi.MotorSpeed[motor1] = speed  
	BrickPi.MotorSpeed[motor2] = speed  
def left():
	BrickPi.MotorSpeed[motor1] = speed  
	BrickPi.MotorSpeed[motor2] = -speed
def right():
	BrickPi.MotorSpeed[motor1] = -speed  
	BrickPi.MotorSpeed[motor2] = speed
def back():
	BrickPi.MotorSpeed[motor1] = -speed  
	BrickPi.MotorSpeed[motor2] = -speed
def stop():
	BrickPi.MotorSpeed[motor1] = 0  
	BrickPi.MotorSpeed[motor2] = 0

def main():
	BrickPiSetup()  # setup the serial port for communication

	BrickPi.MotorEnable[motor1] = 1 #Enable the Motor1
	BrickPi.MotorEnable[motor2] = 1 #Enable the Motor2 

	BrickPiSetupSensors()   #Send the properties of sensors to BrickPi

	BrickPi.Timeout=10	#Set timeout value for the time till which to run the motors after the last command is pressed
	BrickPiSetTimeout()		#Set the timeout
	
	fwd()
	BrickPiUpdateValues()
	time.sleep(5)

if __name__ == "__main__":
    main()
