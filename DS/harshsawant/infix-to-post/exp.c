#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

char infix[MAX];
char postfix[MAX];
char stack[MAX];
int top = -1;

int isFull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(char item)
{
    if (isFull())
    {
        printf("Stack Overflow");
        return;
    }
    else
    {
        top++;
        stack[top] = item;
    }
}

char pop()
{

    if (isEmpty())
    {
        printf("Stack Underflow");
        exit(1);
    }
    else
    {
        char temp = stack[top];
        top--;
        return temp;
    }
}

int isOperator(char symbol)
{
    if (symbol == '+' || symbol == '-' || symbol == '/' || symbol == '*' || symbol == '^' || symbol == '(' || symbol == ')')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display()
{
    int i;
    printf("Postfix: ");
    for (i = 0; i < strlen(postfix); i++)
    {
        printf("%c", postfix[i]);
    }
}

int getPriority(char symbol)
{

    if (symbol == '^')
    {
        return 3;
    }
    else if (symbol == '*' || symbol == '/' || symbol == '%')
    {
        return 2;
    }
    else if (symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else if (symbol == '(' || symbol == ')')
    {
        return 0;
    }
}

void infixtoposfix(char infix[20])
{
    int i, p = 0;
    char item;

    for (i = 0; i < strlen(infix); i++)
    {

        if (isOperator(infix[i]))
        {
            char element;
            switch(infix[i]){
                case '(': push(infix[i]);
                          break;
                case ')': while ((element = pop()) != '('){
                                postfix[p] = element;
                                p++;
                         }
                         break;
                default:
                         if (top == -1 || getPriority(stack[top]) < getPriority(infix[i])){
                            push(infix[i]);

                        }else{
                        while (getPriority(infix[i]) <= getPriority(stack[top])){
                            postfix[p] = pop();
                            p++;
                        }
                        push(infix[i]);
                        }
                        break;
                        
            }
     
        }else{
            postfix[p] = infix[i];
            p++;
        }
    }

    while (!isEmpty()){

        postfix[p] = pop();
        p++;
    }
}

int main()
{
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixtoposfix(infix);
    display();

    return 0;
}