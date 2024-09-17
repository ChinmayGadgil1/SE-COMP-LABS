//23B-CO-015
#include <stdio.h>
#include <stdlib.h>
#define MAX 30

int PR_NUM=202311095;
char ROLL_NUM[]="23B-CO-015";
void footer(){
    printf("\n================================\n");
    printf("PR NUMBER: %d\n", PR_NUM);
    printf("ROLL NUMBER: %s ",ROLL_NUM);
    printf("\n================================\n");

}

char stackarray[MAX];
int top = -1;
char postfixarray[MAX];
char infixarray[MAX];

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
    stackarray[top] = x;
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    int item = stackarray[top];
    top--;
    return item;
}

int peek(int x)
{
    if(isEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        return stackarray[top];
    }
}

void display()
{
    printf("Stack array:  ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stackarray[i]);
    }
    printf("\ntop=%d\n\n",top);
}
int main()
{
    printf("\nInitially:\n");
    display();
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