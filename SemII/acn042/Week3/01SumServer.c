/* @desc Using named pipes (FIFO’s), write a C program to perform the summation of a given integer array.
@name Ankit Apurv 180970042
@date 28/01/2019
@desc server
*/
#include <stdio.h>	//printf, scanf
#include <fcntl.h> //open()
#include <unistd.h>	//read, write
#include <sys/stat.h> //mkfifo()

int main(void)
{
	int aS[5], sumS=0, i;
	printf("Sum Server\n");

	if (mkfifo("fifo", S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH) == -1)
		return -1;

	int ff = open("fifo", O_RDONLY);
	for(i=0; i<=4; i++)
		read(ff, &aS[i], sizeof(int));
	close(ff);
	
	
	for(i=0; i<=4; i++)
		sumS += aS[i];
	
	ff = open("fifo", O_WRONLY);
	write(ff, &sumS, sizeof(int));
	close(ff);

	close(ff);
	return 0;
}
