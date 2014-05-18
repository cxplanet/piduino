/*
A resistor (100K) and photoresistor are connected in series. +5V 
goes to resistor, ground goes to photoresistor, the junction where 
the resistor and photoresistor meets goes to analog 0. Digital 13 
is used for the LED.
*/


int photoResistor = 0;  //define a pin for Photo resistor
int threshold = 250;

void setup(){
    Serial.begin(9600);  //Begin serial communcation
    pinMode(13, OUTPUT);

}

void loop(){
    Serial.println(analogRead(photoResistor)); 

   /*
    if(analogRead(photoResistor) > threshold ){    
        digitalWrite(13, HIGH);
        Serial.println("high"); 
    }else{
        digitalWrite(13, LOW);
        Serial.println("low"); 
    }
    */
    delay(500);
}
