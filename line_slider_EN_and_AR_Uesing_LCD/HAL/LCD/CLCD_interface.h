/*
 * LCD_interface.h
 *
 *  Created on: Feb 6, 2024
 *      Author: Asser Tanatwy
 */

#ifndef HAL_LCD_CLCD_INTERFACE_H_
#define HAL_LCD_CLCD_INTERFACE_H_
#define  CLCD_CLR     			 0x01       /* replace all characters with ascii space*/
#define  CLCD_HOME    			 0x02       /* return cursor to the first position */
#define  CLCD_ENTRYMODE 	     0x06       /* shift cursor from left to right on read/write */
#define  CLCD_DECREASE			 0x04
#define  CLCD_DISPOFF 	 		 0x08       /* turn display off*/
#define  CLCD_DISPON_CURSON 	 0x0e       /* turn display on & cursor on */
#define  CLCD_FUNCREST 	 		 0x30       /* rest the LCD*/
#define  CLCD_FUNCSET_8BIT 	 	 0x38       /* 8bit data , 2-line display , 5x7 font*/
#define  CLCD_SETCURSOR 	 	 0x80       /* Set cursor position*/
#define  CLCD_DISPON_CURSBLINK 	 0x0f       /* turn display on & cursor blink*/
#define  CLCD_DISPON_CURSOFF  	 0x0c       /* turn display on & cursor off */
#define  CLCD_CGRAM_ADD          0x40		/* this CGRAM Address to create custom chars*/

#define CLCD_ROW_1    1
#define CLCD_ROW_2    2
#define CLCD_ROW_1_ADD 0x80
#define CLCD_ROW_2_ADD 0xC0

#define CLCD_COL_1    1
#define CLCD_COL_2    2
#define CLCD_COL_3    3
#define CLCD_COL_4    4
#define CLCD_COL_5    5
#define CLCD_COL_6    6
#define CLCD_COL_7    7
#define CLCD_COL_8    8
#define CLCD_COL_9    9
#define CLCD_COL_10    10
#define CLCD_COL_11    11
#define CLCD_COL_12    12
#define CLCD_COL_13    13
#define CLCD_COL_14    14
#define CLCD_COL_15    15
#define CLCD_COL_16    16


#define CLCD_CUSTOM_CHAR1	0
#define CLCD_CUSTOM_CHAR2	1
#define CLCD_CUSTOM_CHAR3	2
#define CLCD_CUSTOM_CHAR4	3
#define CLCD_CUSTOM_CHAR5	4
#define CLCD_CUSTOM_CHAR6	5
#define CLCD_CUSTOM_CHAR7	6
#define CLCD_CUSTOM_CHAR8	7

void CLCD_voidInit			(void			  );
void CLCD_voidSendChar		(u8 Copy_u8Data   );
void CLCD_voidSendCommand	(u8 Copy_u8Command);
void CLCD_voidSendString    (u8* string		  );
void CLCD_voidSendNumber    (u64 Copy_Number  );
void CLCD_voidSetPosition(u8 Copy_u8Row ,u8 Copy_u8Col);
void CLCD_voidCustomChar(void);
void CLCD_voidSend_AR_String(u8* string , u8 length);

#endif /* HAL_LCD_CLCD_INTERFACE_H_ */
