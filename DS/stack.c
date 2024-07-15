#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

int stackArr[MAX];
int top = -1;

char infix[20] = "A+B-C";
char postfix[20];

int isFull()
{
    return (top == MAX - 1);
}

int isEmpty()
{
    return (top == -1);
}

void push(int x)
{
    if (isFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stackArr[top] = x;
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    int item = stackArr[top];
    top--;
    return item;
}

int isWhiteSpace(char a)
{
    return a == ' ' || a == '\t';
}

int in_stack_priority(char a)
{
    switch (a)
    {
    case '+':
    case '-':
        return 1;
    case '%':
    case '/':
    case '*':
        return 2;
    case '^':
        return 4;
    case '(':
        return 0;
    default:
        return 0;
    }
}

int in_symbol_priority(char a)
{
    switch (a)
    {
    case '+':
    case '-':
        return 1;
    case '%':
    case '/':
    case '*':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

void infix_to_postfix()
{
    int i, p = 0;
    char symbol, next;
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        if (!isWhiteSpace(symbol))
        {
            switch (symbol)
            {
            case '(':
                push(symbol);
                break;
            case ')':
                while ((next = pop()) != '(')
                {
                    postfix[p++] = next;
                }
                break;
            case '+':
            case '-':
            case '/':
            case '*':
            case '%':
            case '^':
                while (!isEmpty() && in_stack_priority(stackArr[top]) >= in_symbol_priority(symbol))
                {
                    postfix[p++] = pop();
                }
                push(symbol);
                break;
            default:
                postfix[p++] = symbol;
            }
        }
    }

    while (!isEmpty())
    {
        postfix[p++] = pop();
    }
    postfix[p] = '\0';
}

int main()
{
    infix_to_postfix();
    printf("%s\n", postfix);
    return 0;
}
