

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include <util/delay.h>

#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LCD/CLCD_interface.h"
#include "../HAL/KPD/KPD_interface.h"

int main (void)
{
	CLCD_voidInit();
	KPD_voidInit();

	while(1)
	{
		u8 LOC_u8char ;
		LOC_u8char=KPD_u8GetPressed();
		if(LOC_u8char !=0)
		CLCD_voidSendChar(LOC_u8char);
	}

	return 0;
}

	/*
	 *
	 *
	 * */
