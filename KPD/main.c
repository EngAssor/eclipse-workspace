/*
 * main.c
 *
 *  Created on: Jan 29, 2021
 *      Author: pc1
 */
#include "LIB/typ.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KPD_interface.h"


int main(){
volatile	u8 key;
	//initialization
	DIO_VidSetPortDir(DIO_PORTD,0x0f);
	DIO_VidSetPortVal(DIO_PORTD,0xf0);
	DIO_VidSetPortDir(DIO_PORTC,DIO_PORTOUTPUT);
	DIO_VidSetPortDir(DIO_PORTA,DIO_PORTOUTPUT);
 // LCD initialization

	LCD_vidInit();
LCD_vidSendCommand(LCD_CLR);

	//

	while(1)
	{
		key =u8_GetPressedKey();
		if(key != NOTPRESSED)
		{
			LCD_vidSendChar(key);
		}
	}
}
