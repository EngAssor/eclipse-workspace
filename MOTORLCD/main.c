/*
 * main.c
 *
 *  Created on: Jan 29, 2021
 *      Author: pc1
 */
#include "LIB/typ.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KPD_interface.h"


int main(){
volatile	u8 key;
	//initialization
	DIO_VidSetPortDir(DIO_PORTD,0x0f);
	DIO_VidSetPortVal(DIO_PORTD,0xf0);
	DIO_VidSetPortDir(DIO_PORTC,DIO_PORTOUTPUT);
	DIO_VidSetPortDir(DIO_PORTA,DIO_PORTOUTPUT);
	DIO_VidSetPortDir(DIO_PORTB,0xff);
 // LCD initialization

	LCD_vidInit();
LCD_vidSendCommand(LCD_CLR);

	//
u8 state = 'S' ;
LCD_vidWriteStr("DC MOTOR is : ");
LCD_vidRowCol(0,15);
		LCD_vidSendChar(state);
	while(1)
	{


		key =u8_GetPressedKey();
		if(key != NOTPRESSED)
		{
			switch(key){

		case '+' :
			switch(state){
			case 'S' :
				state ='R';


				LCD_vidRowCol(0,15);
					LCD_vidSendChar(state);
					DIO_VidSetPinVal(DIO_PIN2,DIO_PORTB,DIO_LOW);
					DIO_VidSetPinVal(DIO_PIN3,DIO_PORTB,DIO_LOW);
					DIO_VidSetPinVal(DIO_PIN0,DIO_PORTB,DIO_HIGH);
					DIO_VidSetPinVal(DIO_PIN1,DIO_PORTB,DIO_HIGH);
					key = NOTPRESSED;
					break ;

			case 'R' :

				state ='L';

				//LCD_vidWriteStr("DC MOTOR is : ");
				LCD_vidRowCol(0,15);
								LCD_vidSendChar(state);
								DIO_VidSetPinVal(DIO_PIN2,DIO_PORTB,DIO_HIGH);
								DIO_VidSetPinVal(DIO_PIN3,DIO_PORTB,DIO_HIGH);
								DIO_VidSetPinVal(DIO_PIN0,DIO_PORTB,DIO_LOW);
								DIO_VidSetPinVal(DIO_PIN1,DIO_PORTB,DIO_LOW);
								key = NOTPRESSED;
								break ;
			case 'L' :
				state ='S';
							//LCD_vidSendCommand(LCD_CLR);
						//	LCD_vidWriteStr("DC MOTOR is : ");
							LCD_vidRowCol(0,15);
											LCD_vidSendChar(state);
					DIO_VidSetPinVal(DIO_PIN2,DIO_PORTB,DIO_LOW);
					    DIO_VidSetPinVal(DIO_PIN3,DIO_PORTB,DIO_LOW);
						DIO_VidSetPinVal(DIO_PIN0,DIO_PORTB,DIO_LOW);
						DIO_VidSetPinVal(DIO_PIN1,DIO_PORTB,DIO_LOW);
						key = NOTPRESSED;
						break ;


}
				break;
	/*	case '-':
			if (state == 'S'){
						state ='L';

						//LCD_vidWriteStr("DC MOTOR is : ");
						LCD_vidRowCol(0,15);
										LCD_vidSendChar(state);
							// h code

					}
					else if(state=='R')
					{
						state ='S';

					//	LCD_vidWriteStr("DC MOTOR is : ");
						LCD_vidRowCol(0,15);
										LCD_vidSendChar(state);
							// h code
					}
					else if(state =='S')
					{
						state ='L';

							//		LCD_vidWriteStr("DC MOTOR is : ");
									LCD_vidRowCol(0,15);
													LCD_vidSendChar(state);
										// h code

					}
			key = NOTPRESSED;
					break;*/

									}


		}
	}
}
