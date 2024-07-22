# include<stdio.h>
#include<limits.h>
#include<stdlib.h>

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

int main(){
printf("\npush(74)\n");
push(74);
display();

printf("\npush(27)\n");
push(27);
display();

printf("\npush(64)\n");
push(64);
display();

printf("\npush(20)\n");
push(20);
display();

printf("\npop()\n");
pop();
display();

printf("\npop()\n");
pop();
display();

printf("\npop()\n");
pop();
display();

printf("\npush(41)\n");
push(41);
display();

printf("\npush(109)\n");
push(109);
display();

printf("\npush(84)\n");
push(84);
display();

printf("\npop()\n");
pop();
display();

printf("\npush(102)\n");
push(102);
display();

printf("\npop()\n");
pop();
display();

printf("\npop()\n");
pop();
display();

printf("\npop()\n");
pop();
display();



return 0;
}