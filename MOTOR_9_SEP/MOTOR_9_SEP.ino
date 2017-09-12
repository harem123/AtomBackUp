// motor controlling

// modificado 9 de sep

//sumary el script debe recibir una unica orden de encender motores a baja velocidad 
// luego estar encendido hasta que reciba una unica orden 
// tal vez debe leer la velocidad de forma constante por si las 
// se debe añadir diodos libres y reles 
// se debe crear los q manejen los disparadores entonces 
// recibir orden de lanzar balon y orden de velocidad aun no orden de altura 
// pwm pins 2 to 13 and 44 to 46
int m1 = 6,m2=8,normalVar = 0;


void setup() 
{
  // put your setup code here, to run once:
  
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 100");

}

void loop() 
{
  // put your main code here, to run repeatedly:
 //Serial.read(leer motores);
 //char varchar == True;
 while (varchar == true);
 if (Serial.available())
 {
  int serialValue = Serial.parseInt();
  if (serialValue >= 0 && serialValue <= 100)
  {
    
    motorControl(serialValue);
    
  }
  if (serialValue == 699)
  {Serial.end();
  }
 }
 
}
void motorControl (int serialValue){
  
  normalVar = serialValue * 2;
  analogWrite(m1,normalVar);
  analogWrite(m2,normalVar);
  Serial.print("new pwm value set on: ");
  Serial.print(serialValue,DEC);
 // Serial.print("%");
  Serial.print("\n");
  }
