//18 Prefix Evaluation
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool push(int stack[], int *pTopIndex, int size, int topValue)
{
    if(*pTopIndex == size-1)
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

int toInt(char x)
{
    switch(x)
    {
        case '0': return(0);
        case '1': return(1);
        case '2': return(2);
        case '3': return(3);
        case '4': return(4);
        case '5': return(5);
        case '6': return(6);
        case '7': return(7);
        case '8': return(8);
        case '9': return(9);
    }
    return(0);
}

int main(void)
{
    int topIndex = -1, size, op1, op2, i;
    bool success;
    system("clear");
    printf("18 Prefix Evaluation\n\n");

    printf("Size of expression : ");
    scanf("%d", &size);
    char expr[size];

    printf("Valid Operands are + - / * \n");
    printf("Enter the expression : ");
    for(i = 0; i < size; i++)
        scanf("%s", &expr[i]);

    int eval[size];
    for(i = size-1; i >= 0; i++)
    {
        if(expr[i]=='+' || expr[i]=='-' || expr[i]=='/' || expr[i]=='*')
        {//pop last two and use operand, then push back
            op1 = pop(eval, &topIndex, &success);
            op2 = pop(eval, &topIndex, &success);
            switch(expr[i])
            {
                case '+':
                    push(eval, &topIndex, size,  op1+op2);
                    break;

                case '-':
                    push(eval, &topIndex, size,  op1-op2);
                    break;

                case '/':
                    push(eval, &topIndex, size,  op1/op2);
                    break;

                case '*':
                    push(eval, &topIndex, size,  op1*op2);
                    break;
            }
        }
        else
        {
            int x = toInt(expr[i]);
            push(eval, &topIndex, size, x);
        }
    }
    if(topIndex != 0)
        printf("Expression is invalid!\n");
    else
        printf("Eval : %d\n", eval[0]);
    return(0);
}