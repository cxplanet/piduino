int led = 12;
int led2 = 13;


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT); 
pinMode(led2, OUTPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(30);  
digitalWrite(led2, HIGH);  // wait for a seconddigitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10);               // wait for a second
  digitalWrite(led2, LOW);    // turn the LED off by making the voltage LOW
  delay(30);
}
