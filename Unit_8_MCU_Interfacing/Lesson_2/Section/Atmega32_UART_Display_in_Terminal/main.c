/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

//====Include
#include "Uart.h"
#include "LCD.h"


//====main Function
int main ()
{
	//Init Function
	LCD_INIT();
    MCAL_Uart_Init();
    //Send Char
    MCAL_Uart_Send('M');
    MCAL_Uart_Send('i');
    MCAL_Uart_Send('n');
    MCAL_Uart_Send('a');

    //Send String
    MCAL_Uart_Send_String("Saad");

	LCD_Send_Command(Cursor_in_begining_of_Line_2);

    while(1)
    {
    	LCD_Send_char(MCAL_Uart_Receive());
    }
	return 0;
}
