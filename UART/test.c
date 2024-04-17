#include "LIB/typ.h"
#include "DIO_interface.h"
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL
#define BAUD 9600
#define BAUDRATE (((F_CPU/(BAUD*16UL)))-1)
void UART_vidIniti(void)
{
UBRRH =BAUDRATE>>8;
UBRRL=BAUDRATE;
UCSRB =(1<<TXEN)|(1<<RXEN);
UCSRC =(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);

}
void UART_vidTransmit(u8 Byte)
{
while (!(UCSRA & (1<<UDRE)));
UDR=Byte;
}
u8 UART_u8Receive(void)
{
while(!(UCSRA & (1<<RXC)));
return UDR;
}
u8 state =0;
int main (void)
{
	 UART_vidIniti();
	 UART_vidTransmit('A');

while(1)
{
	state = UART_u8Receive();

}

}
