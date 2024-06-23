/*
 * WatchDogTimer_Driver.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef WATCHDOGTIMER_H_
#define WATCHDOGTIMER_H_

//============================<Includes>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "Utils.h"

//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
//                                            Support APIs by: TIMER
//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
void MCAL_WatchDogTimer_On ();
void MCAL_WatchDogTimer_Off ();



#endif /* WATCHDOGTIMER_H_ */
