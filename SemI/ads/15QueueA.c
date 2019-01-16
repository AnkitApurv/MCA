//15 Queue via Array
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//insert from first=firstIndex, remove from later=lastIndex
//insert => shift each to +1, lastIndex++, insert[firstIndex]
//remove => get value[lastIndex], lastIndex--
//show => from last to first

void insertQ(int queue[], int value, int *pLastIndex, int size)
{
    if(*pLastIndex == size-1)
    {
        printf("Queue is full!, Cannot insert\n");
        return;
    }
    if(*pLastIndex >= 0)
    {
        int i;
        for(i = *pLastIndex; i >= 0 ; i--)
            queue[i+1] = queue[i];
    }
    queue[0] = value;
    (*pLastIndex)++;
    return;
}

int removeQ(int queue[], int *pLastIndex, bool *pSuccess)
{
    if(*pLastIndex < 0)
    {
        printf("Queue is empty!, Cannot remove\n");
        *pSuccess = false;
        return(-1);
    }
    int removedValue = queue[*pLastIndex];
    (*pLastIndex)--;
    *pSuccess = true;
    return(removedValue);
}

void showQ(int queue[], int lastIndex)
{
    if(lastIndex < 0)
    {
        printf("Nothing to show, Queue is empty!\n");
        return;
    }
    int i;
    printf("Queue :\n");
    for(i = lastIndex; i >= 0; i--)
        printf("%d\t", queue[i]);
    return;
}

int main(void)
{
    int lastIndex=-1, choice, size;
    system("clear");
    printf("15 Queue via Array\n\n");

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
                showQ(queue, lastIndex);
                break;

            case 2:
                printf("Value to insert : ");
                scanf("%d", &value);
                insertQ(queue, value, &lastIndex, size);
                break;

            case 3:
                value = removeQ(queue, &lastIndex, &success);
                if(success)
                    printf("Removed Value : %d\n", value);
                break;

            case 4:
                return(0);
        }
    }
    return(0);
}