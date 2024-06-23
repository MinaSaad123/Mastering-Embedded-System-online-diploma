/*
 * Problem_7.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#include"stdio.h"
void main(){


	float a,b;
		printf("Enter the value of a:");
		fflush(stdin);fflush(stdout);
		scanf("%f",&a);
		printf("\nEnter the value of b:");

		fflush(stdin);fflush(stdout);
		scanf("%f",&b);
		a=a+b;
		b=a-b;
		a=a-b;
		printf("\t\nAfter swapping, value of a:%f\n",a);
		printf("After swapping, value of b:%f",b);




}
