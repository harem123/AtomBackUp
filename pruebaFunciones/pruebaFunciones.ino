int mLanzador1 = 6; // pwm motor 1
int mLanzador2 = 7; // pwm motor 2
int eLanzador = 22;  // digital error
int mBanda = 8; // pwm banda
int sDisparo = 9; // digital sensado lanzado
int ordenInicio = 10;// digital recibe inicio
int ordenLanzar = 11;// digital recibe orden mover banda 
int balonLanzado = 12; // envia señal de balon lanzado
int balonEnlanzador = 13; // envia señal de que el balon entro al lanzador desde la banda
int actuadorLineal1 = 14;
int actuadorLineal2 = 15;// pin digital actuador lineal funciona con puente h invirtiendo el giro al cambiar la polaridad
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
  int d;
  

}
void onMotores(){
  analogWrite(mLanzador1,120); 
  analogWrite(mLanzador2,120); 
//  digitalWrite(motReady, HIGH);
  
 // analogWrite(mLanzador1,0); 
  //analogWrite(mLanzador2,0);
  //return 0;
}
void loop() {
  // put your main code here, to run repeatedly:
// while(digitalRead(ordenInicio) == HIGH ){
 while (c=0){
onMotores();}
 
 
  
analogWrite(mLanzador1, 0);
analogWrite(mLanzador2, 0);
c == 0;
}

// inicio funciones
int moveAngulo()
{
//  se mueve a una poscion mediante el tiempo de activacion solo existen 2 posciones arriba y abajo
  angulo = rand() % 12;
  
  return angulo;
}

void moveBanda()
{
 // if(digitalRead(ordenLanzar == HIGH){
    while(digitalRead(balonEnlanzador) == LOW ){
    analogWrite(mBanda,120); 
  }
  
  analogWrite(mBanda,0);
//  return 0
}


