#include <SPI.h>
#include <epd2in7.h>
#include "imagedata.h"
#include <epdpaint.h>

#define COLORED     0
#define UNCOLORED   1

int dUp = 2;
int dDown = 3;
int upState = 0;
int downState = 0;
int d = 0;
int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(dUp, INPUT);
  pinMode(dDown, OUTPUT);
}

void loop() {

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

  Serial.println(d);
  delay(100);
  
  if(upState == HIGH){
    if(d != 6){
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
      d = 6;
    }
  }
  if(upState && downState == HIGH){
    count = 1;
    }
  }
  
  
  paint.Clear(COLORED);
  paint.DrawStringAt(20, 8, "ROLLERCOASTER", &Font16, UNCOLORED);
  epd.TransmitPartialData(paint.GetImage(), 0, 32, paint.GetWidth(), paint.GetHeight());
  paint.Clear(UNCOLORED);
  paint.DrawStringAt(0, 16, "Fares:", &Font16, COLORED);
  epd.TransmitPartialData(paint.GetImage(), 0, 64, paint.GetWidth(), paint.GetHeight());
  paint.Clear(UNCOLORED);
  paint.DrawStringAt(0, 8, "Adult - $5.00", &Font16, COLORED);
  epd.TransmitPartialData(paint.GetImage(), 0, 96, paint.GetWidth(), paint.GetHeight());
  paint.Clear(UNCOLORED);
  paint.DrawStringAt(0, 0, "Child - $2.50", &Font16, COLORED);
  epd.TransmitPartialData(paint.GetImage(), 0, 128, paint.GetWidth(), paint.GetHeight());
  paint.Clear(UNCOLORED);
  if (d == 4){
  paint.DrawStringAt(2, 0, "Wacky Wednesday!", &Font16, COLORED);
  paint.DrawStringAt(60, 16, "$2.00", &Font16, COLORED);
  epd.TransmitPartialData(paint.GetImage(), 0, 160, paint.GetWidth(), paint.GetHeight());
  }
  else {
  paint.Clear(UNCOLORED);
  paint.DrawStringAt(2, 0, ":) ENJOY!", &Font16, COLORED);
  epd.TransmitPartialData(paint.GetImage(), 0, 160, paint.GetWidth(), paint.GetHeight());
  paint.Clear(UNCOLORED);
  }
  epd.DisplayFrame();
  epd.Sleep();
}


