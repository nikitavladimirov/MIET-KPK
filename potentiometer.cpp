// Потенциометр в связке с LCD дисплеем

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(A2, INPUT);
  // Print a message to the LCD.
  lcd.print("Value:       V");
  Serial.begin(9600);
}

void loop() {
  int inputValue = analogRead(A2);
  float voltage = inputValue * 5.0/1024;
  Serial.println(voltage);
  lcd.setCursor(8, 0);
  lcd.print(voltage);
}
