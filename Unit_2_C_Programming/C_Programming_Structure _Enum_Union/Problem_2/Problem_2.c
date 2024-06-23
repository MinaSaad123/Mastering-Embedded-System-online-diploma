/*
 * Problem_2.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
#include"stdio.h"

struct SDistance
{
int m_feet;
int m_inch;
} st1, st2;
void st1_distance();
void st2_distance();
void sum();
int main()
{

 distance(st1, st2);

}
void distance(struct SDistance st1)
{
   printf("Enter information for 1st\t\n");
   printf("Enter feet: ");
   fflush(stdin);
   fflush(stdout);
   scanf("%d",&st1.m_feet);

   printf("Enter inch: ");
   fflush(stdin);
   fflush(stdout);
   scanf("%d",&st1.m_inch);

   printf("Enter information for 2st\t\n");
   printf("Enter feet: ");
   fflush(stdin);
   fflush(stdout);
   scanf("%d",&st2.m_feet);

   printf("Enter inch: ");
   fflush(stdin);
   fflush(stdout);
   scanf("%d",&st2.m_inch);

   printf("sum= %d, %d",st2.m_feet + st1.m_feet,st2.m_inch + st1.m_inch);
}

