# include<stdio.h>
# include<stdlib.h>
# include<limits.h>

struct node{
    int info;
    struct node* link;
};

struct node* front=NULL;
struct node* rear=NULL;

void insert(int data){
    struct node* tmp=(struct node*)malloc(sizeof(struct node));
    if (tmp==NULL)
    {
        printf("Queue Overflow\n");
        return;
    }
    tmp->info=data;
    tmp->link=NULL;
    if(front==NULL){
        front=tmp;
    }
    else{
        rear->link=tmp;
    }
    rear=tmp;
}

int delete(){
    if(front==NULL){
        printf("Queue Underflow\n");
        return INT_MIN;
    }
    struct node* tmp=front;
    int data=tmp->info;
    front=front->link;
    free(tmp);
    return data;
}

int peek(){
    if(front==NULL){
        printf("Queue Underflow\n");
        return INT_MIN;
    }
    return front->info;
}

int main(){


return 0;
}