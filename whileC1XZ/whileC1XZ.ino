
const int En_WrRd_RS485 =  2;

const int Led_1 =  13; 
const int Led_2 =  3; 
  
//const int sensor_1 = 11; 

// variables para 32 sensados 
//int myPins[] = {5, 6, 22, 23, 24, 25, 26, 27, 28, 29, 30,31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52,53,100}; // 32 elementos
int myPins[] = {4,5,6,7,8,9,10,11,12};
int sN=33;
//***************
char VarChar = ' ';
String BufferIn = "";        
boolean StringCompleta = false; 

void setup() 
{ 
  // se define pines en modo entrada
  for(int j= 0 ; j <32; j++){
  pinMode(myPins[j],INPUT);}
  //******************
  Serial.begin(9600);
  BufferIn.reserve(5);  
    
  pinMode(En_WrRd_RS485, OUTPUT);
  
  pinMode(Led_1, OUTPUT);
  pinMode(Led_2, OUTPUT);
  
  
  digitalWrite(En_WrRd_RS485, LOW); 
  digitalWrite(Led_1, LOW);
  digitalWrite(Led_2, LOW);
   
} 
 
void loop() 
{ 
  int celda=0;// variable celda que se exporta 
  if (StringCompleta) 
  {         
       delay(50);
       digitalWrite(En_WrRd_RS485, LOW); 
       Serial.println(BufferIn);
      
 
      if ((BufferIn.indexOf('S')) >= 0)
      {
          if (BufferIn.indexOf('1') >= 0)
          {
            Serial.println("OK");
            delay(500);
            
            boolean flag = true;
            
            while(flag == true)
            {  
               digitalWrite(Led_2, HIGH);
               for(int i = 0;i < 9; i ++)
               {     

                 if( (digitalRead(myPins[i])) == HIGH)/// this for loop reduces time from 16 ms to 5 ms
                 {
                     flag = false;
                     int foo = i;
                     celda = foo;
                     sN=i;
                     Serial.println(celda);
                     i = 33;
                 }
                
    
               }
            }
             
          }
            delay(500);
            digitalWrite(Led_2, LOW);
            Serial.println("out");
      }      

          
  }     
  
  StringCompleta = false;
  BufferIn = "";
} 
 

void serialEvent()
{
  while (Serial.available()) 
  {
    VarChar = (char)Serial.read();
    BufferIn += VarChar;
    if (VarChar == 'Z') 
      { StringCompleta = true; 
      }   
  }
}



