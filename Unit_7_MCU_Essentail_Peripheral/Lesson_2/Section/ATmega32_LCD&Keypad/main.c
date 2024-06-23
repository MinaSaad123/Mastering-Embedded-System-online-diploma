/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */


//Include Libs
#include "GPIO.h"
#include "LCD.h"
#include "Keypad.h"
int main()
{
	char character;
	LCD_INIT();
	//Printing in LCD
	LCD_Send_string("Thanks");
	_delay_ms(1000);
	Keypad_INIT();
	while(1)
	{
		character = Keypad_Selected_char();
		switch(character)
		{
		    //No character is Selected
		    case 'N':
			break;
			//Clear screen
		    case '?':
			LCD_Send_Command(Clear_Display);
			break;
			//Write character on screen
		    default:
		    LCD_Send_char(character);
			break;
		}
		while(Keypad_Selected_char() == character);
	}
    return 0;
}
