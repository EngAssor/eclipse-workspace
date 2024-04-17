/*
 * Timerprog.c
 *
 *  Created on: Apr 7, 2021
 *      Author: pc1
 */

#include "LIB/typ.h"
#include "LIB/Bit_Math.h"
#include "Timerprv.h"

void Timer_inti(void)
{
	//  8  prescaler
	TCCR0|=(1<<CS01);
	// set counter to zero
		TCNT0=0;
		// Enable the interrupt
		TIMSK|=(1<<TOIE0);

}
void AVR_DelayMs_8MegaHZ(u16 NumINMs )
{

}
