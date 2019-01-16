//03 Binary Search Recursive

#include <stdio.h>
#include <stdlib.h>

int searchBinaryRecursive(int list[], int beginIndex, int endIndex, int key);

int main(void)
{
	system("clear");
	printf("03 Binary Search Recursive\n\n");

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
	int result = searchBinaryRecursive(list, 0, listSize-1, key);

	if(result == -1)
		printf("\nSearch is complete, no match is found!\n");
	else
		printf("\nSearch is complete, element found at index %d\n", result);

	return(0);
}


int searchBinaryRecursive(int list[], int beginIndex, int endIndex, int key)
{
	int index = -1;

	while(beginIndex <= endIndex)
	{
		int midIndex = (beginIndex + endIndex) / 2;

		if(key == list[midIndex])
			return(midIndex);
		else if(key < list[midIndex])
			return searchBinaryRecursive(list, beginIndex, midIndex-1, key);
		else //key > list[midIndex]
			return searchBinaryRecursive(list, midIndex+1, endIndex, key);
	}
	return(index);
}
