/*
 * Problem_8.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
#include"stdio.h"
void main(){

char x;
float a,b;

printf("Enter operator either +,-.*,/:");
fflush(stdin);fflush(stdout);
scanf("%c",&x);
printf("Enter two operands");
fflush(stdin);fflush(stdout);
scanf("%f %f",&a,&b);

	switch(x){
	case '+':
printf("%f+%f=%f",a,b,a+b);
break;
	case '-':
	printf("%f-%f=%f",a,b,a-b);
	break;
	case '*':
	printf("%f*%f=%f",a,b,a*b);
	break;
	case '/':
	printf("%f/%f=%f",a,b,a/b);
	break;
	default:
		printf("ERROR");
}

}

