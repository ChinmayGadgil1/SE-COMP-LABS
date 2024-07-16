#include <stdio.h>
#include <string.h>
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

void display(){
    if (isEmpty()) 
    {
        printf("Empty");
    }
    else{
        for (int i = 0; i <= top; i++)
        {
            printf("%c", stackArr[i]);
        }
        
    }
    
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

int peek(){
    if (isEmpty())
    {
        printf("Empty");
    }
    else
    {
        return stackArr[top];
    }
    
    
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


void infix_to_postfix(const char* infix)
{
    int i, p = 0;
    char symbol, next;
    char stack[MAX];
    printf("\nSymbol\t\tStack\t\tPostfix Array\n");
    printf("---------------------------------------------\n");
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
                next = pop();
                while (next != '(')
                {
                    postfix[p++] = next;
                    next=pop();
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
            
            printf("%c\t\t",symbol);
            display();
            printf("\t\t%s\n",postfix);
        }
        
    }

    while (!isEmpty())
    {
        postfix[p++] = pop();
    }
    postfix[p] = '\0';
    printf(" \t\t%s\t\t%s\n","Empty",postfix);
}

int main()
{
    char infix[20];
    printf("Enter infix expression:\n");
    gets(infix);
    infix_to_postfix(infix);

    printf("\nPostfix Expression:\n%s",postfix);
    return 0;
}
