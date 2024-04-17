

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include <util/delay.h>
#include <string.h>
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LCD/CLCD_interface.h"
#include "../HAL/KPD/KPD_interface.h"

u8 mystrcmp(u8 * str1 ,u8 *str2, u8 len)
{
	u8 cmp_status =0;
	u8 i=0;
	for(;i<len;i++)
	{
		if(str1[i]-str2[i])
		{
			cmp_status=1;
		}
	}

	return cmp_status;
}
void buzz(void)
{
	DIO_enumSetPINDirection(DIO_PORTC,DIO_PIN7,DIO_OUTPUT);
	DIO_enumSetPINValue(DIO_PORTC,DIO_PIN7,DIO_HIGH);
}
void enterbuzz(void)
{
	DIO_enumSetPINDirection(DIO_PORTC,DIO_PIN7,DIO_OUTPUT);
	for(u8 x=0;x<8;x++)
	{
		DIO_enumSetPINValue(DIO_PORTC,DIO_PIN7,DIO_HIGH);
		_delay_ms(10*x);
		DIO_enumSetPINValue(DIO_PORTC,DIO_PIN7,DIO_LOW);
		_delay_ms(10*x);

	}

}


int main (void)
{


	u8 user1[3]={'a','b','c'};
	u8 user2[3]={'b','a','c'};
	u8 user3[3]={'c','a','b'};

	u8 pass1[3]={'1','2','3'};
	u8 pass2[3]={'4','5','6'};
	u8 pass3[3]={'7','8','9'};

	u8 Log_input[3]={0};
	u8 i=0;
	u8 login_flag=0;
	u8 login_err=0;
	u8 pass_err=0;
	u8 wedone =0;
	CLCD_voidInit();
	KPD_voidInit();
	CLCD_voidSendCommand(CLCD_DISPON_CURSON);
	CLCD_voidSendString("welcome ..!");
	_delay_ms(3000);
	CLCD_voidSendCommand(CLCD_CLR);
	CLCD_voidSendString("Enter you ID:");
	CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_1);

	while(1)
	{
		u8 LOC_input=0;
		LOC_input=KPD_u8GetPressed();
		if(LOC_input !=0 )
		{
			if(LOC_input=='=')
			{
					CLCD_voidSendCommand(CLCD_CLR);
					CLCD_voidSendString("Enter you ID:");
					CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_1);
					 i=0;
					 login_flag=0;
					 login_err=0;
					 pass_err=0;
					 wedone =0;
					 continue;


			}
	if(!wedone)

		{
		if(login_flag == 0)

			{
				CLCD_voidSendChar(LOC_input);
			}
			else
			{
					CLCD_voidSendChar('*');

			}
			_delay_ms(100);
			Log_input[i]=LOC_input;
			i++;
			if(i==3 && login_flag == 0)
			{


				_delay_ms(1000);

				if(!(mystrcmp(Log_input,user1,3)))
				{

					login_flag=1;
					i=0;
					CLCD_voidSendCommand(CLCD_CLR);
					CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
					CLCD_voidSendString("Enter you Passwd");
					CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_1);
				}
				else if(!(mystrcmp(Log_input,user2,3)))
				{
					login_flag=2;
					i=0;
					CLCD_voidSendCommand(CLCD_CLR);
					CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
					CLCD_voidSendString("Enter you Passwd");
					CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_1);
				}
				else if(!(mystrcmp(Log_input,user3,3)))
								{
									login_flag=3;
									i=0;
									CLCD_voidSendCommand(CLCD_CLR);
									CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
									CLCD_voidSendString("Enter you Passwd");
									CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_1);

								}
				else
				{
					CLCD_voidSendCommand(CLCD_CLR);
					CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
					CLCD_voidSendString("Please try again");
					CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_1);
					i=0;
					login_err++;
					if(login_err==3)
					{
						CLCD_voidSendCommand(CLCD_DISPOFF);
						buzz();
					}
				}
			}
			else if(login_flag)
			{

				if(i==3)
				{
				switch (login_flag) {
					case 1:
							if(!mystrcmp(Log_input,pass1,3))
							{
								CLCD_voidSendCommand(CLCD_CLR);
								CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
								CLCD_voidSendString("Welcome User1");
								enterbuzz();
								wedone++;
							}
							else
							{
								CLCD_voidSendCommand(CLCD_CLR);
								CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
								CLCD_voidSendString("Please try again");
								CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_1);
								i=0;
								pass_err++;
							}
						break;
					case 2:
						if(!mystrcmp(Log_input,pass2,3))
							{
							    CLCD_voidSendCommand(CLCD_CLR);
								CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
								CLCD_voidSendString("Welcome User2");
								enterbuzz();
								wedone++;

							}
						else
							{
							CLCD_voidSendCommand(CLCD_CLR);
							CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
							CLCD_voidSendString("Please try again");
							CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_1);
							i=0;
							pass_err++;
							}
						break;
					case 3:
						if(!mystrcmp(Log_input,pass3,3))
						{
							CLCD_voidSendCommand(CLCD_CLR);
							CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
							CLCD_voidSendString("Welcome User3");
							enterbuzz();
							wedone++;

						}
						else
							{
							CLCD_voidSendCommand(CLCD_CLR);
							CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
							CLCD_voidSendString("Please try again");
							CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_1);
							i=0;
							pass_err++;
							}

						break;
					default:
						break;
				}
				if(pass_err==3)
								{
									CLCD_voidSendCommand(CLCD_DISPOFF);
									buzz();
								}
				}

			}


		}
		}
	}

	return 0;
}

	/*
	 *
	 *
	 * */
