/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: aser
 */
#include "LIB/typ.h"
#include "LIB/Bit_Math.h"
#define DDRA *((u8 *) 0x3A)

#define PORTA *((u8 *) 0x3B)
int main(void)
{
DDRA = 0b00000001;

while(1)
{
	PORTA =0b00000001;
	for(int i=0;i<25000;i++);
	PORTA =0b00000000;
	for(int i=0;i<25000;i++);

	}
return 0;
}
