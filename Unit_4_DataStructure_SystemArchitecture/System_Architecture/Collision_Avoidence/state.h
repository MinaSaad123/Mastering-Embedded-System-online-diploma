/*
 * state.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef STATE_H_
#define STATE_H_
//include libs
#include "stdio.h"
#include "stdlib.h"

//text replacement for function
#define ST_define(state_fun) void ST_##state_fun()
#define ST(state_fun) ST_##state_fun

//models interface
void DC_set_speed(int speed);
void US_get_distance(int distance);

#endif /* STATE_H_ */
