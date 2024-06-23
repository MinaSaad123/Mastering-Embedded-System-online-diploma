/*
 * LCD.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

//Include Lib
#include "util/delay.h"

/*************LCD Instruction Macros*************/
#define Clear_Display                       0x01
#define Entry_Mode    						0x06
#define Display_off_Cursor_off    			0x08
#define Display_on_Cursor_on    			0x0E
#define Display_on_Cursor_off    			0x0c
#define Display_on_Cursor_blinking    		0x0F
#define Shift_entire_display_left    		0x18
#define Shift_entire_display_right    		0x1C
#define Move_cursor_left_by_one_character   0x10
#define Move_cursor_right_by_one_character  0x14
#define Function_Set_4_bit_Mode_Line_1      0x20
#define Function_Set_4_bit_Mode_Line_2      0x28
#define Function_Set_8_bit_Mode_Line_1      0x30
#define Function_Set_8_bit_Mode_Line_2      0x38
#define Cursor_in_begining_of_Line_1        0x80
#define Cursor_in_begining_of_Line_2        0xC0

/*****************LCD Control Signals******************/
#define Write      0
#define Read       1
#define Rs_on      1
#define Rs_off     0
#define Rw_on      1
#define Rw_off     0
#define Rw_Pin     2
#define Rs_Pin     1
#define E_Pin      3
#define Busy       1
#define NotBusy    0

//===================Set it in 8-bit Mode
#define Eight_bit_Mode
//#define Four_bit_Mode

/*****************Function Prototype******************/
void LCD_is_busy();
void LCD_INIT();
void LCD_E_on_E_off();
void LCD_Send_Command(int Com);
void LCD_Send_string(char* String);
void LCD_Send_char(char Character);




#endif /* INC_LCD_H_ */
