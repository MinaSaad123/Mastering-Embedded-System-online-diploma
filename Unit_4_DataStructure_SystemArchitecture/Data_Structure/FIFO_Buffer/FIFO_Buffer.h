/*
 * fifo_buffer.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef FIFO_BUFFER_H_
#define FIFO_BUFFER_H_
//including libs
#include "stdio.h"
#include "stdlib.h"
//making length macro
#define width 5
//making datatype macro
#define element_type int
//initializing buffer details
typedef struct
{
	unsigned int length;
	unsigned int count;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_buf_t;
// enum errors
typedef enum
{
	FIFO_null,
	FIFO_no_error,
	FIFO_empty,
	FIFO_full
}FIFO_buf_status;
//APIS
FIFO_buf_status FIFO_buf_init(FIFO_buf_t* FIFO_buf, element_type* buf);
FIFO_buf_status FIFO_buf_enqueue(FIFO_buf_t* FIFO_buf, element_type item);
FIFO_buf_status FIFO_buf_dequeue(FIFO_buf_t* FIFO_buf, element_type* item);
FIFO_buf_status FIFO_buf_is_full(FIFO_buf_t* FIFO_buf);
void FIFO_print_buffer(FIFO_buf_t* FIFO_buf);

#endif /* FIFO_BUFFER_H_ */
