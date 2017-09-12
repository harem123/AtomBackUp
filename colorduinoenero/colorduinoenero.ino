#include <Colorduino.h>



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
}

void loop() {
  // put your main code here, to run repeatedly:
 /* Colorduino.SetPixel(0,2,255,255,0);
  
  Colorduino.FlipPage();*/
  for (int b=0; b<255; b+=50){
  Colorduino.SetPixel(0,2,(0),(0),b);
  Colorduino.SetPixel(0,3,(0),(0),b);
  Colorduino.SetPixel(1,2,(0),(0),b);
  Colorduino.SetPixel(1,3,(0),(0),b);
  
  Colorduino.SetPixel(2,6,(255),(0),0);
  Colorduino.SetPixel(2,7,(255),(0),0);
  Colorduino.SetPixel(3,6,(255),(0),0);
  Colorduino.SetPixel(3,7,(255),(0),0);

  Colorduino.SetPixel(0,6,(0),(255),0);
  Colorduino.SetPixel(0,7,(0),(255),0);
  Colorduino.SetPixel(1,6,(0),(255),0);
  Colorduino.SetPixel(1,7,(0),(255),0);

  Colorduino.FlipPage();
  delay(200);
  }
  int b=0;
 
  
 
  //*************************
  
/*for (int b=0; b<255;b+=254){
  Colorduino.SetPixel(0,0,255,255,b);
  delay(100);
  Colorduino.FlipPage();
  }
  int b=0;
  //******************************
  for (int b=0; b<255;b+=254){
  Colorduino.SetPixel(0,0,255,255,b);
  delay(100);
  Colorduino.FlipPage();
  }
  int b=0;
/*for (int y=0; y<8;y++){  
  
  
  Colorduino.SetPixel(y,6,0,255,100);
  
  
}
for (int y=0; y<8;y++){  
  
  
  Colorduino.SetPixel(y,0,255,0,100);
  
}
*/


}
