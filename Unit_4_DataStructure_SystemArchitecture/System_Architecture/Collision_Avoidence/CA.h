/*
 * CA.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef CA_H_
#define CA_H_
//include lib
#include "state.h"

//enum status
enum
{
	CA_driving,
	CA_waiting
}CA_status;

//prototypes
ST_define(CA_driving);
ST_define(CA_waiting);

//pointer to function
void (*CA_state)();



#endif /* CA_H_ */
