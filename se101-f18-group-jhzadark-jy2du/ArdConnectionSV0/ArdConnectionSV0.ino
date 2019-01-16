#include <Wire.h>

int dPin = A0;
int count = 0;
int val = 0;
int vPin = 9;

void setup() {
  //Serial.begin(9600);
  Wire.begin(); // join i2c bus (address optional for master)
  pinMode(dPin, INPUT);
  pinMode(vPin, OUTPUT);
}

void loop() {
  digitalWrite(vPin, HIGH);
  
  val = analogRead(dPin);

  if(val < 300){
    count++;
    Wire.beginTransmission(8); // transmit to device #8 
    Wire.write(count);  
    //Serial.println("hi");// sends one byte
    Wire.endTransmission();    // stop transmitting
  }
  delay(60);
 
}
