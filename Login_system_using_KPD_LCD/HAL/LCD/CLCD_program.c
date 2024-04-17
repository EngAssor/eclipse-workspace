/*
 * LCD_program.c
 *
 *  Created on: Feb 6, 2024
 *      Author: Assor
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>
#include "../../MCAL/DIO/DIO_interface.h"
#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"



void CLCD_voidInit			(void)
{
	DIO_enumSetPortDirection(CLCD_DATA_PORT,DIO_OUTPUT			 );
	DIO_enumSetPINDirection (CLCD_CONTROL_PORT,CLCD_RS,DIO_OUTPUT);
	DIO_enumSetPINDirection (CLCD_CONTROL_PORT,CLCD_RW,DIO_OUTPUT);
	DIO_enumSetPINDirection (CLCD_CONTROL_PORT,CLCD_EN,DIO_OUTPUT);
	_delay_ms(50);
	CLCD_voidSendCommand(CLCD_FUNCSET_8BIT);//Func Set
	_delay_ms(1);
	CLCD_voidSendCommand(CLCD_DISPON_CURSOFF);//Display on and cursor off
	_delay_ms(1);
	CLCD_voidSendCommand(CLCD_CLR);//Display clear
	_delay_ms(2);
	CLCD_voidSendCommand(CLCD_ENTRYMODE);//Entry Mode no shift






}
void CLCD_voidSendChar		(u8 Copy_u8Data)
{

	DIO_enumSetPortValue(CLCD_DATA_PORT,Copy_u8Data);
	DIO_enumSetPINValue(CLCD_CONTROL_PORT,CLCD_RS,DIO_HIGH);
	DIO_enumSetPINValue(CLCD_CONTROL_PORT,CLCD_RW,DIO_LOW);

	DIO_enumSetPINValue(CLCD_CONTROL_PORT,CLCD_EN,DIO_HIGH);
	_delay_ms(1);
	DIO_enumSetPINValue(CLCD_CONTROL_PORT,CLCD_EN,DIO_LOW);
	_delay_ms(1);


}
void CLCD_voidSendCommand	(u8 Copy_u8Command)
{
	DIO_enumSetPortValue(CLCD_DATA_PORT,Copy_u8Command);
	DIO_enumSetPINValue(CLCD_CONTROL_PORT,CLCD_RS,DIO_LOW);
	DIO_enumSetPINValue(CLCD_CONTROL_PORT,CLCD_RW,DIO_LOW);

	DIO_enumSetPINValue(CLCD_CONTROL_PORT,CLCD_EN,DIO_HIGH);
	_delay_ms(1);
	DIO_enumSetPINValue(CLCD_CONTROL_PORT,CLCD_EN,DIO_LOW);
	_delay_ms(1);


}
void CLCD_voidSendString(u8* string)
{

	u8 i =0;
	while(string[i] != '\0')
	{
		CLCD_voidSendChar(string[i]);
		i++;

	}
}

void CLCD_voidSendNumber(u64 Copy_u64Number)
{
	u64 LOC_u64R_Number=0;
		while(Copy_u64Number!=0)
		{
			LOC_u64R_Number=LOC_u64R_Number+(Copy_u64Number%10);
			Copy_u64Number/=10;
			if(Copy_u64Number != 0)
				LOC_u64R_Number*=10;

		}

	u8 Loc_u8NumberToSend =0;
	while(LOC_u64R_Number != 0)
	{
		Loc_u8NumberToSend=LOC_u64R_Number%10;
		LOC_u64R_Number/=10;
		Loc_u8NumberToSend+=48;
		CLCD_voidSendChar(Loc_u8NumberToSend);
	}

}

void CLCD_voidSetPosition(u8 Copy_u8Row ,u8 Copy_u8Col)
{

	if(Copy_u8Row == CLCD_ROW_1)
	{
			CLCD_voidSendCommand(CLCD_ROW_1_ADD +(Copy_u8Col-1));

	}
	else if(Copy_u8Row == CLCD_ROW_2)
	{
		CLCD_voidSendCommand(CLCD_ROW_2_ADD+(Copy_u8Col-1));
	}
}
void CLCD_voidCustomChar(void)
{
CLCD_voidSendCommand(CLCD_CGRAM_ADD);
for(u8 i =0;i<sizeof(CustomeChar)/sizeof(CustomeChar[0]);i++)
{
	CLCD_voidSendChar(CustomeChar[i]);


}
CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
}

