#include <Colorduino.h>

// variables de estado
int inicioFin=0;
int result=0;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  while (! Serial);
  Serial.println("Serial Ready");  

}

void loop() {
  // put your main code here, to run repeatedly:
 /* encender dos leds azul y verde
  estos leds esperan un serial in para activarse
  duran 10 seg y se apagan 
  vuelven a iniciar tras otro serial in 
  esperan un serial in para cambiar el color a rojo o verde
  se puede hacer con estados para iniciar apagar e interrumpir
  va a llamar una funcion que hace toda la parte de los leds*/
  if (Serial.available())
 {
   char serialValue = Serial.read();
   switch(serialValue)
   {
    case 'i' :
    inicioFin = 1;
    case 'f' :
    inicioFin = 2;
    case 'v' : 
    result = 1;
    case 'r' :
    result = 2;
    case 'o':
    Serial.end();
    default :
    Serial.println("invalido"); 
    
   } 
 }
Serial.println(inicioFin);   
Serial.println(result);    
}

void leds(int inicioFin,result)
{
  /* las luces encienden cuando inicio esta en 1, si se recibe result inicio pasa a 2 y cambia de color dependiendo de result
   *  si no se recibe result se espera al contador 
  */
  
}

