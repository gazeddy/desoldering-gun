#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
U8G2_ST7920_128X64_1_SW_SPI u8g2(U8G2_R0, /* clock=*/ 8, /* data=*/ 10, /* CS=*/ 9, /* reset=*/ 13);
const int Temp = A0;  // Analog input pin that the potentiometer is attached to
int sensorValue = 0;        // value read from the pot

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
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
                
  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (switchVal == HIGH ) { 
    digitalWrite(4, LOW);
  } else {
    digitalWrite(4, HIGH);
  }
  if (sensorValue >=135) {
    digitalWrite(3, LOW);
    digitalWrite(13, LOW);
  } else {
    digitalWrite(3, HIGH);
    digitalWrite(13, HIGH);
  }
}