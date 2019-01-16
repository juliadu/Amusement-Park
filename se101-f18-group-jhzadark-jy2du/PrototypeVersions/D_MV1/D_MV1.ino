/*
SENSES 2 ITERATIONS THEN STOPS ROLLERCOASTER
*/

int pPin = 12;
int fPin = 4;
int bPin = 5;
int iterations = 0;

void setup() {
  Serial.begin(9600);
  pinMode(fPin, OUTPUT);
  pinMode(bPin, OUTPUT);
}

void loop() {
  while(iterations < 4){
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
  
  //Serial.print(cm);
  //Serial.print("cm");
  //Serial.println();

  digitalWrite(fPin, HIGH);
  digitalWrite(bPin, LOW);
  //Serial.println("hi");
  
  if(cm < 10){
  iterations++;
  Serial.println(iterations);
  if(iterations==4) {
    delay(200);
    digitalWrite(fPin, LOW);
  }
  }
  delay(60);
  }
}

long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}
