/*
 * ADC_prog.c
 *
 *  Created on: Feb 13, 2021
 *      Author: pc1
 */

#ifndef ADC_PROG_C_
#define ADC_PROG_C_
#include "LIB/typ.h"
#include "LIB/Bit_Math.h"
#include "ADC_interface.h"
#include "ADC_prv.h"
#include "ADC_config.h"
void ADC_VidInit(void)
{
	// VREF selection() and result adjustment selection
	ADC_ADMUX=(ADC_VREF <<REFS0)|(ADC_RES_ADJUST<<ADLAR);
	// initialization ADC to be enable , Prescaler value =64
	ADC_ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(0<<ADPS0);

}
u16 ADC_u16GetADCRead(u8 chId)
{
	// make sure that channel index  is within ADC channels (0-7)(first 3 bits)
	chId =  chId & 0b00000111;
	// clear the first 3 bits before selection the channel ID
	ADC_ADMUX =(ADC_ADMUX & 0xf8)|chId;
	// start conversion
	ADC_ADCSRA |= (1<<ADSC);
	// polling on ADIF flag till conversion is finished
	while ((ADC_ADCSRA& (1<<ADIF))==0);
	return ADC_ADCRES;
	}
void ADC_vidEnable(void)
{
	SET_BIT(ADC_ADCSRA,ADEN);
}
void ADC_vidDiable(void)
{
	CLR_BIT(ADC_ADCSRA,ADEN);
	}
u8 u8ADC_GetTempInC(u16 ADC_Read)
{
return (u32)(ADC_Read*(5000/1024))/10;
}
u8 u8ADC_GetTempInF(u16 ADC_Read)
{
	return (((u32)(ADC_Read*(5000/1024))/10)*1.8)+32;
}


#endif /* ADC_PROG_C_ */
