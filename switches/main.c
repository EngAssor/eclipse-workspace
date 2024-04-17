/*
 * main.c
 *
 *  Created on: Jan 22, 2021
 *      Author: pc1
 */
#include "LIB\typ.h"
#include "DIO_interface.h"
#include<avr/delay.h>
 int main (void)
 {

	/* void DIO_VidSetPinDir(u8 PinId,u8 PortId,u8 PinDir); done
	 void DIO_VidSetPinVal(u8 PinId,u8 PortId,u8 PinVal); done
	 void DIO_VidSetPortVal(u8 PortId,u8 PortVal); done
	 void DIO_VidSetPortDir(u8 PortId,u8 PortDir); done
	 u8 DIO_u8GetPinVal(u8 PortId,u8 PinId);	   done	*/
	 // inti


	 DIO_VidSetPinDir(DIO_PIN7,DIO_PORTB,DIO_OUTPUT);
	 DIO_VidSetPinDir(DIO_PIN6,DIO_PORTB,DIO_OUTPUT);




	 // loop
	 while(1)
	 {
		 DIO_VidSetPinVal(DIO_PIN7,DIO_PORTB,DIO_HIGH);



	 }
 }
