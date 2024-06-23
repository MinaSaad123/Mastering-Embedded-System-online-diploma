/*
 * US.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef US_H_
#define US_H_
//include lib
#include "state.h"

//enum status
enum
{
	US_idl,
	US_busy
}US_status;

//prototypes
ST_define(US_busy);
ST_define(US_init);

//pointer to function
void (*US_state)();




#endif /* US_H_ */
