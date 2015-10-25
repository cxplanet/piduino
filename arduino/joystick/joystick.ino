#include <Stepper.h>

// the threshold values for the vertical stick
// values are from 0 - 677
const unsigned int UP = 364;
const unsigned int DOWN = 304;
const unsigned int NEUTRAL = 334;

unsigned int currVert = NEUTRAL;
unsigned int lastState = NEUTRAL;
int currSpeed = 0;

// initialize the stepper library on pins 8 through 11:
const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup()
{
    Serial.begin(9600);
    digitalWrite(4, HIGH); pinMode(4, INPUT);
    digitalWrite(5, HIGH); pinMode(5, INPUT);
} 

void loop() {
  // put your main code here, to run repeatedly:
  currVert = (unsigned int)analogRead(4);//5 is horizontal
  currSpeed = map (currVert, 0, 677, -240, 240);
  Serial.println(currSpeed);
  if (currSpeed > 10) {
    myStepper.setSpeed(currSpeed);
    myStepper.step(5);
  } else if (currSpeed < -10) {
    myStepper.setSpeed(abs(currSpeed));
    myStepper.step(-5);
    
  }

}
