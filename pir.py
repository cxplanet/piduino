import RPi.GPIO as GPIO
import time

# uses a PIR to detect motion. There's a good example of how this works at
# https://learn.adafruit.com/pir-passive-infrared-proximity-motion-sensor/how-pirs-work
# Note that on this one, the PIR we are using has a 3.3V digital out, so we're 
# golden, with respect to protecting the Pi's pins

sensorPin = 7
# this time, let's using the logical mapping of pins
GPIO.setmode(GPIO.BCM)
# it is useful to default an input pin to a known state if no input is present. 
# This can be done by adding a pullup resistor (sets the pin high), or a pulldown resistor (sets the pin to low)
GPIO.setup(sensorPin, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

prevState = False
currState = False

while True:
    time.sleep(0.1)
    prevState = currState
    currState = GPIO.input(sensorPin)
    if currState != prevState:
        newState = "Motion detected!" if currState else "All is quiet"
        print "GPIO pin %s is %s" % (sensorPin, newState)
