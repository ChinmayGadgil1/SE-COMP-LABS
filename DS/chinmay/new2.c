#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define TAB '\t'
#define BLANK ' '
#define max 8 
int top=-1;
int ftop=-1;
char infix[max];
long int stack[max];
float stackf[max];
char stack_arr[max];
char postfix[max];
void push(char symbol);
void push1(int symbol);
void fpush(float symbol);
int isfull();
int fisFull();
int isempty();
int fisempty();
int pop();
int pop1();
float fpop();
void display();
int insymbolpr(char symbol);
int instackpr(char symbol);
int whitespace(char symbol);
void infixtopostfix();
long int eval_postfix();

int main(){
    int result;
    printf("enter postfix expression with values: ");
    scanf("%s",postfix);
    printf("%-7s\t\t%-10s\t\t\t\t%-15s\n","Symbol","Stack","FloatStack");
    eval_postfix();
return 0;
}
void push(char symbol){
    if(isfull()){
        printf("Stack overflow");
        return;
    }
else{
    top++;
    stack_arr[top]=symbol;
}
}
void push1(int symbol){
    if(isfull()){
        printf("Stack overflow");
        return;
    }
    else{
    top++;
    stack[top]=symbol;
    }
}

void fpush(float symbol) {
    if(fisFull()){
        printf("Stack overflow");
        return;
    }
    else{
    ftop++;
    stackf[ftop]=symbol;
    }
}


int isfull(){
    if(top==max-1){
        return 1;

    }
    else{
        return 0;
    }
}

int fisFull() {
    if(ftop==max-1) {
        return 1;
    } else {
        return 0;
    }
}

int isempty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int fisempty() {
    if(ftop==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int pop(){
    if(isempty()){
        printf("Stack underflow");
        exit(1);
    }
    else{
        int item=stack_arr[top];
        stack_arr[top]='\0';
        top--;
        return item;
    }
}

int pop1(){
    if(isempty()){
        printf("Stack underflow");
        exit(1);
    }
    else{
        int item=stack[top];
        stack[top]='\0';
        top--;
        return item;
    }

}

float fpop() {
    if(fisempty()) {
        printf("Stack underflow");
        exit(1);
    }
    else{
        float item=stackf[ftop];
        stackf[ftop]='\0';
        ftop--;
        return item;
    }
}

void display(){

    if(isempty()){
        printf("stack is empty");
        return;

    }
    else{
        printf("The contents of the stack from top are : \n");
        for(int i=top;top>=0;top--){
            printf("%d",stack_arr[i]);
        }
    }

}
int insymbolpr(char symbol){

    switch (symbol)
    { 
    case '+':
    case '-':return 1;
    case '/':
    case '%':
    case '*':return 2;
    case '^':return 4;
default:return 0;
}


}
int instackpr(char symbol){
     switch (symbol)
    {
    case '(':return 0;

    case '+':
    case '-':return 1;
     case '/':
     case '%':
    case '*':return 2;
    case '^':return 3;
default:return 0; 
}


}
int whitespace(char symbol){

    if(symbol==TAB || symbol==BLANK){
        return 1;
    }
    else{
        return 0;
}

}

void infixtopostfix(){
    int i, p=0;
    char symbol, next;
    printf("Contents of the stack: \n");
    printf("Symbol\t Stack\t Postfix array\t \n");
    for(i=0; i< strlen(infix); i++){
    symbol = infix[i];
        if(!whitespace(symbol)){
            switch(symbol){
                case'(':push(symbol);
                        break;
                case')':while((next = pop())!='('){
                          postfix[p++] = next;
                        }
                        break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^':while(!isempty() && (instackpr(stack_arr[top]) >= insymbolpr(symbol))){
                          postfix[p++] = pop();
                        }
                        push(symbol);
                        break;
                default: postfix[p++]=symbol;
            }

        printf("%c\t %s\t %s",infix[i],stack_arr,postfix);

        }
        printf("\n");
 
    }
     while(!isempty()){
        postfix[p++]=pop();
    }
    postfix[p]= '\0';
    printf("\t\t%s\n",postfix);
}

long int eval_postfix() {
    top=-1;
    ftop=-1;
    int a,b;
    float x,y;
    int i;
    char symbol;
    for(i=0;i<strlen(postfix);i++) {
        symbol=postfix[i];
        printf("%-7c",symbol);
        if(symbol>='0' && symbol<='9') {
            push1(symbol-'0');
            fpush(symbol-'0');
        } 
        else {
            a=pop1();
            b=pop1();
            x=fpop();
            y=fpop();
            switch(symbol) {
                case '+':
                push1(b+a);
                fpush((float)(y+x));
                break;
                case '-':
                push1(b-a); 
                fpush((float)(y-x));
                break;
                case '*':
                push1(b*a);
                fpush((float)(y*x)); 
                break;
                case '/':
                push1(b/a); 
                fpush((float)y/x);
                break;
                case '^':
                push1(pow(b,a)); 
                fpush(pow(y,x));
                break;
                default:printf("Wrong choice\n");
            }
        }
        printf("\t\t");
        for(int j=0;j<=max;j++) {
            if(j<=top)
                printf("%d, ",stack[j]);
            else
                printf("   ");   
        }
        printf("\t\t");
        for(int j=0;j<=top;j++) {
            printf("%0.1f, ",stackf[j]);
        }
        printf("\n");
    }
    printf("\nResult of postfix evaluation int: %d",pop1());
    printf("\nResult of postfix evaluation float: %.2f",fpop());

}