#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <SPI.h>
#include <SoftwareSerial.h>
#include <digitalWriteFast.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>

MI0283QT9 lcd;  //MI0283QT9 Adapter v1





int main(void)
{
	init();
	DDRB |= (1<<DDB3);
	Serial.begin(9600);
	lcd.begin();
	init_adc_single_sample();
	//clear screen
	lcd.fillScreen(RGB(255,255,255));
	
	while(1)
	{
		single_sample();
	}
}