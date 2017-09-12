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
for (int x=0; x<8;x++){  
  
  
  Colorduino.SetPixel(7,x,255,255,0);
  
}
for (int y=0; y<8;y++){  
  
  
  Colorduino.SetPixel(y,6,0,255,100);
  
}
for (int y=0; y<8;y++){  
  
  
  Colorduino.SetPixel(y,0,255,0,100);
  
}
Colorduino.FlipPage();

}
