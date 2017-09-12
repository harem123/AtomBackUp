#include <Colorduino.h>
// idea atencion aqui usar un vector para que solo pueda tomar valores deseados de celda y todo quede en una misma 
// ademas poner pasito a pasito suave suaveciito el recorrido random que solo pueda aumentar mas 1 en la culebra
// falta poner los random de las celdas mirar que tmbn hay el arduino de sensores 
// se debe guardar las ultimas celdas habilitadas un vector blanco azul verde rojo asi [23 56 61 62 63] 
// si ya esta deshabilitada seria [0 23 34 35 36]
// si paso el tiempo [0 0 0 0 0]
      
int matriz[8][8] = {      // con esta matriz se representa las 64 celdas tiene numero de 1 a 5 
    {0, 0, 0, 0, 0, 0, 0, 0}, // para colores rojo verde azul y blanco distingue los numeros 1 2 3 4 
    {0, 0, 0, 0, 0, 0, 0, 0}, // estos numeros le dan el color 
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},};

   
 int altas[4][8] = {
  {1, 2,   3,  4,  5,  6,  7,  8}, 

  {17, 18, 19, 20, 21, 21, 23, 24}, 

  {33, 34, 35, 36, 37, 38, 39, 40},

  {49, 50, 51, 52, 53, 54, 55, 56},};

    
  int bajas[4][8]={
  {9, 19, 11, 12, 13, 14, 15, 16},

  {25, 26, 27, 28, 29, 30, 31, 32},

  {41, 42, 43, 44, 45, 46, 47, 48}, 

  {57, 58, 59, 60, 61, 62, 63, 64},}; 

  int direcciones[1][5] = { // falta funcion para poner en cero todo lo demas cada vez que hace update
    {0, 0, 0, 0, 0}, };



// ++++++ se declaran variables para temporizador y la semilla del random     
int c=0;
int c2=0;// solo controla positions el primer random
int bx,by;
int p=random(0,7);

unsigned long previousSec = 0;




//+++++++++++ hacen el cambio line To Grid
int i,j;
int r= 0;
int vy=0;
int vx , vbw , vbw2 , xbw ,ybw ;

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
Serial.begin(9600);
//******************************************
  // set the digital pin as output:
 
       
}
 
void loop()
{
  unsigned long currentSec = millis(); // actualizo el tiempo
  
  
  

  if (currentSec < 6000)// es el que apaga la celda dorada
        {
            
         positionsBlanco();  
           
          
        }
  else {
    matrizDelBlanco(0);
    //matrizPaint();
    //matriz[3][3]=0;
    //Serial.print("in function\n");
  }

  if(currentSec < 10000 ){  // es el temporizador total c se actualiza cada 1 seg si pasa de 10 se apaga todo
  

    if (currentSec - previousSec > 1000){ // es el delay q permite hacer todo cada segundo
      positions(c);
      c++;
      i++;
      
      matrizPaint();
      
      matrizDelRG(0);
      
      
      previousSec = currentSec -1 ;
    }
  }
  else{ // solo entra aqui cuando han pasado 10 seg segun lo que indica c 

        matrizDelete(0);  // esta borra todo incluyendo celdas azules y blancas
        matrizPaint();// pinta otra vez la matriz q ahora esta apagada por completo
        
      }


}

// ++++++++++++++inicio funciones ++++++++++++

void matrizPaint(){ // recorre la matriz y mira si el numero es 1 2 3 o 4 y pinta segun cada caso
  
  int r,g,b,val;
    for(int f=0;f<=7;f++){ // recorre las filas de la matriz 
      for (int c=0;c<=7;c++){
      val= matriz[f][c];      // guarda el valor de cada celda
         switch(val){
         case 0: r=0; g=0; b= 0; Colorduino.SetPixel(f,c,r,g,b); break;   // segun el valor de la casilla lo pinta de un color
         case 1: r=255; g=0; b=0; Colorduino.SetPixel(f,c,r,g,b); break;
        
         case 2: r=0; g=255; b=0; Colorduino.SetPixel(f,c,r,g,b); break;
         case 3: r=0; g=0; b=255; Colorduino.SetPixel(f,c,r,g,b); break;
         case 4: r=0; g=0; b=255; Colorduino.SetPixel(f,c,r,g,b); break;
         case 5: r=255; g=255; b=255; Colorduino.SetPixel(f,c,r,g,b); break;
         case 6: r=0; g=220; b=0; Colorduino.SetPixel(f,c,r,g,b); break;
         default: break;
       }
      }
   }
  Colorduino.FlipPage();// Update the actual LED
}


void matrizDelRG(int color){ // borra la cola de las celdas verdes y rojas no borra las azules por q tienen otros numeros
  
int r,g,b,val;
  for(int f=0;f<=7;f++){ // recorre las filas de la matriz 
    for (int c=0;c<=7;c++){
    if( matriz[f][c]!=4 && matriz[f][c]!=5 && matriz[f][c]!=6){ 
    matriz[f][c]=color;  // en la columna (desplazamiento-c) es la casilla indicada para multiplexar con desplazamiento se rota el mensaje 
     
     }
    }
 }
}

void matrizDelBlanco(int color){ // borra la cola de las celdas verdes y rojas no borra las azules por q tienen otros numeros
  
int r,g,b,val;
  for(int f=0;f<=7;f++){ // recorre las filas de la matriz 
    for (int c=0;c<=7;c++){
    if(matriz[f][c] ==5){ 
       matriz[f][c]=color;  // en la columna (desplazamiento-c) es la casilla indicada para multiplexar con desplazamiento se rota el mensaje 
     
     }
    }
 }
}
void matrizDelete(int color){// borra todo llenando la matriz de ceros tambien borra azul y blanco
  
int r,g,b,val;
  for(int f=0;f<=7;f++){ // recorre las filas de la matriz 
    for (int c=0;c<=7;c++){
    
    matriz[f][c]=color;  // llena todo de ceros
     
     
    }
 }
 
}

void positions(int c){
if(c<1){
vx= random(0, 7);
vy= random(0, 7);
bx= random(0, 7);
by= random(0, 7);
}
matriz[bx][vy+1]=3; // enciende la celda azul

matriz[vx][vy]=2; // enciencen las celdas rojas y verdes
matriz[vx+1][vy]=1;
matriz[vx-1][vy]=1;

if(vx == 7)
  {
    
    vx--;
  }
else 
  {
   vx = vx + random(-1,1) ;
   Serial.print(millis());
   Serial.print("\n");
   Serial.print(vx);
   Serial.print("\n");
  }
}

void positionsBlanco(){
if(c2<1)
  {
  vbw2= random(0, 7);
  vbw= random(0, 7);
  c2++;
  }

matriz[vbw][vbw2]=5; // al relacionarlo con vy que es la coordnada de la celda verde 
                            // tiene un comportamiento erratico

}

  

//   1 2   3  4  5  6  7  8 
//   9 19 11 12 13 14 15 16
//  17 18 19 20 21 21 23 24 
//  25 26 27 28 29 30 31 32
//  33 34 35 36 37 38 39 40
//  41 42 43 44 45 46 47 48 
//  49 50 51 52 53 54 55 56
//  57 58 59 60 61 62 63 64 

  