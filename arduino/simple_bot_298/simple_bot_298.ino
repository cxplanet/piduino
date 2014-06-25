 /**
The pin breakdown is as follows:

Function          Channel A	Channel B
Direction	  Digital 12	Digital 13
Speed (PWM)	  Digital 3	Digital 11
Brake	          Digital 9	Digital 8
Current Sensing	  Analog 0	Analog 1

**/

int pingOut = 8; 
int pingIn = 7;
long safeDistance = 8.0;

void setup() {
Serial.begin(9600);
  //initializing the pin states
  pinMode(pingOut, OUTPUT);
  
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT);  //Initiates Brake Channel A pin
  
  //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Motor Channel A pin
  pinMode(11, OUTPUT); //Initiates Brake Channel A pin
  
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
   // turnLeft(500);
  }  
}

void moveForward(int motorSpeed)
{
  delay(250);
  digitalWrite(12, HIGH); //Establishes forward direction of Channel A
  digitalWrite(13, HIGH); //Establishes forward direction of Channel B
    
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
    
  analogWrite(3, motorSpeed);   //Spins the motor on Channel A at full speed
  analogWrite(11, motorSpeed);   //Spins the motor on Channel A at full speed
  
}

void fullStop(double delayMs)
{
    digitalWrite(9, HIGH);  // Brake for Channel A
    digitalWrite(8, HIGH);  // Brake for Channel B
    analogWrite(3, 0);   //Spins the motor on Channel A at full speed
  analogWrite(11, 0);
    delay(delayMs);              // 1/4 sec delay for good measure
}

void backup(int motorSpeed, double timeMs)
{
  fullStop(250);
  
  digitalWrite(12, LOW); //Backwards direction of Channel A
  digitalWrite(13, LOW);  //Backwards direction of Channel B
    
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
    
  analogWrite(3, motorSpeed);   //Spins the motor on Channel A at full speed
  analogWrite(11, motorSpeed);   //Spins the motor on Channel A at full speed
  
  delay(timeMs);
  
  fullStop(250);
   turnLeft(1500);
}

void turnLeft(double timeMs)
{
  Serial.print("turn left");
   //backward turn @ half speed
  digitalWrite(12, HIGH); //Backward direction of Channel A
  digitalWrite(9, LOW);  //Disengage the Brake for Channel A
  analogWrite(3, 123);   //Spins the motor on Channel A at half speed 
  delay(500);
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



