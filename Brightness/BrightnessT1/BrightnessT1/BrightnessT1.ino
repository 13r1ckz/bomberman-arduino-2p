#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <Wire.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>

#define BAUDRATE 9600

//Declare display !
MI0283QT9 lcd;  //MI0283QT9 Adapter v1

ISR(TIMER1_OVF_vect){
	

}

int main(void){ //arduino start
	init();
	Serial.begin(BAUDRATE);
	DDRC |= (1 << PORTC5);	/* Set all pins as input */
	int brichtnes;
	TCCR2A |= (1 << CS02) | (1 << CS00);
	TIMSK1 |= (1<<TOIE0);
	TCNT1 = 0;
	sei();						//	enable interrupts!
	
	//	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	uint8_t clear_bg=0x00; //0x80 = dont clear background for fonts (only for DisplayXXX)

	//init display
	lcd.begin();

	//clear screen
	lcd.fillScreen(RGB(255,255,255));
	
	while (1){//arduino loop		
		brichtnes = PINC3;
		Serial.print(brichtnes);		
	}
	return 0;
}
