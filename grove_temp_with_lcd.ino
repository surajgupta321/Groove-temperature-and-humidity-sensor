//Hands on Practicle
#include <TH02_dev.h>
#include "Arduino.h"
#include "Wire.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4); 

void setup()
{ 
  lcd.backlight();
  lcd.init();
  lcd.begin(20,4);
  lcd.setCursor(6,0);
  lcd.print("Welcome");
  lcd.setCursor(9,1);
  lcd.print("To");
  lcd.setCursor(2,2);
  lcd.print("Hands on Practical");
  Serial.begin(9600);          
  Serial.println("Welcome To");
  Serial.println("Hands on Practical");
  delay(2000);
  TH02.begin();
  delay(100); 
}
 

void loop()
{
   float temper = TH02.ReadTemperature(); 
   Serial.println("Temperature:");   
   Serial.print(temper);
   Serial.println("C ");
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Temperature: ");
   lcd.print(temper);
   lcd.print((char)223); //to print degree symbol on lcd
   lcd.print("C ");
   
   float humidity = TH02.ReadHumidity();
   Serial.println("Humidity = ");
   Serial.print(humidity);
   Serial.println("% ");
   lcd.setCursor(0,2);
   lcd.print("Humidity: ");
   lcd.print(humidity);
   lcd.print("% ");
   delay(1000);
}
