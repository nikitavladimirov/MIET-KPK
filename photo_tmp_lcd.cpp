// Фоторезистор и датчик температуры c выводом информации на LCD дисплей

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() 
{
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.print("Temp:      C");
  lcd.setCursor(0, 1);
  lcd.print("Volt:      V");
}

void loop() 
{
  int valueTMP = analogRead(A4);
  int valuePhotoRes = analogRead(A5);
  float valueTMPNew = (valueTMP * 5.0/1024 - 0.5) * 100; // 0.5 is voltage offset on TMP36 temperature sensor
  float valuePhotoResNew = (valuePhotoRes * 5.0/1024 );
  Serial.print(valueTMPNew + String(" : "));
  Serial.println(valuePhotoResNew);
  lcd.setCursor(7, 0);
  lcd.print(valueTMPNew, 1);
  lcd.setCursor(7, 1);
  lcd.print(valuePhotoResNew, 1);
  //lcd.clear(); // full clear LCD scren
}
