#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* link;
};

void displayList(struct node*);
void countNodes(struct node*);
void searchList(struct node*,int);
struct node* addAtBegin(struct node*,int);
struct node* addAtEnd(struct node* ,int);
struct node* createList(struct node*);
struct node* addAtBet(struct node*,int,int);



int main(){

struct node* start=NULL;
int choice;
int item;
int index;

while (1)
{
    printf("\n\n1. Create list\n");
    printf("2. Display list\n");
    printf("3. Count\n");
    printf("4. Search list\n");
    printf("5. Quit\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        start=createList(start);
        break;
    
    case 2:
        displayList(start);
        break;
    case 3: 
        countNodes(start);
        break;
    case 4:
        printf("Enter element to be searched: ");
        scanf("%d",&item);
        searchList(start,item);
        break;
    case 5:
        printf("Enter element and index to add:\n");
        scanf("%d%d", &item,&index);
        start=addAtBet(start,item,index);
        break;
    case 6:
        printf("\nQuiting...\n");
        exit(1);
    default:
        printf("Invalid input try again\n");
        break;
    }

}


return 0;
}


void displayList(struct node* start){
    if (start==NULL)    
    {
        printf("List Empty\n");
        return;
    }
    struct node *p=start;

    printf("Your list:\n");
    while (p!=NULL)
    {
        printf("%d ",p->info);
        p=p->link;
    }
    return;  
}

void countNodes(struct node* start){
    int count=0;
    struct node* p=start;
    while (p!=NULL)
    {
        count++;
        p=p->link;
    }
    printf("Number of Node=%d\n",count);
    return;
}

void searchList(struct node* start,int item){
    if (start==NULL)
    {
        printf("List is Empty, Element not found\n");

    }
    int pos=1;
    struct node* p=start;
    while (p!=NULL)
    {
        if(p->info==item)
        {
            printf("\nElement %d found at position %d\n",item,pos);
            return;
        }
            pos++;
            p=p->link;
    }
    
    printf("Element not found\n");

}

struct node* addAtBegin(struct node* start,int data){
    struct node* tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->link=start;
    start=tmp;
    return start;
}

struct node* addAtEnd(struct node* start,int data){
    struct node* tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=data;
    
    struct node* p=start;

    while (p->link!=NULL)
    {
        p=p->link;
    }
    
    p->link=tmp;
    tmp->link=NULL;

    return start;
}

struct node* createList(struct node* start){

    int n,data;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    start=NULL;
    if (n==0)
    {
        return start;
    }

    printf("Enter element: ");
    scanf("%d",&data);
    start=addAtBegin(start,data);
    for (int i = 1 ; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d",&data);
        start=addAtEnd(start,data);
    }
    
    return start;
}

struct node* addAtBet(struct node* start,int data,int pos){
    struct node* tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=data;

    struct node* p=start;
    struct node* q=start->link;

    for (int i = 0; i < pos; i++)
    {
        p=p->link;
        q=q->link;
    }
    
    p->link=tmp;
    tmp->link=q;
    return start;
}