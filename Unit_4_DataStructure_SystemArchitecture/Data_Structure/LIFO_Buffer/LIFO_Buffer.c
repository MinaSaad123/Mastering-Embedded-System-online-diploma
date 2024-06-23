/*
 * lifo_buffer.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

//header files
#include "LIFO_Buffer.h"
//initialize your buffer
LIFO_buf_status LIFO_buf_init(LIFO_buf_t* LIFO_buf, element_type* buf, unsigned int length   )
{
   if (buf == NULL)
	  return LIFO_null;
   //starts of lifo
   LIFO_buf->base = buf;
   LIFO_buf->head = LIFO_buf->base;
   LIFO_buf->count = 0;
   LIFO_buf->length = length;
   return LIFO_no_error;
}

//to check if lifo is empty or not
LIFO_buf_status LIFO_buf_emptyORnot(LIFO_buf_t* LIFO_buf)
{
	if (LIFO_buf->base == NULL)
		return LIFO_null;
	if (LIFO_buf->count == 0)
		return LIFO_empty;
    if (LIFO_buf->count == LIFO_buf->length)
    	return LIFO_full;
}
// add temp to your buffer
LIFO_buf_status LIFO_buf_push_item(LIFO_buf_t* LIFO_buf, element_type item)
{
	// buffer exist or not
    if ( LIFO_buf->base == NULL || LIFO_buf->head == NULL )
    return LIFO_null;
    // is there is space in buffer
    if (LIFO_buf->count <= LIFO_buf->length)
    {
       *(LIFO_buf->head) = item;
       LIFO_buf->head++;
       LIFO_buf->count++;
       return LIFO_no_error;
    }
    else return LIFO_full;
}
LIFO_buf_status LIFO_buf_pop_item(LIFO_buf_t* LIFO_buf, element_type* item)
{
      if(!LIFO_buf->base)
        return LIFO_null;
      if(LIFO_buf->count == 0)
    	return LIFO_empty;

      //poping
      LIFO_buf->head--;
      LIFO_buf->count--;
      *item = *(LIFO_buf->head);

      return LIFO_no_error;

}
