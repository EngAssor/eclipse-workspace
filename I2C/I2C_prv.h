/*
 * I2C_prv.h
 *
 *  Created on: Mar 27, 2021
 *      Author: pc1
 */

#ifndef I2C_PRV_H_
#define I2C_PRV_H_
//********//  REGISTERS I2C   \\\\\\\\\\\\***\\\\\\\/
#define 	TWDR		*((volatile u8*)0x23)
#define 	TWAR		*((volatile u8*)0x22)
#define 	TWSR		*((volatile u8*)0x21)
#define 	TWBR		*((volatile u8*)0x20)
#define 	TWCR		*((volatile u8*)0x56)
/////////////////////////////////////////////////////



//////////      TWCR PINS         ///////
#define TWINT   7
#define TWEA    6
#define TWSTA   5
#define TWSTO   4
#define TWWC    3
#define TWEN    2
#define TWIE    0
//////////////////////////////////////////////


#endif /* I2C_PRV_H_ */
