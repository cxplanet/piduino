//pin which triggers ultrasonic sound
int pingPin = 13; 

//pin which delivers time to receive echo using pulseIn()
int inPin = 12;

//range in cm which is considered safe to enter, anything 
//coming within less than 5 cm triggers red LED
int safeZone = 5;

//LED pin numbers
int greenLed = 3, redLed = 2;

void setup() {
  // initialize serial communication
  Serial.begin(9600);
}

void loop()
{
  //raw duration in milliseconds, cm is the 
  //converted amount into a distance
  long duration, cm, inches;

  //initializing the pin states
  pinMode(pingPin, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);  
  
  //sending the signal, starting with LOW for a clean signal
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  //setting up the input pin, and receiving the duration in 
  //microseconds for the sound to bounce off the object infront
  pinMode(inPin, INPUT);
  duration = pulseIn(inPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToInches(duration);
  
  //printing the current readings to the serial display
  Serial.print(cm * .393);
  Serial.print(" inches");
  Serial.println();
  
  //checking if anything is within the safezone, if not, keep 
  //green LED on if safezone violated, activate red LED instead
  if (cm > safeZone)
  {
    digitalWrite(12, HIGH); //Establishes forward direction of Channel A
    digitalWrite(9, LOW);   //Disengage the Brake for Channel A
    analogWrite(3, 15);   //Spins the motor on Channel A at full speed
    delay(200);
  }
  
  delay(100);
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
