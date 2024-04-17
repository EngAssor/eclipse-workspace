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

	 DIO_VidSetPortDir(DIO_PORTA,DIO_PORTOUTPUT);
	 DIO_VidSetPortDir(DIO_PORTB,DIO_PORTOUTPUT);
	 DIO_VidSetPortDir(DIO_PORTC,DIO_PORTOUTPUT);
	 DIO_VidSetPortDir(DIO_PORTD,DIO_PORTOUTPUT);


	 // loop
	 while(1)
	 {
		 DIO_VidSetPortVal(DIO_PORTA,DIO_PORTOUTPUT);
		 DIO_VidSetPortVal(DIO_PORTB,DIO_PORTOUTPUT);
		 DIO_VidSetPortVal(DIO_PORTC,DIO_PORTOUTPUT);
		 DIO_VidSetPortVal(DIO_PORTD,DIO_PORTOUTPUT);

	 }
 }
