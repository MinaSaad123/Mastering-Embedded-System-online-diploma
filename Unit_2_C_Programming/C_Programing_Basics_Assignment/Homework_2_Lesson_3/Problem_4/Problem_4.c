/*
 * Problem_4.c
 *
 *  Created on: ??�/??�/????
 *      Author: HP
 */


#include"stdio.h"
void main(){
float x;
printf("Enter a  number:");
fflush(stdin);fflush(stdout);
scanf("%f",&x);
if(x>0) {
	printf("%f is positive",x);
}
else if(x<0){
	printf("%f is negative",x);
}
else {
	printf("you entered zero.");
}
}
