/*
 * main.c
 *
 *  Created on: Jan 9, 2021
 *      Author: pc1
 */

#include<avr/io.h>
#include<avr/delay.h>
#include"LIB/typ.h"



#define ZERO  0x3f
#define ONE   0x06
#define TWO   0x5b
#define THREE 0x4f
#define FOUR  0x66
#define FIVE  0x6d
#define SIX   0x7d
#define SEVEN 0x07
#define EIGHT 0x7F
#define NINE  0x67


u8 arr[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
 int main (void)
 {
// initialization
	 DDRA=0xff;
	 u8 i ;
	 //loop
	 while(1)
	 {
		 for(i=0;i<10;i++)
		 {

			 PORTA=arr[i];
			 _delay_ms(1000);
		 }
	 }

 }
