/*
 * fifo_buffer.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
#include "FIFO_Buffer.h"

FIFO_buf_status FIFO_buf_init(FIFO_buf_t* FIFO_buf, element_type* buf)
{
	//checking if buffer is exist
	if (buf == NULL)
	return FIFO_null;
	//passing details for buffer
	FIFO_buf->base = buf;
	FIFO_buf->head = FIFO_buf->base;
	FIFO_buf->tail = FIFO_buf->base;
	FIFO_buf->count = 0;
	FIFO_buf->length = width;
	return FIFO_no_error;
}
FIFO_buf_status FIFO_buf_enqueue(FIFO_buf_t* FIFO_buf, element_type item)
{
	if (FIFO_buf->base == NULL || FIFO_buf->head == NULL)
	return FIFO_null;
	/********accessing place in buffer********/
	//case buffer is full
	if (FIFO_buf->count == FIFO_buf->length)
		return FIFO_full;
	// general case
	*(FIFO_buf->head) = item;
	FIFO_buf->count++;
	FIFO_buf->head++;
	return FIFO_no_error;
}
//getting data from buffer
FIFO_buf_status FIFO_buf_dequeue(FIFO_buf_t* FIFO_buf, element_type* item)
{
	if (FIFO_buf->tail == FIFO_buf->base + FIFO_buf->length * sizeof(element_type))
	{
		*item = *(FIFO_buf->tail);
		FIFO_buf->tail = FIFO_buf->base;
		FIFO_buf->count--;
	}
    else if(FIFO_buf->count == 0)
	{
		return FIFO_empty;
	}
    else
    {
	*item = *(FIFO_buf->tail);
	FIFO_buf->tail++;
	FIFO_buf->count--;
    }

	return FIFO_no_error;
}
//checking fifo is full or not
FIFO_buf_status FIFO_buf_is_full(FIFO_buf_t* FIFO_buf)
{
	if (FIFO_buf->count == FIFO_buf->length)
	   return FIFO_full;
	return FIFO_no_error;
}
//printing function
void FIFO_print_buffer(FIFO_buf_t* FIFO_buf)
{
   element_type* temp;
   int i;
   int fun_count = FIFO_buf->count;
   if (FIFO_buf->count == 0)
   {
	   printf("FIFO is empty\n");
   }
   else
   {
	    temp = FIFO_buf->tail;
	    printf("******print FIFO****** \n");
	    for(i = fun_count;i != 0;--i)
	    {
           if(fun_count == FIFO_buf->length)
           {
        	   temp = FIFO_buf->base;

           }

        printf("FIFO print is done(%d) \n", *temp);
        temp++;
        fun_count--;


	    }
        printf("**********done**********\n\n");
   }

}
