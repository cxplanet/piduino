#Commands:
#	w-Move forward
#	a-Move left
#	d-Move right
#	s-Move back
#	x-Stop
#	t-Increase speed
#	g-Decrease Speed

import cwiid   
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
	#setup wii
	button_delay = 0.1
 
	print 'Press 1 + 2 on your Wii Remote now ...'
	time.sleep(1)
 
	# Connect to the Wii Remote. If it times out
	# then quit.
	try:
		wii=cwiid.Wiimote()
	except RuntimeError:
		print "Error opening wiimote connection"
		quit()
 
	print 'Wii Remote connected...\n'
	print 'Press some buttons!\n'
	print 'Press PLUS and MINUS together to disconnect and quit.\n'

	global speed
	BrickPiSetup()  # setup the serial port for communication

	BrickPi.MotorEnable[motor1] = 1 #Enable the Motor1
	BrickPi.MotorEnable[motor2] = 1 #Enable the Motor2 

	BrickPiSetupSensors()   #Send the properties of sensors to BrickPi

	BrickPi.Timeout=10000	#Set timeout value for the time till which to run the motors after the last command is pressed
	BrickPiSetTimeout()		#Set the timeout

	wii.rpt_mode = cwiid.RPT_BTN
	while True:
		buttons = wii.state['buttons']
		if (buttons - cwiid.BTN_PLUS - cwiid.BTN_MINUS == 0):
			wii.rumble = 1
			time.sleep(1)
			wii.rumble = 0
			exit(wii)
		elif(buttons & cwiid.BTN_LEFT):
			left()
		elif(buttons & cwiid.BTN_RIGHT):
			right()
		elif(buttons & cwiid.BTN_UP):
			fwd()
		elif(buttons & cwiid.BTN_DOWN):
			back()
		else:
			stop()
		BrickPiUpdateValues() 	#Update the motor values
		time.sleep(button_delay)         # sleep for 10 ms
if __name__ == "__main__":
    main()
