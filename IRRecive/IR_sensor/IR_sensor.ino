#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdint.h>

int count=0;
uint8_t bit = 0xFF;
uint8_t teller = 0;

ISR(TIMER1_OVF_vect) {	//macro met interrupt vector
	teller++;
	if ( teller >= 1)			//bij elke 60e interrupt ...
	{
		PORTD ^= (1<<PORTD6);		//...toggle LED D6
		teller = 0;
	}
}

ISR(INT1_vect){
	if(PIND & (1<<PIND3)){
		//Serial.println("1");
		count++;
		}else{
		//Serial.println("0");
		bit &=~(1<<count);
		count++;
		
	}
}


void timer() {
	DDRD |=(1<<DDD6);

	TIMSK1 |=(1<<0);// enabled global and timer overflow interrupt;
	TCCR1A = 0; // normal operation page 148 (mode0);
	TCNT1 = 0; // 16bit counter register
	TCCR1B |=(1<<1) | (1<<0);// start timer/ set clock
}
void initInterrupt0()
{
	DDRD &=~(1<<DDD3);
	PORTD |= (1<<PORTD3);
	EIMSK |= (1 << INT1);
	EICRA |= (1<<ISC10);

}

unsigned char reverse(unsigned char b) {
	b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
	b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
	b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
	Serial.print("R");
	Serial.println(b,BIN);
}

int main(void){
	DDRD  |=(1<<DDD4);
	DDRD  |=(1<<DDD6);
	init();
	Serial.begin(9600);
	timer();
	initInterrupt0();
	
	sei();
	int i;
	int j;
	while(1){
		
		_delay_ms(100);
		for(i=0;i<6;i++){
			PORTD |=(1<<PORTD4);
			_delay_ms(100);
			PORTD &=~(1<<PORTD4);
			_delay_ms(0.0000000002);
		}
		for(j=0;j<2;j++){
			PORTD |=(1<<PORTD4);
			_delay_ms(0.00000002);
			PORTD &=~(1<<PORTD4);
			_delay_ms(100);
		}
		reverse(bit);
		Serial.print("M");
		Serial.println(bit,BIN);
	
		
	}
}

