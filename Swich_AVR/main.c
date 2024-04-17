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
#include  "LED/LED_interface.h"
#include "SW_interface.h"
int main(void)
{
	SW_Type  SW1  ={DIO_PORTC,DIO_PIN0,SW_PULL_UP};// set sw1 to port c pin 0 pull up
	LED_Type LED1 ={DIO_PORTB,DIO_PIN3,ACTIVE_HIGH};// ser led1 to port b pin 3 active high

	SW_voidInit(SW1);
	LED_voidInit(LED1);

	while (1) //supre loop
		{
			if (SW_u8GetPressed(SW1) == 0)
			{
				_delay_ms(150);
				if (SW_u8GetPressed(SW1) == 0)
					LED_voidOn(LED1);

			}
			else {
				LED_voidOff(LED1);
			}
		}
	return 0;
}
