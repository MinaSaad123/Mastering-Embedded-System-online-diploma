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

	char i = 0, RX_Buffer = 0;
	while (1)
	{

		while (i != 100)
		{
			PORTB &= ~(1 << 4);
			SPDR = i;
			while ( !Read_Bit(SPSR, SPIF) );
			RX_Buffer = SPDR;
			PORTA = RX_Buffer;
			_delay_ms(1000);
			++i;
		}

		i = 0;

	}

	return 0;
}
