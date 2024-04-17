/*
 * main.c
 *
 *  Created on: Jan 22, 2021
 *      Author: pc1
 */
#include "LIB\typ.h"
#include "DIO_interface.h"
#include"LCD_interface.h"
#include "LCD_config.h"
#include <stdio.h>
u8 arr[5];
 int main (void)
 {
	 DIO_VidSetPortDir(DIO_PORTC,0xff);
	 DIO_VidSetPortDir(DIO_PORTB,0xff);



	 LCD_vidInit();
LCD_vidSendCommand(0x80);
u16 f =32000;
itos(f,arr);


while(1)
	 {

}

}
