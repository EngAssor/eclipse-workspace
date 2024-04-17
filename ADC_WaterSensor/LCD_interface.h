/*
 * LCD_interface.h
 *
 *  Created on: Jan 23, 2021
 *      Author: pc1
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/****** LCD commands****/
#define  LCD_CLR     			 0x01       /* replace all characters with ascii space*/
#define  LCD_HOME    			 0x02       /* return cursor to the first position */
#define  LCD_ENTRYMODE 			 0x06       /* shift cursor from left to right on read/write */
#define  LCD_DISPOFF 	 		 0x08       /* turn display off*/
#define  LCD_DISPON_CURSON 	 	 0x0e       /* turn display on & cursor on */
#define  LCD_FUNCREST 	 		 0x30       /* rest the LCD*/
#define  LCD_FUNCSET_8BIT 	 	 0x38       /* 8bit data , 2-line display , 5x7 font*/
#define  LCD_SETCURSOR 	 		 0x80       /* Set cursor position*/
#define  LCD_DISPON_CURSBLINK 	 0x0f       /* turn display on & cursor blink*/
#define  LCD_DISPON_CURSOFF	   	 0x0c       /* turn display on & cursor off */


/****************/
void LCD_vidInit(void);
void LCD_vidSendCommand(u8 u8Cmd);
void LCD_vidSendChar(u8 u8Char);
void LCD_vidWriteStr(u8* pu8str);
void LCD_vidCustomchar(u8 LOC,u8* u8toarr);
void LCD_vidRowCol(u8 u8x ,u8 u8y);
void itos(u16 res);
#endif /* LCD_INTERFACE_H_ */
