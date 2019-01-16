/*
SENSES 2 ITERATIONS THEN STOPS ROLLERCOASTER
*/

int sensorpin = 8;
int fPin = 4;
int bPin = 5;
int iterations = 0;
int val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(fPin, OUTPUT);
  pinMode(bPin, OUTPUT);
}

void loop() {
  while(iterations < 4){
    val = analogRead(sensorpin);
    Serial.println(val);
  
  //Serial.print(cm);
  //Serial.print("cm");
  //Serial.println();

  digitalWrite(fPin, HIGH);
  digitalWrite(bPin, LOW);
  //Serial.println("hi");
  
  if(val < 300){
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
