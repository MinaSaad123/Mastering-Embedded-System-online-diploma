/*
 * WatchDogTimer_Driver.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

//================================<Includes>
#include "WatchDogTimer.h"

//===================================<MCAL_WatchDogTimer_On Function>
void MCAL_WatchDogTimer_On()
{
	WDTCR = (1 << WDP0) | (1 << WDP1) | (1 << WDP2) | (1 << WDE);
}

//===================================<MCAL_WatchDogTimer_Off Function>
void MCAL_WatchDogTimer_Off()
{
	WDTCR = (1<<WDTOE)|(1<<WDE);
	WDTCR = 0x00;
}

