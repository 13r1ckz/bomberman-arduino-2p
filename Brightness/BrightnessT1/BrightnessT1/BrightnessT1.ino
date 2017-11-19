#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <EEPROM.h>
#include <Wire.h>
#include <SPI.h>
#include <SoftwareSerial.h>
#include <digitalWriteFast.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <DisplaySPI.h>
#include <DisplayUART.h>
#include <DisplayI2C.h>

MI0283QT9 lcd;  //MI0283QT9 Adapter v1

int step;
void init_adc_single_sample()
{
	ADMUX |= (1<<MUX0);		// input analog A1 Arduino
	ADMUX |= (1<<REFS0);	// 5 volt
	ADCSRA = (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); // clock/128
	ADCSRA |= (1<<ADEN);	// ADC enable
}
void init_pwm_fast()
{
	TCCR2A |= (1<<COM0A1);					// Non-inverting mode A
	TCCR2A |= (1 << WGM01) | (1 << WGM00);	// set fast PWM Mode
	TCCR2B |= (1 << CS01);					// set prescaler to 8 and start the timer
}

void single_sample()
{
	uint8_t bricht;
	uint16_t result;
	ADCSRA |= (1<<ADSC);		// Start conversion
	while(ADCSRA & (1<<ADSC)) ;	// Wait
	result = ADC;
	step = (result >> 2);
	
	Serial.print("input ");
	Serial.println(result >> 2);
	bricht = map((result >> 2), 0, 255, 0, 100);
	Serial.print("remap ");
	Serial.println(bricht);
	lcd.led(bricht);

}

int main(void)
{
	init();
	DDRB |= (1<<DDB3);
	Serial.begin(9600);
	lcd.begin();
	init_adc_single_sample();
	init_pwm_fast();
	//clear screen
	lcd.fillScreen(RGB(255,255,255));
	
	while(1)
	{
		single_sample();
	}
}