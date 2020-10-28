// Бегущий поворотник

#include <Adafruit_NeoPixel.h>

#define PIN 4 // input pin for RGB led

#define NUMPIXELS 10 // count of leds

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

bool buttonFlag = false;

void setup()
{
  pinMode(3, INPUT);
  pixels.begin();
  attachInterrupt(1, setFlag, RISING); // (пин (вектор прерывания) 2 -> 0 3 -> 1, обработчик, режим прерывания)
  Serial.begin(9600);
}

void setFlag()
{
  buttonFlag = !buttonFlag;
  Serial.println(buttonFlag);
}  
  
void loop()
{
  while(buttonFlag == true)
  {
    for(int i = 0; i < NUMPIXELS; i++)
    {
      pixels.setPixelColor(i, pixels.Color(255, 100, 0));
      pixels.show();
      delay(50);
    }
    delay(5);
    for(int i = 0; i < NUMPIXELS; i++)
    {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      pixels.show();
      delay(50);
    }
  }
}
