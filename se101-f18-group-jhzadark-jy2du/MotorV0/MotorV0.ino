/*
Forward - fPin high, bPin low
Backward - fPin low, bPin high
*/

int fPin = 4;
int bPin = 5;

void setup() {
  pinMode(fPin, OUTPUT);
  pinMode(bPin, OUTPUT);
}

void loop() {
  digitalWrite(fPin, HIGH);
  digitalWrite(bPin, LOW);
  delay(10000);
  digitalWrite(fPin, LOW);
  
  //digitalWrite(bPin, HIGH);
  //delay(2000);
  //digitalWrite(bPin, LOW);
}
