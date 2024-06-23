/*
 * ATmega32_Leds_Toggles_Sequentially_With_Alarm.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

//Include Libs
#include "util/delay.h"

//Typedef
typedef volatile unsigned int vuint32_t;

/*******GPIOA Register Addresses*********/
#define PORTD     *((vuint32_t*)0x32)
#define DDRD      *((vuint32_t*)0x31)

/*********Function definition***********/
//GPIO init Function
void GPIO_INIT()
{
	  PORTD &= ~(0xff);
	  //Make (Port4, PortD5, PortD6, PortD7) Output
	  DDRD  |= (0b11110000);

}

//Main Function
int main()
{
	GPIO_INIT();

	//**The Task** Toggle Leds Sequentially with Alarm
	while(1)
	{
		//Toggle Led 1
		PORTD |= 0b00100000;
		_delay_ms(500);
		PORTD &= ~0b0100000;
		//Toggle Led 2
		PORTD |= 0b01000000;
		_delay_ms(500);
		PORTD &= ~0b01000000;
		//Toggle Led 3
		PORTD |= 0b10000000;
		_delay_ms(500);
		PORTD &= ~0b10000000;
		//Alarm on
		PORTD  |= (0b00010000);
		_delay_ms(5000);
		//Alarm off
		PORTD  &= ~(0b00010000);






	}



	return 0;
}

