/*
 * ADC_prv.h
 *
 *  Created on: Feb 13, 2021
 *      Author: pc1
 */

#ifndef ADC_PRV_H_
#define ADC_PRV_H_

// ADC reference voltage //
#define ADC_VCC 		  1

#define ADC_INTERNAL_VREF 0

#define ADC_EXT_VREF 	  3
/******************************************/
// ADC result adjust macros //

#define ADC_RIGHT   0
#define ADC_LEFT    1

/*****************************************/

//   Registers Definition  //

#define ADC_ADCSRA    *((volatile u8*)(0x26))//ADCSRA reg
#define ADC_ADCRES    *((volatile u16*)(0x24))// ADC result reg
#define ADC_ADMUX	 *((volatile u8*)(0x27))//DMUX reg

/***********************************************************/



//register ADMUX bits
#define REFS1    7
#define REFS0    6
#define ADLAR    5
#define MUX4     4
#define MUX3     3
#define MUX2     2
#define MUX1     1
#define MUX0     0
//-------------------


// register ADCRA bits
#define ADEN      7
#define ADSC      6
#define ADATE     5
#define ADIF      4
#define ADIE      3
#define ADPS2     2
#define ADPS1     1
#define ADPS0     0
#endif /* ADC_PRV_H_ */
