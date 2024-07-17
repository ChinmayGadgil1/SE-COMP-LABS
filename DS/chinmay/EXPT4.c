#include <stdio.h>
#include <stdlib.h>

#define MAX 30

char stackArr[MAX];

int top = -1;

char postfix[MAX];

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

int peek()
{
    if (isEmpty())
    {
        printf("Empty");
    }
    else
    {
        return stackArr[top];
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Empty");
    }
    else
    {
        for (int i = 0; i <= top; i++)
        {
            printf("%c", stackArr[i]);
        }
    }
}

int main()
{
   
    return 0;
}

