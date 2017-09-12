#include <Colorduino.h>

      
int ledState = LOW;             // ledState used to set the LED
unsigned long previousMillis = 0; 
unsigned long previousMillisB = 0;
unsigned long previousMillisRG = 0;// will store last time LED was updated
unsigned long sum;
int OnTime = 1000;// milliseconds of on-time
int OnB=10000;
int OnRG=20000;

//long OffTime = 1000;  // milliseconds of off-time

int g=0;
int t=255;
int t2=255;
void setup() 
{
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Serial Ready");
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
    if( (currentMillisB - previousMillisB  >= OnB))
      {t2 = 0;
       g = 0;
      }// apaga componente B celda azul
  
    if( (currentMillisRG - previousMillisRG  >= OnRG))
      {    
       t = 0;
      }// apaga celdas roja y verde
      
   
      
       if (currentMillis - previousMillis >= OnTime)
       {
          if(ledState == LOW )
            {ledState = HIGH;
             if(currentMillisB - previousMillisB <= OnB)
             {
               g= 255;
             }
           }
          else
          {
          ledState = LOW;
          g= 0;
          }
      
       previousMillis = currentMillis;  // Remember the time
    
      }
     
    if (Serial.available())
    {
       int serialValue = Serial.parseInt();
       if (serialValue >= 0 && serialValue <= 100)
        {
           Serial.println("serial value read");
           previousMillis = currentMillis;  // Remember the time
           previousMillisB = currentMillisB;  // Remember the time
           previousMillisRG = currentMillisRG;  // Remember the time
           t2= 255;
           t=255;
    
        }
       if (serialValue == 699)
       {Serial.end();
       }
 
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
    /*sum = currentMillisRG - previousMillisRG;
    Serial.print(previousMillisRG,DEC);
    Serial.print("a ");
    Serial.print(sum,DEC);
    Serial.print("b ");*/
}

