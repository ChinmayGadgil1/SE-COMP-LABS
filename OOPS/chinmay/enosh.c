#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 8
int stackArr[MAX];
double stack_arr[MAX];
int top=-1;
int dtop=-1;
char postfix[MAX];

int isFull(){
    return top==MAX-1;
}
int isEmpty(){
    return top==-1;
}
void push(int k){
    if (isFull()){
        printf("Stack Overflow\n");
        exit(1);
    }
    stackArr[++top]=k;
}
int pop(){
    if (isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    return stackArr[top--];
}
int peek(){
    if (isEmpty()){
        printf("Stack is Empty\n");
        exit(1);
    }
    return stackArr[top];
}
int isWhiteSpace(char a){
    return a==' '||a=='\t';
}

int disFull(){
    return dtop==MAX-1;
}
int disEmpty(){
    return dtop==-1;
}

void Dpush(double k){
    if (disFull()){
        printf("Stack Overflow\n");
        exit(1);
    }
    stack_arr[++dtop]=k;
}
double Dpop(){
    if (disEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack_arr[dtop--];
}

int in_stack_priority(char a){
    switch (a){
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
int in_symbol_priority(char a){
    switch (a){
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
void infix_to_postfix(const char *infix){
    top=dtop=-1;
    int i,p=0;
    char symbol;
    top=-1;
    printf("\nSymbol\t\tStack\t\tPostfix Array\n");
    for(i=0;i<strlen(infix);i++){
        symbol = infix[i];
        if(!isWhiteSpace(symbol)){
            switch(symbol){
            case '(':
                push(symbol);
                break;
            case ')':
                while(!isEmpty()&&peek()!='('){
                    postfix[p++]=pop();
                }
                pop();
                break;
            case '+':
            case '-':
            case '/':
            case '*':
            case '%':
            case '^':
                while (!isEmpty()&&in_stack_priority(stackArr[top])>=in_symbol_priority(symbol)){
                    postfix[p++]=pop();
                }
                push(symbol);
                break;
            default:
                postfix[p++]=symbol;
            }
            printf("%c\t\t",symbol);
            for (int j=0;j<=top;j++){
                printf("%c",stackArr[j]);
            }
            printf("\t\t%s\n",postfix);
        }
    }
    while(!isEmpty()){
        char topSymbol=pop();
        if (topSymbol!='('){
            postfix[p++]=topSymbol;
        }
    }
    postfix[p]='\0';
    printf(" \t\t%s\t\t%s\n","Empty",postfix);
}
void postfixEval(const char postfix[]){
    top=dtop=-1;
    long int result=0,tmp;
    int a,b,i,j,k;
    float A,B,Dtmp,Dresult=0;
    printf("Symbol\t\tStack int\t\t\tStack float\n\n");

    for(i=0;i<strlen(postfix);i++){
        char symbol=postfix[i];
        if(!isWhiteSpace(symbol)){
            if(symbol>='0'&&symbol<='9'){
                push(symbol-'0');
                Dpush((symbol - '0'));
            }else{
                a=pop();
                b=pop();
                A=Dpop();
                B=Dpop();
                switch (symbol){
                case '+':
                    tmp = b + a;
                    Dtmp = B + A;
                    break;
                case '-':
                    tmp = b - a;
                    Dtmp = B - A;
                    break;
                case '*':
                    tmp = b * a;
                    Dtmp = B * A;
                    break;
                case '/':
                    tmp = b / a;
                    Dtmp = B / A;
                    break;
                case '%':
                    tmp = b % a;
                    Dtmp = fmod(B,A);
                    break;
                case '^':
                    tmp = (int)pow(b, a);
                    Dtmp = pow(B,A);
                    break;
                default:
                    break;
                }
                push(tmp);
                Dpush(Dtmp);
            }
            printf("%c\t\t", symbol);
            for (int i = 0; i <MAX; i++)
            {
                if(i<=top)
                    printf("%d,", stackArr[i]);
                else
                    printf("  ");
            }
            printf("\t\t\t");
            for (int i = 0; i <MAX; i++)
            {
                if(i<=top)
                    printf("%.2f,", stack_arr[i]);
                else
                    printf("    ");
            }
            printf("\n");
        }
    }
    result = pop();
    Dresult = Dpop();
    printf("\nResult: %d\t\t%f\n",result,Dresult);
}

int main(){
    char infix[30];
    long int result;
    int choice;
    while (1){
        printf("\n1. Infix To Postfix\n2. Postfix Evaluation\n3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            printf("\nEnter infix expression:\n");
            while (getchar()!='\n');
            fgets(infix,sizeof(infix),stdin);
            infix[strcspn(infix, "\n")] ='\0';
            infix_to_postfix(infix);
            printf("\nPostfix expression: %s\n",postfix);
            top=-1;
            break;
        case 2:
            printf("\nEnter the postfix expression:\n");
            scanf("%s",postfix);
            postfixEval(postfix);
            //printf("\nResult: %ld\n\n",result);
            top=-1;
            break;
        case 3:
            printf("\n\nClosing\n\n");
            exit(1);
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}