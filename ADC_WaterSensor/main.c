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
u16 ADC ;
u16 volt;

u8 waterPrecent;
u16 waterResist;
f32 temp;
void main (void)
{
/*set port b & c to out to start lcd */

DIO_VidSetPortDir(DIO_PORTC,DIO_PORTOUTPUT);
DIO_VidSetPortDir(DIO_PORTB,DIO_PORTOUTPUT);

/*******************************************/

/*******************************************/
DIO_VidSetPinDir(DIO_PIN0,DIO_PORTA,DIO_INPUT); //ADC channel 0 as input
ADC_VidInit();
/*******************************************/
LCD_vidInit();
LCD_vidSendCommand(LCD_DISPON_CURSON);
LCD_vidWriteStr("Welcome to ");
LCD_vidRowCol(1,0);
LCD_vidWriteStr("Water Sensor");
_delay_ms(1000);
LCD_vidSendCommand(LCD_CLR);
LCD_vidWriteStr("Water percentage");
LCD_vidRowCol(1,0);
LCD_vidWriteStr(" is:");
LCD_vidRowCol(1,14);
LCD_vidWriteStr("%");

/*****************************************/
while(1)
{

ADC=ADC_u16GetADCRead(ADC_CH0);
volt =(u32)(ADC*(5000/1024));// getting volt in mv
LCD_vidRowCol(1,4);
volt/=1000;// mv to v
waterResist = (5000)*((5/volt)-1);//u16
temp=(waterResist/7545);// f32
waterPrecent = temp * 100;//u8
LCD_vidRowCol(1,10);
itos(waterResist);




}
}
