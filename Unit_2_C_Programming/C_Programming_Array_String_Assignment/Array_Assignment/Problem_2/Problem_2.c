/*
 * Problem_2.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */


#include"stdio.h"
void main(){

int x,i;
	printf("Enter number of data:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	float y[x],z=0;
	for(i=0;i<x;i++){
		printf("enter a[%d]",i);
			fflush(stdin);fflush(stdout);
			scanf("%f",&y[i]);
	}
		for(i=0;i<x;i++){
		z=z+y[i];
		}
		printf("average =%f",z/x);
}
