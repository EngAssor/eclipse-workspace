#include "LIB/typ.h"
#include"CalculatorFun.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KPD_interface.h"
 int  main (void)
  {
u8 input[20];
u8 right[10];
u8 left[10];
u8 result [5];

volatile	u8 key;

	//initialization
	DIO_VidSetPortDir(DIO_PORTD,0x0f);
	DIO_VidSetPortVal(DIO_PORTD,0xf0);
	DIO_VidSetPortDir(DIO_PORTC,DIO_PORTOUTPUT);
	DIO_VidSetPortDir(DIO_PORTA,DIO_PORTOUTPUT);
 // LCD initialization

	LCD_vidInit();
LCD_vidSendCommand(LCD_CLR);

	//
u8 i=0 ;
u8 loop1;
u8 j;
s32 res;
	while(1)
	{

		key =u8_GetPressedKey();
		if(key!='c')
		{
		if(key != NOTPRESSED)
		{
			LCD_vidSendChar(key);
			input[i++]=key;
		}
		else{}
		if (key=='=')
		{
			res = findResult(right,left,input);
			itos(res,result);
			for( loop1=0;loop1<5;loop1++)
			{
				if(result[loop1]!='0')
				{
					for( j =loop1;j<5;j++)
					{
						LCD_vidSendCommand(0xc0);
					LCD_vidSendChar(result[j]);
					}
				break;
				}
			}
		}
		}
		else
			{
			LCD_vidSendCommand(LCD_CLR);
			}

	}
  }

