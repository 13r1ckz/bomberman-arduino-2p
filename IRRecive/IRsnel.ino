#include <avr/interrupt.h>
#include <avr/io.h>

//zender
int tellerZender;
//ontvanger
uint8_t ontvangenbericht= 0x00;
uint16_t tellerontvanger = 0;
uint16_t tempteller = 0;
uint8_t startbit = 0;
signed char bitteller = 7;
char letter;
int ontvangeraantal=0;
int verschil;
void setPWM38();
void setPWM56();
void setInterrupt();
void sendByte();
void sendBit();
void sendStartBit();
void sendStopBit();
void sendPulse();
void initInterrupt0();


ISR(TIMER2_COMPB_vect){
}

ISR(TIMER1_OVF_vect) {    //macro met interrupt vector
	tellerZender++;
	tellerontvanger++;
}

ISR(INT0_vect){

	verschil = tellerontvanger - tempteller;
	//Serial.println(verschil);
	
	if(startbit == 0){
		if(verschil >= 4){
			startbit = 1;
			//Serial.println("Startbit");
			ontvangeraantal++;
		}
	} else if (startbit == 1)
	
	{
		
		if(verschil >= 4){
			startbit = 0;
			//Serial.println("Stopbit");
			tellerontvanger = 0;
			tempteller = 0;
			ontvangeraantal++;
			} else if(verschil >= 3 && verschil <4){
			//Serial.print("1");
			ontvangenbericht |=(1<<bitteller);
			bitteller--;
			ontvangeraantal++;
			
			} else if(verschil >= 2 && verschil <3){
			//Serial.print("0");
			ontvangenbericht &=~(1<<bitteller);
			bitteller--;
			ontvangeraantal++;
			
		}
	}
	
	if(ontvangeraantal % 10 == 0){
		if(bitteller == -1){
			bitteller =7;
			letter = ontvangenbericht;
			Serial.print(letter);
			ontvangenbericht = 0x00;
			}else{
			bitteller =7;
			ontvangenbericht = 0x00;
		}
	}
	tempteller = tellerontvanger;
}
int main(void){
	Serial.begin(9600);
	//setPWM38();
	setInterrupt();
	setPWM56();
	initInterrupt0();
	while(1){
		if(Serial.available()){
			char letter = Serial.read();
			sendByte(letter);
		}
	}
}

void sendByte(uint8_t command){
	uint8_t temporaryCommand = command;
	sendStartBit();
	char i;
	//Serial.println(temporaryCommand, BIN);
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
}

void sendStartBit(){
	sendPulse();
	tellerZender = 0;
	while(!(tellerZender == 3)){
		Serial.print("");
	}
}

void sendStopBit(){
	sendStartBit();
	tellerZender = 0;
	sendPulse();
}

void sendBit(char b){
	sendPulse();
	tellerZender = 0;
	if(b == 1){
		while(!(tellerZender ==2)){
			Serial.print("");
		}
		} else {
		while(!(tellerZender == 1)){
			Serial.print("");
		}
	}
}

void sendPulse(){
	tellerZender = 0;
	TCCR2A |= (1 << COM2B1);
	while(!(tellerZender == 1)){
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
}

void setPWM56(){
	TCCR2A =  (1 << COM2B1) | (1 << WGM21) | (1 << WGM20);
	TCCR2B = (1 << WGM22) | (1 << CS21); //Fast PWM & prescaler /8 - 16000000/8/36 / 55,5 KHz
	OCR2A = 35;
	OCR2B = 17;  // Duty Cycle 50%
	TIMSK2 |= (1<<OCIE2B);
	DDRD |= (1<<DDD3) ; //pin 3
}

void setInterrupt(){
	TCCR1B |= (1 << CS10);
	TIMSK1 |= (1<<TOIE1);
	TCNT1 = 0;
	sei();
}

void initInterrupt0()
{
	DDRD &=~(1<<DDD2);
	PORTD |= (1<<PORTD2);
	EIMSK |= (1 << INT0);
	EICRA |= (1<<ISC01);
	
}