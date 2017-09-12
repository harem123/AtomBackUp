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
  
}

  

//   1 2   3  4  5  6  7  8 
//   9 19 11 12 13 14 15 16
//  17 18 19 20 21 21 23 24 
//  25 26 27 28 29 30 31 32
//  33 34 35 36 37 38 39 40
//  41 42 43 44 45 46 47 48 
//  49 50 51 52 53 54 55 56
//  57 58 59 60 61 62 63 64 
