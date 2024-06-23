/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

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
    DDRB  |= 1 << 6;         //Set Pin as output
    PORTA &= (unsigned char)(~0xff);        //Clear data  Register

	//================SPI configuration====================
	Reset_Bit(SPCR, MSTR);  //Enable Master Mode
	Set_Bit(SPCR, SPE);     //Enable SPI


	char i = 0, RX_Buffer = 0;
	while (1)
	{

		while (i != 100)
		{
			PORTB &= ~(1 << 4);
			RX_Buffer = SPDR;
			while (!Read_Bit(SPSR, SPIF));
			SPDR = i;
			PORTA = RX_Buffer;

			++i;
		}

		i = 0;
	}

	return 0;
}


