/*
@desc :
Write a program to perform Linear Search using pipes and fork ()
system calls.

@author : Ankit Apurv 180970042

@date 21/01/2019
*/

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	printf("02 Linear Search\n");
	char s1[10] = {'\0'}, key;
	int i, index=-1;
	printf("Input string : ");
	scanf("%10s", s1);
	printf("Key : ");
	scanf("%1s", &key);
	for(i=0; i<=9; i++)
	{
		if(s1[i] == key)
			index = i+1;
	}
	if(index > -1)
		printf("Key found at %d.\n", index);
	else
		printf("Key not found.\n");
	return 0;
}
