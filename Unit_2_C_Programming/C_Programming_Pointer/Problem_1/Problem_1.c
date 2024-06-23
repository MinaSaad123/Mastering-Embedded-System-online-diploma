/*
 * Problem_1.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
#include"stdio.h"
int main()
{
	int m = 29;
	int* ab = &m;
	printf("address of m:%p\t\nvalue of m:%d\n now ab is assigned with address of m.\t\naddress of pointer ab:%p\t\ncontent of pointer:%d\n", &m, m, ab, *ab);
	*ab = 34;
	printf("the value of m is assigned to 34 now.\t\naddress of pointer ab:%p\t\ncontent of pointer:%d\n", ab, *ab);
	*ab = 7;
	printf("the value of ab is assigned with value of 7 now.\t\nthe address of m ; %p\t\nthe value of m : %d", &m, m);

return 0;

}

