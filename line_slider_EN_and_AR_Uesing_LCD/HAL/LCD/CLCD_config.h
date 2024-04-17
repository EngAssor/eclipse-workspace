/*
 * LCD_config.h
 *
 *  Created on: Feb 6, 2024
 *      Author: Asser Tanatwy
 */

#ifndef HAL_LCD_CLCD_CONFIG_H_
#define HAL_LCD_CLCD_CONFIG_H_

/**
 * Options :-
 * 1- DIO_PORTA
 * 2- DIO_PORTB
 * 3- DIO_PORTC
 * 4- DIO_PORTD
 * */
// D0 to D7
#define CLCD_DATA_PORT DIO_PORTA
 /* Options :-
 * 1- DIO_PORTA
 * 2- DIO_PORTB
 * 3- DIO_PORTC
 * 4- DIO_PORTD
 * */
// RS , RW , EN
#define CLCD_CONTROL_PORT DIO_PORTC
/**
 * Options:-
 * 1-DIO_PIN0
 * 2-DIO_PIN2
 * 3-DIO_PIN3
 * 4-DIO_PIN4
 * 5-DIO_PIN5
 * 6-DIO_PIN6
 * 7-DIO_PIN7

 * */
#define CLCD_RS   DIO_PIN0
#define CLCD_RW   DIO_PIN1
#define CLCD_EN   DIO_PIN2


#endif /* HAL_LCD_CLCD_CONFIG_H_ */
