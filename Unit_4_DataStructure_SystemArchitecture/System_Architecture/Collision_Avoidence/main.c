/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
#include "CA.h"
#include "US.h"
#include "DC.h"
void setup()
{
	ST(DC_init)();
	ST(US_init)();


	CA_state = ST(CA_waiting);
	US_state = ST(US_busy);
    DC_state = ST(DC_idl);
}
void main()
{
	 volatile int i;
	setup();
	while(1)
	{

		CA_state();
		US_state();
		DC_state();
		for(i=0;i<100000;i++);
	}
}

