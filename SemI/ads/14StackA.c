//14 Stack via Arrays
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool push(int stack[], int *pTopIndex, int *pSize, int topValue)
{
    if(*pTopIndex == *pSize-1)
        return(false);

    stack[++(*pTopIndex)] = topValue;
    return(true);
}

int pop(int stack[], int *pTopIndex, bool *pSuccess)
{
    if(*pTopIndex == -1)
    {
        *pSuccess = false;
        return(0);
    }

    *pSuccess = true;
    return(stack[(*pTopIndex)--]);
}

bool show(int stack[], int topIndex)
{
    if(topIndex == -1)
        return(false);
    int i;
    printf("Stack :\n\tIndex\t\tValue\n");
    for(i = topIndex; i >= 0; i--)
        printf("\t%d\t\t%d\n", i, stack[i]);
    return(true);
}

int main(void)
{
    int topIndex = -1, topValue, choice, size;
    bool success;
    system("clear");
    printf("14 Stack via Array\n\n");

    printf("Size of array (integers) : ");
    scanf("%d", &size);
    int stack[size], i;

    for(i = 0; i < size; i++)
        stack[i] = 0;

    while(true)
    {
        printf("\n1. Show the stack.\n");
        printf("2. Push to stack.\n");
        printf("3. Pop from stack.\n");
        printf("4. Exit\n");
        printf("Choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            default:
            case 1:
                success = show(stack, topIndex);
                if(!success)
                    printf("Nothing to show, Stack Underflow!\n");
                break;

            case 2:
                printf("Value to push : ");
                scanf("%d", &topValue);
                success = push(stack, &topIndex, &size, topValue);
                if(!success)
                    printf("Cannot push, Stack Overflow!\n");
                break;

            case 3:
                topValue = pop(stack, &topIndex, &success);
                if(!success)
                {
                    printf("Cannot pop, Stack Underflow!\n");
                    break;
                }
                printf("Popped Value : %d\n", topValue);
                break;

            case 4:
                return(0);
        }
    }
    return(0);
}