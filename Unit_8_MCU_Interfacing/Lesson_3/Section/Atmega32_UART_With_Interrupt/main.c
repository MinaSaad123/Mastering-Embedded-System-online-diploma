/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

//====Include
#include "Uart.h"
#include "LCD.h"

//===Variables
int x = 0;
extern void (*G_CallBack[])() ;

//====TXC_Syn Function
//void UART_TXC_Syn ()
//{
//	MCAL_Uart_Send(/*Something*/);
//}

//====RXC_Syn Function
void UART_RXC_Syn ()
{
	LCD_Send_Command(Cursor_in_begining_of_Line_1 + x);
    x++;
	LCD_Send_char(MCAL_Uart_Receive());

}

//====main Function
int main ()
{
	//Init Function
	LCD_INIT();
    MCAL_Uart_Init();

    //Enable Uart
    MCAL_Uart_ENR_DIS_Interrupt(Enable);

    //Passing Synchronous to Pointer to Function
    G_CallBack[0] = UART_RXC_Syn;

    //G_CallBack[1] = UART_TXC_Syn;

    LCD_Send_Command(Clear_Display);  //Clear display

    char i = '0';
    while(1)
    {
    	LCD_Send_Command(Cursor_in_begining_of_Line_2);
        LCD_Send_char(i);


    	if (i == '9')
    	{
    		i = '0';
            LCD_Send_Command(Clear_Display);  //Clear display
            x = 0;
    	}
    	_delay_ms(1500);
    	i++;
    }
	return 0;
}
