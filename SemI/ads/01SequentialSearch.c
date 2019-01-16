//01 Sequential Search

#include <stdio.h>
#include <stdlib.h>

int searchSequential(int list[], int listSize, int key);

int main(void)
{
	system("clear");
	printf("01 Sequential Search\n\n");

	printf("How long should the list be? ");
	unsigned int listSize;
	scanf("%u", &listSize);

	printf("\nFill the list (%d integers) :\n", listSize);
	int list[listSize], i;
	for(i = 0; i < listSize; i++)
		scanf("%d", &list[i]);

	printf("\nProvide the key to be searched : ");
	int key;
	scanf("%d", &key);

	//-1 cannot be an array index, it denotes fail case
	int result = searchSequential(list, listSize, key);

	if(result == -1)
		printf("\nSearch is complete, no match is found!\n");
	else
		printf("\nSearch is complete, element found at index %d\n", result);

	return(0);
}

int searchSequential(int list[], int listSize, int key)
{
	//-1 cannot be an array index, it denotes fail case
	int index = -1;

	int i;
	for(i = 0; i < listSize; i++)
	{
		if(list[i] == key)
			return(i);
	}

	return(index);
}
