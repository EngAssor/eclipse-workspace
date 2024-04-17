
/**
 * Traffic light using 3 leds and tow 7-segments with AVR
 *
 * author : Aser Tantawy
 * date: 5/2/2024
 * */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include <util/delay.h>

#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LCD/CLCD_interface.h"

int main (void)
{
	CLCD_voidInit();
	CLCD_voidCustomChar();
	CLCD_voidSendCommand(CLCD_WRITE_R_TO_L);
	CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_16);
	CLCD_voidSendChar(CLCD_CUSTOM_CHAR1);
	CLCD_voidSendChar(CLCD_CUSTOM_CHAR2);
	CLCD_voidSendChar(CLCD_CUSTOM_CHAR3);


	return 0;
}

	/*
	 *
	 *
	 * */
