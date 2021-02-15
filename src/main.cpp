#include <Arduino.h>
const int Temp = A0;  // Analog input pin that the potentiometer is attached to
int sensorValue = 0;        // value read from the pot

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(13, OUTPUT);

}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(Temp);
  //read the pushbutton value into a variable
  int switchVal = digitalRead(2);
  //print out the value of the pushbutton
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