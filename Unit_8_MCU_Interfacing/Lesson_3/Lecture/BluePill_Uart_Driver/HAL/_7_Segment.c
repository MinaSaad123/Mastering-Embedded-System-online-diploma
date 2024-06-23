/*
 * _7_Segment.c
 *
 *  Created on: ٠٧‏/٠٩‏/٢٠٢٣
 *      Author: HP
 */

//Include
#include "Stm32f103c6_GPIO_Driver.h"
#include "Stm32f103x6.h"
#include "_7_Segment.h"

//========Global variable
uint32_t _7_Segment[10] = {Num0, Num1, Num2, Num3};


/*********Function definition***********/
//====_7_Segment_INIT Function
void _7_Segment_GPIO_Init()
{
	GPIO_Config_t _7_Segment_Pin;

	//==========7 Segment Pins
	//PinA8
	_7_Segment_Pin.GPIO_PinNumber = GPIO_PIN_8;
	_7_Segment_Pin.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_10M;
	_7_Segment_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOB, &_7_Segment_Pin);
	//PinA9
	_7_Segment_Pin.GPIO_PinNumber = GPIO_PIN_9;
	_7_Segment_Pin.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_10M;
	_7_Segment_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOB, &_7_Segment_Pin);
	//PinA10
	_7_Segment_Pin.GPIO_PinNumber = GPIO_PIN_10;
	_7_Segment_Pin.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_10M;
	_7_Segment_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOB, &_7_Segment_Pin);
	//PinA11
	_7_Segment_Pin.GPIO_PinNumber = GPIO_PIN_11;
	_7_Segment_Pin.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_10M;
	_7_Segment_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOB, &_7_Segment_Pin);
	//PinA12
	_7_Segment_Pin.GPIO_PinNumber = GPIO_PIN_12;
	_7_Segment_Pin.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_10M;
	_7_Segment_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOB, &_7_Segment_Pin);
	//PinA13
	_7_Segment_Pin.GPIO_PinNumber = GPIO_PIN_13;
	_7_Segment_Pin.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_10M;
	_7_Segment_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_INIT(GPIOB, &_7_Segment_Pin);
	//PinA14
	_7_Segment_Pin.GPIO_PinNumber = GPIO_PIN_14;
	_7_Segment_Pin.GPIO_Output_SPEED = GPIO_OUTPUT_SPEED_10M;
	_7_Segment_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_Set_Output_Particular(GPIOB, 0xff << 8);
}

 void _7_Segment_Display(int i)
{
	//Clean 7-Segment
	MCAL_GPIO_Set_Output_Particular(GPIOB, 0xEf << 8);
	//Display The Number
	MCAL_GPIO_Reset_Output_Particular(GPIOB, _7_Segment[i] << 8);

}

