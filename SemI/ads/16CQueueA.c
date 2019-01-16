//16 Circular Circular Queue via Array
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//insert - incerment lastIndex, then insert
//delete - store for return, then increment firstIndex

bool insertQ(int queue[], int size, int *pFirstIndex, int *pLastIndex, int value)
{
    if((*pLastIndex == size-1 && *pFirstIndex == 0) || (*pLastIndex == (*pFirstIndex)-1))
    {
        printf("Circular Queue is full!, Cannot insert\n");
        return(false);
    }
    if(*pLastIndex == size-1)
        *pLastIndex = 0;
    else if( (*pFirstIndex == -1) && (*pLastIndex == -1) )
        *pFirstIndex = *pLastIndex = 0;
    else
        (*pLastIndex)++;
    queue[*pLastIndex] = value;
    return(true);
}

int removeQ(int queue[], int size, int *pFirstIndex, int *pLastIndex, bool *pSuccess)
{
    if( (*pFirstIndex == -1) && (*pLastIndex == -1) )
    {
        printf("Circular Queue is empty!, Cannot remove\n");
        *pSuccess = false;
        return(-1);
    }
    int removedValue = queue[*pFirstIndex];
    if(*pFirstIndex == *pLastIndex)
        *pFirstIndex = *pLastIndex = -1;
    else if(*pFirstIndex == size-1)
        *pFirstIndex = 0;
    else
        (*pFirstIndex)++;
    *pSuccess = true;
    return(removedValue);
}

bool showQ(int queue[], int size, int firstIndex, int lastIndex)
{
    if( (firstIndex == -1) && (lastIndex == -1) )
    {
        printf("Nothing to show, Circular Queue is empty!\n");
        return(false);
    }
    int i;
    printf("Circular Queue :\n");

    if(lastIndex <= size-1)
        for(i = firstIndex; i <= lastIndex; i++)
            printf("%d\t", queue[i]);
    else
    {
        for(i = firstIndex; i <= size-1; i++)
            printf("%d\t", queue[i]);
        for(i = 0; i <= lastIndex; i++)
            printf("%d\t", queue[i]);
    }
    return(true);
}

int main(void)
{
    int lastIndex = -1, choice, size, firstIndex = -1;
    system("clear");
    printf("16 Circular Queue via Array\n\n");

    printf("Size of array (integers) : ");
    scanf("%d", &size);
    int queue[size], value;
    bool success;

    while(true)
    {
        printf("\n1. Show the queue.\n");
        printf("2. Insert to queue.\n");
        printf("3. Remove from queue.\n");
        printf("4. Exit\n");
        printf("Choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            default:
            case 1:
                showQ(queue, size, firstIndex, lastIndex);
                break;

            case 2:
                printf("Value to insert : ");
                scanf("%d", &value);
                insertQ(queue, size, &firstIndex, &lastIndex, value);
                break;

            case 3:
                value = removeQ(queue, size, &firstIndex, &lastIndex, &success);
                if(success)
                    printf("Removed Value : %d\n", value);
                break;

            case 4:
                return(0);
        }
    }
    return(0);
}