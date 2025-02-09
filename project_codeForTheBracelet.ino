#include <Wire.h>               //very common protocol,primaly used for data
#include <SPI.h>               //it contains bus manager implementations for hardware resources
#include <Adafruit_GFX.h>        // set graphics functions for all of our Screan display  
#include <Adafruit_SSD1306.h>   //handles display communication , memory mapping, and low-level drawing 

Adafruit_SSD1306 srituhobby = Adafruit_SSD1306(128, 64, & Wire);

#define sensor A0 //haertbeat 
#define Highpulse 540 

int sX = 0;
int sY = 60;
int x = 0;
int Svalue;
int value; 
long Stime = 0;
long Ltime = 0;
int count = 0;
int Bpm = 0;

#define TILT 2

void setup() {
 



 Serial.begin(9600);
  srituhobby.begin(SSD1306_SWITCHCAPVCC,0X3C); //address 0x3C for 128x32 
  delay(1000); 
  srituhobby.clearDisplay();
}

void loop() {
 Svalue = analogRead(sensor);
 Serial.println(Svalue);
 value = map(Svalue, 0, 1024, 0, 45);

 int y = 60 - value;

 if (x > 128) {
  x = 0;
  sX = x;
  srituhobby.clearDisplay();
 }
   srituhobby.drawLine(sX, sY, x, y, WHITE);
   sX = x;
   sY = y;
   x ++;

   BPM() ;
   srituhobby.setCursor(0,0);
   srituhobby.setTextSize(2);
   srituhobby.setTextColor(SSD1306_WHITE);
   srituhobby.print("BPM :");
   srituhobby.display();
}

void BPM() {

  if (Svalue > Highpulse) {
    Stime  = millis() - Ltime;
     count++;

    if (Stime / 1000 >= 10) {
      Ltime = millis();
      Serial.println(count);
      srituhobby.setCursor(60,0);
      srituhobby.setTextSize(2);
      srituhobby.setTextColor(SSD1306_WHITE);
      srituhobby.print(count);
      srituhobby.print("  ");
      srituhobby.display();
      count = 0;
    }
  }
}
