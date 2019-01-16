int age = 0;
bool isChild = false;
int once = 0;
int choice = 0;

void setup() {
  Serial.begin(9600);
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
    Serial.println("#1");
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
