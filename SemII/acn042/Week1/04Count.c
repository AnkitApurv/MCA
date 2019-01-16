/*  author ankit apurv
	week 1 14/01/19
	desc to count words, vowels, consonants in child process
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	pid_t k = fork();
	if(k < 0)
	{
		printf("Child creation failed!\n");
		return 1;
	}
	
	else if(k == 0)
	{
		printf("Control in Child Process\n");

		FILE* f1 = fopen("/tmp/t1.txt", "a+");
		if(f1 == NULL)
		{
			printf("file not found!");
		}
		char buff[12];

		fputs("first file\n", f1);
		int i = 0;
		while(buff[i+1] !='\n')
		{
			buff[i] = (char)fgetc(f1);
			i++;
		}

		fclose(f1);

		int wordCount=1, vovewlCount=0;
		for(i=0; i<12; i++)
		{
			if(buff[i] == ' ')
				wordCount++;
			if(buff[i] == 'a' || buff[i] == 'e' || buff[i] == 'i' || buff[i] == 'o' || buff[i] == 'u' || buff[i] == 'A' || buff[i] == 'E' || buff[i] == 'I' || buff[i] == 'O' || buff[i] == 'U')
				vovewlCount++;
		}
		printf("Word Count : %d\n", wordCount);
		printf("Vovewl Count : %d\n", vovewlCount);

	}
	else if(k > 0)
	{
		wait(NULL);
		printf("Control in Parent process\n");
	}
	return 0;
}
