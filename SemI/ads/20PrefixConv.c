//20 Prefix Conversion
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//operator precedence -> dmas
/* Infix-to-Prefix
https://stackoverflow.com/questions/1946896/conversion-from-infix-to-prefix

1. Push “)” onto STACK, and add “(“ to end of the Infix.
2. Scan Infix from right to left and repeat step 3 to 6 for each element of Infix until the STACK is empty.
    2.1. If an operand is encountered add it to Prefix.
    2.2. If a right parenthesis is encountered push it onto STACK.
    2.3. If an operator is encountered then: 
        a. Repeatedly pop from STACK and add to Prefix each operator (on the top of STACK) which has same or higher precedence than the operator. 
        b. Add operator to STACK.
    2.4. If left parenthesis is encontered then 
        a. Repeatedly pop from the STACK and add to Prefix (each operator on top of stack until a left parenthesis is encounterd) 
        b. Remove the left parenthesis.
7. Exit
*/

bool push(char stack[], int *pTopIndex, int size, char topValue)
{
    if(*pTopIndex == size-1)
        return(false);

    stack[++(*pTopIndex)] = topValue;
    return(true);
}

char pop(char stack[], int *pTopIndex, bool *pSuccess)
{
    if(*pTopIndex == -1)
    {
        *pSuccess = false;
        return(0);
    }

    *pSuccess = true;
    return(stack[(*pTopIndex)--]);
}

bool inToPre(char infix[], char Prefix[], int size)
{
    char opstack[size], x;
    int topO = -1, topP = -1, i;
    bool success = false;
    for(i = size-1; i >= 0; i--)
    {
        switch(infix[i])
        {
            case ')':
                push(opstack, &topO, size, infix[i]);
                break;

            case '(':
                while(opstack[topO] != ')')
                {
                    x = pop(opstack, &topO, &success);
                    push(Prefix, &topP, size, x);
                }
                x = pop(opstack, &topO, &success);
                push(Prefix, &topP, size, x);
                push(Prefix, &topP, size, infix[i]);
                break;

            case '/':
                while(opstack[topO] == '/')
                {
                    x = pop(opstack, &topO, &success);
                    push(Prefix, &topP, size, x);
                }
                push(opstack, &topO, size,  infix[i]);
                break;

            case '*':
                while(opstack[topO] == '/' || opstack[topO] == '*')
                {
                    x = pop(opstack, &topO, &success);
                    push(Prefix, &topP, size, x);
                }
                push(opstack, &topO, size,  infix[i]);
                break;

            case '+':
                while(opstack[topO] == '/' || opstack[topO] == '*' || opstack[topO] == '+')
                {
                    x = pop(opstack, &topO, &success);
                    push(Prefix, &topP, size, x);
                }
                push(opstack, &topO, size,  infix[i]);
                break;

            case '-':
                while(opstack[topO] == '/' || opstack[topO] == '*' || opstack[topO] == '+' || opstack[topO] == '-')
                {
                    x = pop(opstack, &topO, &success);
                    push(Prefix, &topP, size, x);
                }
                push(opstack, &topO, size,  infix[i]);
                break;

            default:
                push(Prefix, &topP, size, infix[i]);
                break;
        }
    }
    return(false);
}


bool show(char stack[], int topIndex)
{
    if(topIndex == -1)
        return(false);
    printf("%s\n", stack);
    return(true);
}

bool getExpression(char expr[], int size)
{
    printf("Enter the expression (Valid Operands / * + -): \n");

    int i;
    for(i = 0; i < size; i++)
        scanf("%s", &expr[i]);
    expr[i+1] = '\0';
    return(true);
}


int main(void)
{
    system("clear");
    printf("\n20 Prefix Conversion\n\n");

    int size;
    printf("Size infix of expression : "); scanf("%d", &size);
    char infix[size+1]; //to avoid garbage
    getExpression(infix, size);

    char Prefix[size];
    inToPre(infix, Prefix, size);

    printf("\nInfix Expression : "); show(infix, size);
    printf("\nPrefix Exression : "); show(Prefix, size);

    return(0);
}