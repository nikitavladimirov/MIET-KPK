#include <Servo.h>

Servo servo;

const int pinBtn = 4;

int btnCounter = 0;
int btnState = 0;
int lastBtnState = 0;
bool buttonFlag = false;
void setup()
{  
  pinMode(pinBtn, INPUT);
  
  servo.attach(9);
  servo.write(0);
  delay(500);
  Serial.begin(9600);
}

void loop()
{
  btnState = digitalRead(pinBtn);
  delay(100);
  
  if (btnState != lastBtnState) 
  {    
    if (btnState == HIGH && buttonFlag == false) 
    {
      writeServoValue(90);
      Serial.println("tuda");
    }
    else if(btnState == HIGH && buttonFlag == true)
    {
      writeServoValue(0);
      Serial.println("obratno");
    }  
    delay(5); 
  }
  
  lastBtnState = btnState;    

}

void writeServoValue(int value)
{
    buttonFlag = !buttonFlag; 
    servo.attach(9);
    servo.write(value);
    delay(2000);
    servo.detach();
}  
