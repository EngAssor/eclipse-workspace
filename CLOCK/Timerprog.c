/*
 * Timerprog.c
 *
 *  Created on: Apr 7, 2021
 *      Author: pc1
 */

#include "LIB/typ.h"
#include "LIB/Bit_Math.h"
#include "Timerprv.h"
#include <avr/interrupt.h>
static const u8  secfirst[11]={'0','1','2','3','4','5','6','7','8','9'};
static const u8 scesecod[7]={'0','1','2','3','4','5','6'};
static const u8 minfirst[10]={'0','1','2','3','4','5','6','7','8','9'};
static const u8 minsecod[7]={'0','1','2','3','4','5','6'};
static const u8 hourfrist[9]={'1','2','3','4','5','6','7','8','9'};
static const u8 hoursecond[2]={'0','1'};
static const u8 daynight [2]={'A','P'};

void Timer_inti(void)
{
	//  8  prescaler
	TCCR0|=(1<<CS01);
	// set counter to zero
		TCNT0=0;
		// Enable the interrupt
		TIMSK|=(1<<TOIE0);
		// Enable the global interrupt
		SET_BIT(SREG,7);
}
void AVR_DelayMs_8MegaHZ(u16 NumINMs )
{

}
