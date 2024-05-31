#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
const char BUTTON_PIN =8; 
bool pressed = false;  
 
LiquidCrystal_I2C lcd (0x27, 16 ,2); 
void setup(){ 
Serial.begin(9600); 
lcd.backlight(); 
lcd.println("s1 sit up straight to relax s2 ins and outs s3 breathe in together"); 
Serial.begin(9600); 
pinMode(BUTTON_PIN,INPUT_PULLUP); 
} 
 
void loop() { 
lcd.clear(); 
 lcd.println("s1 sit up straight to relax s2 ins and outs s3 breathe in together"); 
delay(1000); 
lcd.clear(); 
 
 bool currentState =digitalRead(BUTTON_PIN); 
 if (currentState == pressed) { 
  Serial.println("s1 sit up straight to relax s2 ins and outs s3 breathe in together"); 
  while(digitalRead(BUTTON_PIN)== pressed){ 
   } 
} 
 
 
}