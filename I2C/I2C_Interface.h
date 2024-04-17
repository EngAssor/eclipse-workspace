/*
 * I2C_Interface.h
 *
 *  Created on: Mar 27, 2021
 *      Author: pc1
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_
#include "I2C_prv.h"
/****************\\\\\\\\   Status MACROS            /////////////*\\\\\*/
#define STARTTRANS       0x08;
#define RESTARTTRANS     0x10;
#define WRITEACK         0x18;
#define WRITENOTACK		 0x20;
#define READACK			 0x28;
#define READNOT 		 0x30;
#define Arbitration      0x38;
//////////////////////////////////////////////////////////////////////////


/*             PUBLIC FUNction                       */
u8 TWI_Receive(void);
u8 CheckStatus(u8 Status);
void TWI_SendSA_R(u8 SA);
void TWI_Stop(void);
void TWI_Start(void);
void TWI_vidInit(void);






#endif /* I2C_INTERFACE_H_ */
