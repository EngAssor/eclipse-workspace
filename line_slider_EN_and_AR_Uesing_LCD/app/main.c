
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
#include "../HAL/LCD/CLCD_interface.h"

#define EN_LENGTH     4
#define AR_LENGTH     3
int main (void)
{ /* LCD Init */
	CLCD_voidInit();
	CLCD_voidCustomChar();
	CLCD_voidSendChar(CLCD_CUSTOM_CHAR1);
	CLCD_voidSendChar(CLCD_CUSTOM_CHAR2);
	CLCD_voidSendChar(CLCD_CUSTOM_CHAR3);
	CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
/*****************************************************/
	u8 * n1   ="r";
	u8 * n2   ="er";
	u8 * n3   ="ser";
	u8 * n4   ="Aser";
	u8 A_N1 []={CLCD_CUSTOM_CHAR3};
	u8 A_N2 []={CLCD_CUSTOM_CHAR3,CLCD_CUSTOM_CHAR2};
	u8 A_N3 []={CLCD_CUSTOM_CHAR1,CLCD_CUSTOM_CHAR2,CLCD_CUSTOM_CHAR3};

	u8 * EN_name[]={n1,n2,n3,n4};
	u8 * AR_name[]={A_N1,A_N2,A_N3};
	u8 i=0;
	s8 j=0;
	s8 k=0;
	for(j=0;j<EN_LENGTH;j++)
					{
		CLCD_voidSendCommand(CLCD_ENTRYMODE);

						CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
						CLCD_voidSendString(EN_name[j]);
						if(i<3)
						{
							//CLCD_voidSendCommand(CLCD_DECREASE);
							CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_16-i);
							CLCD_voidSendChar(A_N3[i]);
							i++;

						}

						_delay_ms(1000);

					}
	while(1)
	{

				j=0;
				k=0;
				for(i=1;i<=16;i++)
				{
					if(i>13 && j<4)
						{
							CLCD_voidSetPosition(CLCD_ROW_1,1);
							CLCD_voidSendString(EN_name[j]);
							j++;

						}
					CLCD_voidSetPosition(CLCD_ROW_1,i);
					CLCD_voidSendString(EN_name[3]);


					if(i>15 && k<3)
					{
						CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_16-k);
						CLCD_voidSend_AR_String(A_N3,k+1);
						k++;


					}

					CLCD_voidSetPosition(CLCD_ROW_2,16-i);
					CLCD_voidSend_AR_String(A_N3 ,3);




						_delay_ms(1000);

						CLCD_voidSendCommand(CLCD_CLR);

				}



	}


	return 0;
}

	/*
	 *
	 *
	 * */
