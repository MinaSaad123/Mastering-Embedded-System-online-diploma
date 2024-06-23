/*
 * Problem_3.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#include"stdio.h"

struct SComplex
{
int m_real;
int m_imaginary;

};
void sum_of_1_2();
void main()
{
struct SComplex first, second;
sum_of_1_2(first, second);


}
void sum_of_1_2(struct SComplex first, struct SComplex second)
{
	printf("for 1st complex number\t\n");
	printf("enter real and imaginary number respectivly :");
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d",&first.m_real,&first.m_imaginary);

	printf("for 2st complex number\t\n");
	printf("enter real and imaginary number respectivly :");
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d",&second.m_real,&second.m_imaginary);
	printf("sum = %d+%di",first.m_real + second.m_real,first.m_imaginary + second.m_imaginary);



}
