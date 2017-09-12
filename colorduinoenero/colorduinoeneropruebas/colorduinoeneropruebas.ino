#include <Colorduino.h>

      
int ledState = LOW;             // ledState used to set the LED
unsigned long previousMillis = 0; 
//unsigned long previousMillisB = 0;
//unsigned long previousMillisRG = 0;// will store last time LED was updated
long OnTime = 1000;// milliseconds of on-time
long OnB=10000;
long OnRG=30000;
//long OffTime = 1000;  // milliseconds of off-time

int g=0;
int t=255;
int t2=255;
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
  unsigned long currentMillisB = millis();
  unsigned long currentMillisRG = millis();
   // Colorduino.FlipPage();}// Update the actual LED
    if( (currentMillisB  >= OnB))
  {t2=0;
     
  }
  
  if( (currentMillisRG  >= OnRG))
  {    
    t=0;
       
  }
  if( (currentMillis - previousMillis >= OnTime))
  {
    
    if(ledState == LOW && currentMillis < OnB)
    {ledState = HIGH;
    g= 255;
    }
    else{
      ledState = LOW;
      g= 0;
    }
    //g=255;
    previousMillis = currentMillis;  // Remember the time
    
    
  }
  Colorduino.SetPixel(0,2,(0),(g),t2);
    Colorduino.SetPixel(0,3,(0),(g),t2);
    Colorduino.SetPixel(1,2,(0),(g),t2);
    Colorduino.SetPixel(1,3,(0),(g),t2);
    
    Colorduino.SetPixel(2,6,(t),(0),0);
    Colorduino.SetPixel(2,7,(t),(0),0);
    Colorduino.SetPixel(3,6,(t),(0),0);
    Colorduino.SetPixel(3,7,(t),(0),0);

    Colorduino.SetPixel(0,6,(0),(t),0);
    Colorduino.SetPixel(0,7,(0),(t),0);
    Colorduino.SetPixel(1,6,(0),(t),0);
    Colorduino.SetPixel(1,7,(0),(t),0);
     
    Colorduino.FlipPage();// Update the actual LED
}
