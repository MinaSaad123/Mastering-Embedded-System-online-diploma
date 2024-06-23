/*
 * LCD.c
 *
 *  Created on: ??�/??�/????
 *      Author: HP
 */

//Include
#include "LCD.h"
#include "Stm32f103x6.h"
#include "Stm32f103c6_GPIO_Driver.h"

/*******************************Function definition******************************/

//===========================LCD_GPIO_INIT===================================
void LCD_GPIO_Init()
{
	GPIO_Config_t LCD_Pin;

	//=========================Control Pins
	//RW Pin
	LCD_Pin.GPIO_PinNumber = Rw_Pin;
	LCD_Pin.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_2M;
	LCD_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOA, &LCD_Pin);
	//RS Pin
	LCD_Pin.GPIO_PinNumber = Rs_Pin;
	LCD_Pin.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_2M;
	LCD_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOA, &LCD_Pin);
	//Enable
	LCD_Pin.GPIO_PinNumber = E_Pin;
	LCD_Pin.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_2M;
	LCD_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOA, &LCD_Pin);

	//=========================Data Pins
	//PinA0
	LCD_Pin.GPIO_PinNumber = GPIO_PIN_0;
	LCD_Pin.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_2M;
	LCD_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOA, &LCD_Pin);
	//PinA1
	LCD_Pin.GPIO_PinNumber = GPIO_PIN_1;
	LCD_Pin.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_2M;
	LCD_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOA, &LCD_Pin);
	//PinA2
	LCD_Pin.GPIO_PinNumber = GPIO_PIN_2;
	LCD_Pin.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_2M;
	LCD_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOA, &LCD_Pin);
	//PinA3
	LCD_Pin.GPIO_PinNumber = GPIO_PIN_3;
	LCD_Pin.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_2M;
	LCD_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOA, &LCD_Pin);
	//PinA4
	LCD_Pin.GPIO_PinNumber = GPIO_PIN_4;
	LCD_Pin.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_2M;
	LCD_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOA, &LCD_Pin);
	//PinA5
	LCD_Pin.GPIO_PinNumber = GPIO_PIN_5;
	LCD_Pin.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_2M;
	LCD_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOA, &LCD_Pin);
	//PinA6
	LCD_Pin.GPIO_PinNumber = GPIO_PIN_6;
	LCD_Pin.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_2M;
	LCD_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOA, &LCD_Pin);
	//PinA7
	LCD_Pin.GPIO_PinNumber = GPIO_PIN_7;
	LCD_Pin.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_2M;
	LCD_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOA, &LCD_Pin);

}

//===========================LCD_INIT Function===============================
void LCD_Init()
{
	_delay_ms(1);
	_delay_ms(1);                    //To make sure it is not Busy
	//Reset LCD_Data_Pins
    MCAL_GPIO_Reset_Output_Particular(LCD_Data_Pins, LCD_Data_Val);
	_delay_ms(1);
	//LCD_Send_Command(Clear_Display);  //Clear display

	//==============Suppose we are in Eight bit Mode
    #ifdef Eight_bit_Mode
    //Command to make it in 8-bit Mode
	LCD_Send_Command(Function_Set_8_bit_Mode_Line_2);
	_delay_ms(1);
    #endif
	//==============Suppose we are in Four bit Mode
    #ifdef Four_bit_Mode
	//Command to initialize 4-bit Mode
	//Reset LCD_Data_Pins
    MCAL_GPIO_Reset_Output_Particular(LCD_Da-ta_Pins, LCD_Data_Val);
    MCAL_GPIO_Set_Output_Particular(LCD_Data_Pins, 0x02);  //Send command
    LCD_E_on_E_off();
    //Command to make it in 4-bit Mode
    MCAL_GPIO_Reset_Output_Particular(LCD_Data_Pins, LCD_Data_Val);  	//Reset LCD_Data_Pins
    //Send command
    MCAL_GPIO_Set_Output_Particular(LCD_Data_Pins, Function_Set_4_bit_Mode_Line_2);
    LCD_E_on_E_off();
    #endif
    LCD_Send_Command(Entry_Mode);                      //Entry

}

//==========================LCD_E_off_E_on Function=======================
void LCD_E_on_E_off()
{
	MCAL_GPIO_WritePin(LCD_Control_Pins, HIGH, E_Pin);      //Set E on
	_delay_ms(1);                                          //Delay
	MCAL_GPIO_WritePin(LCD_Control_Pins, LOW, E_Pin);       //Set E off
}

//=====================LCD_Send_Command Function============================
void LCD_Send_Command(int Com)
{
	_delay_ms(1);                                                      //To make sure it is not Busy
    MCAL_GPIO_WritePin(LCD_Control_Pins, LOW, Rs_Pin);                  //Set RS off
	//==============Eight_bit_Mode
    #ifdef Eight_bit_Mode
	//Send Command
    MCAL_GPIO_Reset_Output_Particular(LCD_Data_Pins, LCD_Data_Val);  	//Reset LCD_Data_Pins
    MCAL_GPIO_Set_Output_Particular(LCD_Data_Pins, Com);
	_delay_ms(1);                                                       //Small delay
    #endif

	//==============Four_bit_Mode
    #ifdef Four_bit_Mode
    MCAL_GPIO_Reset_Output_Particular(LCD_Data_Pins, LCD_Data_Val);  	//Reset LCD_Data_Pins
	//Send first piece from Command
    MCAL_GPIO_Set_Output_Particular(LCD_Data_Pins, (Com & 0x0f) );
	_delay_ms(1);                 //Small delay
	//Receive   Command
	LCD_E_on_E_off();
    MCAL_GPIO_Reset_Output_Particular(LCD_Data_Pins, LCD_Data_Val);  	//Reset LCD_Data_Pins
	//Send second piece from Command
    MCAL_GPIO_Set_Output_Particular(LCD_Data_Pins, ((Com & 0x0F) << 4) );
    #endif
	//Receive Command
	LCD_E_on_E_off();
    MCAL_GPIO_Reset_Output_Particular(LCD_Data_Pins, LCD_Data_Val);  	//Reset LCD_Data_Pins
}

//===========================LCD_Send_char Function=========================
void LCD_Send_char(char Character)
{
	_delay_ms(1);                //To make sure it is not Busy
	MCAL_GPIO_WritePin(LCD_Control_Pins, HIGH, Rs_Pin);
	//==============Eight_bit_Mode
	#ifdef Eight_bit_Mode
	//Send data
    MCAL_GPIO_Reset_Output_Particular(LCD_Data_Pins, LCD_Data_Val);  	//Reset LCD_Data_Pins
    MCAL_GPIO_Set_Output_Particular(LCD_Data_Pins, Character);          //Send Data To Eight Pins
   #endif

	//==============Four_bit_Mode
   #ifdef Four_bit_Mode
    //Send first piece from Command
    MCAL_GPIO_Set_Output_Particular(LCD_Data_Pins, (Character & 0xF0));
    _delay_ms(1);                                                       //Small delay
    //Receive   Command
    LCD_E_on_E_off();
    MCAL_GPIO_Reset_Output_Particular(LCD_Data_Pins, LCD_Data_Val);  	//Reset LCD_Data_Pins
    //Send second piece from Command
    MCAL_GPIO_Set_Output_Particular(LCD_Data_Pins, ((Character & 0x0F) << 4));
   #endif
    _delay_ms(1);
	//Receive data
    LCD_E_on_E_off();
    MCAL_GPIO_Reset_Output_Particular(LCD_Data_Pins, LCD_Data_Val);  	//Reset LCD_Data_Pins
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
	}
}












