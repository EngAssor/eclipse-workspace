/*
 * DIO_prog.c
 *
 *  Created on: Jan 22, 2021
 *      Author: pc1
 */
#include "LIB\typ.h"
#include "LIB\Bit_Math.h"
#include "DIO_interface.h"
#include "DIO_prv.h"
void TogelpinVal(u8 REG ,u8 pin)
{
	switch(REG)
	{
	case DIO_PORTA :TOG_BIT(DDRA_REG,pin); break;
	case DIO_PORTB :TOG_BIT(DDRB_REG,pin); break;
	case DIO_PORTC :TOG_BIT(DDRC_REG,pin); break;
	case DIO_PORTD :TOG_BIT(DDRD_REG,pin); break;

	}

}
void DIO_VidSetPinDir(u8 PinId,u8 PortId,u8 PinDir)
{
if((PortId<=DIO_PORTD)&&(PinId<=DIO_PIN7))
{
if (PinDir == DIO_OUTPUT)
{
switch(PortId)
{
case DIO_PORTA :SET_BIT(DDRA_REG,PinId); break;
case DIO_PORTB :SET_BIT(DDRB_REG,PinId); break;
case DIO_PORTC :SET_BIT(DDRC_REG,PinId); break;
case DIO_PORTD :SET_BIT(DDRD_REG,PinId); break;


}


}
else if (PinDir == DIO_INPUT)
{
switch(PortId)
{
case DIO_PORTA :CLR_BIT(DDRA_REG,PinId); break;
case DIO_PORTB :CLR_BIT(DDRB_REG,PinId); break;
case DIO_PORTC :CLR_BIT(DDRC_REG,PinId); break;
case DIO_PORTD :CLR_BIT(DDRD_REG,PinId); break;
}

}
else
{
//error
}
}
else
{
// error
}
}
void DIO_VidSetPinVal(u8 PinId,u8 PortId,u8 PinVal)
{
	if((PortId<=DIO_PORTD)&&(PinId<=DIO_PIN7))
	{
	if (PinVal == DIO_OUTPUT)
	{
	switch(PortId)
	{
	case DIO_PORTA :SET_BIT(PORTA_REG,PinId);break;
	case DIO_PORTB :SET_BIT(PORTB_REG,PinId); break;
	case DIO_PORTC :SET_BIT(PORTC_REG,PinId); break;
	case DIO_PORTD :SET_BIT(PORTD_REG,PinId);break;


	}


	}
	else if (PinVal == DIO_INPUT)
	{
	switch(PortId)
	{
	case DIO_PORTA :CLR_BIT(PORTA_REG,PinId); break;
	case DIO_PORTB :CLR_BIT(PORTB_REG,PinId);break;
	case DIO_PORTC :CLR_BIT(PORTC_REG,PinId); break;
	case DIO_PORTD :CLR_BIT(PORTD_REG,PinId); break;
	}

	}
	else
	{
	//error
	}
	}
	else
	{
	// error
	}

}
void DIO_VidSetPortVal(u8 PortId,u8 PortVal)
{


		if (PortId <= DIO_PORTD)
		{
		switch(PortId)
		{
		case DIO_PORTA :PORTA_REG=PortVal; break;
		case DIO_PORTB :PORTB_REG=PortVal; break;
		case DIO_PORTC :PORTC_REG=PortVal; break;
		case DIO_PORTD :PORTD_REG=PortVal; break;
		}
		}
	else
		{
		//error
		}
}


void DIO_VidSetPortDir(u8 PortId,u8 PortDir)
{
if(PortId<=DIO_PORTD)
{
switch(PortId)
{
case DIO_PORTA :DDRA_REG=PortDir; break;
case DIO_PORTB :DDRB_REG=PortDir; break;
case DIO_PORTC :DDRC_REG=PortDir; break;
case DIO_PORTD :DDRD_REG=PortDir; break;
}
}
else
{
//error
}
}
u8 DIO_u8GetPinVal(u8 PortId,u8 PinId)
{
u8 PinState=0xff;//means wrong input (port id or pin id)
if((PortId<=DIO_PORTD)&&(PinId<=DIO_PIN7))
{
	switch(PortId)
	{
	case DIO_PORTA :PinState=GET_BIT(PINA_REG,PinId); break;
	case DIO_PORTB :PinState=GET_BIT(PINB_REG,PinId); break;
	case DIO_PORTC :PinState=GET_BIT(PINC_REG,PinId); break;
	case DIO_PORTD :PinState=GET_BIT(PIND_REG,PinId); break;
	}
	return PinState;

}
else
{
	return 0; //error
}
}

