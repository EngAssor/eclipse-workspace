/*
 * main.c
 *
 *  Created on: Jan 11, 2021
 *      Author: pc1
 */
#include<avr/io.h>
#include<avr/delay.h>
#include"LIB/typ.h"
#define ZERO  0x3f
#define ONE   0x06
#define TWO   0x5b
#define THREE 0x4f
#define FOUR  0x66
#define FIVE  0x6d
#define SIX   0x7d
#define SEVEN 0x07
#define EIGHT 0x7F
#define NINE  0x6f
#define GREEN 0x01
#define YELLOW 0x02
#define RED    0x04
 u8 arr[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};

int main(){
	// initialization
	DDRA=0xff;
	DDRC=0xff;
	DDRB=0x07;

	//loop
	while(1)
	{
		PORTB=GREEN;
		PORTA=ONE;
		PORTC=ZERO;
		_delay_ms(1000);
		s8 i;
		for(i=9;i>=0;i--)
		{
			PORTA=ZERO;
			PORTC=arr[i];
			_delay_ms(1000);
		}
		PORTB=YELLOW;
		PORTA=ZERO;
		for(i=3;i>=0;i--)
		{
			PORTC=arr[i];
			_delay_ms(1000);
		}

		PORTB=RED;
		PORTA=ONE;
		PORTC=ZERO;
		_delay_ms(1000);

		for(i=9;i>=0;i--)
				{
					PORTA=ZERO;
					PORTC=arr[i];
					_delay_ms(1000);
				}

	}
}
