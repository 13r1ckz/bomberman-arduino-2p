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
	DDRB |= (1<<DDB3);
	Serial.begin(9600);
	while(1)
	{
		single_sample();
		OCR2A = step;
		Serial.println(step);
		_delay_ms(10);
	}
	
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
