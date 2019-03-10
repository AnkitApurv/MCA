/* @desc Using named pipes (FIFO’s), write a C program to perform the operation of integer array merging and the resultant 
array should be in sorted order. 
@name Ankit Apurv 180970042
@date 03/02/2019
@desc client
*/
#include <stdio.h>	//printf, scanf
#include <fcntl.h> //open()
#include <unistd.h>	//read, write

//#include <sys/types.h>
int main(void)
{
	int a1[5], a2[5], a3[10], i;
	printf("Sort Merge Client\n");
	
	int ff = open("fifo", O_WRONLY);
	printf("First array (5 integers) :\n");
	for(i=0; i<=4; i++)
	{
		scanf("%d", &a1[i]);
		write(ff, &a1[i], sizeof(int));
	}

	printf("Second array (5 integers) :\n");
	for(i=0; i<=4; i++)
	{
		scanf("%d", &a2[i]);
		write(ff, &a2[i], sizeof(int));
	}
	close(ff);
	
	ff = open("fifo", O_RDONLY);
	printf("Sorted, merged array :\n");
	for(i=0; i<=9; i++)
	{
		read(ff, &a3[i], sizeof(int));
		printf("%d\t", a3[i]);
	}
	printf("\n");
	close(ff);
	
	unlink("fifo");
	return 0;
}


