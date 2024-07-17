#include <stdio.h>
#include <stdlib.h>

#define MAX 4

int stackArr[MAX];
int top = -1;

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
    printf("push(%d)\n", x);  // Added printf statement
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
    printf("pop()\n");  // Added printf statement
    return item;
}

int peek()
{
    if (isEmpty())
    {
        printf("Empty\n");
    }
    else
    {
        return stackArr[top];
    }
}

void display()
{
    printf("StackArr:  ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stackArr[i]);
    }
    printf("\ntop=%d\n\n",top);
}

int main()
{
    push(74);
    display();
    push(27);
    display();
    push(64);
    display();
    push(20);
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    push(41);
    display();
    push(109);
    display();
    push(84);
    display();
    pop();
    display();
    push(102);
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    return 0;
}
