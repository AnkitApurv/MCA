/*
@desc :
Write a C program to perform menu based arithmetic operations
using pipes.

@author : Ankit Apurv 180970042

@date 21/01/2019
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	printf("03 Calculator\n");
	
	int p[2];
	if(pipe(p) == -1) return -1;
	pid_t k = fork();
	if(k < 0)
	{
		printf("Child creation failed!\n");
		return 1;
	}
	else if(k > 0)
	{
		printf("\nParent process\n");
	
		int x, y, choiceP, resultP;
		printf("x : "); scanf("%d", &x);
		printf("y : "); scanf("%d", &y);
		printf("\nOperations \n 1.Division \n 2.Multiplication \n 3.Addition \n 4.Substraction \n Choice(int) : "); 
		scanf("%d", &choiceP);
		
		//send x, y, choiceP
		write(p[1], &x, sizeof(int));
		write(p[1], &y, sizeof(int));
		write(p[1], &choiceP, sizeof(int));
		
		//wait and recieve resultP
		wait(NULL);
		read(p[0], &resultP, sizeof(int));
		printf("Result = %d\n", resultP);
	}	
	else if(k == 0)
	{
		printf("\nChild Process\n");
		
		int a, b, choice, result;
		//recieve a, b, choice
		read(p[0], &a, sizeof(int));
		read(p[0], &b, sizeof(int));
		read(p[0], &choice, sizeof(int));
		
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
		//send result
		write(p[1], &result, sizeof(int));
	}	
	return 0;
}
