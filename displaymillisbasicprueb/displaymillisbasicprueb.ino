#include <Colorduino.h>

// variables de temporizadores      
int ledState = LOW;             // ledState used to set the LED
unsigned long previousMillis = 0; 
unsigned long previousMillisB = 0;
unsigned long previousMillisRG = 0;// will store last time LED was updated
unsigned long previousMillisRG1 =0;
unsigned long previousMillisRG2 =0;
unsigned long previousMillisRG3 =0;
unsigned long sum;
int OnTime = 1000;// milliseconds of on-time
int OnB=5000;
int OnRG=15000;
int XyTime = 3000;

//long OffTime = 1000;  // milliseconds of off-time
// variables de apagado y encendido de leds
int g=0;
int t=255;
int tv1,tv2,tv3;
int t2=255;
// variables de coordenadas de celdas 
 int xv=1; int yv=1; int xb=0; int yb=4;
 int xr,yr,xr2,yr2; 
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
  unsigned long currentMillisRG1= millis();
  unsigned long currentMillisRG2= millis();
   unsigned long currentMillisRG3= millis();
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
       if (serialValue >= 1 && serialValue <= 7777)
        {
           Serial.println("serial value read");
           previousMillis = currentMillis;  // Remember the time
           previousMillisB = currentMillisB;  // Remember the time
           previousMillisRG = currentMillisRG;  // Remember the time
           t2= 255;
           t=255;
           xv++; 
           yv++; 
           xb += 2; yb++;
        }
       if (serialValue == 9999)
       {Serial.print("serial conection finished");
        Serial.end();
       }
 
    } 
     

 
  
 /*if ((xv+1) % 2 == 0){
    xr= xv;  xr2= xv;  yr=yv+1; yr2= yv-1;
 }
 if (((xv+1) % 2) != 0){
    xr= xv+1;  xr2= xv;  yr=yv; yr2 = yv-1;
 }*/

   if (currentMillisRG1 - previousMillisRG1 >= XyTime)
       { 
        
       
        previousMillisRG1 = currentMillisRG1;  // Remember the time
      }
  


  
  Colorduino.SetPixel(xv,yv,(0), t,0);// celda verde
  Colorduino.SetPixel(xv,yv+1,(0), tv1,0);// celda verde
  Colorduino.SetPixel(xv,yv+2,(0), tv2,0);// celda verde  
  Colorduino.SetPixel(xv,yv+3,(0), tv3,0);// celda verde   
 /*Colorduino.SetPixel(xr,yr,(t), 0,3);// celda roja
 Colorduino.SetPixel(xr,yr+1,(tr), 0,0);// celda roja+1
 Colorduino.SetPixel(xr,yr+2,(tr2), 0,0);// celda roja+2
 
 Colorduino.SetPixel(xr2,yr2,(t), 0,0);// celda roja
 Colorduino.SetPixel(xr2,yr2+1,(tr), 0,0);// celda roja+1
 Colorduino.SetPixel(xr2,yr2+2,(tr2), 0,0);// celda roja+2*/
 
 Colorduino.SetPixel(xb,yb,(0), g,t2);//celda azul        
 Colorduino.FlipPage();// Update the actual LED
    /*sum = currentMillisRG - previousMillisRG;
    Serial.print(previousMillisRG,DEC);
    Serial.print("a ");
    Serial.print(sum,DEC);
    Serial.print("b ");*/
}

