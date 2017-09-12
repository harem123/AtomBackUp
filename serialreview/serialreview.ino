void setup() {  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13, OUTPUT);
Serial.print(" press 1 to turn led ON and press 0 to turn OFF");
digitalWrite(13, LOW); }

void loop() {  // put your main code here, to run repeatedly:
int a=Serial.read();
if (a==49) {
  digitalWrite(13,HIGH);
}
if (a==48) {
  digitalWrite(13,LOW);
}
delay(1);
}
