/* 
* IRcom.h
*
* Created: 20-12-2017 12:20:23
* Author: wendy
*/
#include <Arduino.h>
#include <avr/interrupt.h>

#ifndef __IRCOM_H__
#define __IRCOM_H__

class IRcom {

//variables
public:
	uint8_t ontvangenbericht;
	int tempteller = 0;
	int startbit = 0;
	signed char bitteller = 7;
	char letter;
	int ontvangeraantal=0;
	int verschil;
protected:
private:
	int tellerzender = 0;
	int tellerontvanger = 0;

//functions
public:
	void setIR(); //zetten van timers en interrupts
	void sendByte(uint8_t command);//byte versturen
	
	//functies voor tellen
	void setTellerOntvanger(uint16_t teller);
	uint16_t getTellerOntvanger();
	void setTellerVerzender(uint16_t teller);
	uint16_t getTellerVerzender();
	
	
protected:
private:
	void sendBit(char b);
	void sendPulse();
	void sendStartBit();
	void sendStopBit();
	void setTimer();
	void setPWM56();
	void setInterrupt();
}; 

#endif //__IRCOM_H__
