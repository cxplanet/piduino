
 #include <Servo.h>
 
 // pin assignments
 int photoResistor = 0;
 //set this to your darkness threshold
 int darkness = 50;
 // set this to your 'full light' threshold
 int light = 650;
 Servo servo;
 int val;
 
 void setup() {
   pinMode(photoResistor, INPUT);
   servo.attach(9);
   Serial.begin(9600);
 }
 
 // read from the analog input connected to the LDR
 // and print the value to the serial port.
 // the delay is only to avoid sending so much data
 // as to make it unreadable.
 void loop() {
   val = analogRead(photoResistor);
   Serial.println(val);
   // map scales the servo range to the light range
   val = map(val, darkness, light, 1, 179);
   Serial.print("Mapped val: ");
   Serial.println(val);
   servo.write(val);
   delay(1500);
 }
