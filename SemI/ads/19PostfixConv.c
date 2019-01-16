//19 Postfix Conversion
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//operator precedence -> dmas
//https://interactivepython.org/runestone/static/pythonds/BasicDS/InfixPrefixandPostfixExpressions.html
/* Infix-to-Postfix
1. Create an empty stack called opstack for keeping operators. Create an empty list for output.
2. Convert the input infix string to a list by using the string method split.
3. Scan the token list from left to right.
    3.1. If the token is an operand, append it to the end of the output list.
    3.2. If the token is a left parenthesis, push it on the opstack.
    3.3. If the token is a right parenthesis, pop the opstack until the corresponding left parenthesis is removed. 
        Append each operator to the end of the output list.
    3.4. If the token is an operator, *, /, +, or -, push it on the opstack. 
        However, first remove any operators already on the opstack that have higher or equal precedence and append them to the output list.
4. When the input expression has been completely processed, check the opstack. 
    Any operators still on the stack can be removed and appended to the end of the output list.
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

bool inToPost(char infix[], char postfix[], int size)
{
    int i = 0;
    char opstack[size], x;
    int topO = -1, topP = -1;
    bool success = false;
    for(i = 0; i < size; i++)
    {
        switch(infix[i])
        {
            case '(':
                push(opstack, &topO, size, infix[i]);
                break;

            case ')':
                while(opstack[topO] != '(')
                {
                    x = pop(opstack, &topO, &success);
                    push(postfix, &topP, size, x);
                }
                x = pop(opstack, &topO, &success);
                push(postfix, &topP, size, x);
                push(postfix, &topP, size, infix[i]);
                break;

            case '/':
                while(opstack[topO] == '/')
                {
                    x = pop(opstack, &topO, &success);
                    push(postfix, &topP, size, x);
                }
                push(opstack, &topO, size,  infix[i]);
                break;

            case '*':
                while(opstack[topO] == '/' || opstack[topO] == '*')
                {
                    x = pop(opstack, &topO, &success);
                    push(postfix, &topP, size, x);
                }
                push(opstack, &topO, size,  infix[i]);
                break;

            case '+':
                while(opstack[topO] == '/' || opstack[topO] == '*' || opstack[topO] == '+')
                {
                    x = pop(opstack, &topO, &success);
                    push(postfix, &topP, size, x);
                }
                push(opstack, &topO, size,  infix[i]);
                break;

            case '-':
                while(opstack[topO] == '/' || opstack[topO] == '*' || opstack[topO] == '+' || opstack[topO] == '-')
                {
                    x = pop(opstack, &topO, &success);
                    push(postfix, &topP, size, x);
                }
                push(opstack, &topO, size,  infix[i]);
                break;

            default:
                push(postfix, &topP, size, infix[i]);
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
    printf("\n19 Postfix Conversion\n\n");

    int size;
    printf("Size infix of expression : "); scanf("%d", &size);
    char infix[size+1]; //to avoid garbage
    getExpression(infix, size);

    char postfix[size];
    inToPost(infix, postfix, size);

    printf("\nInfix Expression : "); show(infix, size);
    printf("\nPostfix Exression : "); show(postfix, size);

    return(0);
}