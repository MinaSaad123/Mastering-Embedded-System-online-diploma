/*
 * Keypad.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#include "Keypad.h"
#include "GPIO.h"
//Static array
int Keypad_Row[] = {R0, R1, R2, R3};    //rows
int Keypad_Col[] = {C0, C1, C2, C3};    //columns

/*******************************Function definition******************************/

//===========================Keypad_INIT Function===============================
void Keypad_INIT()
{
	Set_input(DDRD, 0x0F);              //Set 4-bit input
	Set_output(DDRD, 0XF0);             //Set 4-bit output
	Set_Pull_up(PORTD, 0x0F);           //Set Pull-up on
    Set_output(PORTD, 0xF0);            //Set all output Pins with High
    /**Last two lines can be shorten (Set_output(PORTD, 0xFF))**/
}

//===========================Keypad_Selected_char Function===============================
char Keypad_Selected_char()
{
	int i, j;
	//check is there is a selected button
	for (i = 0; i < 4; ++i)
	{
		Set_output(PORTD, 0xF0);
		Reset_bit(PORTD, Keypad_Col[i]);
		for (j = 0; j < 4; ++j)
		{
			if (!(Keypad_Pin & (1 << Keypad_Row[j]))) //Check if it is the selected button
			{
				switch (i)
				{
				case 0:
					if (j == 0)
						return '7';
					else if (j == 1)
						return '4';
					else if (j == 2)
						return '1';
					else if (j == 3)
						return '?';
					break;
				case 1:
					if (j == 0)
						return '8';
					else if (j == 1)
						return '5';
					else if (j == 2)
						return '2';
					else if (j == 3)
						return '0';
					break;
				case 2:
					if (j == 0)
						return '9';
					else if (j == 1)
						return '6';
					else if (j == 2)
						return '3';
					else if (j == 3)
						return '=';
					break;
				case 3:
					if (j == 0)
						return '/';
					else if (j == 1)
						return '*';
					else if (j == 2)
						return '-';
					else if (j == 3)
						return '+';
					break;
				}
			}
		}
	}
	return 'N';
}
