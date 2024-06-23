/*
 * DC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
//include lib
#include "DC.h"

//some datatypes
 static int DC_speed;


/************function defination**************/
//init DC driver
ST_define(DC_init)
{
	//init DC
	printf("DC_init \n");
}
//DC motor to get speed
void DC_set_speed(int speed)
{
	DC_speed = speed;
	printf("CA---------speed = %d------>DC\n", DC_speed);


}

//DC idl function
ST_define(DC_idl)//get speed from CA
{
	DC_status = DC_idl;
	printf("DC_idle State: speed=%d \n",DC_speed);
	DC_state = ST(DC_idl);

}

// i cant see benfits from busy states

