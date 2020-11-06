// Датчик температуры TMP36 с выводом информации на LCD дисплей

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int startValue = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(A3, INPUT);
  startValue = analogRead(A3);
  lcd.setCursor(0, 0);
  lcd.print("Temp:     C");
  Serial.begin(9600);
}

void loop() {

  int value = analogRead(A3);
  float voltage = (value * 5.0/1024 - 0.5) * 100 ; // 0.5 is voltage offset on TMP36 temperature sensor
  Serial.print(value + String(":")); 
  Serial.println(voltage);
  
  lcd.setCursor(7, 0);
  lcd.print(voltage, 1);
}
