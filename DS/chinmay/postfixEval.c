#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
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

long int postfixEval(const char postfix[])
{
    long int result = 0, tmp;
    int a, b;
    for (int i = 0; i < strlen(postfix); i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
            push(postfix[i] - '0');
            
        else{
            a = pop();
            b = pop();

            switch (postfix[i])
            {
            case '+':
                tmp = b + a;
                break;
            case '-':
                tmp = b - a;
                break;
            case '*':
                tmp = b * a;
                break;
            case '/':
                tmp = b / a;
                break;
            case '%':
                tmp = b % a;
                break;
            case '^':
                tmp = pow(b, a);
                break;

            default:
                break;
            }
            push(tmp);
        }
    }

    result = pop();
    return result;
}

int main()
{
   

    char postfix[20];
    printf("Enter the postfix expression:\n");
    gets(postfix);

    long int result = postfixEval(postfix);

    printf("The result is: %ld", result);

    return 0;
}