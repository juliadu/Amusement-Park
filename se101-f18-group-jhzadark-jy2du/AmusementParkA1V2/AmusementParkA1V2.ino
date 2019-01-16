#include <Wire.h>
#include <SPI.h>

int age = 0;
bool isChild = false;
int once = 0;
int choice = 0;
int pPin = A0;
int fPin = 4;
int bPin = 5;
int iterations = 0;
int val = 0;
int rollerLoops = 0;
bool camera = false;
int camAns = 0;
int camOnce = 0;
byte address = 0x00;
int cameraPin= 10;
int ferrisLoops = 0;
int motorPin = 3;
int motorSpeed = 150;
int speedControl = 50;
int ferrisCount = 0;
const int swMotorPin = 6;
int swOnce = 0;
int swingLoops = 0;
int poPin = A2;
int pValue = 0;
int ledPin = 9;

double tCost = 0.00;
double pRoller = 5.00;
double pFerris = 3.00;
double pSwing = 4.00;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  pinMode(fPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode (cameraPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(swMotorPin, OUTPUT);
  pinMode(poPin, INPUT);
  pinMode(ledPin, OUTPUT);
  SPI.begin();
}

void loop() {
  while (once == 0){
  pValue = analogRead(poPin);
  pValue = map(pValue, 0, 1023, 0, 255);
  Serial.println(pValue);
  analogWrite(ledPin, pValue); 
  Wire.beginTransmission(8); // transmit to device #8 
  Wire.write(0); 
  Wire.endTransmission();
  Serial.println("AMUSEMENT PARK NAME");
  Serial.println("Welcome!");
  Serial.println("Please input your age");
  once++;
  }
  while(once == 1){
  pValue = analogRead(poPin);
  pValue = map(pValue, 0, 1023, 0, 255);
  analogWrite(ledPin, pValue); 
  if (Serial.available() > 0) {
  age = Serial.parseInt();
  Serial.println(age);
  if (age<0){
    Serial.println("Please input a VALID age");
    age = Serial.parseInt();
  }
  else if (age <= 16){
    Serial.println("You qualify for children's pricing");
    isChild = true;
    once++;
  }
  else{
    Serial.println("You do not qualify for children's pricing :(");
    once++;
  }
  }
  }
  while (once == 2){
  Wire.beginTransmission(8); // transmit to device #8 
  Wire.write(0); 
  Wire.endTransmission();
  Serial.println();
  Serial.println("Here are the available rides:");
  Serial.println("1) Rocker Roller Coaster");
  Serial.println("2) Fantastic Ferris Wheel");
  Serial.println("3) Swingin' Around");
  Serial.println("4) Exit amusement park");
  Serial.println("Please enter the corresponding number!");
  once++;
  }
  while(once == 3){
  if (Serial.available() > 0) {
  choice = Serial.parseInt();
  if (choice == 1){
    Serial.println(choice);
    Serial.println("How many times would you like to ride the roller coaster?");
    once++;
    while(once == 4){
      if (Serial.available() > 0) {
        rollerLoops = Serial.parseInt();
        if (rollerLoops<0){
          Serial.println("Please input a VALID number");
          rollerLoops = Serial.parseInt();
        }
        else{
          Serial.println(rollerLoops);
          once++;
        }
      }
    }
    Serial.println("Would you like a photo? Enter 'y' or 'n'.");
    while(once == 5){
      if (Serial.available() > 0) {
        camAns = Serial.read();
        if(camAns == 'y'){
          camera = true;
          once++;
          Serial.println('y');
        }
        else if(camAns != 'n'){
          Serial.println("Please input a VALID answer");
        }
        else{
          Serial.println('n');
          once++;
        }
      }
    }
    while(once == 6 && iterations < rollerLoops * 2){
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
  
      digitalWrite(fPin, HIGH);
      digitalWrite(bPin, LOW);

      if(camOnce == 0 && camera == true){
      delay(700);
      digitalPotWrite(0); // no resistance here. Camera is triggered.
      delay(200);
      digitalPotWrite(128); //resistance here. Camera is not triggered.
      camOnce++;
      }
  
      if(cm < 10){
        iterations++;
        Serial.println(iterations);
        if(iterations==rollerLoops) {
          delay(200);
          digitalWrite(fPin, LOW);
          if (isChild){
            tCost += (pRoller/2) * rollerLoops;
          }
          else{
            tCost += (pRoller) * rollerLoops;
          }
          iterations = 0;
          camOnce = 0;
          camera = false;
          once = 2;
        }
    }
    delay(60);
    }
  }
  else if (choice == 2){
    Serial.println(choice);
    Serial.println("How many times would you like to ride the ferris wheel?");
    once++;
    while(once == 4){
      if (Serial.available() > 0) {
        ferrisLoops = Serial.parseInt();
        if (ferrisLoops<0){
          Serial.println("Please input a VALID number");
          ferrisLoops = Serial.parseInt();
        }
        else{
          Serial.println(ferrisLoops);
          once++;
        }
      }
    }
    Serial.println("Would you like a photo? Enter 'y' or 'n'.");
    while(once == 5){
      if (Serial.available() > 0) {
        camAns = Serial.read();
        if(camAns == 'y'){
          camera = true;
          once++;
          Serial.println('y');
        }
        else if(camAns != 'n'){
          Serial.println("Please input a VALID answer");
        }
        else{
          Serial.println('n');
          once++;
        }
      }
    }
    while(once == 6 && ferrisCount < 80 * ferrisLoops){
        if(camOnce == 0 && camera == true){
        delay(700);
        digitalPotWrite(0); // no resistance here. Camera is triggered.
        delay(200);
        digitalPotWrite(128); //resistance here. Camera is not triggered.
        camOnce++;
        }
        analogWrite(motorPin, motorSpeed);
        delay(speedControl); 
        analogWrite(motorPin, 0);
        delay(speedControl);
        ferrisCount++;
      }
      analogWrite(motorPin, 0);
      if (isChild){
        tCost += (pFerris/2) * ferrisLoops;
      }
      else{
        tCost += (pFerris) * ferrisLoops;
      }
      once = 2;
      camOnce = 0;
      camera = false;
      ferrisCount = 0;
    
  }
  else if (choice == 3){
    Serial.println(choice);
    Serial.println("How many times would you like to ride the swing?");
    once++;
    while(once == 4){
      if (Serial.available() > 0) {
        swingLoops = Serial.parseInt();
        if (swingLoops<0){
          Serial.println("Please input a VALID number");
          swingLoops = Serial.parseInt();
        }
        else{
          Serial.println(swingLoops);
          once++;
        }
      }
    }
    Serial.println("Would you like a photo? Enter 'y' or 'n'.");
    while(once == 5){
      if (Serial.available() > 0) {
        camAns = Serial.read();
        if(camAns == 'y'){
          camera = true;
          once++;
          Serial.println('y');
        }
        else if(camAns != 'n'){
          Serial.println("Please input a VALID answer");
        }
        else{
          Serial.println('n');
          once++;
        }
      }
    }
    while(once == 6){
      if (swOnce == 0){
        digitalWrite(swMotorPin, HIGH);
        delay(1000);
        swOnce = 1;  
      }
      if(camOnce == 0 && camera == true){
        delay(700);
        digitalPotWrite(0); // no resistance here. Camera is triggered.
        delay(200);
        digitalPotWrite(128); //resistance here. Camera is not triggered.
        camOnce++;
        }
      for (int i = 0; i < swingLoops * 250; i++){
        digitalWrite(swMotorPin, HIGH);
        delay(20);
        digitalWrite(swMotorPin, LOW);
        delay(30);
      }
      if (isChild){
        tCost += (pSwing/2) * swingLoops;
      }
      else{
        tCost += (pSwing) * swingLoops;
      }
      
      swOnce = 0;
      once = 2;
      swingLoops = 0;
      camera = false;
    }
  }
  else if (choice == 4){
    Wire.beginTransmission(8); // transmit to device #8 
    Wire.write(4); 
    Wire.endTransmission();
    Serial.println("\nSad to see you go!");
    Serial.println("Your total fares are:");
    Serial.print("$");
    Serial.print(tCost);
  }
  else {
    Serial.println("\nPlease enter a VALID option");
    once = 2;
  }
  }
  }
}

long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}

int digitalPotWrite(int value)
{
digitalWrite(cameraPin, LOW);
SPI.transfer(address);
SPI.transfer(value);
digitalWrite(cameraPin, HIGH);
}
