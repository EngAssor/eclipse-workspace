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
void snak(u16 adc)
{
if(adc>500&&adc <1000)
{
	DIO_VidSetPortVal(DIO_PORTD,0x01);
}
else if(adc>1000&&adc<1500)
{
	DIO_VidSetPortVal(DIO_PORTD,0x02);

}
else if(adc>1500&&adc<2000)
{
	DIO_VidSetPortVal(DIO_PORTD,0x04);

}
else if(adc>2000&&adc<2500)
{
	DIO_VidSetPortVal(DIO_PORTD,0x08);

}
else if(adc>2500&&adc<3000)
{
	DIO_VidSetPortVal(DIO_PORTD,0x10);

}
else if(adc>3000&&adc<3500)
{
	DIO_VidSetPortVal(DIO_PORTD,0x20);

}
else if(adc>3500&&adc<4000)
{
	DIO_VidSetPortVal(DIO_PORTD,0x40);

}
else if(adc>4000&&adc<4500)
{
	DIO_VidSetPortVal(DIO_PORTD,0x80);

}
}
u16 ADC ;
u16 volt;
void main (void)
{
DIO_VidSetPortDir(DIO_PORTC,DIO_PORTOUTPUT);
DIO_VidSetPortDir(DIO_PORTB,DIO_PORTOUTPUT);
DIO_VidSetPortDir(DIO_PORTD,DIO_PORTOUTPUT);


DIO_VidSetPinDir(DIO_PIN0,DIO_PORTA,DIO_INPUT); //ADC channel 0 as input
u16 arr[6];
LCD_vidInit();
LCD_vidSendCommand(LCD_DISPON_CURSON);
LCD_vidWriteStr("Welcome to ");
LCD_vidRowCol(1,0);
LCD_vidWriteStr("Voltameter V 1.0 ");
_delay_ms(1000);
ADC_VidInit();
LCD_vidSendCommand(LCD_CLR);
LCD_vidWriteStr("Voltage is : ");
LCD_vidRowCol(1,13);
LCD_vidWriteStr("mv");
while(1)
{

ADC=ADC_u16GetADCRead(ADC_CH0);
volt =(u32)(ADC*(5000/1024));
LCD_vidRowCol(1,4);
itos(volt,arr);
if (volt < 1000)
{
DIO_VidSetPinVal(DIO_PIN0,DIO_PORTD,DIO_HIGH);
}
else
{
	DIO_VidSetPinVal(DIO_PIN0,DIO_PORTD,DIO_LOW);

}



}
}
