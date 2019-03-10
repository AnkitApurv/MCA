/*
@desc :
Write a Client Server Program to input a string or number on the
parent, send to child and check whether they are palindromes and return the result
from the server to the client.

@author : Ankit Apurv 180970042

@date 21/01/2019
*/

#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	printf("01 Palindrome\n");
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
		
		
		char s1[10] = {'\0'};
		int length;
		printf("Word size : ");
		scanf("%d", &length);
		printf("Input string : \n");
		scanf("%s", s1);
		
		write(p[1], &length, sizeof(int));
		write(p[1], s1, sizeof(char)*10);
		
		wait(NULL);
		
		bool isPal = false;
		read(p[0], &isPal, sizeof(bool));
		
		
		if(isPal)
			printf("%s is palindrome.\n", s1);
		else
			printf("%s is not palindrome.\n", s1);
	}
	else if(k == 0)
	{
		printf("\nChild Process\n");
		
		char s2[10] = {'\0'}, s3[10] = {'\0'};
		bool isP = true;
		int i, j, l;
		
		read(p[0], &l, sizeof(int));
		read(p[0], s3, sizeof(char)*10);
		j=l-1;
		
		for(i=0; i<=l; i++)
		{
			s2[j--] = s3[i];
		}
		for(i=0; i<=l; i++)
		{
			if(s3[i] != s2[i])
			{
				isP = false;
				break;
			}
		}
		write(p[1], &isP, sizeof(bool));
	}	
	return 0;
}

