#include <Arduino.h>
//#include <Wire.h>
//#include <LiquidCrystal_I2C.h>

const int Temp = A0;  // Analog input pin that the potentiometer is attached to
int sensorValue = 0;        // value read from the pot

void setup() {
 Serial.begin(9600);
 pinMode(D1, INPUT_PULLUP);
 pinMode(D3, OUTPUT);
 pinMode(D4, OUTPUT);
<<<<<<< HEAD
 pinMode(D13, OUTPUT);
=======
 pinMode(D13, OUTPUT);
>>>>>>> 8ea8565180f742cc98daed2f29f6e47c5f7aa225

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
