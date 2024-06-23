/*
 * Problem_1.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#include"stdio.h"
void main(){
	float a,b,c;
	printf("Enter the value of a:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&a);
	printf("\nEnter the value of b:");

	fflush(stdin);fflush(stdout);
	scanf("%f",&b);
	c=a;
	a=b;
	b=c;
	printf("\t\nAfter swapping, value of a:%f\n",a);
	printf("After swapping, value of b:%f",b);


}
