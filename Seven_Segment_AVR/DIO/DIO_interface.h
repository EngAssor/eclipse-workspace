/*
author : Asser Tantwy 
date : 30/10/2023

*/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

typedef enum
{
	DIO_NOK,
	DIO_OK
}DIO_ErroStatus;




 DIO_ErroStatus DIO_enumSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);
 DIO_ErroStatus DIO_enumSetPortValue    (u8 Copy_u8Port, u8 Copy_u8Value    );

 DIO_ErroStatus DIO_enumSetPINDirection(u8 Copy_u8Port,u8 Copy_u8PINNumber, u8 Copy_u8Direction);
 DIO_ErroStatus DIO_enumSetPINValue    (u8 Copy_u8Port,u8 Copy_u8PINNumber, u8 Copy_u8Value    );

 DIO_ErroStatus DIO_enumGetPortValue    (u8 Copy_u8Port, u8 *Copy_ptrData                       );
 DIO_ErroStatus DIO_enumGetPINValue     (u8 Copy_u8Port,u8 Copy_u8PINNumber, u8 *Copy_ptrData   );



/* MACROS */
#define DIO_OUTPUT 1
#define DIO_INPUT  0
#define DIO_HIGH   1
#define DIO_LOW    0
#define DIO_PORTA  1
#define DIO_PORTB  2
#define DIO_PORTC  3
#define DIO_PORTD  4
/************************/
 /* PINS*/
#define DIO_PIN0    0
#define DIO_PIN1    1
#define DIO_PIN2    2
#define DIO_PIN3    3
#define DIO_PIN4    4
#define DIO_PIN5    5
#define DIO_PIN6    6
#define DIO_PIN7    7


#endif
