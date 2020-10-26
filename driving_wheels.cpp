//Имитация работы ведущих колёс автомобиля

const int pinBtnPlus = 8;
const int pinBtnMinus = 9;
const int pinMotor = 6;

int btnCounter = 0;
int btnStatePlus = 0;
int btnStateMinus = 0;

int lastBtnStatePlus = 0;
int lastBtnStateMinus = 0;

void setup()
{
  pinMode(pinBtnPlus, INPUT);
  pinMode(pinBtnMinus, INPUT);
  
  pinMode(pinMotor, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  btnStatePlus = digitalRead(pinBtnPlus);
  btnStateMinus = digitalRead(pinBtnMinus);
  
  delay(100);
  
  if ((btnStatePlus != lastBtnStatePlus) || (btnStateMinus != lastBtnStateMinus))
  {
    if (btnStatePlus == HIGH)
    {
      btnCounter++;
    }
    if (btnStateMinus == HIGH)
    {
      btnCounter--;
    }
  }
  
  lastBtnStatePlus = btnStatePlus;
  lastBtnStateMinus = btnStateMinus;
  
  Serial.println(btnCounter);
  setTransmissionValue(btnCounter);
}

void setTransmissionValue(int &value)
{
  if(value > 6) value = 6;
  if(value < 0) value = 0;
  
  switch(value){
  	case 0:
  	 	analogWrite(pinMotor,0);
  		break;
  	case 1:
  		analogWrite(pinMotor,36);
  		break;
  	case 2:
  		analogWrite(pinMotor,72);
  		break;
  	case 3:
  		analogWrite(pinMotor,108);
  		break;
  	case 4:
  		analogWrite(pinMotor,144);
  		break;
  	case 5:
  		analogWrite(pinMotor,180);
  		break;
  	case 6:
  		analogWrite(pinMotor,216);
  		break;
  }
}
