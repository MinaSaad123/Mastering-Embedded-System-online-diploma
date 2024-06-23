/*
 * Problem_3.c
 *
 *  Created on: ??ş/??ş/????
 *      Author: HP
 */


#include"stdio.h"
void main(){
	float a,b,c;
printf("Enter a three number:");
fflush(stdin);fflush(stdout);
scanf("%f %f %f",&a,&b,&c);
if (a>b){
if (a>c){
printf("Largest number:%f",a);

}
else printf("Largest number:%f",c);
}
else if(b>a){
	if(b>c){
		printf("largest number:%f",b);
	}else printf("largest nuber:%f",c);
}
}
