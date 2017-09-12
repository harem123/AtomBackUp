// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
}

byte x = 8;

void loop() {
  
  Wire.beginTransmission(8); // transmit to device #8 if 0 begin 8 if 0 begin 9 random for numbers 0 to 31 2 of them 
  Wire.write("0422");        // sends five bytes se envia y espera a q vuelva otra orden de enviar ademas debe revisar si llego el mensaje
  Wire.write(x);              // sends one byte
  Wire.endTransmission();    // stop transmitting

  x++;
  delay(500);
}
