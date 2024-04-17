/*
 * DIO_interface.h
 *
 *  Created on: Jan 22, 2021
 *      Author: pc1
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
/**************************************/
/*********Public functions************/
/************************************/
void DIO_VidSetPinDir(u8 PinId,u8 PortId,u8 PinDir);
void DIO_VidSetPinVal(u8 PinId,u8 PortId,u8 PinVal);
void DIO_VidSetPortVal(u8 PortId,u8 PortVal);
void DIO_VidSetPortDir(u8 PortId,u8 PortDir);
u8 DIO_u8GetPinVal(u8 PortId,u8 PinId);

/***************************/
/**************************/



/**************************************/
/*********Public MACROS************/
/************************************/
/***** PORTS*****/
#define DIO_PORTA  0
#define DIO_PORTB  1
#define DIO_PORTC  2
#define DIO_PORTD  3
/******* port value ********/

#define  DIO_PORTHIGH 0xff
#define  DIO_PORTLOW  0x00
/************************/
/****** input&output*****/
#define DIO_INPUT   0
#define DIO_OUTPUT  1
#define  DIO_PORTOUTPUT 0xff
#define  DIO_PORTINPUT  0x00
/****** high&low*****/
#define DIO_HIGH    1
#define DIO_LOW     0
/****** PINS *******/
#define DIO_PIN0    0
#define DIO_PIN1    1
#define DIO_PIN2    2
#define DIO_PIN3    3
#define DIO_PIN4    4
#define DIO_PIN5    5
#define DIO_PIN6    6
#define DIO_PIN7    7
/***********************************/
/**********************************/

#endif /* DIO_INTERFACE_H_ */
