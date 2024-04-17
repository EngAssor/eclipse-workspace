/*
 * KPD_prog.c
 *
 *  Created on: Jan 29, 2021
 *      Author: pc1
 */

#define F_CPU 8000000UL
#include "LIB/typ.h"
#include "DIO_interface.h"
#include "KPD_interface.h"
#include "KPD_prv.h"
#include "KPD_config.h"
#include "avr\delay.h"

static const u8 KPD_ARRAY[4][4]=
{
	{'1','2','3','+'},
	{'4','5','6','-'},
	{'7','8','9','x'},
	{'0','.','/','c'}

};
u8  u8_GetPressedKey(void)
{
	u8 u8switchVal = NOTPRESSED;
	u8 u8col;
	u8 u8row;
	// loop on columns to put zeros
	for(u8col=KPD_colBGN;u8col<KPD_colNUM;u8col++)
	{	// set the column to  zero
		DIO_VidSetPinVal(u8col,KPD_PORT,DIO_LOW);
		for(u8row=KPD_rowBGN;u8row<KPD_rowBGN+KPD_rowNUM;u8row++)
		{
			if(DIO_u8GetPinVal(KPD_PORT,u8row) == DIO_LOW)
			{
				u8switchVal=KPD_ARRAY[u8row-4][u8col];
				while(DIO_u8GetPinVal(KPD_PORT,u8row) == DIO_LOW);
				_delay_ms(50);
			}

		}

		DIO_VidSetPinVal(u8col,KPD_PORT,DIO_HIGH);
	}
return u8switchVal;
}
