#include <Colorduino.h>


void setup() 
{
  
}
 
void loop()
{
  
  
   color();
   filas(1);
   columnas(7);
   Colorduino.FlipPage();
   
}
void todosEncendidos ()
{

 for (int i=0;i<8;i++)
 {
   for(int j=0;j<8;j++){
   Colorduino.SetPixel(i,j,(255),(255),255);
   }
 }
 Colorduino.FlipPage();
} 

void filas (int f)
{
   for(int j=0;j<8;j++)
   {
   Colorduino.SetPixel(f,j,(255),(255),255);
   }
 
 Colorduino.FlipPage();
} 

void columnas (int col)
{
   for(int j=0;j<8;j++)
   {
   Colorduino.SetPixel(j,col,(r),(g),b);
   }
 
 Colorduino.FlipPage();
} 

void colorFila (int i,int r,int g,int b)
{
      for(int j=0;j<8;j++)
      {
      Colorduino.SetPixel(i,j,(r),(g),b);
            r += 10
      }
      Colorduino.FlipPage();
}
void lineToGrid(int n) // de 1 a 64
{ 
  int i,j;
  i= n/8; // trunk en esta division
  j= (n%8) + (i*8); // el residuo de la division entre 8  
}
  
void gridToLine(int x int y){
  
}

