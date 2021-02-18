#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <board.h>

U8G2_ST7920_128X64_1_SW_SPI u8g2(U8G2_R0, lcdclock, lcddata,lcdchipselect, lcdreset);
int sensorValue = 0;        // value read from the pot
int setpoint = 0;           //Temperature setpoint
void setup() {
  //start serial connection
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
  pinMode(Heatergate, OUTPUT);
  pinMode(pumpgatePin, OUTPUT);
  pinMode(inbuiltled, OUTPUT);
  u8g2.begin();
}

void loop() {
  // read the temp value:
  sensorValue = analogRead(Temp);
  //read the switch value into a variable
  int switchVal = digitalRead(1);
  //print out the value of the switch and temp sensor
 Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print(" switch = ");
  Serial.print(switchVal);
  Serial.print("\t setpoint = ");
  Serial.println(setpoint);
  
                
  // Keep in mind the pull-up means the switches logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on inbuilt led when the
  // temp sensor is above setpoint and off when it's not:
  if (switchVal == HIGH) { 
    digitalWrite(pumpgatePin, LOW);
    Serial.print("Pump Off ");
  } else {
    digitalWrite(pumpgatePin, HIGH);
    Serial.print("Pump On ");
  }
  if (sensorValue >=135) {
    digitalWrite(Heatergate, LOW);
    digitalWrite(inbuiltled, LOW);
    Serial.print("Heater Off ");
  } else {
    digitalWrite(Heatergate, HIGH);
    digitalWrite(inbuiltled, HIGH);
    Serial.print("Heater On ");
    }
}