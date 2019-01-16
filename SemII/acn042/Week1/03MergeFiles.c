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

		FILE* f1 = fopen("/tmp/t1.txt", "a+");
		FILE* f2 = fopen("/tmp/t2.txt", "a+");
		FILE* f3 = fopen("/tmp/t3.txt", "a+");	
		
		char buff[24] = {'\0'};

		fputs("first file\n", f1);
		fgets(buff, 11, f1);
		fclose(f1);
		printf("t1.txt : %s\n", buff);
		fputs(buff, f3);

		fputs("second file\n", f2);
		fgets(buff, 12, f2);
		fclose(f2);
		printf("t2.txt : %s\n", buff);
		fputs(buff, f3);

		fgets(buff, 24, f3);
		printf("t3.txt : %s\n", buff);

		fclose(f3);
	}
	return 0;
}
