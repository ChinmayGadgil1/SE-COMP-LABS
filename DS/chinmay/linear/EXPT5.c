#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 30

int stackArr[MAX]; 
int top = -1;
char postfix[MAX];

int isFull()
{
    return top == MAX - 1;
}

int isEmpty()
{
    return top == -1;
}

void push(int x) 
{
    if (isFull())
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    stackArr[++top] = x;
}

int pop() 
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stackArr[top--];
}

int peek()
{
    if (isEmpty())
    {
        printf("Stack is Empty\n");
        exit(1);
    }
    return stackArr[top];
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
        return 3;
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
        return 4;
    default:
        return 0;
    }
}

void infix_to_postfix(const char *infix)
{
    int i, p = 0;
    char symbol;
    top = -1;
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
                while (!isEmpty() && peek() != '(')
                {
                    postfix[p++] = pop();
                }
                pop(); 
                break;
            case '+':
            case '-':
            case '/':
            case '*':
            case '%':
            case '^':
                while (!isEmpty() && in_stack_priority(peek()) >= in_symbol_priority(symbol))
                {
                    postfix[p++] = pop();
                }
                push(symbol);
                break;
            default:
                postfix[p++] = symbol;
            }

            printf("%c\t\t", symbol);
            for (int j = 0; j <= top; j++)
            {
                printf("%c", stackArr[j]);
            }
            printf("\t\t%s\n", postfix);
        }
    }

    while (!isEmpty())
    {
        char topSymbol = pop();
        if (topSymbol != '(')
        {
            postfix[p++] = topSymbol;
        }
    }
    postfix[p] = '\0';
    printf(" \t\t%s\t\t%s\n", "Empty", postfix);
}

long int postfixEval(const char postfix[])
{
    long int result = 0, tmp;
    int a, b;
    printf("Symbol\t\tStack\n");
    printf("------------------------------\n");

    for (int i = 0; i < strlen(postfix); i++)
    {
        char symbol = postfix[i];
        if (!isWhiteSpace(symbol))
        {
            if (symbol >= '0' && symbol <= '9')
                push(symbol - '0');
            else
            {
                a = pop();
                b = pop();

                switch (symbol)
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

            printf("%c\t\t", symbol);
            for (int j = 0; j <= top; j++)
            {
                printf("%d,", stackArr[j]);
            }
            printf("\n");
        }
    }

    result = pop();
    return result;
}

int main()
{
    char infix[30];
    long int result;
    int choice;
    while (1)
    {
        printf("\n1. Infix To Postfix\n2. Postfix Evaluation\n3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter infix expression:\n");
            while (getchar() != '\n')
                ;
            fgets(infix, sizeof(infix), stdin);
            infix[strcspn(infix, "\n")] = '\0';
            infix_to_postfix(infix);
            printf("\nPostfix expression: %s\n", postfix);
            top = -1;
            break;
        case 2:
            printf("\nEnter the postfix expression:\n");
            while (getchar() != '\n')
                ;
            fgets(postfix, sizeof(postfix), stdin);
            postfix[strcspn(postfix, "\n")] = '\0';
            result = postfixEval(postfix);
            printf("\nResult: %ld\n\n", result);
            top = -1;
            break;
        case 3:
            printf("\n\nExiting...\n\n");
            exit(1);
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}