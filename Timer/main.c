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
#include <avr/interrupt.h>
#define  F_CPU   8000000UL
u16 count = 0;
u16 count_green=2;
u16 count_yellow =3 ;
u16 count_red =4 ;
void main (){
// inti

	Timer_inti();
	DIO_VidSetPortDir(DIO_PORTD,DIO_PORTOUTPUT);
	// Enable the global interrupt
		SET_BIT(SREG,7);

	// looop
	while(1)
	{

	}
}
ISR(TIMER0_OVF_vect)
{
count ++;

if (count== 1953)
{
	if(count_green ==0)
	{
		TogelpinVal(DIO_PORTD,DIO_PIN0);
		count_green = 2;
	}
	else
	{
		count_green --;
	}
	if(count_yellow ==0)
		{
			TogelpinVal(DIO_PORTD,DIO_PIN1);
			count_yellow = 3;
		}
		else
		{
			count_yellow--;
		}
	if(count_red ==0)
		{
			TogelpinVal(DIO_PORTD,DIO_PIN2);
			count_red = 4;
		}
		else
		{
			count_red--;
		}
}

}
