/*
 * Problem_4.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
#include"stdio.h"
int main()
{
	int arr[15], y, i = 0;
	int *ptr = arr;
	printf("enter the number of elements to be stored in array (max 15) :");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &y);
	printf("input %d number of elements in the array\n", y);
	while(i < y )
	{
      printf("element -%d: ", i + 1 );
      fflush(stdin);
      fflush(stdout);
      scanf("%d", (ptr + i));
      i++;

	}
	while((i - 1) >= 0)
	{
		printf("element -%d : %d\n", i , *(ptr + i - 1));
		i--;

	}

	return 0;
}



