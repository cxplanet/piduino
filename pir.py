import RPi.GPIO as GPIO
import time

# uses a PIR to detect motion. There's a good example of how this works at
# https://learn.adafruit.com/pir-passive-infrared-proximity-motion-sensor/how-pirs-work
# Note that on this one, the PIR we are using has a 3.3V digital out, so we're 
# golden, with respect to protecting the Pi's pins

GPIO.setmode(GPIO.BCM)
PIR_PIN = 7
GPIO.setup(PIR_PIN, GPIO.IN)
def MOTION(PIR_PIN):
	print “Motion Detected!”

print “PIR Module Test (CTRL+C to exit)”
time.sleep(2)
try:
	GPIO.add_event_detect(PIR_PIN, GPIO.RISING, callback=MOTION)
	while 1:
		time.sleep(100)
except KeyboardInterrupt:
	print “ Quit”
GPIO.cleanup()

