/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to
// set pin numbers:
//const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int State1 = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(2, INPUT);pinMode(3, INPUT);pinMode(4, INPUT);pinMode(5, INPUT);pinMode(6, INPUT);pinMode(7, INPUT);
  pinMode(8, INPUT);pinMode(9, INPUT);pinMode(10, INPUT);pinMode(11, INPUT);pinMode(12, INPUT);pinMode(13, INPUT);
  pinMode(14, INPUT);pinMode(15, INPUT);pinMode(16, INPUT);pinMode(17, INPUT);pinMode(18, INPUT);pinMode(19, INPUT);
  pinMode(20, INPUT);pinMode(2, INPUT);pinMode(21, INPUT);pinMode(22, INPUT);pinMode(23, INPUT);pinMode(24, INPUT);
  pinMode(25, INPUT);pinMode(26, INPUT);pinMode(27, INPUT);pinMode(28, INPUT);pinMode(29, INPUT);pinMode(30, INPUT);
  pinMode(31, INPUT);pinMode(32, INPUT);pinMode(33, INPUT);
}
 
 
  

void loop() {
  // read the state of the pushbutton value:
  State1 = digitalRead(2);State2 = digitalRead(2);State1 = digitalRead(2);State1 = digitalRead(2);State1 = digitalRead(2);
  State1 = digitalRead(2);State1 = digitalRead(2);State1 = digitalRead(2);State1 = digitalRead(2);State1 = digitalRead(2);
  State1 = digitalRead(2);State1 = digitalRead(2);State1 = digitalRead(2);State1 = digitalRead(2);State1 = digitalRead(2);
  State1 = digitalRead(2);State1 = digitalRead(2);State1 = digitalRead(2);State1 = digitalRead(2);State1 = digitalRead(2);
  State1 = digitalRead(2);State1 = digitalRead(2);State1 = digitalRead(2);State1 = digitalRead(2);State1 = digitalRead(2);
  State1 = digitalRead(2);State1 = digitalRead(2);State1 = digitalRead(2);State1 = digitalRead(2);State1 = digitalRead(2);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  
}
