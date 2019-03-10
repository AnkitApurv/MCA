/* @desc Write a program to validate the user name and password given by the client and return the result.  
@name Ankit Apurv 180970042
@date 03/02/2019
@desc client
*/
#include <stdio.h>	//printf, scanf
#include <fcntl.h> //open()
#include <unistd.h>	//read, write
#include <stdbool.h>

int main(void)
{
	int i;
	char idC[5], passwdC[5];
	bool isValid = false;

	printf("Validate Client\n");
	
	int ff = open("fifo", O_WRONLY);
	printf("Username :\n");
	scanf("%4s", idC);
	for(i=0; i<=4; i++)
		write(ff, &idC[i], sizeof(char));

	printf("Passwd :\n");
	scanf("%4s", passwdC);
	for(i=0; i<=4; i++)
		write(ff, &passwdC[i], sizeof(char));
	close(ff);

	printf("Result : ");
	ff = open("fifo", O_RDONLY);
	read(ff, &isValid, sizeof(int));
	close(ff);
	if(isValid)
		printf("true\n");
	else
		printf("false\n");

	
	unlink("fifo");
	return 0;
}


