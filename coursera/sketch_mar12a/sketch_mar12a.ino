void setup() {  // put your setup code here, to run once:  
  pinMode(LED_BUILTIN, OUTPUT);  Serial.begin(9600);  Serial.println("- Start Serial Monitor -");  Serial.println();}
void loop() {  // put your main code here, to run repeatedly:  
  int DataReceived;    if (Serial.available()>0)  {   
    DataReceived = Serial.read();
     if(DataReceived == '1'){      
      Serial.println("Get 1, LED On");          
      digitalWrite(LED_BUILTIN, HIGH);      }
     
      else if(DataReceived == '0'){    
        
        Serial.println("Get 0, LED Off");              digitalWrite(LED_BUILTIN, LOW);      }  
        else{        Serial.println("Didn't get  0 or 1, Do nothing");                }      
        }}
