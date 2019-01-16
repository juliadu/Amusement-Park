const int motorPin = 6;
int once = 0;

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  if (once == 0){
  digitalWrite(motorPin, HIGH);
  delay(250);
  once = 1;  
  }
  digitalWrite(motorPin, HIGH);
  delay(10);
  digitalWrite(motorPin, LOW);
  delay(30);
}
