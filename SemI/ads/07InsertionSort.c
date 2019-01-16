//07 Insertion Sort
#include <stdio.h>
#include <stdlib.h>

int* sortInsertion(int list[], int beginIndex, int endIndex);

int main(void)
{
	system("clear");
	printf("06 Insertion Sort\n\n");

	printf("How long should the list be? ");
	unsigned int listSize;
	scanf("%u", &listSize);

	printf("\nFill the list (%d integers) :\n", listSize);
	int list[listSize], i;
	for(i = 0; i < listSize; i++)
		scanf("%d", &list[i]);

	int* sorted = sortInsertion(list, 0, listSize-1);

	printf("\nSorted list :\n");
	for(i = 0; i < listSize; i++)
		printf("%d\t", sorted[i]);

	printf("\n");
	return(0);
}

int* sortInsertion(int list[], int beginIndex, int endIndex)
{
	int temp, i, j;
	for(i = beginIndex+1; i <= endIndex; i++)
	{
		j = i;
		while(list[j] < list[j-1] && j > 0)
		{
			temp = list[j];
			list[j] = list[j-1];
			list[j-1] = temp;
			j--;
		}
	}
	return(&list[beginIndex]);
}


