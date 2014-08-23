/* 
	Editor: http://www.visualmicro.com
	        visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
	        the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
	        all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
	        note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Custom ATmega8 (16Mhz), Platform=avr, Package=MyCustomBoards
*/

#define __AVR_ATmega8__
#define ARDUINO 101
#define ARDUINO_MAIN
#define F_CPU 16000000L
#define __AVR__
#define __cplusplus
extern "C" void __cxa_pure_virtual() {;}

//
//
void NightLightFadeIn();
void NightLightFadeOut();
void delay_50ms();
void Tx();
void floatToStr(float toConvert);

#include "D:\Program Files (x86)\Arduino\hardware\MyCustomBoards\avr\variants\standard\pins_arduino.h" 
#include "D:\Program Files (x86)\Arduino\hardware\MyCustomBoards\avr\cores\arduino\arduino.h"
#include "D:\Dropbox\Dropbox\Apps\ArduinoDroid\SensorCLusterTransmitter\SensorCLusterTransmitter\SensorCLusterTransmitter.ino"
#include "D:\Dropbox\Dropbox\Apps\ArduinoDroid\SensorCLusterTransmitter\SensorCLusterTransmitter\MyClass.cpp"
#include "D:\Dropbox\Dropbox\Apps\ArduinoDroid\SensorCLusterTransmitter\SensorCLusterTransmitter\MyClass.h"
