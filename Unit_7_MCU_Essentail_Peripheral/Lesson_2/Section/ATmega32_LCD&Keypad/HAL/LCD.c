/*
 * LCD.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

//Include
#include "LCD.h"
#include "GPIO.h"

/*******************************Function definition******************************/

//===========================LCD_INIT Function===============================
void LCD_INIT()
{
	//Make control Pins output
	Set_output(DDRB, 0b1110);
	_delay_ms(20);
	LCD_is_busy();                   //To make sure it is not Busy
	Reset_output(PORTA, 0xFF);       //Reset  PortA
	_delay_ms(20);
	LCD_Send_Command(Clear_Display); //Clear display

	//==============Suppose we are in Eight bit Mode
    #ifdef Eight_bit_Mode
    //Command to make it in 8-bit Mode
	LCD_Send_Command(Function_Set_8_bit_Mode_Line_2);
	_delay_ms(10);
    #endif
	//==============Suppose we are in Four bit Mode
    #ifdef Four_bit_Mode
	//Command to initialize 4-bit Mode
	Reset_output(PORTA, 0xFF);    //Reset output
	Set_output(PORTA, 0X02);      //Send command
    LCD_E_on_E_off();
    //Command to make it in 4-bit Mode
	Reset_output(PORTA, 0xFF);    //Reset output
    //Send command
    Set_output(PORTA, Function_Set_4_bit_Mode_Line_2);
    LCD_E_on_E_off();

    #endif
    LCD_Send_Command(Entry_Mode);                      //Entry
    LCD_Send_Command(Display_on_Cursor_on);            //Display_on_Cursor_on
    LCD_Send_Command(Display_on_Cursor_blinking);      //Binking_Cursor_on
}

//==========================LCD_E_off_E_on Function=======================
void LCD_E_on_E_off()
{
    Set_bit(PORTB, E_Pin);         //Set E on
	_delay_ms(50);                 //Delay
	Reset_bit(PORTB, E_Pin);       //Set E off

}

//==========================LCD_is_busy Function===========================
void LCD_is_busy()
{
	/******i can Reduce the number of Lines but i do that just for readability*****/
	Set_input(DDRA, 0xFF);	       //Set all Pins input
    Set_bit(PORTB, Rw_Pin);        //Set RW on
    Reset_bit(PORTB, Rs_Pin);      //Set RS off
    LCD_E_on_E_off();              //Send all information
	Reset_output(PORTB, 0b11100);  //Reset PortB
    Reset_bit(PORTB, Rs_Pin);      //Set RS ON
    Reset_output(PORTB, Rw_Pin);   //Set RW off
}

//=====================LCD_Send_Command Function============================
void LCD_Send_Command(int Com)
{
	LCD_is_busy();                 //To make sure it is not Busy
	Reset_bit(PORTB, Rs_Pin);      //Set RS off
	//==============Eight_bit_Mode
    #ifdef Eight_bit_Mode
	//Send Command
	Set_output(PORTA, Com);
	_delay_ms(5);                  //Small delay
    #endif

	//==============Four_bit_Mode
    #ifdef Four_bit_Mode
	Reset_output(PORTA, 0xFF);    //Reset output
	//Send first piece from Command
	Set_output(PORTA, (Com & 0xF0));
	_delay_ms(5);                 //Small delay
	//Receive   Command
	LCD_E_on_E_off();
    Reset_output(PORTA, 0xFF);    //Reset PortA
	//Send second piece from Command
	Set_output(PORTA, ((Com & 0x0F) << 4));
    #endif
	//Receive Command
	LCD_E_on_E_off();
	Reset_output(PORTA, 0xFF);    //Reset output
}

//===========================LCD_Send_char Function=========================
void LCD_Send_char(char Character)
{
	LCD_is_busy();                //To make sure it is not Busy
    Set_bit(PORTB, Rs_Pin);       //Set RS ON
	//==============Eight_bit_Mode
	#ifdef Eight_bit_Mode
	//Send data
    Set_output(PORTA, Character); //Send Data To Eight Pins
   #endif

	//==============Four_bit_Mode
   #ifdef Four_bit_Mode
    //Send first piece from Command
    Set_output(PORTA, (Character & 0xF0));
    _delay_ms(5);                 //Small delay
    //Receive   Command
    LCD_E_on_E_off();
	Reset_output(PORTA, 0xFF);    //Reset output
    //Send second piece from Command
    Set_output(PORTA, ((Character & 0x0F) << 4));
   #endif
    _delay_ms(1);
	//Receive data
    LCD_E_on_E_off();
	Reset_output(PORTA, 0xFF);    //Reset output
}

//========================LCD_Send_string Function============================
void LCD_Send_string(char* String)
{
	int Count = 0;
	while(*String)
	{
        LCD_Send_char(*String++);
        Count++;
        if(Count == 16)
        {
        	//Cursor in the  Line 2
        	LCD_Send_Command(Cursor_in_begining_of_Line_2);
	    }
        if(Count == 31)
        {
            Count = 0;
            LCD_Send_Command(Clear_Display);
            LCD_Send_Command(Cursor_in_begining_of_Line_1);
        }
        _delay_ms(100);
	}
}

