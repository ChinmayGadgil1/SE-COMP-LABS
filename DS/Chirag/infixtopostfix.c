//23B-CO-015
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_SIZE 30

int PR_NUMBER = 202311095;
char STUDENT_ROLL[] = "23B-CO-015";

void print_footer(){
    printf("\n********************************\n");
    printf("PROJECT NUMBER: %d\n", PR_NUMBER);
    printf("STUDENT ROLL: %s", STUDENT_ROLL);
    printf("\n********************************\n");
}

int stack[MAX_SIZE]; 
int topIndex = -1;
char postfixExpression[MAX_SIZE];

int isStackFull(){
    return topIndex == MAX_SIZE - 1;
}

int isStackEmpty(){
    return topIndex == -1;
}

void stackPush(int value) {
    if (isStackFull()){
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++topIndex] = value;
}

int stackPop(){
    if (isStackEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[topIndex--];
}

int stackPeek(){
    if (isStackEmpty()){
        printf("Stack is Empty\n");
        exit(1);
    }
    return stack[topIndex];
}

int isWhitespace(char ch){
    return ch == ' ' || ch == '\t';
}

int get_in_stack_priority(char ch){
    switch (ch){
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

int get_symbol_priority(char ch){
    switch (ch){
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

void convert_infix_to_postfix(const char *infix){
    int i, pos = 0;
    char symbol;
    topIndex = -1;
    printf("\nSymbol\t\tStack\t\tPostfix Expression\n");
    printf("---------------------------------------------\n");
    for (i = 0; i < strlen(infix); i++){
        symbol = infix[i];
        if (!isWhitespace(symbol)){
            switch (symbol)
            {
            case '(':
                stackPush(symbol);
                break;
            case ')':
                while (!isStackEmpty() && stackPeek() != '(')
                    postfixExpression[pos++] = stackPop();
                stackPop(); 
                break;
            case '+':
            case '-':
            case '/':
            case '*':
            case '%':
            case '^':
                while (!isStackEmpty() && get_in_stack_priority(stackPeek()) >= get_symbol_priority(symbol))
                    postfixExpression[pos++] = stackPop();
                stackPush(symbol);
                break;
            default:
                postfixExpression[pos++] = symbol;
            }
            printf("%c\t\t", symbol);
            for (int j = 0; j <= topIndex; j++){
                printf("%c", stack[j]);
            }
            printf("\t\t%s\n", postfixExpression);
        }
    }
    while (!isStackEmpty()){
        char topSymbol = stackPop();
        if (topSymbol != '('){
            postfixExpression[pos++] = topSymbol;
        }
    }
    postfixExpression[pos] = '\0';
    printf(" \t\t%s\t\t%s\n", "Empty", postfixExpression);
}

long int evaluate_postfix(const char postfix[]){
    long int result = 0, temp;
    int operand1, operand2;
    printf("Symbol\t\tStack\n");
    printf("------------------------------\n");
    for (int i = 0; i < strlen(postfix); i++){
        char symbol = postfix[i];
        if (!isWhitespace(symbol))
        {
            if (symbol >= '0' && symbol <= '9')
                stackPush(symbol - '0');
            else{
                operand1 = stackPop();
                operand2 = stackPop();
                switch (symbol){
                case '+':
                    temp = operand2 + operand1;
                    break;
                case '-':
                    temp = operand2 - operand1;
                    break;
                case '*':
                    temp = operand2 * operand1;
                    break;
                case '/':
                    temp = operand2 / operand1;
                    break;
                case '%':
                    temp = operand2 % operand1;
                    break;
                case '^':
                    temp = pow(operand2, operand1);
                    break;
                default:
                    break;
                }
                stackPush(temp);
            }

            printf("%c\t\t", symbol);
            for (int j = 0; j <= topIndex; j++){
                printf("%d,", stack[j]);
            }
            printf("\n");
        }
    }
    result = stackPop();
    return result;
}

int main(){
    char infixExpression[30];
    long int evalResult;
    int userChoice;
    while (1){
        printf("\n1. Convert Infix To Postfix\n2. Evaluate Postfix Expression\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        switch (userChoice){
        case 1:
            printf("\nEnter infix expression:\n");
            while (getchar() != '\n');
            fgets(infixExpression, sizeof(infixExpression), stdin);
            infixExpression[strcspn(infixExpression, "\n")] = '\0';
            convert_infix_to_postfix(infixExpression);
            printf("\nPostfix expression: %s\n", postfixExpression);
            topIndex = -1;
            break;
        case 2:
            printf("\nEnter the postfix expression:\n");
            while (getchar() != '\n');
            fgets(postfixExpression, sizeof(postfixExpression), stdin);
            postfixExpression[strcspn(postfixExpression, "\n")] = '\0';
            evalResult = evaluate_postfix(postfixExpression);
            printf("\nResult: %ld\n\n", evalResult);
            topIndex = -1;
            break;
        case 3:
            printf("\n\nExiting...\n\n");
            print_footer();
            exit(0);
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }
    print_footer();
    return 0;
}
