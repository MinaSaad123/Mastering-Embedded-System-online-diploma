/*
 * CA.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

//include lib
#include "CA.h"

//some of data types
static int CA_speed;
static int CA_distance;
static int CA_threshold = 50;




/************function defination**********/
//waiting state
ST_define(CA_waiting)
{
	//state status
	CA_status = CA_waiting;

	//state action
	CA_speed = 0;

	//print message
	printf("CA_waiting state: distance = %d, speed = %d\n", CA_distance, CA_speed);

	//send speed to DC
	DC_set_speed(CA_speed);

}
ST_define(CA_driving)
{
    CA_status = CA_driving;
    CA_speed = 30;
	DC_set_speed(CA_speed);
	printf("CA_driving state: distance = %d, speed = %d\n", CA_distance, CA_speed);

}
void US_get_distance(int distance)
{
	CA_distance = distance;
	(CA_distance <= CA_threshold) ? (CA_state = ST(CA_waiting)) : (CA_state = ST(CA_driving));
	printf("US----------distance = %d ------------>CA\n",CA_distance);

}


