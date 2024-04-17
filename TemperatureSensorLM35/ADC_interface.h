/*
 * ADC_interface.h
 *
 *  Created on: Feb 13, 2021
 *      Author: pc1
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

// ADC channels
#define ADC_CH0 	0
#define ADC_CH1 	1
#define ADC_CH2 	2
#define ADC_CH3 	3
#define ADC_CH4 	4
#define ADC_CH5 	5
#define ADC_CH6 	6
#define ADC_CH7 	7

// public function

void ADC_VidInit(void);
u16 ADC_u16GetADCRead(u8 chId);
void ADC_vidEnable(void);
void ADC_vidDiable(void);
u8 u8ADC_GetTempInC(u16 ADC_Read);
u8 u8ADC_GetTempInF(u16 ADC_Read);


#endif /* ADC_INTERFACE_H_ */
