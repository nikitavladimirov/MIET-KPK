// Автомобильные фары

int buttonState = 0; 
int buttonStateLast = 0;  
int buttonCounter = 0;  

void setup() 
{   
	pinMode(13, OUTPUT);   
	pinMode(9, OUTPUT);      
	pinMode(4, INPUT);      
	Serial.begin(9600); 
}  

void loop() {   
	buttonState = digitalRead(4);   
	if(buttonState != buttonStateLast)   
	{
		if(buttonState == HIGH)     
		{       
			buttonCounter++;       
			Serial.print("number of pushes: ");       
			Serial.println(buttonCounter);     
		}   
	}      
	if(buttonCounter > 2)  
		buttonCounter = 0;      

	if(buttonCounter == 0)
	{     
		analogWrite(9, 0);
	}
	if(buttonCounter == 1)
	{
		analogWrite(9, 128);
	}
	if(buttonCounter == 2)
	{
		analogWrite(9, 255);
	}

	buttonStateLast = buttonState;
}
