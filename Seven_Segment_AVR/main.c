/*
 * main.c
 *
 *  Created on: Feb 4, 2024
 *      Author: Assor
 */

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include <util/delay.h>
#include "DIO/DIO_interface.h"
#include "SSD_interface.h"

int main(void)
{
	SSD_Type SSD1={SSD_COMMON_CATHODE,DIO_PORTA,DIO_PORTC,DIO_PIN7};
	SSD_voidInit(SSD1);

	u8 i;
	while(1)
	{


		for(i=0;i<10;i++)
			{
				SSD_voidSendNumber(SSD1,i);
				SSD_voidEnable(SSD1);
				_delay_ms(500);
			}
	}
	return 0;
}
