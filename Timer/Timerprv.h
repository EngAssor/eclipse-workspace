/*
 * Timerprv.h
 *
 *  Created on: Apr 7, 2021
 *      Author: pc1
 */

#ifndef TIMERPRV_H_
#define TIMERPRV_H_


/************    Registers              ***************/
#define    TCCR0                *((volatile u8* )(0x53))              //Timer/Counter Control Register
#define    TIMSK				*((volatile u8* )(0x59) )              //Timer/Counter Interrupt Mask Register
#define    OCR0					*((volatile u8* )(0x5C) )             //Output Compare Register
#define    TCNT0				*((volatile u8* )(0x52) )            //Timer/Counter Register
#define    TIFR                 *((volatile u8* )(0x58) )          //Timer/Counter Interrupt Flag Register
#define    SFIOR 				*((volatile u8* )(0x50) )        //Special Function IO Register
/////////////////////////////////////////////////////////
/***************   Timer/Counter Control Register (TCCR0) Bits           **************************/
//#define      BitName        num
#define 		CS00				0
#define 		CS01				1
#define 		CS02				2
#define 		WGM01				3
#define 		COM00				4
#define 		COM01				5
#define 		WGM00				6
#define 		FOC0				7
///////////////////////////////////////////////////////////////////////////////////////////////////

/***************   Timer/Counter Interrupt Mask Register (TIMSK) Bits           **************************/
//#define      bitName        num
#define 		TOIE0				0
#define 		OCIE0				1
#define 		TOIE1				2
#define 		OCIE1B				3
#define 		OCIE1A				4
#define 		TICIE1				5
#define 		TOIE2				6
#define 		OCIE2				7
///////////////////////////////////////////////////////////////////////////////////////////////////

/***************   Output Compare Register (OCR0) PINS           **************************/
// NO BITS  all are value
///////////////////////////////////////////////////////////////////////////////////////////////////
/***************   Timer/Counter Register (TCNT0) PINS           **************************/
// NO BITS  all are value
///////////////////////////////////////////////////////////////////////////////////////////////////

/***************  Timer/Counter Interrupt Flag Register  (TIFR) Bits           **************************/
//#define      bitName        num
#define 		TOV0				0
#define 		OCF0				1
#define 		TOV1				2
#define 		OCF1B				3
#define 		OCF1A				4
#define 		ICF1				5
#define 		TOV2				6
#define 		OCF2				7
///////////////////////////////////////////////////////////////////////////////////////////////////


#endif /* TIMERPRV_H_ */
