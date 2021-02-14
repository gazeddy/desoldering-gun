#include <Arduino.h>
//#include <Wire.h>
//#include <LiquidCrystal_I2C.h>

const int Temp = A0;  // Analog input pin that the potentiometer is attached to
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)


void setup() {
 Serial.begin(9600);
 pinMode(D1, INPUT_PULLUP);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(13, OUTPUT);

}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(Temp);
  //read the pushbutton value into a variable
  int switchVal = digitalRead(D1);
  //print out the value of the pushbutton
 Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t switch = ");
  Serial.println(switchVal);
                
  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (switchVal == HIGH && sensorValue <= 110 ) { 
    digitalWrite(D4, LOW);
  } else {
    digitalWrite(D4, HIGH);
  }
  if (sensorValue >=135) {
    digitalWrite(D3, LOW);
    digitalWrite(D13, LOW);
  } else {
    digitalWrite(D3, HIGH);
    digitalWrite(D13, HIGH);
  }
}