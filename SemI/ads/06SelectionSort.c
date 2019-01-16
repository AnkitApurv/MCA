//06 Selection Sort
#include <stdio.h>
#include <stdlib.h>

int* sortSelection(int list[], int beginIndex, int endIndex);

int main(void)
{
	system("clear");
	printf("06 Selection Sort\n\n");

	printf("How long should the list be? ");
	unsigned int listSize;
	scanf("%u", &listSize);

	printf("\nFill the list (%d integers) :\n", listSize);
	int list[listSize], i;
	for(i = 0; i < listSize; i++)
		scanf("%d", &list[i]);

	int* sorted = sortSelection(list, 0, listSize-1);

	printf("\nSorted list :\n");
	for(i = 0; i < listSize; i++)
		printf("%d\t", sorted[i]);

	printf("\n");
	return(0);
}

int* sortSelection(int list[], int beginIndex, int endIndex)
{
	int temp, i, j, indexOfSmallest;
	for(i = beginIndex; i <= endIndex; i++)
	{
		indexOfSmallest = i;
		for(j = i; j <= endIndex; j++)
		{
			if(list[i] > list[j])
				indexOfSmallest = j;
		}
		if(indexOfSmallest != i)
		{
			temp = list[indexOfSmallest];
			list[indexOfSmallest] = list[i];
			list[i] = temp;
		}
	}
	return(&list[beginIndex]);
}


