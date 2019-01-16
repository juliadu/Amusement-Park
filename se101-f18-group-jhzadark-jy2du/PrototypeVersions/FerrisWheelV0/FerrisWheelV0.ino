int motorPin = 3;
int motorSpeed = 75;
int rideLength = 8000;
int count = 0;
 
void setup() {
// Set up the motor pin to be an output: 
pinMode(motorPin, OUTPUT);
// Set up the serial port: 
Serial.begin(9600);
}

 
 
void loop() 
{ 
  if(count==0) {
  analogWrite(motorPin, motorSpeed);
  delay(rideLength); 
  count++;
  }
  
  analogWrite(motorPin, 0);
  
} 
