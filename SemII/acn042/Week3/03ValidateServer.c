/* @desc Write a program to validate the user name and password given by the client and return the result. 
@name Ankit Apurv 180970042
@date 03/02/2019
@desc server
*/
#include <stdio.h>	//printf, scanf
#include <fcntl.h> //open()
#include <unistd.h>	//read, write
#include <sys/stat.h> //mkfifo()
#include <stdbool.h>
#include <string.h>

int main(void)
{
	int i;
	char idC[5], passwdC[5];
	char id[5] = "wert";
	char passwd[5] = "ghjk";
	bool isValid = false;

	if (mkfifo("fifo", S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH) == -1)
		return -1;

	printf("Validate Server\n");
	
	int ff = open("fifo", O_RDONLY);
	printf("Username :\n");
	for(i=0; i<=4; i++)
		read(ff, &idC[i], sizeof(char));

	printf("Passwd :\n");
	for(i=0; i<=4; i++)
		read(ff, &passwdC[i], sizeof(char));
	close(ff);

	printf("Result :\n");
	if(strcmp(id, idC) == 0 && strcmp(passwd, passwdC) == 0)
		isValid = true;
	else
		isValid=false;
	ff = open("fifo", O_WRONLY);
	write(ff, &isValid, sizeof(int));
	close(ff);
	return 0;
}
