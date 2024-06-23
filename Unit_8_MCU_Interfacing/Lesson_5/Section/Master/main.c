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
    DDRB  |= 0xB0;           //Set Pin as output
    PORTB &= (unsigned char)(~0xff);        //Clear data  Register
    PORTB |= (1 << 4);       //Make SS is High

	//================SPI configuration====================
	Set_Bit(SPCR, MSTR);    //Enable Master Mode
	Set_Bit(SPCR, SPE);     //Enable SPI

	LCD_INIT();
    LCD_Send_string("Master");

	char i = '0', RX_Buffer;
	while (1)
	{
        LCD_Send_Command(Cursor_in_begining_of_Line_2);
		SPDR = i;
		while ( !Read_Bit(SPSR, SPIF) );
		RX_Buffer = SPDR;
		LCD_Send_char(RX_Buffer);
		LCD_Send_Command(Cursor_in_begining_of_Line_1 + 7);
		LCD_Send_char(i);
		PORTB &= ~(1 << 4);

		_delay_ms(1000);
		++i;
		if (i == ('9' + 1) )
		{
			i = '1';
		}
	}
	return 0;
}
