#include <SPI.h>
byte address = 0x00;
int cameraPin= 10;
 

void setup()
{  
  
 pinMode (cameraPin, OUTPUT);
 SPI.begin();
    
}
void loop()
{    
  digitalPotWrite(0); // no resistance here. Camera is triggered.
  delay(500);
  digitalPotWrite(128); //resistance here. Camera is not triggered.
  delay(1000);
}

int digitalPotWrite(int value)
{
digitalWrite(cameraPin, LOW);
SPI.transfer(address);
SPI.transfer(value);
digitalWrite(cameraPin, HIGH);
}
