/*
@desc :
Write a Client Server Program to input a string or number on the
client and check whether they are palindromes and return the result
from the server to the client.

@author : Ankit Apurv 180970042

@date 21/01/2019
*/

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	printf("01 Palindrome\n");
	char s1[10] = {'\0'}, s2[10] = {'\0'};
	int i, j, length;
	printf("Word size : ");
	scanf("%d", &length);
	printf("Input string : \n");
		scanf("%s", s1);
	bool isP = true;
	/*
	j=length-1;
	for(i=0; i<=length; i++)
	{
		s2[j--] = s1[i];
	}
	for(i=0; i<=length; i++)
	{
		if(s1[i] != s2[i])
		{
			isP = false;
			break;
		}
	}
	*/
	for(i=0; i<length; i++)
	{
		if(s1[i] != s1[(length-1) - i])
		{
			isP = false;
			break;
		}
	}
	if(isP)
		printf("%s is palindrome.\n", s1);
	else
		printf("%s is not palindrome.\n", s1);
	return 0;
}

