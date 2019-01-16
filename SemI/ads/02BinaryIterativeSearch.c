//02 Binary Search Iterative

#include <stdio.h>
#include <stdlib.h>

int searchBinaryIterative(int list[], int beginIndex, int endIndex, int key);

int main(void)
{
	system("clear");
	printf("02 Binary Search Iterative\n\n");

	printf("How long should the list be? ");
	unsigned int listSize;
	scanf("%u", &listSize);

	printf("\nFill the list (%d integers)(ascending order) :\n", listSize);
	int list[listSize], i;
	for(i = 0; i < listSize; i++)
		scanf("%d", &list[i]);

	printf("\nProvide the key to be searched : ");
	int key;
	scanf("%d", &key);

	//-1 cannot be an array index, it denotes fail case
	int result = searchBinaryIterative(list, 0, listSize-1, key);

	if(result == -1)
		printf("\nSearch is complete, no match is found!\n");
	else
		printf("\nSearch is complete, element found at index %d\n", result);

	return(0);
}


int searchBinaryIterative(int list[], int beginIndex, int endIndex, int key)
{
	//-1 cannot be an array index, it denotes fail case
	int index = -1;

	while(beginIndex <= endIndex)
	{
		int midIndex = (beginIndex + endIndex) / 2;

		if(key == list[midIndex])
			return(midIndex);
		else if(key < list[midIndex]) //key in earlier half
			endIndex = midIndex - 1;
		else //key > list[midIndex] - key in later half
			beginIndex = midIndex + 1;
	}
	return(index);
}
