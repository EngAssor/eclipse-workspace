/*
 * main.c
 *
 *  Created on: Feb 13, 2021
 *      Author: pc1
 */

#include "LIB/typ.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "ADC_interface.h"
#include <avr/delay.h>


void main (void)
{
DIO_VidSetPortDir(DIO_PORTC,DIO_PORTOUTPUT);
DIO_VidSetPortDir(DIO_PORTB,DIO_PORTOUTPUT);
DIO_VidSetPortDir(DIO_PORTD,DIO_PORTOUTPUT);

u16 ADC ;

DIO_VidSetPinDir(DIO_PIN0,DIO_PORTA,DIO_INPUT); //ADC channel 0 as input
u8 arr[5];
LCD_vidInit();

while(1)
{
ADC=ADC_u16GetADCRead(ADC_CH0);
itos(ADC,arr);
if (ADC > 500)
{
DIO_VidSetPinVal(DIO_PIN0,DIO_PORTD,DIO_HIGH);
}
else
{
	DIO_VidSetPinVal(DIO_PIN0,DIO_PORTD,DIO_LOW);

}




}
}
