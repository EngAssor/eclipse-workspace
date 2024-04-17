/*
 * KPD_program.c
 *
 *  Created on: Feb 21, 2024
 *      Author: Assor
 */
#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"


void KPD_voidInit(void)
{
	DIO_enumSetPINDirection(KPD_PORT,KPD_R0,DIO_INPUT);
	DIO_enumSetPINDirection(KPD_PORT,KPD_R1,DIO_INPUT);
	DIO_enumSetPINDirection(KPD_PORT,KPD_R2,DIO_INPUT);
	DIO_enumSetPINDirection(KPD_PORT,KPD_R3,DIO_INPUT);

	DIO_enumSetPINValue(KPD_PORT,KPD_R0,DIO_HIGH);
	DIO_enumSetPINValue(KPD_PORT,KPD_R1,DIO_HIGH);
	DIO_enumSetPINValue(KPD_PORT,KPD_R2,DIO_HIGH);
	DIO_enumSetPINValue(KPD_PORT,KPD_R3,DIO_HIGH);

	DIO_enumSetPINDirection(KPD_PORT,KPD_C0,DIO_OUTPUT);
	DIO_enumSetPINDirection(KPD_PORT,KPD_C1,DIO_OUTPUT);
	DIO_enumSetPINDirection(KPD_PORT,KPD_C2,DIO_OUTPUT);
	DIO_enumSetPINDirection(KPD_PORT,KPD_C3,DIO_OUTPUT);

	DIO_enumSetPINValue(KPD_PORT,KPD_C0,DIO_HIGH);
	DIO_enumSetPINValue(KPD_PORT,KPD_C1,DIO_HIGH);
	DIO_enumSetPINValue(KPD_PORT,KPD_C2,DIO_HIGH);
	DIO_enumSetPINValue(KPD_PORT,KPD_C3,DIO_HIGH);
}

u8 KPD_u8GetPressed(void)
{
	u8 LOC_u8ReturnData = 0 ;
	u8 LOC_u8PinValue       ;
	u8 LOC_u8ROW            ;
	u8 LOC_u8COL            ;

	for(LOC_u8COL=0 + KPD_COL_INIT; LOC_u8COL < KPD_COL_END + 1 ; LOC_u8COL++) // loop on col pins
	{
		DIO_enumSetPINValue(KPD_PORT,LOC_u8COL,DIO_LOW); // make col pin low
		for(LOC_u8ROW = 0 + KPD_ROW_INIT ;LOC_u8ROW < KPD_ROW_END + 1 ;LOC_u8ROW++ ) // loop on rows pins
		{
			DIO_enumGetPINValue(KPD_PORT,LOC_u8ROW,&LOC_u8PinValue); // read row value
			if(LOC_u8PinValue == DIO_LOW)
			{
				_delay_ms(50); // delay for bouncing
				DIO_enumGetPINValue(KPD_PORT,LOC_u8ROW,&LOC_u8PinValue);
				if(LOC_u8PinValue == DIO_LOW)
							{
								LOC_u8ReturnData = KPD_u8Buttons[LOC_u8ROW-KPD_ROW_INIT][LOC_u8COL-KPD_COL_INIT];// store the data according to 2d array
							}
				DIO_enumGetPINValue(KPD_PORT,LOC_u8ROW,&LOC_u8PinValue);
				while(LOC_u8PinValue == DIO_LOW) // make code stuck until you free the btn
				{
					DIO_enumGetPINValue(KPD_PORT,LOC_u8ROW,&LOC_u8PinValue);
				}
				break; // we get the btn no need to loop
			}
		}
		DIO_enumSetPINValue(KPD_PORT,LOC_u8COL,DIO_HIGH); // make col pin high to loop

	}
return LOC_u8ReturnData;
}
