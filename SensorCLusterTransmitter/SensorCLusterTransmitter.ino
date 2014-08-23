#include <VirtualWireTxShrunk.h>
#include <EEPROM.h>
#include <dht.h>
#include <avr/io.h>
#undef int
#undef abs
#undef double
#undef float
#undef round
#define lightSensor A5
#define DHT22_PIN A1
#define MotionPin A2 //PORTC Pin 2 or 
#define NightLightPin 11

//#define EmergLightPin 5


//EEPROM Address for entries
int txDelayAddr = 0;
int nightLtDelayAddr = 1;
int sensorNameAddr = 2; //In hex, will translate else where untill reliable eeprom string entry can be found.



float CTemp = 0, CurrentTemp = 0, humid = 0;
char message[26];
int lightData = 0;
int currentNightLightBrightness = 0;
bool nightLightWakeingInProgress, nightLightDimmingInProgress, nightLightOnBool = 0;
const char ID[] = "OUTSIDE:"; // 7 chars
char sendBuffer[14];
uint8_t motionSense = 0; 
char convertBuf[24];
//int strNameLength = 0;
unsigned long nightLightOnTime = 0;
unsigned long nightLightOnDelay = 15000UL; //Night Stays on for 15 Sec unless motion continues to trigger.

//char inChar;
//char DevNameArray[14];
//byte index = 0;
//int curPosition = 1;
unsigned long lastFadeingIncTime = 0;
unsigned long fadeInterval = 20UL;
unsigned long brodcastDelay = 60000UL; //Broadcasts only once every 60sec, WIll adjust once sleep mode is being used.
unsigned long motionIgnoreDelay = 2000UL;
unsigned long lastMotionDetect = 0;
unsigned long lastBrodcast = 0;
int maxNightLightBright = 120;

//volatile int state = LOW;
//need to add to custom virtual wire library
//
// void blink()
//{
//  state = !state;
//}


dht DHT;

//void blink()
//{
	//state = !state;
	////digitalWrite(13, state);
//}

void setup()
{
	pinMode(lightSensor,INPUT);
	pinMode(DHT22_PIN,INPUT);
	pinMode(MotionPin, INPUT);
	pinMode(NightLightPin, OUTPUT);
	//pinMode(EmergLightPin, OUTPUT);
	vw_setup(1500);	 // Bits per sec	
	//attachInterrupt(12, blink, CHANGE); //added for possible data tx light
	delay(100);
	int txDelayTMP = EEPROM.read(txDelayAddr);
	int nightLtDelayTMP = EEPROM.read(nightLtDelayAddr);
	int SensorNameValueTMP = EEPROM.read(sensorNameAddr);
	
	
	if (txDelayTMP != 0xFF)
	{
		sprintf(message,"%s:TXDEL:%d",ID,txDelayTMP);
		Tx();
		Tx();
		brodcastDelay = txDelayTMP * 1000UL;
	}
	else
	{
		EEPROM.write(txDelayAddr, (brodcastDelay / 1000));
	}
	
	if (nightLtDelayTMP != 0xFF)
	{
		sprintf(message,"%s:NLDEL:%d",ID,nightLtDelayTMP);
		Tx();
		Tx();
		nightLightOnDelay = nightLtDelayTMP * 1000UL;
	}
	else
	{
		EEPROM.write(nightLtDelayAddr, (nightLightOnDelay / 1000));		
	}
	lastBrodcast = millis();
	
	//analogWrite(NightLightPin, 80);
}

void loop()
{

	//Will change the name of the device for transmission
	//  while(Serial.available() > 0) // Don't read unless
	//   {
	//   if(index < 13) // One less than the size of the array
	//     {
	//     inChar = Serial.read(); // Read a character
	//    DevNameArray[index] = inChar; // Store it
	//    index++; // Increment where to write next
	//   DevNameArray[index] = '\0'; // Null terminate the string
	//     }
	//  }

	//  if(DevNameArray[0] != 0)
	//   {
	//First byte is index count of following data
	// EEPROM.write(0,index);
	//Writes new name to EEPROM
	//    while(*DevNameArray)
	//    {
	//    EEPROM.write(curPosition,DevNameArray[curPosition]);
	//     }
	//  curPosition++;

	//   }
	motionSense = 0;
	if(PINC & (1<<2))
	{
		motionSense = 1;
	}
	
	//motionSense = digitalRead(MotionPin);
	//delay_50ms();
	if (motionSense && millis() - lastMotionDetect >= motionIgnoreDelay)
	{
		lastMotionDetect = millis();
		sprintf(message,"%s:M:%d",ID,motionSense);		
		Tx();
		Tx();
		Tx();
		Tx();
		
	}
	lightData = analogRead(lightSensor);


	if (millis() - lastBrodcast >= brodcastDelay)
	{
		lastBrodcast = millis();
		DHT.read22(DHT22_PIN);
		delay_50ms();
		CTemp = DHT.temperature;
		humid = DHT.humidity;
				
		delay_50ms();

		CurrentTemp = (CTemp * 1.8) + 32;

		//Transmit Celcius
		floatToStr(CTemp);
		sprintf(message,"%s:C:%s",ID, convertBuf);
		Tx();
		Tx();
		Tx();
		Tx();
		
		//Transmit Farinhieght		
		floatToStr(CurrentTemp);
		sprintf(message,"%s:F:%s",ID, convertBuf );
		Tx();
		Tx();
		Tx();
		Tx();
		

		//Transmit humidity		
		floatToStr(humid);
		sprintf(message,"%s:H:%s",ID, convertBuf );
		Tx();
		Tx();
		Tx();
		Tx();
		

		//Transmit light
		lightData = analogRead(lightSensor);		
		sprintf(message,"%s:L:%d",ID, lightData );
		Tx();
		Tx();
		Tx();
		Tx();
		

		//Transmit Motion
		//motionSense = digitalRead(MotionPin);
		motionSense = 0;
		if(PINC & (1<<2))
		{
			motionSense = 1;
		}
		sprintf(message,"%s:M:%d",ID,motionSense);
		Tx();
		Tx();
		Tx();
		Tx();

	}
	
	lightData = analogRead(lightSensor);
	if (lightData < 25 && motionSense)
	{
		//And has wall power
		if (lastFadeingIncTime == 0)
		{
			lastFadeingIncTime = millis();
		}
		NightLightFadeIn();
	}

	//Light Function Section--------------------------------------
	//Light turning ON
	if (nightLightWakeingInProgress == 1 && millis() - lastFadeingIncTime >= fadeInterval)
	{
		nightLightDimmingInProgress = 0;
		if (currentNightLightBrightness < maxNightLightBright)
		{
			currentNightLightBrightness = currentNightLightBrightness + 1;
			if (currentNightLightBrightness > maxNightLightBright)
			{
				currentNightLightBrightness = maxNightLightBright;
			}
			analogWrite(NightLightPin, currentNightLightBrightness);
			lastFadeingIncTime = millis();

		}
		if (currentNightLightBrightness >= maxNightLightBright)
		{
			lastFadeingIncTime = 0;
			nightLightWakeingInProgress = 0;
			nightLightOnTime = millis();
			//nightLightOnBool = 1;
		}
	}

	//Light turning OFF
	if (nightLightDimmingInProgress == 1  && millis() - lastFadeingIncTime >= fadeInterval)
	{
		nightLightWakeingInProgress = 0;
		if (currentNightLightBrightness > 0)
		{
			nightLightOnTime = 0;
			--currentNightLightBrightness;
			analogWrite(NightLightPin, currentNightLightBrightness);
			lastFadeingIncTime = millis();
		}
		if (currentNightLightBrightness <= 0)
		{
			lastFadeingIncTime = 0;
			nightLightDimmingInProgress = 0;
			//nightLightOnBool = 0;
		}
	}

	if (nightLightOnTime != 0 && millis() - nightLightOnTime >= nightLightOnDelay)
	{
		if (lastFadeingIncTime == 0)
		{
			lastFadeingIncTime = millis();
		}
		NightLightFadeOut();
	}
}

void NightLightFadeIn()
{
	nightLightWakeingInProgress = 1;
	nightLightDimmingInProgress = 0;
}

void NightLightFadeOut()
{
	nightLightDimmingInProgress = 1;
	nightLightWakeingInProgress = 0;
}

void delay_50ms()
{
	delay(50);
}

void Tx()
{
	vw_send((uint8_t *)message, strlen(message));
	vw_wait_tx();		
}

void floatToStr(float toConvert)
{
	int temp1 = (int)toConvert;
	float decimalNum = toConvert - temp1;
	int decToInt = decimalNum * 100.0; // For two decimal points	
	sprintf(convertBuf, "%d.%d", temp1,decToInt);
	
}
