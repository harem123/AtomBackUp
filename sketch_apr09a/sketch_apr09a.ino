int ledPin = 13; // LED connected to digital pin 13
int inPin = 22;   // pushbutton connected to digital pin 7
int val = 1;     // variable to store the read value

void setup()
{
  pinMode(ledPin, OUTPUT);      // sets the digital pin 13 as output
  pinMode(inPin, INPUT);      // sets the digital pin 7 as input
  digitalWrite(ledPin,  HIGH);
}

void loop()
{
  val = digitalRead(inPin);   // read the input pin
  digitalWrite(ledPin, val);    // sets the LED to the button's value
}
