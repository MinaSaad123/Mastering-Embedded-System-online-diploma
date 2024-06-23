/*
 * student_database.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */


// include libs
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

//macro for printing
#define printD(...) {printf(__VA_ARGS__);\
                     fflush(stdin);\
                     fflush(stdout);\
                    }
//student data
struct Sdata
{
	char name[30];
	int ID;
	int height;
};
//init linked list details
 typedef struct Sstudent
{
	struct Sdata student;
	struct Sstudent* pNextStudent;
}student_t;

//first element in linked list
student_t* gpFirstStudent = NULL;

//function prototype
void fill_the_list(student_t* pNewStudent);


/*******function defination******/

//function to add student
int add_student()
{
    student_t* pLastStudent;
    student_t* pNewStudent = (student_t*)malloc(sizeof(student_t));
    pLastStudent = gpFirstStudent;
    if(gpFirstStudent)//checking if there is element in list
    {
    	while(pLastStudent->pNextStudent)//case it is not null
    	{
    		pLastStudent = pLastStudent->pNextStudent;

    	}
    	pLastStudent->pNextStudent = pNewStudent;

    }
    else //case it is null
    {
    	gpFirstStudent = pNewStudent;
    }
    //fill the data
    fill_the_list(pNewStudent);
    pNewStudent->pNextStudent = NULL;
    return 1;
}
void fill_the_list(student_t* pNewStudent)
{
	//print ID
	printD("\nEnter the ID:")
    scanf("%d", &(pNewStudent->student.ID));
	//print name
	printD("\nEnter the full name:")
    gets((pNewStudent->student.name));
	//print heigh
	printD("\nEnter the heigh:")
	scanf("%d", &(pNewStudent->student.height));
	//print line
	printD("\n")
}
int delete_student()
{
	int DELT_id;
	//get ID to be delete
    printD("Enter student ID to be deleted:")
	// get ID
	scanf("%d",&DELT_id);

   //checking there are a list pr not
    if(gpFirstStudent)// there is
    {
    	student_t* pSelectStudent = gpFirstStudent;
    	student_t* pPreviousStudent = NULL;
    	//check if we arrive to end of list
    	while(pSelectStudent)//no
    	{
    		//ID  is correct or not
    		if(pSelectStudent->student.ID == DELT_id)//yes
    		{
    			if(pPreviousStudent)
    		      {
    		         pPreviousStudent->pNextStudent = pSelectStudent->pNextStudent;
    		         free(pSelectStudent);
    		         return 1;
    		      }
    			else
    			{
    				gpFirstStudent = pSelectStudent->pNextStudent;
    				free(pSelectStudent);
    				return 1;
    			}
    		}
    		else //yes
    	    {
    		    pPreviousStudent = pSelectStudent;
    		    pSelectStudent = pSelectStudent->pNextStudent;
    		}

    	}
    	//this ID is not exist
    	printf("the Entered ID is not exist\n");
    	return 0;

    }
    else printf("the list empty\n");//there is not list
    return 0;
}
int delete_list()
{
	student_t* current_student = gpFirstStudent;
	//checking list exist or not
	if(current_student == NULL)//not exist
	{
		printf("list is empty/n");
		return 0;
	}
	else//exist
	{
        student_t* temp;

        while(current_student)//checking still there is element in list
        {
        	temp = current_student;
        	current_student = current_student->pNextStudent;
        	//delete element
        	free(temp);
        }
        gpFirstStudent = NULL;
        return 1;
	}

}
void view_student()
{
	student_t* current_student = gpFirstStudent;
	//check there is list or not
	if( current_student == NULL)//there is
	{
		printf("the list is empty\n");
	}
	else
	{   int count = 0;
		while(current_student)
		{
			//printing student details
			printf("\n record number is %d\n", count + 1);
			printf("\n student ID:%d\n", current_student->student.ID );
			printf("\n student name:%s\n", current_student->student.name);
			printf("\n student heigh is %d\n", current_student->student.height);
			printf("*******************************\n");
			//get another student
			current_student = current_student->pNextStudent;
			count++;

		}
	}
}
/***************we cannot know the middle of even with fast ptr and slow ptr*****************/
void number_of_students()
{
	student_t* current_student = gpFirstStudent;
	int count = 0;
	//check there is a list or not
	if(current_student)//yes
	{
		//loop to know number of students
	    while(current_student)
	    {
	    	count++;
	    	current_student = current_student->pNextStudent;
	    }
	    printf("number of students:%d \n", count);
	}
	else//no
	{
		printf("there is not students\n");
	}
}
int loop_detection()
{
	student_t* pSlow = gpFirstStudent, *pFast = gpFirstStudent;
    //arrive the end or not
	while(pFast && pFast->pNextStudent)
	{
       pSlow = pSlow->pNextStudent;
       pFast = pFast->pNextStudent->pNextStudent;
       //check there is a loop or not
       if(pFast == pSlow)
       {
    	   printf("/nthere is loop\n");
    	   return 1;
       }
	}
	printf("\n no loops exist\n");
	return 0;
}
void print_student_from_end()
{
	int n;
	printD("\nEnter the number you want to get from end:")
	scanf("%d", &n);
	student_t* reference = gpFirstStudent;
	student_t* pMain = gpFirstStudent;
	//make reference precedes main with n
	while(n)
	{
		reference = reference->pNextStudent;
		n--;
	}
	while(reference)//make main refer to n from end
	{
		pMain = pMain->pNextStudent;
		reference = reference->pNextStudent;
	}
	printf("\n student name:%s\n", pMain->student.name);
}

void reverse_list()
{
	student_t* selected_student = gpFirstStudent;
	student_t* temp;
	student_t* previous_student = NULL;
	if(selected_student == NULL)
	{
		printf("list is empty\n");
	}
	else
	{
        while(selected_student)
        {
    		temp = selected_student->pNextStudent;
    		selected_student->pNextStudent = previous_student;
    		previous_student = selected_student;
    		selected_student = temp;
        }
	}

}
int main()
{
	int i;
	while(1)
	{
		printf("      choose one option\n");
		printf("              ***\n");
		printf("1: addstudent\n");
		printf("2: delete_student\n");
		printf("3: view students\n");
		printf("4: delete_all\n");
		printf("5: number_of_students\n");
		printf("6: loop detection\n");
		printf("7: print student from end\n");
		printf("   **********************************\n");
        printD("Enter option number:")
		scanf("%d",&i);
        switch(i)
        {
        case 1:
        	add_student();
        	break;
        case 2:
        	delete_student();
        	break;
        case 3:
        	view_student();
        	break;
        case 4:
        	delete_list();
        	break;
        case 5:
        	number_of_students();
        	break;
        case 6:
        	loop_detection();
        	break;
        case 7:
        	print_student_from_end();
			break;
        }
	}


	return 0;
}





