/*
 * LCD_prog.c
 *
 *  Created on: Jan 23, 2021
 *      Author: pc1
 */

#include "LIB\typ.h"
#include <avr\delay.h>
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_prv.h"



void LCD_vidInit(void)
{
//delay for 30 ms to ensure LCD uc initialization
_delay_ms(30);
// set the LCD  8bit data , 2-line display , 5x7 font*/
LCD_vidSendCommand(LCD_FUNCSET_8BIT);

_delay_ms(1);
//display on/off
LCD_vidSendCommand(LCD_DISPON_CURSOFF);
_delay_ms(15);

//return home (return cursor to the first position)
LCD_vidSendCommand(LCD_HOME);
_delay_ms(15);
// enter set command (shift cursor from left to right on read/write)
LCD_vidSendCommand(LCD_ENTRYMODE);
_delay_ms(2);

}
void LCD_vidSendCommand(u8 u8Cmd)
{
	// clear RS pin
DIO_VidSetPinVal(LCD_RS_PIN,LCD_CONTROL_PORT,DIO_LOW);
// clear RW pin
DIO_VidSetPinVal(LCD_RW_PIN,LCD_CONTROL_PORT,DIO_LOW);
// Set enable pin to high
DIO_VidSetPinVal(LCD_EN_PIN,LCD_CONTROL_PORT,DIO_HIGH);
// load commAND to the data port
DIO_VidSetPortVal(LCD_DATA_PORT,u8Cmd);
// clear enable pin
DIO_VidSetPinVal(LCD_EN_PIN,LCD_CONTROL_PORT,DIO_LOW);
_delay_ms(5);
// Set enable pin to high
DIO_VidSetPinVal(LCD_EN_PIN,LCD_CONTROL_PORT,DIO_HIGH);
_delay_ms(10);

}
void LCD_vidSendChar(u8 u8Char)
{
	// Set RS pin to high
	DIO_VidSetPinVal(LCD_RS_PIN,LCD_CONTROL_PORT,DIO_HIGH);
	// clear RW pin
	DIO_VidSetPinVal(LCD_RW_PIN,LCD_CONTROL_PORT,DIO_LOW);
	// Set enable pin to high
	DIO_VidSetPinVal(LCD_EN_PIN,LCD_CONTROL_PORT,DIO_HIGH);
	// load character to the data port
	DIO_VidSetPortVal(LCD_DATA_PORT,u8Char);
	// clear enable pin
	DIO_VidSetPinVal(LCD_EN_PIN,LCD_CONTROL_PORT,DIO_LOW);
	_delay_ms(5);
	//clear en pin
	DIO_VidSetPinVal(LCD_EN_PIN,LCD_CONTROL_PORT,DIO_HIGH);
	_delay_ms(10);

}
void LCD_vidWriteStr(u8* pu8str)
{
	// using a pointer to array of characters to send them to the LCD
u8 i =0;
while(pu8str[i]!=0)
{
LCD_vidSendChar(pu8str[i++]);
}
}
void LCD_vidCustomchar(u8 LOC,u8* u8toarr)
{
	// using the CG ROM to store  the char we create as a 8 byte
	//so we take an array of this bytes
	//use 0x40 address to store the character (this in data-sheet) add 8 on it first location and so on ,
	// using the 0x80 to print & 0x40 to store
	u8 i;
	if(LOC<8)
	{
		LCD_vidSendCommand(0x40 + (LOC*8) );
		for(i=0;i<8;i++)
		{
		LCD_vidSendChar(u8toarr[i]);
		}
	}
}
void LCD_vidRowCol(u8 u8x ,u8 u8y)
{
// to choose which row and column to print on it
switch(u8x)

{
case 0 : LCD_vidSendCommand(u8y+127);break;// 127 = 0x80 this is first row address

case 1: LCD_vidSendCommand(u8y+191);break;// 191 =0xc0  this is second row address


}

}
void itos(u16 res,u8* result)
{
	s8 i =5;
for(i=4;i>=0;i--)
{
	result[i]=res%10 +'0' ;
	res=res/10;
}
u8 k;
u8 j;
for(k =0;k<5;k++)
{
	if(result[k]!='0')
	{
		for(j=k;j<5;j++)
		{
		LCD_vidSendChar(result[j]);
		}
	break;
	}
}
}
