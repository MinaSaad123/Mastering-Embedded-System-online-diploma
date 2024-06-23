/*
 * q7).c
 *
 *  Created on: ??ş/??ş/????
 *      Author: HP
 */


#include"stdio.h"

int main(){
int sum(int);
int x=1;
printf("%d",sum(x));
return 0;
}
int sum(int x){


    if(x!=101){
return x+sum(x+1);}
return 0;
}
