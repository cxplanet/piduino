#include <SoftwareSerial.h>

int RX_PIN = 2;
int TX_PIN = 3;
int LED_PIN = 13;

byte mockAltVal1[10] = {48, 48, 48, 48, 48, 49, 46, 48, 13, 10};
int mockAltVal2[10] = {48, 48, 48, 48, 48, 49, 46, 48, 13, 10};
int mockAltVal3[10] = {48, 48, 48, 48, 48, 49, 46, 48, 13, 10};

SoftwareSerial serialDevice = SoftwareSerial(RX_PIN, TX_PIN);
byte ledState = 0;

void setup() {
  // put your setup code here, to run once:
    pinMode(RX_PIN, INPUT);
    pinMode(TX_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);
    serialDevice.begin(9600);
}
    
void loop() {
  // put your main code here, to run repeatedly:
  serialDevice.write(mockAltVal1, 10);
  delay(250);
  
  digitalWrite(LED_PIN)
}
