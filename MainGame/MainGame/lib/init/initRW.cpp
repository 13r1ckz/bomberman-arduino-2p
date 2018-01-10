#include "initRW.h"

/*
Herschreven init functie
*/
initRW::init()
{
		// this needs to be called before setup() or some functions won't
		// work there
		sei();
		
		#if defined(TCCR0B) && defined(CS01) && defined(CS00)
		// this combination is for the standard 168/328/1280/2560
		sbi(TCCR0B, CS01);
		sbi(TCCR0B, CS00);
		#else
		#error Timer 0 prescale factor 64 not set correctly
		#endif

		// enable timer 0 overflow interrupt
		#if defined(TIMSK) && defined(TOIE0)
		sbi(TIMSK, TOIE0);
		#elif defined(TIMSK0) && defined(TOIE0)
		sbi(TIMSK0, TOIE0);
		#else
		#error	Timer 0 overflow interrupt not set correctly
		#endif	;

        TCCR1B = 0;

        // set timer 1 prescale factor to 64
        sbi(TCCR1B, CS11);
        sbi(TCCR1B, CS10);

        // put timer 1 in 8-bit phase correct pwm mode
        sbi(TCCR1A, WGM10);

        // set timer 2 prescale factor to 64
        sbi(TCCR2B, CS22);

        // configure timer 2 for phase correct pwm (8-bit)
        sbi(TCCR2A, WGM20);
		// set a2d prescale factor to 128
		// 16 MHz / 128 = 125 KHz, inside the desired 50-200 KHz range.
		// XXX: this will not work properly for other clock speeds, and
		// this code should use F_CPU to determine the prescale factor.
		sbi(ADCSRA, ADPS2);
		sbi(ADCSRA, ADPS1);
		sbi(ADCSRA, ADPS0);

		// enable a2d conversions
		sbi(ADCSRA, ADEN);
} //initRW

