#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO/DIO_interface.h"
#include "LED_interface.h"
#include <util/delay.h>
void DIO_Delay(u32 ticks)
{
u32 x;
for(x=0;x<ticks;x++);

}
int main(void)
{
LED_Type led1={DIO_PORTC,DIO_PIN7,ACTIVE_HIGH};
//LED_Type led2={DIO_PORTD,DIO_PIN4,ACTIVE_HIGH};
//LED_Type led3={DIO_PORTD,DIO_PIN3,ACTIVE_HIGH};

LED_voidInit(led1);
while(1)
{
	_delay_ms(1000);
	LED_voidOn(led1);
	_delay_ms(1000);
	LED_voidOff(led1);

}
return 0;
}
