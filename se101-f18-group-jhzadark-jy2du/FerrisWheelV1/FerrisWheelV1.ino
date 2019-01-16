int motorPin = 3;
int motorSpeed = 150;
int speedControl = 50;
int count = 0;
 
void setup() {
// Set up the motor pin to be an output: 
pinMode(motorPin, OUTPUT);
// Set up the serial port: 
Serial.begin(9600);
}

 
 
void loop() 
{ 
  if(count<80) {
  analogWrite(motorPin, motorSpeed);
  delay(speedControl); 
  analogWrite(motorPin, 0);
  delay(speedControl);
  count++;
  }
  
  analogWrite(motorPin, 0);
  
} 
