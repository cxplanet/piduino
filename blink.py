import RPi.GPIO as GPIO
import time

def blink(pin):
        GPIO.output(pin,GPIO.HIGH)
        time.sleep(1)
        GPIO.output(pin,GPIO.LOW)
        time.sleep(1)
        return

# you can make reference to GPIO pins either using GPIO.BOARD (pin #)
# or GPIO.BCM (logical mapping for the GPIO I/O pins as 'Broadcom SOC channel' )
# We'll use physical pins for now
GPIO.setmode(GPIO.BOARD)
# pin 11 is going to be output, ie 
GPIO.setup(11, GPIO.OUT)
# blink 10 times
for i in range(0,5):
	blink(11)
GPIO.cleanup()