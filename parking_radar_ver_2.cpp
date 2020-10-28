// Парковочный радар
//
// Сравнение с порогом разбито на 2 части для left и right УЗ дальномеров
//
const int sonarPinSig = 13;

const int sonarPinTrig = 5;
const int sonarPinEcho = 4;

const int pinLeft = 12;
const int pinRight = 8;

void setup()
{
  pinMode(sonarPinTrig, OUTPUT);
  pinMode(sonarPinEcho, INPUT);
  pinMode(pinLeft, OUTPUT);
  pinMode(pinRight, HIGH);
  
  digitalWrite(pinRight, LOW);
  digitalWrite(pinLeft, LOW);
  
  Serial.begin(9600);
}

void loop()
{
  int distanceRight = sonarPinFour();
  int distanceLeft = sonarPinThree();
  if(distanceRight < 40)
  {
    tone(9, 400);
    digitalWrite(pinRight, HIGH);
  }
  else
  {
    noTone(9); 
    digitalWrite(pinRight, LOW);
  }
  if(distanceLeft < 40)
  {
    tone(9, 500);
    digitalWrite(pinLeft, HIGH);
  }
  else
  {
    noTone(9);
    digitalWrite(pinLeft, LOW);
  }
  Serial.println(String("left: ") + distanceLeft + String(" cm, right: ") + + distanceRight + String(" cm"));
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

int sonarPinFour()
{
  int duration, cm;
  
  digitalWrite(sonarPinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(sonarPinTrig, HIGH);
  delayMicroseconds(5);
  digitalWrite(sonarPinTrig, LOW);

  duration = pulseIn(sonarPinEcho, HIGH);

  cm = microsecondsToCentimeters(duration);

  delay(100);
  
  return cm;
}

int sonarPinThree()
{
  int duration, cm;
  
  pinMode(sonarPinSig, OUTPUT);
  digitalWrite(sonarPinSig, LOW);
  delayMicroseconds(2);
  digitalWrite(sonarPinSig, HIGH);
  delayMicroseconds(5);
  digitalWrite(sonarPinSig, LOW);
  
  pinMode(sonarPinSig, INPUT);
  duration = pulseIn(sonarPinSig, HIGH);

  cm = microsecondsToCentimeters(duration);

  delay(100);
  
  return cm;
}
