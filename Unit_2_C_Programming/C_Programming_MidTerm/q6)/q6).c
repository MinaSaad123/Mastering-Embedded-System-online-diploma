/*
 * q6).c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */


#include"stdio.h"

int main(){
void unique();
int x;
printf("please enter number:");
fflush(stdin);fflush(stdout);
scanf("%d",&x);
int v=0;

unique(x,v);

return 0;
}
void unique( int x,int v){
    int i,c,arr[x];
    //input array
    for(i=0;i<x;i++){
        printf("please enter:");
     fflush(stdin);fflush(stdout);
    scanf("%d",&arr[i]);
}


 re:
 c=0;
for(i=0;i<x;i++){
    if(arr[v]==arr[i]){
        c+=1;
    }
}
if(c==1){
    printf("%d\t",arr[v]);
}
v++;
if(v!=x) goto re;

}
