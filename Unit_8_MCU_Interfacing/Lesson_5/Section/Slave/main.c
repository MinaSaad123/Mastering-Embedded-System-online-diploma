
/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

//===========Include
#include "avr/delay.h"
#include "avr/io.h"
#include "Utils.h"
#include "LCD.h"

//===main Function
int main ()
{
	//=================GPIO configuration==================
	// <For 7-Segment>
    DDRA  &= (unsigned char)(~0xFF);        //Clear data Direction Register
    DDRA  |= 0xFF;           //Set data Direction Register
    PORTA &= (unsigned char)(~0xFF);        //Clear data  Register

    // <For SPi Pins>
    DDRB  &= (unsigned char)(~0xff);        //Clear data Direction Register
    DDRB  |= 1 << 6;         //Set Pin as output
    PORTA &= (unsigned char)(~0xff);        //Clear data  Register

	//================SPI configuration====================
	Reset_Bit(SPCR, MSTR);  //Enable Master Mode
	Set_Bit(SPCR, SPE);     //Enable SPI

	LCD_INIT();
    LCD_Send_string("Slave");

	char RX_Buffer, Str = 'A';
	while (1)
	{
		while (!Read_Bit(SPSR, SPIF));
		RX_Buffer = SPDR;
		LCD_Send_Command(Cursor_in_begining_of_Line_1 + 7);
		LCD_Send_char(RX_Buffer);
		SPDR = Str;
		LCD_Send_Command(Cursor_in_begining_of_Line_2);
		_delay_ms(1000);
		LCD_Send_char(Str);
		++Str;
		if ( Str == ('Z' + 1) )
		{
			Str = 'A';
		}

	}

	return 0;
}


