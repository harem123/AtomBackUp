//PULSADOR COMO INTERRUPTOR
  int pinLED = 13;
  int pinTouch = 22;
  int SenalActual = 1;
  int SenalAntigua = 1;
  int Estado = 1;


 
void setup() {
 //Encendido de la bombilla
 pinMode(pinLED,OUTPUT);
 //entrada del sensor
 pinMode(pinTouch,INPUT);
}
 
void loop() {
 //detector de flancos
 flancoSubida();
 
}
void flancoSubida(){

  SenalActual = digitalRead(pinTouch);
 if (SenalActual == HIGH && SenalAntigua == LOW)
 {
 //si hay un flanco de subida, cambia el estado de bajo a alto 0 de alto a bajo.
 Estado = !Estado;
 //lo sacamos
 digitalWrite(pinLED, HIGH);
 delay(2000);
 
 };
 SenalAntigua = SenalActual;
  digitalWrite(pinLED, LOW);
}
