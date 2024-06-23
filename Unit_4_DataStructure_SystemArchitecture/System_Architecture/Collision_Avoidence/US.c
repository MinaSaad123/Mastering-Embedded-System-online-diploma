/*
 * US.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
//include lib
#include "US.h"

//some of datatypes
static int US_distance;

/**********function defination************/
ST_define(US_busy)//know the new distance
{
	//get new distance
    US_distance = ((rand() % 10) + 45);
	printf("US_busy State: distance = %d  \n ",US_distance);
	//Sending distance to CA
	US_get_distance(US_distance);
	//loop itself
	US_state =ST(US_busy);

}
ST_define(US_init)
{
	//init US
	printf("US_init \n");

}


