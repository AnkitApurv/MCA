/*  author ankit apurv
	week 1 14/01/19
	desc to merge files in child process and display the result using fork syscall
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
	else if(k > 0)
	{
		printf("Control in Parent process\n");
		wait(NULL);
	}
	else
	{
		printf("Control in Child Process\n");

		char buff1[12] = {'\0'};
		char buff2[12] = {'\0'};
		char buff3[24] = {'\0'};

		FILE* f1a = fopen("t1.txt", "w");
		fprintf(f1a,"first file ");
		fclose(f1a);

		FILE* f1b = fopen("t1.txt", "r");
		fgets(buff1, 12, f1b);
		fclose(f1b);

		printf("t1.txt : %s\n", buff1);

		FILE* f2a = fopen("t2.txt", "w");
		fprintf(f2a, "second file");
		fclose(f2a);
		
		FILE* f2b = fopen("t2.txt", "r");
		fgets(buff2, 12, f2b);
		fclose(f2b);

		printf("t2.txt : %s\n", buff2);

		FILE* f3a = fopen("t3.txt", "w");
		fprintf(f3a,"%s", buff1);
		fprintf(f3a,"%s", buff2);
		fclose(f3a);

		FILE* f3b = fopen("t3.txt", "r");
		fgets(buff3, 24, f3b);
		fclose(f3b);

		printf("t3.txt : %s\n", buff3);
	}
	return 0;
}
