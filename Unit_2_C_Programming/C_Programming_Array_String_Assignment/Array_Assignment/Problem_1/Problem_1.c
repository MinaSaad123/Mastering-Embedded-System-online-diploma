/*
 * Problem_1.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#include"stdio.h"
void main(){
int i,j;
float x[2][2],y[2][2],z[2][2];
for( i=0;i<2;i++){
for( j=0;j<2;j++){
	printf("enter a[%d][%d]",i,j);
	fflush(stdin);fflush(stdout);
	scanf("%f",&x[i][j]);
}

}
for( i=0;i<2;i++){
for( j=0;j<2;j++){
	printf("enter b[%d][%d]",i,j);
	fflush(stdin);fflush(stdout);
	scanf("%f",&y[i][j]);
}
}
printf("sum of matrix:\n");
for( i=0;i<2;i++){
for( j=0;j<2;j++){
	z[i][j]=x[i][j]+y[i][j];
	printf("%f\t",z[i][j]);
}
printf("\n");
}


}
