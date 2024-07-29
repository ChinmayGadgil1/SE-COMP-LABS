# include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int info;
    struct node* link;
};

struct node* top=NULL;

void push(int item){
    struct node* tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    if (tmp==NULL)
    {
        printf("Stack Overflow\n");
        return;
    }\
    tmp->info=item;
    tmp->link=top;
    top=tmp;
}

int pop(){
    if (top==NULL)
    {
        printf("Stack Underflow\n");
        return INT_MIN;
    }

    int item=top->info;
    struct node*p=top;
    top=top->link;
    free(p);
    return item;
}

int peek(){
    if (top==NULL)
    {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    return top->info;
}

void display(){
    if (top==NULL)
    {
        printf("Stack Empty\n");
        return;
    }
    for (struct node* p = top; p !=NULL; p=p->link)
    {
        printf("%d ",p->info);

    }
    printf("\n");
    
}

int match(char a,char b){
    if (a=='(' && b==')' || a=='[' && b==']' || a=='{' && b=='}')
    {
        return 1;
    }
    return 0;
}

int validParentheses(const char input[]){
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i]=='('|| input[i]=='['|| input[i]=='{')
        {
            push(input[i]);
        }
        else if (input[i]==')' || input[i]==']' || input[i]=='}')
        {
            if (top==NULL)
            {
                return 0;
            }
            if (!match(top->info,input[i]))
            {
                return 0;
            }
            pop();
        }
    }
    if (top==NULL)
    {
        return 1;
    }
    return 0;
}

int main(){

char input[100];
printf("Enter the expression: ");
scanf("%s",input);
if (validParentheses(input))
{
    printf("Valid Parentheses\n");
}
else
{
    printf("Invalid Parentheses\n");
}

return 0;
}