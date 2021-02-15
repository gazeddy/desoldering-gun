#include <Arduino.h>
const int Temp = A0;   
int sensorValue = 0;    
void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(13, OUTPUT);

}

void loop() {
  sensorValue = analogRead(Temp);
  int switchVal = digitalRead(2);
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t switch = ");
  Serial.println(switchVal);
                
 if (switchVal == HIGH) { 
    digitalWrite(4, LOW);
    Serial.print("Pump Off ");
  } else {
    digitalWrite(4, HIGH);
    Serial.print("Pump On ");
  }
  if (sensorValue >=135) {
    digitalWrite(3, LOW);
    digitalWrite(13, LOW);
    Serial.print("Heater Off ");
  } else {
    digitalWrite(3, HIGH);
    digitalWrite(13, HIGH);
    Serial.print("Heater On ");
  }