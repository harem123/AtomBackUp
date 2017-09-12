// Coursera Module 3 assignment by John O'Neal 
// the fast blink is set to 1/4 second ON state and 1/4 off state for total cycle of 1/2 second
// the slow blink state is set to 1 second ON and 1 second off for total cycle time of 2 seconds

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int fastb=0;
  int slowb=0;
  for (fastb = 1; fastb <= 5; ++fastb)
  {
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(250);                      
  digitalWrite(LED_BUILTIN, LOW);   
  delay(250);
  }
  for (slowb = 1; slowb <= 5; ++slowb)
  {
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(1000);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(1000);
  }
}
