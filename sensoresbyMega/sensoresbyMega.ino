/*
// pines NO usables del 0, 1,  para serial, 2 para interrupciones,13 por led built in
// usables 3,12 - 14-36

  This example code is in the public domain.
*/
int myPins[] = {6,22, 23, 24, 25, 26, 27, 28, 29, 30,31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52,53};// 32 elementos
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
 // pinMode(2,INPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 100");
  
}

// the loop routine runs over and over again forever:
void loop() {
 int sV=3;
 int celda=0;
 int sN=0;
 
// int digiRead= digitalRead(2);
for(int i = 1;i < 33; i ++){
  if( (digitalRead(myPins[i])) == 1)
  {
     
     int foo=i;
     celda= foo;
     sN=i;
     i=33;
    
  }
}
  



  
  // print out the value you read:
 // Serial.println(myPins[sN]);
  
  Serial.print(millis());
  Serial.print(' ');
  //Serial.print("celda  ");
  //Serial.println(celda);
 
  //delay(1);        // delay in between reads for stability
  if (Serial.available())
 {
  
  int serialValue = Serial.parseInt();
  
  if (serialValue == 999)
    {
  
  Serial.print("out  ");
      Serial.end();
  }
 }
}
