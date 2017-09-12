#include <Adafruit_NeoPixel.h>

// motor controlling
// pwm pins 2 to 13 and 44 to 46
int pwm = 6;




void setup() 
{
  // put your setup code here, to run once:
  
  pinMode(pwm, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 50 to 200");

}

void loop() 
{
  // put your main code here, to run repeatedly:
 if (Serial.available())
 {
  int serialValue = Serial.parseInt();
  if (serialValue >= 0 && serialValue <= 255)
  {
    analogWrite(pwm,serialValue);
    Serial.print("new pwm value: ");
    Serial.print(serialValue,DEC);
    Serial.print(" -- ");
  }
  if (serialValue == 699)
  {
    Serial.print("break");
    Serial.end();
    
  }
 }
 

}
