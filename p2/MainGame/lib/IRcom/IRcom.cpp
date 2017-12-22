/* 
* IRcom.cpp
*
* Created: 20-12-2017 12:20:23
* Author: wendy
*/

#include "IRcom.h"

void IRcom::setIR(){
	setPWM56();
	setInterrupt();
	setTimer();
} 

void IRcom::sendByte(uint8_t command){	
	uint8_t temporaryCommand = command;
	
	sendStartBit();

	char i;	
	for(i = 0; i < 8; i++){
		if(temporaryCommand & (1<<7)){
			sendBit(1);
		} else {
			sendBit(0);
		}
		temporaryCommand <<= 1;
	}
	sendStopBit();
	TCCR2A |= (1 << COM2B1);	
} //~IRcom

void IRcom::setInterrupt(){
	DDRD &=~(1<<DDD2);
	PORTD |= (1<<PORTD2);
	EIMSK |= (1 << INT0);
	EICRA |= (1<<ISC01);
}

void IRcom::setPWM56(){
	TCCR2A =  (1 << COM2B1) | (1 << WGM21) | (1 << WGM20);
	TCCR2B = (1 << WGM22) | (1 << CS21); //Fast PWM & prescaler /8 - 16000000/8/36 / 55,5 KHz
	OCR2A = 35;
	OCR2B = 17;  // Duty Cycle 50%
	TIMSK2 |= (1<<OCIE2B);
	DDRD |= (1<<DDD3) ; //pin 3
}

void IRcom::setTimer(){
	TCCR1B |= (1 << CS10);
	TIMSK1 |= (1<<TOIE1);
	TCNT1 = 0;
	//sei();
}

void IRcom::sendBit(char b){
	sendPulse();
	setTellerVerzender(0);
	if(b == 1){
		while(!(getTellerVerzender() == 20)){
			Serial.print("");
		}
	} else {
		while(!(getTellerVerzender() == 10)){
			Serial.print("");
		}
	}
}

void IRcom::sendPulse(){
	setTellerVerzender(0);
	TCCR2A |= (1 << COM2B1);
	while(!(getTellerVerzender() == 10)){
		Serial.print("");
	}
	TCCR2A &= ~(1 << COM2B1);
}

void IRcom::sendStartBit(){
	sendPulse();
	setTellerVerzender(0);
	while(!(getTellerVerzender() == 30)){
		Serial.print("");
	}
}

void IRcom::sendStopBit(){
	sendStartBit();
	setTellerVerzender(0);
	sendPulse();
	sei();
}

//tellers

void IRcom::setTellerOntvanger(uint16_t teller){
	tellerontvanger = teller;
}

void IRcom::setTellerVerzender(uint16_t teller){
	tellerzender = teller;
}

uint16_t IRcom::getTellerOntvanger(){
	return tellerontvanger;
}

uint16_t IRcom::getTellerVerzender(){
	return tellerzender;
}

