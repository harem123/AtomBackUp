// recibe la orden de iniciar los motores mLanzador1 y mLanzador2 los cuales quedan encendidos hasta la orden de apagado esto 
// dura todo el tiempo que entra el jugador,
// se recibe la orden de mover el motor mBanda para que un balon caiga en la lanzadora
// ademas crea el mismo la variable angulo para cambiar la altura de disparo
// se envia la bandera de lanzamiento realizado
// sensa si el balon se disparo mediante sDisparo, si la banda se movio y sDisparo no se activo se da el eLanzador que puede implicar que no hay balones

const int mLanzador1 = 6; // pwm motor 1
const int mLanzador2 = 7; // pwm motor 2
const int eLanzador = 22;  // digital error al raspberry
const int mBanda = 8; // pwm banda
const int sDisparo = 9; // digital sensado lanzado
const int ordenInicio = 10;// digital recibe inicio
const int ordenLanzar = 11;// digital recibe orden mover banda 
const int balonLanzado = 12; // envia señal de balon lanzado
const int balonEnlanzador = 13; // envia señal de que el balon entro al lanzador desde la banda
const int actuadorLineal1 = 14;
const int actuadorLineal2 = 15;// pin digital actuador lineal funciona con puente h invirtiendo el giro al cambiar la polaridad
const int allReady = 16; // pin digital salida // al raspberry
float angulo;
int c = 0; 


void setup() {
  // put your setup code here, to run once
  pinMode(mLanzador1, OUTPUT); 
  pinMode(mLanzador2, OUTPUT); 
  pinMode(eLanzador, OUTPUT);  
  pinMode(mBanda, OUTPUT);  
  pinMode(sDisparo, INPUT); 
  pinMode(ordenInicio, INPUT);
  pinMode(ordenLanzar, INPUT);
  pinMode(balonLanzado, INPUT);
  pinMode(balonEnlanzador,INPUT);
  pinMode(allReady,OUTPUT);
  int d;

}

void loop() {
  // put your main code here, to run repeatedly:
// while(digitalRead(ordenInicio) == HIGH ){
 
 onMotores();
 moveAngulo();
 moveBanda();
    if (digitalRead(ordenLanzar) == HIGH ){delay(1000);}
    if(digitalRead(balonLanzado) == LOW && digitalRead(balonEnlanzador) == HIGH){
      digitalWrite(eLanzador,HIGH);
      }
    
}

//////////////////////////// inicio funciones ////////////////////////////

// inicio funciones
void moveAngulo()
{
//  se mueve a una poscion mediante el tiempo de activacion solo existen 2 posciones arriba y abajo
  angulo = rand() % 1;
  if ( angulo == 0){
   // comprueba poscicion y
    //mueve arriba o no mueve
   
   
  }
   if ( angulo == 1){
    //comperba poscioon 
    
    //mueve abajo o no mueve
  }
  
  //return angulo;
}
void onMotores()
{
   
  if (digitalRead(ordenInicio)== HIGH){
  analogWrite(mLanzador1,120); 
  analogWrite(mLanzador2,120); 
 // digitalWrite(motReady, HIGH);// remplazar por serial comand 1
  }
  if (digitalRead(ordenInicio) == LOW){
    analogWrite(mLanzador1,0);
    analogWrite(mLanzador2,0); 
  }
  
 // analogWrite(mLanzador1,0); 
  //analogWrite(mLanzador2,0);
  //return 0;
}
void moveBanda()
{
 if(digitalRead(ordenLanzar) == HIGH){
    while(digitalRead(balonEnlanzador) == LOW )//
    {
    analogWrite(mBanda,120); 
  }
 }
  if(digitalRead(ordenLanzar) == LOW){
    analogWrite(mBanda,0);} 
//  return 0;
}


