/*  author ankit apurv
	week 1 14/01/19
	desc to demonstrate fork() syscall
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t k = fork();
	if(k < 0)
		printf("Child creation failed!\n");
	else if(k == 0)
		printf("This is child process.\n");
	else
		printf("This is parent process.\n");
	pid_t self = getpid();
	pid_t parent = getppid();
	printf("Parent PID : %d\n", parent);
	printf("Self PID : %d\n", self);
	if(k > 0)
		wait(NULL);	//allow child to terminate before parent
	return 0;
}
