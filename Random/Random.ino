


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

int i,j;
int r= 0;

int foov,foov2;

int foob,foob2,foo;
  
int food,food2,foo1d;

void setup() 
{
Serial.begin(9600);
randomSeed(analogRead(0));
}
 
void loop()
{
  unsigned long currentSec = millis(); // actualizo el tiempo
  
  
if(r<1){// enciendo la luz azul y blanca solo una vez gracias a c q se actualiza cada 1000 ms
      
  
  foob = random(0,3);
  foob2 = random(0,7);
  foo = altas[foob][foob2];
  Serial.println("foo");
   Serial.println(foo);

  lineToGrid(foo);
  matriz[i][j] = 4;
  Serial.println("blue");
   Serial.println(i);
   Serial.println("j");
   Serial.println(j);
  //i=0; j=0;
   food = random(0,3);
   food2 = random(0,7);
   foo1d = altas[food][food2];
  lineToGrid(foo1d);
  matriz[i][j] = 5;
Serial.println("dorado");
   Serial.println(foo1d);
   Serial.println(i);
   Serial.println("j");
   Serial.println(j);
   lineToGrid(foo);
   matriz[i][j] = 0;

   Serial.println((matriz[i][j]));
   lineToGrid(foo);
   Serial.println(i);
   lineToGrid(foo1d); 
   Serial.println("food1");
   Serial.println(i);

  
  r++;
  }
   
}
// lanzo pared 1,4
// 
// ++++++++++++++inicio funciones ++++++++++++






void lineToGrid(int l){

  if(l<64){
  i= l/8;} // trunk en esta division
    else i=7;
  if (i>0){
  j= l- (i*8);}  // el residuo de la division entre 8  
    else j= l-1;
}



  

//   1 2   3  4  5  6  7  8 
//   9 19 11 12 13 14 15 16

//  17 18 19 20 21 21 23 24 
//  25 26 27 28 29 30 31 32

//  33 34 35 36 37 38 39 40
//  41 42 43 44 45 46 47 48

//  49 50 51 52 53 54 55 56
//  57 58 59 60 61 62 63 64  



//   0 1  2  3  4  5  6  7   
//   8 9 10 11 12 13 14 15 

//  16 17 18 19 20 21 21 23  
//  24 25 26 27 28 29 30 31 

//  32 33 34 35 36 37 38 39 
//  40 41 42 43 44 45 46 47  

//  48 49 50 51 52 53 54 55 
//  56 57 58 59 60 61 62 63  

