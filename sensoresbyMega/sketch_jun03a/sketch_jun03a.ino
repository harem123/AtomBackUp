/*
// pines NO usables del 0, 1,  para serial, 2 para interrupciones,13 por led built in
// usables 3,12 - 14-36

  This example code is in the public domain.
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  pinMode(2,INPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 100");
  
}

// the loop routine runs over and over again forever:
void loop() {
 int sV = 3;
 int digiRead= digitalRead(2);
  if( digiRead == 1)
  {
     sV = 1;  
  }
 if(digiRead == 0)
  {
     sV = 2;  
  }
  
 

  
  // print out the value you read:
  Serial.println(sV);
  Serial.print(" time ");
  Serial.print(millis());
  Serial.print(" ");
 
  delay(1);        // delay in between reads for stability
  if (Serial.available())
 {
  
  int serialValue = Serial.parseInt();
  
  if (serialValue == 999)
  {Serial.end();
  }
 }
}
