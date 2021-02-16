// Board Definition
// to allow easy changing of board map pins here
const int Temp = A0;  // Temp sensor pin
const int switchPin = 1;  // Triggerswitch input use external pullup to vcc
const int Heatergate = 2; // Gate for heater mosfet
const int pumpgatePin = 3; // Gate for Pump Mosfet
const int inbuiltled = 13; // Optional led output heater status without lcd
// ST9720 SPI interface
const int lcdclock = 8; //SCK - E
const int lcdchipselect = 9; //CS - RS
const int lcddata = 10; //MOSI - 
const int lcdreset = 13; // not used or connected 
// Rotary Encoder pins
const int enca = 4; 
const int encb = 5;
const int encswitch = 6; // pullup required switching to ground

// Neopixel status LED 
const int led = 7;