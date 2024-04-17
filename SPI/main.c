/*
 * main.c
 *
 *  Created on: Mar 26, 2021
 *      Author: pc1
 */
#include "LIB/typ.h"
#include <avr/io.h>
#include <avr/delay.h>
#include "LCD_interface.h"
#include "DIO_interface.h"
#define MOOD SLAVE
void SPI_Ini()
{

SPCR|=(1<<SPE);
#if(MOOD== MASTER)
SPCR|=(1<<MSTR);
#endif
}
void SPI_Send(u8 data)
{
	u8 flush;
	SPDR =data;
	while(!(SPSR&(1<<SPIF)));
	flush = SPDR;

}
u8 SPI_Receive(void)
{

	while(!(SPSR&(1<<SPIF)));

return SPDR;
}
u8 SPI_Read(void)
{
SPDR =0xff;
while(!((SPSR&(1<<SPIF))));
return SPDR;
}
u8 readSPI;
int main ()
{
	DIO_VidSetPortDir(DIO_PORTB,0x07);
	DIO_VidSetPortDir(DIO_PORTC,DIO_PORTOUTPUT);
	LCD_vidInit();
/**       LCD       ****/


////////////////////*    SPI      */////////////////////
DIO_VidSetPinDir(DIO_PIN5,DIO_PORTB,DIO_INPUT);   //MOSI
DIO_VidSetPinDir(DIO_PIN6,DIO_PORTB,DIO_OUTPUT);  //MISO
DIO_VidSetPinDir(DIO_PIN7,DIO_PORTB,DIO_INPUT);// CK
DIO_VidSetPinDir(DIO_PIN4,DIO_PORTB,DIO_INPUT); //SS
///////////////////*  PULL UP  *//////////////////////////
DIO_VidSetPinVal(DIO_PIN4,DIO_PORTB,DIO_HIGH);
DIO_VidSetPinVal(DIO_PIN5,DIO_PORTB,DIO_HIGH);
DIO_VidSetPinVal(DIO_PIN7,DIO_PORTB,DIO_HIGH);
/*************************************************/
SPI_Ini();


//LCD_vidWriteStr("jjjjj");

while(1)
{
	//_delay_ms(1000);
readSPI = SPI_Receive();
LCD_vidSendChar(readSPI);

}


}
