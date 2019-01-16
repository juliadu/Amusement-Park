int pPin = 12;

void setup() {
  Serial.begin(9600);
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

  delay(100);

}

long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}
