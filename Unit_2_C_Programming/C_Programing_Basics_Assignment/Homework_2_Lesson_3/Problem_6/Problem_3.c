/*
 * Pproblem_3.c
 *
 *  Created on: ??�/??�/????
 *      Author: HP
 */

#include"stdio.h"
void main(){
int a,x=0;
printf("Enter an integer:");
fflush(stdin);fflush(stdout);
scanf("%d",&a);
for(int i=1;i<=a;i++){
	x=x+i;


}

printf("sum=%d",x);
}

