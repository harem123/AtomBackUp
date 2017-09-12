// variables
int servo=0;
int t=500; //ms
// ejecutar una vez
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(servo, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
 digitalWrite(servo, HIGH);
 
}
