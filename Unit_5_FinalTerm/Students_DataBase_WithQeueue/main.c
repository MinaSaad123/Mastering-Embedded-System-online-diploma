/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */


/*************************************************************************************************/
/*************i Try to do his project without count in FIFO element to get it harder**************/
/*************************************************************************************************/

//include libs
#include "Student_DataBase_With_Queue.h"

//set up buffer address
Sinfo_t Buffer[50];

//global buffer
FIFO_t DataBase;

//main function
int main()
{
	FIFO_Init_Buf(&DataBase, Buffer);
	int choice;
	while(1)
	{
		printf("Choose The Task that you want to perform\n");
		printf("1. Add the Student Details Manually\n");
		printf("2. Add the Student Details From Text File\n");
		printf("3. Find the Student Details by Roll Number\n");
		printf("4. Find the Student Details by First Name\n");
		printf("5. Find the Total number of Students\n");
		printf("6. Delete the Students Details by Roll Number\n");
		printf("7. Update the Students Details by Roll Number\n");
		printf("8. Show all information\n");
		printf("9. Find the Students Registered in Course\n");
		printf("10. To Exit\n");
		Dprint("Enter your choice to perform the task:")
		scanf("%d", &choice);
		printf("*****************************************************\n");
		switch(choice)
		{
		case 1:
		Add_Student_Details_manually(&DataBase);
		break;
		case 2:
		Add_Student_Details_From_File(&DataBase);
		break;
		case 3:
		Find_The_Student_By_Given_Roll(&DataBase);
		break;
		case 4:
		Find_The_Student_By_First_Name(&DataBase);
		break;
		case 5:
		Count_Of_Students(&DataBase);
		break;
		case 6:
		Delete_Student(&DataBase);
		break;
		case 7:
		Update_Student(&DataBase);
		break;
		case 8:
		Show_All_Information(&DataBase);
		break;
	    case 9:
		Find_The_Students_Registered_In_Course(&DataBase);
		break;
		case 10:
		exit(1);
		break;
		default:
		printf("[ERROR] Enter valid option\n");
		break;


		}
		printf("-------------------------------------------------------------------\n");
		printf("-------------------------------------------------------------------\n\n");
		

	}

	return 0;
}


