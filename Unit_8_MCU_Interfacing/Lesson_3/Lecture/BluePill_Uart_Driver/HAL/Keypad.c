/*
 * Keypad.c
 *
 *  Created on: ??�/??�/????
 *      Author: HP
 */

//======Include
#include "Keypad.h"
#include "Stm32f103c6_GPIO_Driver.h"
#include "Stm32f103x6.h"
//Static array
int Keypad_Row[] = {R0, R1, R2, R3};    //rows
int Keypad_Col[] = {C0, C1, C2, C3};    //columns

/*******************************Function definition******************************/

//===========================Keypad_INIT Function===============================
void Keypad_GPIO_Init()
{
	GPIO_Config_t KeyPad_Pins;
	int i;

	//==============================Set Inputs
	//R0
	KeyPad_Pins.GPIO_PinNumber = R0;
	KeyPad_Pins.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	KeyPad_Pins.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_INIT(GPIOA, &KeyPad_Pins);
	//R1
	KeyPad_Pins.GPIO_PinNumber = R1;
	KeyPad_Pins.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	KeyPad_Pins.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_INIT(GPIOA, &KeyPad_Pins);
	//R2
	KeyPad_Pins.GPIO_PinNumber = R2;
	KeyPad_Pins.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	KeyPad_Pins.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_INIT(GPIOA, &KeyPad_Pins);
	//R3
	KeyPad_Pins.GPIO_PinNumber = R3;
	KeyPad_Pins.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	KeyPad_Pins.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_INIT(GPIOA, &KeyPad_Pins);

	//==============================Set Output
    //C0
	KeyPad_Pins.GPIO_PinNumber = C0;
	KeyPad_Pins.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_10M;
	KeyPad_Pins.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOB, &KeyPad_Pins);
    //C1
	KeyPad_Pins.GPIO_PinNumber = C1;
	KeyPad_Pins.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_10M;
	KeyPad_Pins.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOB, &KeyPad_Pins);
    //C2
	KeyPad_Pins.GPIO_PinNumber = C2;
	KeyPad_Pins.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_10M;
	KeyPad_Pins.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOB, &KeyPad_Pins);
    //C3
	KeyPad_Pins.GPIO_PinNumber = C3;
	KeyPad_Pins.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_10M;
	KeyPad_Pins.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOB, &KeyPad_Pins);

	//make all output HIGH
	for(i = 0; i < 4;++i)
	{
		MCAL_GPIO_WritePin(GPIOB, HIGH, Keypad_Col[i]);
	}

	for(i = 0; i < 4;++i)
	{
		MCAL_GPIO_WritePin(KeyPad_Input, HIGH, Keypad_Row[i]);
	}

}

//===========================Keypad_Selected_char Function===============================
char Keypad_Selected_char()
{
	int i, j;
	//check is there is a selected button

		for (i = 0; i < 4; ++i)
		{
			MCAL_GPIO_WritePin(KeyPad_Output, HIGH, C0);
			MCAL_GPIO_WritePin(KeyPad_Output, HIGH, C1);
			MCAL_GPIO_WritePin(KeyPad_Output, HIGH, C2);
			MCAL_GPIO_WritePin(KeyPad_Output, HIGH, C3);

			//Make Output LOW
			MCAL_GPIO_WritePin(KeyPad_Output, LOW, Keypad_Col[i]);

			for (j = 0; j < 4; ++j)
			{
				if (!(MCAL_GPIO_ReadPin(KeyPad_Input, Keypad_Row[j]))) //Check if it is the selected button
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


