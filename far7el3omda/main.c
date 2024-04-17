/*
 * main.c
 *
 *  Created on: Jan 12, 2021
 *      Author: pc1
 */
#include<avr/io.h>
#include<avr/delay.h>
#include"LIB/typ.h"
#include"LIB/MACROS.h"
#define ALLLEDS 0xff
#define ALLOFF 0x00
#define LED1 0x01
#define LED2 0x02
#define LED3 0x04
#define LED4 0x08
#define LED5 0x10
#define LED6 0x20
#define LED7 0x40
#define LED8 0x80
#define _2LED 0x03
#define _3LED 0x07
#define _4LED 0x0f
#define _5LED 0x1f
#define _6LED 0x3f
#define _7LED 0x7f
#define _8LED 0xff
#define LED8_1 0x81
#define LED7_2 0x42
#define LED6_3 0x24
#define LED5_4 0x18
u8 led[8]={LED1,LED2,LED3,LED4,LED5,LED6,LED7,LED8};
u8 tled[4]={LED8_1,LED7_2,LED6_3,LED5_4};
u8 snak[8]={LED1,_2LED,_3LED,_4LED,_5LED,_6LED,_7LED,_8LED};
int main(void){
	//initialization
	DDRA=0xff;
	DDRD=0x00;
	PORTD=0xff;
	s8 i ;
	// loop

	while(1){

//Flashing every 500 ms
		if((PIND>>0&1)==0)
		{
			PORTA=ALLLEDS;
			_delay_ms(500);
			PORTA=ALLOFF;
			_delay_ms(500);

		}
		//Shifting Left every 250 ms
		else if((PIND>>1&1)==0)
		{
			for(i=0;i<8;i++)
			{
				PORTA=led[i];
				_delay_ms(250);
			}


		}
		//Shifting Right every 250 ms
else if((PIND>>2&1)==0)
		{
			for(i=7;i>=0;i--)
			{
				PORTA=led[i];
				_delay_ms(250);
			}
		}
		//2-LEDs Converging every 300 ms
else if((PIND>>3&1)==0)
		{

			for(i=0;i<4;i++)
			{
				PORTA=tled[i];
				_delay_ms(300);
			}



		}
		//2-LEDs Diverging every 300 ms
else if((PIND>>4&1)==0)
		{

	for(i=3;i>=0;i--)
				{
					PORTA=tled[i];
					_delay_ms(300);
				}


		}
		//Ping Pong effect every 250 ms
else if((PIND>>5&1)==0)
		{
		for(i=0;i<8;i++)
		{
			PORTA=led[i];
			_delay_ms(250);

		}
		for(i=6;i>0;i--)
		{
			PORTA =led[i];
				_delay_ms(250);
		}

		}
		//7 Incrementing (Snake effect) every 300 ms
else if((PIND>>6&1)==0)
{
	for(i=0;i<8;i++)
	{
		PORTA=snak[i];
		_delay_ms(300);
	}
}

//2-LEDs Converging/Diverging every 300 ms
else if((PIND>>7&1)==0)
{
	for(i=0;i<4;i++)
			{
				PORTA=tled[i];
				_delay_ms(300);
			}


	for(i=2;i>0;i--)
				{
					PORTA=tled[i];
					_delay_ms(300);
				}

}

		else
		{
			PORTA=0x00;
		}

}
}
