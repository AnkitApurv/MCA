//05 Bubble Sort
#include <stdio.h>
#include <stdlib.h>

int* sortBubble(int list[], int beginIndex, int endIndex);

int main(void)
{
	system("clear");
	printf("05 Bubble Sort\n\n");

	printf("How long should the list be? ");
	unsigned int listSize;
	scanf("%u", &listSize);

	printf("\nFill the list (%d integers) :\n", listSize);
	int list[listSize], i;
	for(i = 0; i < listSize; i++)
		scanf("%d", &list[i]);

	int* sorted = sortBubble(list, 0, listSize-1);

	printf("\nSorted list :\n");
	for(i = 0; i < listSize; i++)
		printf("%d\t", sorted[i]);

	printf("\n");
	return(0);
}

int* sortBubble(int list[], int beginIndex, int endIndex)
{
	int temp, i, j;
	for(i = beginIndex; i <= endIndex; i++)
	{
		for(j = beginIndex; j <= endIndex-1; j++)
		{
			if(list[j] > list[j+1])
			{
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
	}
	return(&list[beginIndex]);
}


