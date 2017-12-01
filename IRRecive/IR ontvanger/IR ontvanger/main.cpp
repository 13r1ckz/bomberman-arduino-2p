#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

uint8_t command= 0x00;
uint16_t teller = 0;
uint16_t tempteller = 0;
int recievedPulse = 1;
int startbit = 0;
int stopbit = 0;

ISR(TIMER1_OVF_vect) {//macro met interrupt vector
	teller++;
}


ISR(INT0_vect){

	
	if((PIND &(1<<PIND2))){
		
		teller = 0;

		} else {
		if ((teller - tempteller) >= 40)
		{
			
			if(!startbit){
				Serial.println("startbit");
				startbit = 1;
				}else{
				Serial.println("stopbit");
				teller = 0;
				startbit = 0;
				
			}
			tempteller=teller;
			
		}else if ((teller - tempteller)>=30)
		{	tempteller=teller;
			Serial.println("1");
		}
		else if((teller - tempteller)>=20)
		{	tempteller=teller;
			Serial.println("0");
		}
		//Serial.println(teller);
	}
}


void timer() {
	TCCR1B |= (1 << CS11);
	TIMSK1 |= (1<<TOIE1);
	TCNT1 = 0;
}
void initInterrupt0()
{
	DDRD &=~(1<<DDD2);
	PORTD |= (1<<PORTD2);
	EIMSK |= (1 << INT0);
	EICRA |= (1<<ISC01);

}



int main(void){
	DDRD  |=(1<<DDD4);
	DDRD  |=(1<<DDD6);
	//init();
	Serial.begin(9600);
	timer();
	initInterrupt0();
	sei();
	while(1){
		Serial.print("");
	}
}
