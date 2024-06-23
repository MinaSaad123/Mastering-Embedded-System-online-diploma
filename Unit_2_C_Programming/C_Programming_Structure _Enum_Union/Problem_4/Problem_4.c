/*
 * Problem_4.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */


#include"stdio.h"

struct Sstudent
{

char m_name[30];
int m_roll_number;
int m_mark;
}student_1;

void main()
{
    int i;
    struct Sstudent x[10];
	 for(i = 0; i < 10; i++)
	 {
	printf("Enter information of student %d\t\n",i + 1);
	printf("Enter name:");
	fflush(stdin);
	fflush(stdout);

	scanf("%s",&student_1.m_name);
	printf("Enter roll:");
	fflush(stdin);
	fflush(stdout);

    scanf("%d",&student_1.m_roll_number);
    printf("Enter marks: ");
    fflush(stdin);
    fflush(stdout);

    scanf("%d",&student_1.m_mark);
}
for(i = 0; i < 10; i++)
{
	printf("Displaing information\t\n");
	printf("name: %s\t\n",student_1.m_name);
	printf("roll: %d\t\n",student_1.m_roll_number);
	printf("marks: %d\t\n",student_1.m_mark);
}
/* EX6: output
size of union = 32
size of structure = 40*/
}
