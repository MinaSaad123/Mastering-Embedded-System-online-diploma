/*
 * DC.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef DC_H_
#define DC_H_
//include lib
#include "state.h"

//enum status
enum
{
	DC_idl,
	DC_busy
}DC_status;

//prototypes
ST_define(DC_idl);
ST_define(DC_busy);
ST_define(DC_init);

//pointer to function
void (*DC_state)();



#endif /* DC_H_ */
