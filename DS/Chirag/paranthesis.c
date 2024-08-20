# include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char info;
    struct node* link;
};

struct node* top=NULL;

void display(){
    if (top==NULL)
    {
    printf("\n top\n");
    printf("------\n");
    printf("|NULL|\n");
    printf("------\n");
        return;
    }
    printf("\n   top\n");
    printf("----------\n");
    printf("|%8p|\n",top);
    printf("----------\n");
    printf("     |               ");
    for (struct node* p = top; p !=NULL; p=p->link)
    {
        printf("----------------     ");
    }
    printf("\n");
    printf("     |-------------->");
    

    for (struct node* p = top; p !=NULL; p=p->link)
    {
        if (p->link!=NULL)
        {
            printf("| '%c' |%8p|---> ",p->info,p->link);
        }
        else{
            printf("| '%c' |%8p| ",p->info,"NULL");

        }

    }
    printf("\n");
    printf("                     ");
    for (struct node* p = top; p !=NULL; p=p->link)
    {
        printf("----------------     ");
    }
    printf("\n");
    printf("                   ");

    
    for (struct node* p = top; p !=NULL; p=p->link)
    {
        printf("       %8p       ",p);
    }
    printf("\n\n");
    
}

void push(char item){
    struct node* tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    if (tmp==NULL)
    {
        printf("Stack Overflow\n");
        return;
    }

    tmp->info=item;
    tmp->link=top;
    top=tmp;
    
}

char pop(){
    if (top==NULL)
    {
        printf("Stack Underflow\n");
        exit(1);
    }

    char item=top->info;
    struct node*p=top;
    top=top->link;
    free(p);
    
    return item;
}

char peek(){
    if (top==NULL)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return top->info;
}



int match(char a,char b){
    if (a=='(' && b==')' || a=='[' && b==']' || a=='{' && b=='}')
    {
        return 1;
    }
    return 0;
}

int validParentheses(char inp[]){
    
    char input[100];
    strcpy(input,inp);
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i]=='('|| input[i]=='['|| input[i]=='{')
        {
            push(input[i]);
            printf("push('%c')\n",input[i]);
            display();
            
        }
        else if (input[i]==')' || input[i]==']' || input[i]=='}')
        {
            if (top==NULL)
            {
                return 0;
            }
            if (!match(peek(),input[i]))
            {
                return 0;
            }
            pop();
            printf("pop()\n");
            display();
        }
    }
    if (top==NULL)
    {
        return 1;
    }
    return 0;
}

char complement(char c){
    if(c==')') return '(';
    if(c=='}') return '{';
    if(c==']') return '[';
    else return '0';
}
char fix[100];
void fixPar(char input[]){
    int p=0;

    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i]=='('|| input[i]=='['|| input[i]=='{')
        {
            push(input[i]);
            fix[p++]=input[i];
        }
        else if (input[i]==')' || input[i]==']' || input[i]=='}')
        {
            
            if (top==NULL)
            {
                fix[p++]=complement(input[i]);
                fix[p++]=input[i];
            }
            if (!match(peek(),input[i]))
            {

                fix[p++]=complement(input[i]);
                fix[p++]=input[i];
            }
            pop();
        }
    }

    while (top!=NULL)
    {
        char c=pop();
        fix[p++]=c;
        fix[p++]=complement(c);
    }
    
}

int main(){

char input[100];
char inp[3];
printf("Enter the expression: ");
scanf("%s",input);
if (validParentheses(input))
{
    printf("\nResult=> Valid Parentheses\n\n");
}
else
{
    printf("\nResult=> Invalid Parentheses\n\n");
    
    if (1)
    {
        fixPar(input);
        printf("Before: %s\n",input);
        printf("After: %s\n",fix);
    }
    
    
}

return 0;
}