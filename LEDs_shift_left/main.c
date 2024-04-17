/*
 * main.c
 *
 *  Created on: Nov 1, 2023
 *      Author: Asser Tanatwy
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO_private.h"
#include "DIO_interface.h"
u8 LEDs[8]={
		DIO_PIN0,
		DIO_PIN1,
		DIO_PIN2,
		DIO_PIN3,
		DIO_PIN4,
		DIO_PIN5,
		DIO_PIN6,
		DIO_PIN7
};

#define ALLON     0
#define SHIFT     1
#define PINGPONG  2
#define BLINKALL  3
#define PNGPONG2  4
#define SNAKE     5
// dummy function to delay
void DIO_Delay(u32 ticks)
{
u32 x;
for(x=0;x<ticks;x++);

}
int main(void)
{
	DIO_enumSetPortDirection(DIO_PORTA,DIO_OUTPUT);// Set Port A as an Output
	DIO_enumSetPortValue(DIO_PORTA,DIO_LOW);// reset all values in port A
	DIO_enumSetPINDirection(DIO_PORTD,DIO_PIN0,DIO_INPUT); // make port D as input
	DIO_enumSetPINValue(DIO_PORTD,DIO_PIN0,DIO_HIGH); // make pin 0 as pull up
	volatile s8 i =0,j=0; // loop variables
	volatile u8 input=0; // to store the input thats come from button
	volatile u8 ledmod=0; // Specifying  the shape of leds
	// super loop
	while(1)
	{
		DIO_enumGetPINValue(DIO_PORTD,DIO_PIN0,&input); // read the button value

		if(!input)
		{
			ledmod++;  // change the shape of leds
		}
		else
		{
				// empty
		}
		// switch on leds shapes
		switch(ledmod)
		{
		// All leds on
		case ALLON:
			// turn all leds on
			DIO_enumSetPortValue(DIO_PORTA,DIO_HIGH);
			DIO_Delay(60000);// delay to show the effect

			break;
		// shift the lighting led lift
		case SHIFT:
		for(i=0;i<=7;i++)
		{
			// set all leds off
			DIO_enumSetPortValue(DIO_PORTA,DIO_LOW);
			// turn the led that it's turn
			DIO_enumSetPINValue(DIO_PORTA,LEDs[i],DIO_HIGH);

			DIO_Delay(60000);
		}
		break;
		// ping pong shape
		case PINGPONG :
			// shift the lighting led lift

			for(i=0;i<=7;i++)
					{
						DIO_enumSetPortValue(DIO_PORTA,DIO_LOW);
						DIO_enumSetPINValue(DIO_PORTA,LEDs[i],DIO_HIGH);
						DIO_Delay(60000);
					}
			// shift the lighting led right
			for(i=7;i>=0;i--)
					{
				    	DIO_enumSetPortValue(DIO_PORTA,DIO_LOW);
						DIO_enumSetPINValue(DIO_PORTA,LEDs[i],DIO_HIGH);
						DIO_Delay(60000);
					}
			break;

		case BLINKALL:
			// turn all leds on
			DIO_enumSetPortValue(DIO_PORTA,DIO_HIGH);
			DIO_Delay(60000);
			// turn all leds off
			DIO_enumSetPortValue(DIO_PORTA,DIO_LOW);
			DIO_Delay(60000);

			break;

		// turn leds to middle form both sides
		case PNGPONG2:
			for(i=0,j=7;i<=3&&j>=4;i++,j--)
			{
				// turn the left leds on
				DIO_enumSetPINValue(DIO_PORTA,LEDs[i],DIO_HIGH);
				// turn the right leds on
				DIO_enumSetPINValue(DIO_PORTA,LEDs[j],DIO_HIGH);
				DIO_Delay(60000);
				//turn all leds off
				DIO_enumSetPortValue(DIO_PORTA,DIO_LOW);

			}

			break;

		// sanke shape
		case SNAKE :
			DIO_enumSetPortValue(DIO_PORTA,DIO_LOW);// make all leds low
			for(i=0;i<=7;i++)// loop on leds an turn them on one by one
			{
				DIO_enumSetPINValue(DIO_PORTA,LEDs[i],DIO_HIGH);// make one led on
				DIO_Delay(60000);// delay to show the effect

			}
			DIO_enumSetPortValue(DIO_PORTA,DIO_LOW);// turn all leds off

			break;

default :
	// return to default state
	ledmod=0;
	//turn all leds off
	DIO_enumSetPortValue(DIO_PORTA,DIO_LOW);
	DIO_Delay(65000);

	break;

	}
	}
return 0;
}
