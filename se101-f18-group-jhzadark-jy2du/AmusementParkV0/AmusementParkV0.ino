int age = 0;
bool isChild = false;
int once = 0;
int choice = 0;
int sensorpin = A5;
int fPin = 4;
int bPin = 5;
int iterations = 0;
int val = 0;
int rollerLoops = 0;
int tCost = 0;
bool camera = false;
int camAns = 0;

void setup() {
  Serial.begin(9600);
  pinMode(fPin, OUTPUT);
  pinMode(bPin, OUTPUT);
}

void loop() {
  while (once == 0){
  Serial.println("AMUSEMENT PARK NAME");
  Serial.println("Welcome!");
  Serial.println("Please input your age");
  once++;
  }
  while(once == 1){
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
        camAns = Serial.parseInt();
        Serial.println(camAns);
        //once++;
      }
    }
    while(once == 6 && iterations < rollerLoops){
    val = analogRead(sensorpin);
    digitalWrite(fPin, HIGH);
    digitalWrite(bPin, LOW);
  
    if(val < 300){
      iterations++;
      Serial.println(iterations);
      if(iterations==rollerLoops) {
        delay(200);
        digitalWrite(fPin, LOW);
      }
    }
    delay(60);
    }
  }
  else if (choice == 2){
    Serial.println("#2");
  }
  else if (choice == 3){
    Serial.println("#3");
  }
  else if (choice == 4){
    Serial.println("\nSad to see you go!");
  }
  else {
    Serial.println("\nPlease enter a VALID option");
    once = 2;
  }
  }
  }
}
