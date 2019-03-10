/* @desc Using named pipes (FIFO’s), write a C program to perform the operation of integer array merging and the resultant 
array should be in sorted order. 
@name Ankit Apurv 180970042
@date 03/02/20191/2019
@desc server
*/
#include <stdio.h>	//printf, scanf
#include <fcntl.h> //open()
#include <unistd.h>	//read, write
#include <sys/stat.h> //mkfifo()

void merge(int a1[], int l1, int a2[], int l2, int a3[])
{
	int i, j=0;
	for(i=0; i<=l1-1; i++)
		a3[j++] = a1[i];

	for(i=0; i<=l2-1; i++)
		a3[j++] = a2[i];

	return;
}

void sort(int a[], int l)
{
	int i, j, swap;
	for(i=0; i<l; i++)
	{
		for(j=0; j<l-1; j++)
		{
			if(a[j] > a[j+1])
			{
				swap = a[j];
				a[j] = a[j+1];
				a[j+1] = swap;
			}
		}
	}
	return;
}

int main(void)
{
	int a1[5], a2[5], a3[10], i;
	printf("Sort Merge Server\n");

	if (mkfifo("fifo", S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH) == -1)
		return -1;

	int ff = open("fifo", O_RDONLY);
	printf("First array (5 integers) :\n");
	for(i=0; i<=4; i++)
		read(ff, &a1[i], sizeof(int));

	printf("Second array (5 integers) :\n");
	for(i=0; i<=4; i++)
		read(ff, &a2[i], sizeof(int));
	close(ff);
	
	merge(a1, 5, a2, 5, a3);
	sort(a3, 10);

	ff = open("fifo", O_WRONLY);
	printf("Sorted, merged array :\n");
	for(i=0; i<=9; i++)
		write(ff, &a3[i], sizeof(int));
	close(ff);
	return 0;
}
