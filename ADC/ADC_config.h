/*
 * ADC_config.h
 *
 *  Created on: Feb 13, 2021
 *      Author: pc1
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*reference voltage selection
 * Range : ADC_VCC
 * ADC_INTERNAL_VREF
 * ADC_EXT_VREF */
#define ADC_VREF  ADC_VCC


/*result adjustment
 *range : ADC_RIGHT,ADC_LEFT */
#define ADC_RES_ADJUST  ADC_RIGHT
#endif /* ADC_CONFIG_H_ */
