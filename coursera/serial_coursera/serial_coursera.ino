// open serial monitor
// press 1 to turn on built in led
// press 0 to turn led off


int led = 13;
void setup() {
Serial.begin(9600);
pinMode(led, OUTPUT);
Serial.print(" press 1 to turn led ON and press 0 to turn OFF");
digitalWrite(led,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
   while (Serial.available() > 0 ){
   
  int input = Serial.read();
// i used incomingByte == 49 because when i introduce "1" from
// keyboard, arduino save that ONE on ascii so is 49
// if we read from serial like char so we can use 1 or 0 directly
    if (input == '1'){
  // Serial.print("in while == 49");
        digitalWrite(led,HIGH);
        }
     
     if (input == '0'){
         digitalWrite(led,LOW);
        }
    
 
   delay(1);
   }
 }
