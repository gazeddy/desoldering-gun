#include <Arduino.h>
const int Temp = A0;  // Analog input pin that the temp sensor is connected too
int sensorValue = 0;        // value read from the temp sensor

void setup() {
 Serial.begin(9600);
 pinMode (1, INPUT);
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(13, OUTPUT);

}

void loop() {
  // read the temp value:
  sensorValue = analogRead(Temp);
  //read the switch value into a variable
  int switchVal = digitalRead(1);
  //print out the value of the switch and temp sensor
 Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t switch = ");
  Serial.println(switchVal);
                
  // Keep in mind the pull-up means the switches logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on inbuilt led when the
  // temp sensor is above setpoint and off when it's not:
  if (switchVal == HIGH) { 
    digitalWrite(3, LOW);
    Serial.print("Pump Off ");
  } else {
    digitalWrite(3, HIGH);
    Serial.print("Pump On ");
  }
  if (sensorValue >=135) {
    digitalWrite(2, LOW);
    digitalWrite(13, LOW);
    Serial.print("Heater Off ");
  } else {
    digitalWrite(2, HIGH);
    digitalWrite(13, HIGH);
    Serial.print("Heater On ");
  }
}