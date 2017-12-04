#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

uint8_t ontvangenbericht= 0x00;
uint16_t tellerontvanger = 0;
uint16_t tempteller = 0;
int startbit = 0;
signed char bitteller = 7;
char letter;

ISR(TIMER1_OVF_vect) {//macro met interrupt vector
	tellerontvanger++;
}


ISR(INT0_vect){

	if((PIND &(1<<PIND2))){
		tellerontvanger = 0;
		Serial.println("test");
		} else {
		if ((tellerontvanger - tempteller) >= 40)
		{
			if(!startbit){
				//Serial.println("startbit");
				startbit = 1;
				}else{
				//Serial.println("stopbit");
				tellerontvanger = 0;
				startbit = 0;
			}
			tempteller=tellerontvanger;
		}else if ((tellerontvanger - tempteller)>=30)
		{	tempteller=tellerontvanger;
			//Serial.println("1");
			ontvangenbericht |=(1<<bitteller);
			bitteller--;			
		}
		else if((tellerontvanger - tempteller)>=20)
		{	tempteller=tellerontvanger;
			//Serial.println("0");
			ontvangenbericht &=~(1<<bitteller);
			bitteller--;	
		}
		
		//Serial.println(teller);
		if(bitteller == -1){
			bitteller =7;
			letter = ontvangenbericht;
		Serial.print(letter);
		}
	}
}


void timer() {
	TCCR1B |= (1 << CS10);
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
	Serial.begin(9600);
	timer();
	initInterrupt0();
	sei();
	while(1){
		Serial.print("");
		
	}
}

