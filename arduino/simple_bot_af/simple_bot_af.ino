#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
int pingOut = 19; 
int pingIn = 18;
long safeDistance = 8.0;

void setup() {
Serial.begin(9600);
  //initializing the pin states
  pinMode(pingOut, OUTPUT);
  
  // turn on motor
  motor1.setSpeed(0);
  motor2.setSpeed(0);
 
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  
  
}

void loop(){
  
  long currDistance = checkSafeDistance();
  //printing the current readings to the serial display

  Serial.println(currDistance);
  
  if (currDistance > safeDistance)
  {
    moveForward(255);
  }
  else
  {
    backup(127, 1000);
    turnLeft(500);
  }  
}

void moveForward(int motorSpeed)
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor1.setSpeed(motorSpeed);  
  motor2.setSpeed(motorSpeed);
  delay(250);
  
}

void fullStop(double delayMs)
{
    motor1.setSpeed(0);  
    motor2.setSpeed(0); 
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    delay(delayMs);              // 1/4 sec delay for good measure
}

void backup(int motorSpeed, double timeMs)
{
  fullStop(250);
  
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor1.setSpeed(motorSpeed);  
  motor2.setSpeed(motorSpeed);  

  delay(timeMs);
}

void turnLeft(double timeMs)
{
  Serial.print("turn left");
   //backward turn @ half speed
  motor1.run(FORWARD);
  motor1.setSpeed(123);
  delay(timeMs);
}

void turnRight()
{
  
}

long checkSafeDistance()
{
  long duration;
  
    //sending the signal, starting with LOW for a clean signal
  digitalWrite(pingOut, LOW);
  delayMicroseconds(2);
  digitalWrite(pingOut, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingOut, LOW);

  //setting up the input pin, and receiving the duration in 
  //microseconds for the sound to bounce off the object infront
  pinMode(pingIn, INPUT);
  duration = pulseIn(pingIn, HIGH);

  // convert the time into a distance
  long inches = microsecondsToInches(duration);
  
  return inches;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

long microsecondsToInches(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled. We then convert,
  // 1cm = .393701 inches
  return (microseconds / 29 / 2) * .393701;
}



