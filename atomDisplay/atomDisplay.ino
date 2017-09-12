// primero las celdas parpadean en diferentes colores luego las celdas activas quedan encendidas, cuando atomSensor envia la informacion todas las celdas se encienden dorado rojo o verde
//Display led crea 3 valores de diferentes categoria dependiendo de la dificultad las celdas estan divididas en 3 categorias arriba abajo y esquinas escoge 2  y 
// les da un color diferente dorado a esquina o arriba y verde a arriba o abajo ademas selecciona las celdas de alado y abajo de las seleccionadas y las ilumina color rojo 
// por eso la numeracion es importante, la que se marque dorado tendra 5 segundos y la verde 10 segundos encendidas,faltando 3 segundos parpadean y cambian a rojo 
// el estado de las celdas cambia segun el color esto se debe sincronizar para saber a cual entro, si se envia estos valores a atomSensores se puede sensar solo estos 
// y esperar 10 seg sino se continua el otro ciclo

eLeds = 22;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

inicioLeds();
if(digitalRead(ordenLanzado) == HIGH && digitalRead(sensor)== LOW){// orden lanzado y orden lanzador todo es flancos no estados 
celdasActivas();
colorCeldas();
digitalWrite(6,HIGH);// envio 3 seg y cambio a off
// inicio sensores 
digitalWrite(8,HIGH); 

// envia la orden de lanzado al lanzador
}


}
void inicioLeds(){
  /* se envia una matriz todo verde todo rojo todo amarillo 
   *  llamando las subrutinas de los leds
   */
}
void celdasActivas(){
  
  /*  recibe el nivel leyendo serial para tratar de escoger celdas dificiles
   *  se usa random para definir las celdas y con estas las aledañas 
   *  se saca 3 variables para indicar el color de cada una y se saca variables para las rojas 
   */
}
void colorCeldas (){
  
  /* como imparte el color tambn cambia la celda debe leer la variable nivel y la variable sensores
   *  para hacer el cambio 
   *  recibe una cadena de valores y enciende todos los leds de el color deseado incluyendo las apagadas
   *  y los parpadeos 
   */
}

// se recibe via serial un valor de 1 a 3 para el nivel 
// se encienden todas las luces de varios colores y parpadeos 
// se envia orden de iniciar motores de lanzador
// se inicia el loop

// se usa random para definir 2 numeros 
// se enciende en amarillo y verde 
// se activa el sensado 
// se envia orden de lanzar balon el lanzador 
// se recibe bandera de balon lanzado del lanzador
// la bandera inicia temporizador para amrillo 10 seg encendido parpadea cuando falten 3 seg
// para verde 15 seg parpadea cuando falten 3 
// las celdas contiguas se encienden en rojo 
// cuando pasa el timepo cambia a rojo las amarrillas y verdes
// se recibe el valor del sensado tiempo y valor de la celda
// se almacena tiempo y se acumula puntaje 
// se enciende todo en amarillo rojo o verde 
// se acumula contador y se sale del loop

// se envia tiempos y puntaje 



