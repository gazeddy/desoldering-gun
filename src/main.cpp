#include <Arduino.h>
//#include <Wire.h>
//#include <LiquidCrystal_I2C.h>

const int Temp = A0;  // Analog input pin that the potentiometer is attached to
int sensorValue = 0;        // value read from the pot

void setup() {
 Serial.begin(9600);
 pinMode (1, INPUT);
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(13, OUTPUT);

}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(Temp);
  //read the pushbutton value into a variable
  int switchVal = digitalRead(1);
  //print out the value of the pushbutton
 Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t switch = ");
  Serial.println(switchVal);
                
  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (switchVal == HIGH && sensorValue <= 110 ) { 
    digitalWrite(3, LOW);
  } else {
    digitalWrite(3, HIGH);
  }
  if (sensorValue >=135) {
    digitalWrite(2, LOW);
    digitalWrite(13, LOW);
  } else {
    digitalWrite(2, HIGH);
    digitalWrite(13, HIGH);
  }
}

