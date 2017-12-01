#include <avr/interrupt.h>
#include <avr/io.h>

int teller, currentTime;
char pwmOn;

void setPWM38();
void setPWM56();
void setInterrupt();
void sendByte();
void sendBit();
void sendStartBit();
void sendStopBit();
void sendPulse();


ISR(TIMER2_COMPB_vect){
	
}

ISR(TIMER1_OVF_vect) {		//macro met interrupt vector
	teller++;
	//Serial.println(teller);
	//PORTD ^= (1<<PORTD6);		//...toggle LED D6
}

int main(void){

	Serial.begin(9600);
	
	//setPWM38();
	setInterrupt();
	setPWM56();
	
	//_delay_ms(500);
	
	while(1){
		
		if(Serial.available()){
			if(Serial.read() == 's'){
				sendByte('q');
			}
		}
		//sendPulse();
		//_delay_ms(500);
	}
	//while(1);
	
}

void sendByte(uint8_t command){
	uint8_t temporaryCommand = command;
	sendStartBit();
	int i;
	
	for(i = 0; i < 8; i++){
		Serial.print("--");
		Serial.println(temporaryCommand, BIN);
		
		if(temporaryCommand & (1<<7)){
			sendBit(1);
			} else {
			sendBit(0);
		}
		temporaryCommand <<= 1;
	}
	sendStopBit();
}

void sendStartBit(){
	TCCR2A &= ~(1 << COM2B1);
	
	sendPulse();

	teller = 0;
	while(!(teller == 30)){
		Serial.print("");
	}
}

void sendStopBit(){
	sendStartBit();
	teller = 0;
	sendPulse();
	TCCR2A |= (1 << COM2B1);
}

void sendBit(char b){
	sendPulse();
	
	teller = 0;
	
	if(b == 1){
		while(!(teller == 20)){
			Serial.print("");
		}
		} else {
		while(!(teller == 10)){
			Serial.print("");
		}
	}
}

void sendPulse(){
	teller = 0;
	TCCR2A |= (1 << COM2B1);
	while(!(teller == 10)){
		Serial.print("");
	}
	TCCR2A &= ~(1 << COM2B1);
}

void setPWM38(){
	TCCR2A =  (1 << COM2B1) | (1 << WGM21) | (1 << WGM20);
	TCCR2B = (1 << WGM22) | (1 << CS21); //Fast PWM & prescaler /8 - 16000000/8/52 / 38,4 KHz
	OCR2A = 51;
	OCR2B = 26;  // Duty Cycle 50%
	TIMSK2 |= (1<<OCIE2B);

	DDRD |= (1<<DDD3) ; //pin 3
	pwmOn = 1;
}

void setPWM56(){
	TCCR2A =  (1 << COM2B1) | (1 << WGM21) | (1 << WGM20);
	TCCR2B = (1 << WGM22) | (1 << CS21); //Fast PWM & prescaler /8 - 16000000/8/36 / 55,5 KHz
	OCR2A = 35;
	OCR2B = 17;  // Duty Cycle 50%
	TIMSK2 |= (1<<OCIE2B);

	DDRD |= (1<<DDD3) ; //pin 3
	pwmOn = 1;
}

void setInterrupt(){
	DDRD |= (1<<DDD6);		//setup (digital pen 6 = PD6)
	TCCR1B |= (1 << CS11);
	TIMSK1 |= (1<<TOIE1);
	TCNT1 = 0;
	sei();
}

