/*
 * Problem_5.c
 *
 *  Created on: ??ş/??ş/????
 *      Author: HP
 */

#include"stdio.h"
struct employee
{
	char* m_name;
	int m_id;

}	S_emp1 = {"mina", 1000}, S_emp2 = {"saad", 1001}, S_emp3 = {"nazir", 1002};




int main()
{
struct employee* arr[3] = {&S_emp1, &S_emp2, &S_emp3};
struct employee (*(*ptr)[3]) = &arr;
printf("%s\n", (*(*ptr + 1))->m_name);
printf("%d", (*(*ptr + 1))->m_id);





	return 0;
}
