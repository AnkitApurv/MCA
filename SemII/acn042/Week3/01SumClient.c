/* @desc Using named pipes (FIFO’s), write a C program to perform the summation of a given integer array.
@name Ankit Apurv 180970042
@date 28/01/2019
@desc client
*/
#include <stdio.h>	//printf, scanf
#include <fcntl.h> //open()
#include <unistd.h>	//read, write

//#include <sys/types.h>
int main(void)
{
	int aC[5], sumC=0, i;
	printf("Sum Client\n");
	printf("Input 5 integers : \n");
	for(i=0; i<=4; i++)
		scanf("%d", &aC[i]);

	int ff = open("fifo", O_WRONLY);
	for(i=0; i<=4; i++)
		write(ff, &aC[i], sizeof(int));
	close(ff);

	ff = open("fifo", O_RDONLY);
	read(ff, &sumC, sizeof(int));
	close(ff);

	unlink("fifo");
	
	printf("Sum : %d\n", sumC);
	return 0;
}


