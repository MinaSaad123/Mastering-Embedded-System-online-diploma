/*
 * Problem_5.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */



#include"stdio.h"
void main(){
	int n,i,c,z=0;
	printf("please enter the number of elements:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	float x[n];
	for(i=0;i<n;i++){
		printf("please enter the element:");
		fflush(stdin);fflush(stdout);
		scanf("%f",&x[i]);
	}
	printf("enter the element to be searched:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&c);
for(i=0;i<n;i++){
if(x[i]==c){
    z=z+i+1;

}
else z=z;
}
	if(z==0){

		printf("the number is not exsit");
	}
	else printf("number found at the location :%d",z);
}
