/* 
* initRW.cpp
*
* Created: 12/14/2017 2:27:42 PM
* Author: gerjo
*/


#include "initRW.h"

// default constructor
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
		#endif	
} //initRW

