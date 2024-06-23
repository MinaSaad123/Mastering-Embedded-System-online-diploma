/*
 * lifo_buffer.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef LIFO_BUFFER_H_
#define LIFO_BUFFER_H_
//headers files
#include "stdio.h"
#include "stdlib.h"

//choose your datatype
#define element_type char
#define width 5

typedef struct
{
	unsigned int  length;
	element_type* head;
	element_type* base;
	unsigned int  count;
}LIFO_buf_t;

typedef enum
{
	LIFO_no_error,
	LIFO_empty,
	LIFO_full,
	LIFO_null
}LIFO_buf_status;

//APIS
LIFO_buf_status LIFO_buf_init(LIFO_buf_t* LIFO_buf, element_type* buf, unsigned int length);
LIFO_buf_status LIFO_buf_emptyORnot(LIFO_buf_t* LIFO_buf);
LIFO_buf_status LIFO_buf_push_item(LIFO_buf_t* LIFO_buf, element_type item);
LIFO_buf_status LIFO_buf_pop_item(LIFO_buf_t* LIFO_buf, element_type* item);







#endif /* LIFO_BUFFER_H_ */
