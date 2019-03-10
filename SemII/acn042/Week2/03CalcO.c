/*
@desc :
Write a C program to perform menu based arithmetic operations
using pipes.

@author : Ankit Apurv 180970042

@date 21/01/2019
*/

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	printf("03 Calculator\n");
	int b, a, choice, result;
	printf("a : ");
	scanf("%d", &a);
	printf("b : ");
	scanf("%d", &b);
	printf("\nOperations \n 1.Division \n 2.Multiplication \n 3.Addition \n 4.Substraction \n Choice(int) : ");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			result = a/b;
			break;
		case 2:
			result = a*b;
			break;
		case 3:
			result = a+b;
			break;
		case 4:
			result = a-b;
			break;
		default:
			result=0;
	}
	printf("Result = %d\n", result);
	return 0;
}
