/*
 * Lifted and modified from:
 *http://www.beefrankly.org/blog/2011/12/21/read-out-4-pin-cpu-fan-speed/
 *
 * Wire fans in parallel, using 12 v power supply
 */
int fanPulse = 8; // not needed unless you want to know speed
int fan1 = 3; // PWM for fan1
int fan2 = 5; // PWM for fan2



unsigned long pulseDuration;

void setup()
{
  Serial.begin(9600);
  pinMode(fanPulse, INPUT);
  digitalWrite(fanPulse,HIGH);
}

void readPulse() {
  pulseDuration = pulseIn(fanPulse, LOW);
  double frequency = 1000000/pulseDuration;
  
  Serial.print("pulse duration:");
  Serial.println(pulseDuration);
  
  Serial.print("time for full rev. (microsec.):");
  Serial.println(pulseDuration*2);
  Serial.print("freq. (Hz):");
  Serial.println(frequency/2);
  Serial.print("RPM:");
  Serial.println(frequency/2*60);

}

void loop()
{
  for (int velocity = 109; velocity < 255; velocity += 20)
  {
    Serial.println(velocity);
    analogWrite(fan1, velocity);
    analogWrite(fan2, velocity);
    delay(5000);
    readPulse();
  }
}
