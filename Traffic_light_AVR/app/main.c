
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
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SSD/SSD_interface.h"
#define red    0
#define yellow 1
#define green  2
int main (void)
{
	// set the configuration of hardware
	LED_Type traffic_leds[3]={{DIO_PORTD,DIO_PIN5,ACTIVE_HIGH},
							  {DIO_PORTD,DIO_PIN4,ACTIVE_HIGH},
							  {DIO_PORTD,DIO_PIN3,ACTIVE_HIGH}};


	SSD_Type SSD1		={SSD_COMMON_CATHODE,DIO_PORTA,DIO_PORTD,DIO_PIN7};
	SSD_Type SSD2		={SSD_COMMON_CATHODE,DIO_PORTC,DIO_PORTD,DIO_PIN6};
	//----------------------------------------------------------------------

	// Init hardware
	// Init leds
	LED_voidInit(traffic_leds[red]);
	LED_voidInit(traffic_leds[green]);
	LED_voidInit(traffic_leds[yellow]);
	//Init seven segments
	SSD_voidInit(SSD1);
	SSD_voidInit(SSD2);
	//-----------------------------------------------------------------------
	s8 i =0;// loop variable

	while(1)
		{
			LED_voidOn(traffic_leds[red]);
			SSD_voidSendNumber(SSD1,0);
			SSD_voidEnable(SSD1);
			SSD_voidSendNumber(SSD2,1);
			SSD_voidEnable(SSD2);
			_delay_ms(1000);
			SSD_voidSendNumber(SSD2,0);
			for(i=9;i>=0;i--)
			{
				SSD_voidSendNumber(SSD1,i);
				_delay_ms(1000);
			}

			LED_voidOff(traffic_leds[red]);
			LED_voidOn(traffic_leds[yellow]);
			_delay_ms(1000);
			for(i=3;i>=0;i--)
						{
							SSD_voidSendNumber(SSD1,i);
							_delay_ms(1000);
						}
			LED_voidOff(traffic_leds[yellow]);
			LED_voidOn(traffic_leds[green]);
			SSD_voidSendNumber(SSD2,1);
			_delay_ms(1000);
			SSD_voidSendNumber(SSD2,0);

			for(i=9;i>=0;i--)
					{
						SSD_voidSendNumber(SSD1,i);
						_delay_ms(1000);
					}
					LED_voidOff(traffic_leds[green]);







		}



	return 0;
}

	/*
	 *
	 *
	 * */
