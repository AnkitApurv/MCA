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

		char buff[11] = {'\0'};

		FILE* f1a = fopen("t4.txt", "w");
		fprintf(f1a, "fourth file");
		fclose(f1a);

		FILE* f1b = fopen("t4.txt", "r");
		fgets(buff, 12, f1b);
		fclose(f1b);
		int i=0, wordCount=1, vovewlCount=0;
		while(i<11)
		{
			if(buff[i] == ' ')
				wordCount++;
			else if(buff[i] == 'a' || buff[i] == 'e' || buff[i] == 'i' || buff[i] == 'o' || buff[i] == 'u' || buff[i] == 'A' || buff[i] == 'E' || buff[i] == 'I' || buff[i] == 'O' || buff[i] == 'U')
				vovewlCount++;
			i++;
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
