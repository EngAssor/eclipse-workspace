/*
 * LCD_config.h
 *
 *  Created on: Jan 23, 2021
 *      Author: pc1
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
/*
LCD DATA port configuration
*/
#define LCD_DATA_PORT     DIO_PORTC
/*
  LCD CONTROL port configuration
 */
#define LCD_CONTROL_PORT     DIO_PORTA
/*
 * Control pins
 */
#define LCD_RS_PIN     DIO_PIN0

#define LCD_RW_PIN     DIO_PIN1

#define LCD_EN_PIN     DIO_PIN2

#endif /* LCD_CONFIG_H_ */
