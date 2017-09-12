/*
// pines NO usables del 0, 1,  para serial, 2 para interrupciones,13 por led built in
// usables 3,12 - 14-36

  This example code is in the public domain.
*/
int myPins[] = {5, 6, 22, 23, 24, 25, 26, 27, 28, 29, 30,31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52,53,100}; // 32 elementos
  //            0,1,2 , 3 ,4  ,5  ,6  , 7 ,8  , 9 , 10,11, 12,                             20, 21, 22, 23, 24                      30, 31, 32
// the setup routine runs once when you press reset:
int sN=33;
void setup() {
  // initialize serial communication at 9600 bits per second:
  for(int j= 0 ; j <32; j++){
  pinMode(myPins[j],INPUT);}// OJO NO SE ESTA DEFINIENDO PINES DE ENTRADA 
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Sensing 32 ports");
  
  
}

// the loop routine runs over and over again forever:
void loop() {
int celda=0;
  // OJO ESTAS DEFINICIONES CADA CICLO ESTAN INESTABLES 
 
 
//if ((digitalRead(5)) == HIGH)
//{
    for(int i = 0;i < 32; i ++)
    {     // int digiRead= digitalRead(2);

       if( (digitalRead(myPins[i])) == HIGH)/// this for loop reduces time from 16 ms to 5 ms
        {
          //Serial.println(i);
          int foo = i;
          celda = foo;
          sN=i;
          varchar = Serial.read();
          while( varchar== false){// OJO SOLO ILUSTRATIVO DEBE CREAR UNA VARIABLE 
            Serial.print(i);
          }
          i = 33;
    
        }
   }
//}  



  
  // print out the value you read:
  Serial.print(myPins[celda]);
  //Serial.print(millis());
  Serial.print(' ');
  //Serial.print("celda  ");
  Serial.print(celda);
  Serial.print(' ');
  //delay(1);        // delay in between reads for stability
  if (Serial.available())
 {
  
  int serialValue = Serial.parseInt();
  
  if (serialValue == 999)
    {
  
  Serial.print(" out ");
      Serial.end();
  }
 }
}
