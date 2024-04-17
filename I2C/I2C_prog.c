/*
 * I2C_prog.c
 *
 *  Created on: Mar 27, 2021
 *      Author: pc1
 */


#include "LIB/typ.h"
#include "I2C_prv.h"



void TWI_vidInit(void)
{
	TWBR = 52;
	TWCR |=(1<<TWEN);

}
void TWI_Start(void)
{

TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
while(!(TWCR&(1<<TWINT)));

}
void TWI_Stop(void)
{

TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}
void TWI_SendSA_R(u8 SA)
{
TWDR= SA<<1|0x01;
TWCR=(1<<TWINT)|(1<<TWEN);
while(!(TWCR & (1<<TWINT)));
}
void TWI_SendSA_W(u8 SA)
{
	TWDR = SA<<1;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(!(TWCR&(1<<TWINT)));
}
u8 CheckStatus(u8 Status)
{
	if((TWSR&0xf8)==Status)
	{return 1 ;}
	else
	{return 0;}

}
u8 TWI_Receive(void)
{
TWCR =(1<<TWINT)|(1<<TWEN);
while(!(TWCR&(1<<TWINT)));
return TWDR;

}
