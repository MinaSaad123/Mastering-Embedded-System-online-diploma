/*
 * Problem_4.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
#include"stdio.h"

void main(){
int location,n,i;
printf("please enter the number of elements:");
fflush(stdin);fflush(stdout);
scanf("%d",&n);
float x[n],c;
for(i=0;i<n;i++){
	printf("please enter the element:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&x[i]);
}
float z[n+1];
printf("please enter the element to be insert:");
fflush(stdin);fflush(stdout);
scanf("%f",&c);
printf("please enter the location:");
fflush(stdin);fflush(stdout);
scanf("%d",&location);
for( i=0;i<=n;i++){
if(i<(location-1)){
z[i]=x[i];}
else if (i==(location-1)){z[i]=c;}
else {z[i]=x[i-1];}
}

for(i=0;i<=n;i++){

	printf("%f\t",z[i]);

}
}

