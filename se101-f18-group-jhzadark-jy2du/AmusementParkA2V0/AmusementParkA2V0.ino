#include <Wire.h>
#include <SPI.h>
#include "imagedata.h"
#include <epd2in7.h>
#include <epdpaint.h>


#define COLORED     0
#define UNCOLORED   1

int dUp = 2;
int dDown = 4;
int upState = 0;
int downState = 0;
int d = 0;
int count = 0;
int choice = 0;

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop() {
  delay(100);
   Epd epd;
  if (epd.Init() != 0) {
    Serial.print("e-Paper init failed");
    return;
  }
  epd.ClearFrame();
  unsigned char image[1024];
  Paint paint(image, 176, 32);    //width should be the multiple of 8 
  paint.Clear(UNCOLORED);
  
  while (count == 0){
  
  upState = digitalRead(dUp);
  downState = digitalRead(dDown);

  Serial.print("\nDAY:");
  Serial.print(d);
  delay(100);

  if(upState == HIGH){
    if(d != 7){
      d++;
    }
    else{
      d = 0;
    }
  }
  if(downState == HIGH){
    if (d != 0){
      d--;
    }
    else{
      d = 7;
    }
  }
  if(upState && downState == HIGH){
    count = 1;
    }
  }
  
  paint.Clear(COLORED);
  paint.DrawStringAt(18, 8, "ROLLERCOASTER", &Font16, UNCOLORED);
  epd.TransmitPartialData(paint.GetImage(), 0, 0, paint.GetWidth(), paint.GetHeight());
  paint.Clear(UNCOLORED);
  paint.DrawStringAt(0, 8, "Adult - $5.00", &Font16, COLORED);
  epd.TransmitPartialData(paint.GetImage(), 0, 25, paint.GetWidth(), paint.GetHeight());
  paint.Clear(UNCOLORED);
  paint.DrawStringAt(0, 0, "Child - $2.50", &Font16, COLORED);
  epd.TransmitPartialData(paint.GetImage(), 0, 50, paint.GetWidth(), paint.GetHeight());
  paint.Clear(UNCOLORED);
  paint.Clear(COLORED);
  paint.DrawStringAt(22, 8, "FERRIS WHEEL", &Font16, UNCOLORED);
  epd.TransmitPartialData(paint.GetImage(), 0, 75, paint.GetWidth(), paint.GetHeight());
  paint.Clear(UNCOLORED);
  paint.DrawStringAt(0, 8, "Adult - $3.00", &Font16, COLORED);
  epd.TransmitPartialData(paint.GetImage(), 0, 100, paint.GetWidth(), paint.GetHeight());
  paint.Clear(UNCOLORED);
  paint.DrawStringAt(0, 0, "Child - $1.50", &Font16, COLORED);
  epd.TransmitPartialData(paint.GetImage(), 0, 125, paint.GetWidth(), paint.GetHeight());
  paint.Clear(COLORED);
  paint.DrawStringAt(60, 8, "SWING", &Font16, UNCOLORED);
  epd.TransmitPartialData(paint.GetImage(), 0, 150, paint.GetWidth(), paint.GetHeight());
  paint.Clear(UNCOLORED);
  paint.DrawStringAt(0, 8, "Adult - $4.00", &Font16, COLORED);
  epd.TransmitPartialData(paint.GetImage(), 0, 175, paint.GetWidth(), paint.GetHeight());
  paint.Clear(UNCOLORED);
  paint.DrawStringAt(0, 0, "Child - $2.00", &Font16, COLORED);
  epd.TransmitPartialData(paint.GetImage(), 0, 200, paint.GetWidth(), paint.GetHeight());
  paint.Clear(UNCOLORED);
  if (d == 4){
  paint.DrawStringAt(2, 0, "Wacky Wednesday!", &Font16, COLORED);
  paint.DrawStringAt(40, 16, "$1.00 off", &Font16, COLORED);
  epd.TransmitPartialData(paint.GetImage(), 0, 220, paint.GetWidth(), paint.GetHeight());
  }
  else if (d == 7){
  paint.DrawStringAt(2, 0, "-----CLOSED-----", &Font16, COLORED);
  paint.DrawStringAt(80, 16, ":(", &Font16, COLORED);
  epd.TransmitPartialData(paint.GetImage(), 0, 220, paint.GetWidth(), paint.GetHeight());
  }
  else {
  paint.Clear(UNCOLORED);
  paint.DrawStringAt(35, 15, ":) ENJOY!!", &Font16, COLORED);
  epd.TransmitPartialData(paint.GetImage(), 0, 220, paint.GetWidth(), paint.GetHeight());
  paint.Clear(UNCOLORED);
  }
  epd.DisplayFrame();
  //epd.Sleep();

  while (count == 1 && choice == 4){

  paint.Clear(COLORED);
  paint.DrawStringAt(5, 8, "HAVE A NICE DAY", &Font16, UNCOLORED);
  epd.TransmitPartialData(paint.GetImage(), 0, 100, paint.GetWidth(), paint.GetHeight());
  paint.Clear(UNCOLORED);
  paint.DrawStringAt(0, 8, "Please pay fares.", &Font16, COLORED);
  epd.TransmitPartialData(paint.GetImage(), 0, 125, paint.GetWidth(), paint.GetHeight());
  paint.Clear(UNCOLORED);
  epd.TransmitPartialData(paint.GetImage(), 0, 50, paint.GetWidth(), paint.GetHeight());
  epd.TransmitPartialData(paint.GetImage(), 0, 75, paint.GetWidth(), paint.GetHeight());
  epd.TransmitPartialData(paint.GetImage(), 0, 0, paint.GetWidth(), paint.GetHeight());
  epd.TransmitPartialData(paint.GetImage(), 0, 25, paint.GetWidth(), paint.GetHeight());
  epd.TransmitPartialData(paint.GetImage(), 0, 150, paint.GetWidth(), paint.GetHeight());
  epd.TransmitPartialData(paint.GetImage(), 0, 175, paint.GetWidth(), paint.GetHeight());
  epd.TransmitPartialData(paint.GetImage(), 0, 200, paint.GetWidth(), paint.GetHeight());
  epd.TransmitPartialData(paint.GetImage(), 0, 225, paint.GetWidth(), paint.GetHeight());
  epd.TransmitPartialData(paint.GetImage(), 0, 250, paint.GetWidth(), paint.GetHeight());
  epd.TransmitPartialData(paint.GetImage(), 0, 275, paint.GetWidth(), paint.GetHeight());
  epd.TransmitPartialData(paint.GetImage(), 0, 300, paint.GetWidth(), paint.GetHeight());
  
  epd.DisplayFrame();
  //epd.Sleep();
  //count++;
  }
}

void receiveEvent(int howMany) {
  //while (1 < Wire.available()) { // loop through all but the last
    //int sensorData = Wire.read(); // receive byte as a character
    //Serial.print(sensorData);         // print the character
  //}
  choice = Wire.read();    // receive byte as an integer
  Serial.println(choice);         // print the integer  
}
