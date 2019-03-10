/*
@desc :
Write a program to perform Linear Search using pipes and fork ()
system calls.

@author : Ankit Apurv 180970042

@date 21/01/2019
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	printf("02 Linear Search\n");
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
		
		char s1[10] = {'\0'}, key;
		printf("Input string : ");
		scanf("%10s", s1);
		printf("Key : ");
		scanf("%1s", &key);
		
		//send s1, key
		write(p[1], s1, sizeof(char)*10);
		write(p[1], &key, sizeof(char));
		
		int indexP;
		wait(NULL);
		//recieve indexP
		read(p[0], &indexP, sizeof(int));
		if(indexP > -1)
			printf("Key found at %d.\n", indexP);
		else
			printf("Key not found.\n");
	}	
	else if(k == 0)
	{
		printf("\nChild Process\n");
		
		char s2[10] = {'\0'}, keyC;
		//recieve s2, keyC
		read(p[0], s2, sizeof(char)*10);
		read(p[0], &keyC, sizeof(char));
		int i, index=-1;
		for(i=0; i<=9; i++)
		{
			if(s2[i] == keyC)
				index = i+1;
		}
		//send index
		write(p[1], &index, sizeof(int));
	}
	return 0;
}
