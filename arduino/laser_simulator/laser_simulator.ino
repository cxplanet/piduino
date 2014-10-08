#include <SoftwareSerial.h>

int RX_PIN = 2;
int TX_PIN = 3;
int LED_PIN = 13;

byte mockAltVal1[] = {0x30, 0x30, 0x30, 0x30, 0x30, 0x31, 0x2e, 0x30, 0x0d, 0x0a};

SoftwareSerial serialDevice = SoftwareSerial(RX_PIN, TX_PIN);
byte ledState = 0;

void setup() {
  // put your setup code here, to run once:
    pinMode(RX_PIN, INPUT);
    pinMode(TX_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);
    serialDevice.begin(9600);
    Serial.begin(9600);
}
    
void loop() {
  // put your main code here, to run repeatedly:
  //serialDevice.println("  001.00 m");
  Serial.write(mockAltVal1, sizeof(mockAltVal1));
  
}

