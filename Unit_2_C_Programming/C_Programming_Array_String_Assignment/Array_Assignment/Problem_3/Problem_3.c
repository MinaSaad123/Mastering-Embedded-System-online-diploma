/*
 * Problem_3.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */


#include"stdio.h"
void main (){
int i,j;
float x[2][3],y[3][2];
printf("Enter the matrix:\n");
for(i=0;i<2;i++){
for(j=0;j<3;j++){
printf("Enter the element a%d%d:",i,j);
fflush(stdin);fflush(stdout);
scanf("%f",&x[i][j]);
}

}
for(i=0;i<2;i++){
for(j=0;j<3;j++){
printf("%f\t",x[i][j]);

}printf("\n");
}
for(i=0;i<2;i++){
	for(j=0;j<3;j++){
y[j][i]=x[i][j];
	}
}
printf("\n");
	for(i=0;i<3;i++){
	for(j=0;j<2;j++){
	printf("%f\t",y[i][j]);

	}

		printf("\n");
	}

}
