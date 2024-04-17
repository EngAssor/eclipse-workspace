#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO_private.h"
#include "DIO_interface.h"
void DIO_Delay(u32 ticks)
{
u32 x;
for(x=0;x<ticks;x++);

}
int main(void)
{
	DIO_enumSetPortDirection(DIO_PORTA,DIO_OUTPUT);
	DIO_enumSetPortDirection(DIO_PORTD,DIO_INPUT);
	DIO_enumSetPortValue(DIO_PORTD,DIO_HIGH);
	u8 input=0;
	while(1)
	{
		DIO_enumGetPINValue(DIO_PORTD,DIO_PIN0,&input);
		if(!input)
		{
			DIO_enumSetPINValue(DIO_PORTA,DIO_PIN4,DIO_HIGH);

		}
		DIO_enumSetPINValue(DIO_PORTA,DIO_PIN4,DIO_LOW);

	}

return 0;
}
