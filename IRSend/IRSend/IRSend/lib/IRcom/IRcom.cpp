/*
* IRcom.cpp
*
* Created: 20-12-2017 12:20:23
* Author: Arend & Wendy
*/

#include "IRcom.h"

/*
In deze functie wordt het infrarood aangezet door middel van 3 functies aan te roepen
*/
void IRcom::setIR(){
	setPWM56();						//De PWM wordt ingesteld op 56kHz
	setInterrupt();                 //De interrupt wordt aangezet
	setTimer();						//De timer wordt aangezet
}

/*
In deze functie wordt een byte verstuurd met infrarood
*/
void IRcom::sendByte(uint8_t command){
	uint8_t temporaryCommand = command;
	
	//Een startbit versturen om de ontvanger te laten weten dat er een byte aankomt
	sendStartBit();
	
	char i;
	for(i = 0; i < 8; i++){
		if(temporaryCommand & (1<<7)){       //controleer of de MSB gelijk is aan 1
			sendBit(1);
			} else {
			sendBit(0);
		}
		temporaryCommand <<= 1;				//Schuif alle bitjes 1 plek naar rechts
	}
	
	//Een stopbit versturen zodat de ontvanger weet dat de byte gestuurd is
	sendStopBit();
	
	//Het infrarood ledje wordt aangezet
	TCCR2A |= (1 << COM2B1);
}

/*
In deze functie wordt de interrupt aangezet voor het ontvangen van het infrarood
*/
void IRcom::setInterrupt(){
	DDRD &=~(1<<DDD2);						//Zet pin 2 als input
	PORTD |= (1<<PORTD2);					//Activeer de interne pull-up
	EIMSK |= (1 << INT0);					//Zet INT0 aan
	EICRA |= (1<<ISC01);					//Zet de interrupt op elke neergaande flank
}

/*
In deze functie wordt de PWM voor 56kHz ingesteld
*/
void IRcom::setPWM56(){
	TCCR2A =  (1 << COM2B1) | (1 << WGM21) | (1 << WGM20);//Leeg OCR2B op compare match
	TCCR2B = (1 << WGM22) | (1 << CS21);      //Fast PWM & prescaler /8 - 16000000/8/36 / 55,5 KHz
	OCR2A = 35;
	OCR2B = 17;								// Duty Cycle 50%
	TIMSK2 |= (1<<OCIE2B);					//Output Compare B Match Interrupt Enable
	DDRD |= (1<<DDD3) ;						//pin 3 als output
}

/*
In deze functie wordt de timer ingesteld voor het zenden en ontvangen
*/
void IRcom::setTimer(){
	TCCR1B |= (1 << CS10);					//Geen prescaler
	TIMSK1 |= (1<<TOIE1);					//Timer overflow enable
	TCNT1 = 0;
}
/*
In deze functie wordt een bit verstuurd
*/
void IRcom::sendBit(char b){
	sendPulse();							//Er wordt een korte puls gestuurd
	setTellerVerzender(0);					//De teller wordt op nul gezet
	if(b == 1){								//Is de meegegeven bit een 1 of een 0
		while(!(getTellerVerzender() == 20)){    //Wacht tot de teller 20 is
			_delay_ms(1);
		}
		} else {
		while(!(getTellerVerzender() == 10)){    //Wacht tot de teller 10 is
			_delay_ms(1);
		}
	}
}
/*
In deze functie wordt er een puls gestuurd
*/
void IRcom::sendPulse(){
	setTellerVerzender(0);
	
	TCCR2A |= (1 << COM2B1);					//Zet de poort aan
	while(!(getTellerVerzender() == 10)){		//Wacht tot de teller 10 is
		_delay_ms(1);
	}
	TCCR2A &= ~(1 << COM2B1);					//Zet de poort uit
}

/*
In deze functie wordt er een startbit gestuurd
*/
void IRcom::sendStartBit(){
	sendPulse();								//Er wordt een puls gestuurd
	setTellerVerzender(0);
	while(!(getTellerVerzender() == 30)){      //Wacht tot de teller 30 is
		_delay_ms(1);
	}
}

/*
In deze functie wordt er een stopbit gestuurd
*/
void IRcom::sendStopBit(){
	sendStartBit();
	setTellerVerzender(0);
	sendPulse();
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

