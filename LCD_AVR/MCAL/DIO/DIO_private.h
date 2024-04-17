/*
author : Asser Tantwy 
date : 30/10/2023

*/

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_




/*Registers defination*/
/*Port A registers*/
#define PORTA_REG *((volatile u8 *)0x3B)
#define DDRA_REG  *((volatile u8 *)0x3A)
#define PINA_REG  *((volatile u8 *)0x39)
/*--------------------------*/
/*Port B registers*/
#define PORTB_REG *((volatile u8 *)0x38)
#define DDRB_REG  *((volatile u8 *)0x37)
#define PINB_REG  *((volatile u8 *)0x36)
/*--------------------------*/
/*Port C registers*/
#define PORTC_REG *((volatile u8 *)0x35)
#define DDRC_REG  *((volatile u8 *)0x34)
#define PINC_REG  *((volatile u8 *)0x33)
/*--------------------------*/
/*Port D registers*/
#define PORTD_REG *((volatile u8 *)0x32)
#define DDRD_REG  *((volatile u8 *)0x31)
#define PIND_REG  *((volatile u8 *)0x30)
/*--------------------------*/




#endif
