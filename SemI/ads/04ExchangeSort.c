//04 Exchange Sort
#include <stdio.h>
#include <stdlib.h>

int* sortExchange(int list[], int beginIndex, int endIndex);

int main(void)
{
	system("clear");
	printf("04 Echange Sort\n\n");

	printf("How long should the list be? ");
	unsigned int listSize;
	scanf("%u", &listSize);

	printf("\nFill the list (%d integers) :\n", listSize);
	int list[listSize], i;
	for(i = 0; i < listSize; i++)
		scanf("%d", &list[i]);

	int* sorted = sortExchange(list, 0, listSize-1);

	printf("\nSorted list :\n");
	for(i = 0; i < listSize; i++)
		printf("%d\t", sorted[i]);

	printf("\n");
	return(0);
}

int* sortExchange(int list[], int beginIndex, int endIndex)
{
	int temp, i, j;
	for(i = beginIndex; i < endIndex; i++)
	{
		for(j = i+1; j <= endIndex; j++)
		{
			if(list[i] > list[j])
			{
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}
	return(&list[beginIndex]);
}

