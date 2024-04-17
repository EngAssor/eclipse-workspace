#include <avr/io.h>
#include <avr/interrupt.h>
#include "LIB/typ.h"
#include "LIB/Bit_Math.h"
#include "DIO_interface.h"
u8 flag =0;
int main ()
{
	// initialization
	DIO_VidSetPinDir(DIO_PIN0,DIO_PORTA,DIO_OUTPUT);
	DIO_VidSetPinDir(DIO_PIN2,DIO_PORTD,DIO_INPUT);
	DIO_VidSetPinVal(DIO_PIN2,DIO_PORTD,DIO_HIGH);


	// initialization INT0 interrupt trigger
	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);


	/*Enable interrupt INT0*/
	SET_BIT(GICR,6);
	/*Enable Global  Interrupt */
	SET_BIT(SREG,7);



	// loop
	while(1)
	{

	}


}
ISR(INT0_vect)
{
	if(0==flag)
	{
DIO_VidSetPinVal(DIO_PIN0,DIO_PORTA,DIO_HIGH);
	flag =1;
	}
	else
	{
		DIO_VidSetPinVal(DIO_PIN0,DIO_PORTA,DIO_LOW);
		flag =0;

	}

	}
