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
    printf("push(%d)\n", x);  
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
    printf("pop()\n");  
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
    int choice, item;
    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                printf("Popped element: %d\n", item);
                break;
            case 3:
                item = peek();
                printf("Top element: %d\n", item);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
