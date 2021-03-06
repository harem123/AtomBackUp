#include <Colorduino.h>
// idea atencion aqui usar un vector para que solo pueda tomar valores deseados de celda y todo quede en una misma 
// ademas poner pasito a pasito suave suaveciito el recorrido random que solo pueda aumentar mas 1 en la culebra
// falta poner los random de las celdas mirar que tmbn hay el arduino de sensores 
// se debe guardar las ultimas celdas habilitadas un vector blanco azul verde rojo asi [23 56 61 62 63] 
// si ya esta deshabilitada seria [0 23 34 35 36]
// si paso el tiempo [0 0 0 0 0]


// SUMMARY el script debe recibir unica orden de encendido, luego generar y grabar celdas
// luego recibir un valor de celda sensada y decidir q valor tiene
// ademas si el temporizador de luces llega a 10s asi llegue el valor ya no es valido
// finalmente envia el punataje al cerebro de todo 
      
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
int c=0;// solo controla positions el primer random
int p=random(0,7);

unsigned long previousSec = 0;
int previousC;
int onTime;
int onB;
int onWhite;
int onGreen;
int b = 4;

int foov;
int foov2;

int foob;
int foob2;
int foo;
  
int food;
int food2;
int foo1d;
//+++++++++++ hacen el cambio line To Grid
int i,j;
int r= 0;

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
  
  
  if(r<1){// enciendo la luz azul y blanca solo una vez gracias a c q se actualiza cada 1000 ms
      
  
  foob = random(0,8);
  foob2 = random(0,8);
  foo = altas[foob][foob2];
  lineToGrid(foo);
  matriz[i][j] = 5;
  //i=0; j=0;
   food = random(0,4);
   food2 = random(0,8);
   foo1d = altas[food][food2];
  lineToGrid(foo1d);
  matriz[i][j] = 4;
  
  r++;
  }

  if (currentSec > 3000)// es el que apaga la celda dorada
        {
            
            lineToGrid(foo);
            matriz[i][j] = 0;
           

        }


  if(currentSec < 10000 ){  // es el temporizador total c se actualiza cada 1 seg si pasa de 10 se apaga todo
  

    if (currentSec - previousSec > 1000){ // es el delay q permite hacer todo cada segundo
      positions(c);
      c++;
      i++;
      matrizPaint();
      
      
      matrizDelRG(0);
      
      
      previousSec = currentSec;
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
         case 5: r=255; g=255; b=0; Colorduino.SetPixel(f,c,r,g,b); break;
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


void matrizDelete(int color){// borra todo llenando la matriz de ceros tambien borra azul y blanco
  
int r,g,b,val;
  for(int f=0;f<=7;f++){ // recorre las filas de la matriz 
    for (int c=0;c<=7;c++){
    
    matriz[f][c]=color;  // llena todo de ceros
     
     
    }
 }
 
}

void lineToGrid(int l){

  if(l<64){
  i= l/8;} // trunk en esta division
    else i=7;
  if (i>0){
  j= l- (i*8);}  // el residuo de la division entre 8  
    else j= l-1;
}

void positions(int c){ // esta da las posciones de la culebrita solo usa verdes y rojas parte de un numero p random
  
  if(c < 1 ){
    p=1;
    foov = random(0,4);
    foov2 = random(0,8);
    
  }

  // verde ++
  if (p ==1 ){
  
  int foov3 = altas[foov][foov2];
  lineToGrid(foov3);
  matriz[i][j] = 2;
  matriz[i+1][j]=1;
  matriz[i-1][j]=1;
  direcciones[1][3] = altas[i][j];
  
  }

  else{
  int foov3 = bajas[foov][foov2];
  lineToGrid(foov3);
  matriz[i][j] = 2;
  matriz[i+1][j]=1;
  matriz[i-1][j]=1;
  direcciones[1][3] = bajas[i][j];
  
  }
}

  

//   1 2   3  4  5  6  7  8 
//   9 19 11 12 13 14 15 16
//  17 18 19 20 21 21 23 24 
//  25 26 27 28 29 30 31 32
//  33 34 35 36 37 38 39 40
//  41 42 43 44 45 46 47 48 
//  49 50 51 52 53 54 55 56
//  57 58 59 60 61 62 63 64 

  