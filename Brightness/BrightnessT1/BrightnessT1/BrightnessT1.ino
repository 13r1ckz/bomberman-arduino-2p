#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
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
	uint16_t result;
	ADCSRA |= (1<<ADSC);		// Start conversion
	while(ADCSRA & (1<<ADSC)) ;	// Wait
	result = ADC;
	step = (result >> 2);
	
	Serial.println(result >> 2);
}

int main(void)
{
	init();
	DDRB |= (1<<DDB3);
	Serial.begin(9600);
	init_adc_single_sample();
	init_pwm_fast();
	while(1)
	{
		single_sample();
		//OCR2A = step;
		//Serial.println(step);
		//_delay_ms(10);
	}
}