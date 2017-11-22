/* 
	Editor: http://www.visualmicro.com
			visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
			the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
			all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
			note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Arduino/Genuino Uno, Platform=avr, Package=arduino
*/

#define __AVR_ATmega328p__
#define __AVR_ATmega328P__
#define ARDUINO 10801
#define ARDUINO_MAIN
#define F_CPU 16000000L
#define __AVR__
#define F_CPU 16000000L
#define ARDUINO 10801
#define ARDUINO_AVR_UNO
#define ARDUINO_ARCH_AVR
void init_adc_single_sample();
void init_pwm_fast();
void single_sample();
void mlevel1();
void mlevel2();
void mlevelRandom();
void mhighScore();
void characterA(int X, int Y);
void characterB(int X, int Y);
int navigate();
int Startscherm();
int level1();
int level2();
int levelRandom();
int highScore();
int main(void);

#include "pins_arduino.h" 
#include "Arduino.h"
#include "MainGame.ino"
