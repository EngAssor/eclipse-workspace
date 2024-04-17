/*
 * main.c
 *
 *  Created on: Apr 7, 2021
 *      Author: pc1
 */

#include "LIB/typ.h"
#include "LIB/Bit_Math.h"
#include "DIO_interface.h"
#include "TimerInterface.h"
#include "LCD_interface.h"
#include <avr/interrupt.h>
#define  F_CPU   8000000UL
static const u8  secfirst[10]={'0','1','2','3','4','5','6','7','8','9'};
static const u8 scesecod[7]={'0','1','2','3','4','5','6'};
static const u8 minfirst[10]={'0','1','2','3','4','5','6','7','8','9'};
static const u8 minsecod[7]={'0','1','2','3','4','5','6'};
static const u8 hourfrist[9]={'1','2','3','4','5','6','7','8','9'};
static const u8 hoursecond[2]={'0','1'};
u8 daynight [2]={'A','P'};

u16 sec_counter;
u8 sec_count  ;

void main (void)

{
	// DIO TO LCD
	DIO_VidSetPortDir(DIO_PORTC,DIO_PORTOUTPUT);
	DIO_VidSetPortDir(DIO_PORTB,0xe0);
	/*************************************************/

// inti

	Timer_inti();
	LCD_vidInit();


	LCD_vidSendChar(hoursecond[0]);
	LCD_vidSendChar(hourfrist[0]);
	LCD_vidSendChar(':');
	LCD_vidSendChar(minsecod[0]);
	LCD_vidSendChar(minfirst[0]);
	LCD_vidSendChar(':');
	LCD_vidSendChar(scesecod[0]);
	LCD_vidSendChar(secfirst[0]);
	LCD_vidSendChar(':');
	LCD_vidSendChar(daynight[0]);
	LCD_vidSendChar('M');




	// looop
while(1)
{

}

}
 ISR(TIMER0_OVF_vect)
 {

sec_counter ++;
if (sec_counter== 3906)
{
	sec_counter=0;
	sec_count++;
TogelpinVal(DIO_PORTD,DIO_PIN2);
TCNT0=0;
}

 }
