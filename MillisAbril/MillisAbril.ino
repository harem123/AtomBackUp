#include <Colorduino.h>

int ledPin =  13;      // the number of the LED pin
int ledState = LOW;             // ledState used to set the LED
unsigned long previousMillis = 0;        // will store last time LED was updated
long OnTime = 1000;// milliseconds of on-time
long OnTimeTot2=10000;
long OnTimeTot=5000;
long OffTime = 1000;          // milliseconds of off-time
 
void setup() 
{
  Colorduino.Init();
// compensate for relative intensity differences in R/G/B brightness
// array of 6-bit base values for RGB (0~63)
// whiteBalVal[0]=red
// whiteBalVal[1]=green
// whiteBalVal[2]=blue
unsigned char whiteBalVal[3] = {36,63,63}; // for LEDSEE 6x6cm round matrix
Colorduino.SetWhiteBal(whiteBalVal);
//******************************************
  // set the digital pin as output:
        
}
 
void loop()
{
  
  
  // check to see if it's time to change the state of the LED
  unsigned long currentMillis = millis();
  
    
     
    
   // Colorduino.FlipPage();}// Update the actual LED
  if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
  {
    ledState = LOW;  // Turn it off
    previousMillis = currentMillis;  // Remember the time
    if(currentMillis < OnTimeTot2){
    Colorduino.SetPixel(0,2,(0),(0),255);
    Colorduino.SetPixel(0,3,(0),(0),255);
    Colorduino.SetPixel(1,2,(0),(0),255);
    Colorduino.SetPixel(1,3,(0),(0),255);
    }
    else{
    Colorduino.SetPixel(0,2,(0),(0),0);// se debe cambiar los valores de 255 a 0 y no reescribir todo asi mismo
    Colorduino.SetPixel(0,3,(0),(0),0);// cambiar el color cada cierto tiempo y no reescribir 
    Colorduino.SetPixel(1,2,(0),(0),0);
    Colorduino.SetPixel(1,3,(0),(0),0);
    }
    

    Colorduino.SetPixel(2,6,(130),(0),0);
    Colorduino.SetPixel(2,7,(255),(0),0);
    Colorduino.SetPixel(3,6,(255),(0),0);
    Colorduino.SetPixel(3,7,(255),(0),0);

    Colorduino.SetPixel(0,6,(0),(255),0);
    Colorduino.SetPixel(0,7,(0),(255),0);
    Colorduino.SetPixel(1,6,(0),(255),0);
    Colorduino.SetPixel(1,7,(0),(255),0);
     
   Colorduino.FlipPage();// Update the actual LED
  }
  else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime ))
  {
    ledState = HIGH;  // turn it on
    previousMillis = currentMillis;   // Remember the time 
    int a=0,b=255,c=255;
    if(currentMillis < OnTimeTot2){
    Colorduino.SetPixel(0,2,(a),(b),c);
    Colorduino.SetPixel(0,3,(a),(b),c);
    Colorduino.SetPixel(1,2,(a),(b),c);
    Colorduino.SetPixel(1,3,(a),(b),c);
    }
    else{
      Colorduino.SetPixel(0,2,(0),(0),0);
    Colorduino.SetPixel(0,3,(0),(0),0);
    Colorduino.SetPixel(1,2,(0),(0),0);
    Colorduino.SetPixel(1,3,(0),(0),0);
    }
   
    Colorduino.SetPixel(2,6,(255),(0),0);
    Colorduino.SetPixel(2,7,(255),(0),0);
    Colorduino.SetPixel(3,6,(255),(0),0);
    Colorduino.SetPixel(3,7,(255),(0),0);

    Colorduino.SetPixel(0,6,(0),(255),0);
    Colorduino.SetPixel(0,7,(0),(255),0);
    Colorduino.SetPixel(1,6,(0),(255),0);
    Colorduino.SetPixel(1,7,(0),(255),0);//*/
    Colorduino.FlipPage();
    //Colorduino.FlipPage();// Update the actual LED
  }
   //Colorduino.FlipPage();
   
}
