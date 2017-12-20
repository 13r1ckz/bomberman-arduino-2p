#include <avr/interrupt.h>
#include <avr/io.h>

int teller, currentTime; 
char pwmOn;

void setPWM38();
void setPWM56();
void setInterrupt();
void sendBit();
void sendStartBit();
void sendStopBit();
void sendPulse();


ISR(TIMER2_COMPB_vect){
	
}

ISR(TIMER1_OVF_vect) {		//macro met interrupt vector
	teller++;
	//PORTD ^= (1<<PORTD6);		//...toggle LED D6	
}

int main(void){

	Serial.begin(9600);
	
	//setPWM38();
	setInterrupt();
	setPWM56();
	
	while(1){
			sendStartBit();
			sendBit(1);
			sendBit(0);
			sendBit(0);
			sendBit(1);
			sendStopBit();	
	}
	//while(1);
	
}

void sendStartBit(){
	sendPulse();

	teller = 0;
	while(!(teller == 30)){
		Serial.println("Start");
	}
}

void sendStopBit(){
	sendStartBit();
	teller = 0;
	sendPulse();
}

void sendBit(char b){
	sendPulse();
	
	teller = 0;
	
	if(b == 1){
		while(!(teller == 20)){
			Serial.println("1");
		}
	} else {
		while(!(teller == 10)){
			Serial.println("0");
		}
	}
}

void sendPulse(){
	teller = 0;
	TCCR2A |= (1 << COM2B1);
	while(!(teller == 10)){
		Serial.println("pulse");
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
	  TCCR1B |= (1 << CS11);// | (1<<CS20);
	  TIMSK1 |= (1<<TOIE1);
	  TCNT1 = 0;
	  sei();
}

