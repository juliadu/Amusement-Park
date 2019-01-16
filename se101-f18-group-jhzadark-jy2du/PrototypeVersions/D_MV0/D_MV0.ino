/*
IF CLOSE, MOTOR MOVES BACKWARDS
*/

int pPin = 12;
int fPin = 4;
int bPin = 5;

void setup() {
  Serial.begin(9600);
  pinMode(fPin, OUTPUT);
  pinMode(bPin, OUTPUT);
}

void loop() {
  long duration, cm;

  pinMode(pPin, OUTPUT);
  digitalWrite(pPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pPin, LOW);

  pinMode(pPin, INPUT);
  duration = pulseIn(pPin, HIGH);

  cm = microsecondsToCentimeters(duration);
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  if(cm < 10){
  digitalWrite(bPin, HIGH);
  digitalWrite(fPin, LOW);
  }
  else{
  digitalWrite(fPin, HIGH);
  digitalWrite(bPin, LOW);
  }
  delay(100);

}

long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}
