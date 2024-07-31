# include<stdio.h>
#include<limits.h>
#include <stdlib.h>

#define MAX 20

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
    
}




int palindrome(const char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        insert(str[i]);
        push(str[i]);
        i++;
    }
    i = 0;
    while (str[i] != '\0')
    {
        if (delete() != pop())
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int main(){

char str[100];
printf("Enter a string: ");
scanf("%s", str);
if (palindrome(str))
{
    printf("%s is a palindrome\n",str);
}
else
{
    printf("%s is not a palindrome\n",str);
}

return 0;
}