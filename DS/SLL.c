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
struct node* addAtPos(struct node*,int,int);
struct node* addAfter(struct node*,int,int);
struct node* addBefore(struct node*,int,int);
struct node* deleteNode(struct node*,int);
struct node* reverse(struct node*);

int main(){

struct node* start=NULL;
int choice;
int item;
int position;
int data;

while (1)
{
    printf("\n\n1. Create list\n");
    printf("2. Display list\n");
    printf("3. Count\n");
    printf("4. Search list\n");
    printf("5. Add at Beginning\n");
    printf("6. Add at End\n");
    printf("7. Add after Node\n");
    printf("8. Add before Node\n");
    printf("9. Add at position\n");
    printf("10. Delete Node\n");
    printf("11. Reverse List\n");
    printf("12. Quit\n");
    printf("Your choice=> ");
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
        printf("Enter data to be added at beginning: ");
        scanf("%d",&data);
        start=addAtBegin(start,data);
        break;
    case 6:
        printf("Enter data to be added at end: ");
        scanf("%d",&data);
        start=addAtEnd(start,data);
        break;
    case 7:
        printf("Enter the data and item after which to insert: ");
        scanf("%d %d",&data,&item);
        start=addAfter(start,data,item);
        break;
    case 8:
        printf("Enter the data and item before which to insert: ");
        scanf("%d %d",&data,&item);
        start=addBefore(start,data,item);
        break;
    case 9:
        printf("Enter the data and position to insert: ");
        scanf("%d %d",&data,&position);
        start=addAtPos(start,data,position);
        break;
    case 10:
        printf("Enter the item to be deleted: ");
        scanf("%d",&data);
        start=deleteNode(start,data);
        break;
    case 11:
        start=reverse(start);
        break;
    case 12:
        printf("\nQuiting...\n");
        exit(1);
    default:
        printf("Invalid input try again\n");
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



struct node* addAfter(struct node* start,int data,int item){
    struct node* tmp,*p=start;
    while (p!=NULL)
    {
        if(p->info==item)
        {
            tmp=(struct node*)malloc(sizeof(struct node));
            tmp->info=data;
            tmp->link=p->link;
            p->link=tmp;
            return start;
        }
        p=p->link;
    }
    printf("Item not found\n");
    return start;
}

struct node * addBefore(struct node* start,int data,int item){
    struct node* tmp,*p=start;
    if (start==NULL)
    {
        printf("List is Empty\n");
        return start;
    }
    if (start->info==item){
        tmp=(struct node*)malloc(sizeof(struct node));
        tmp->info=data;
        tmp->link=start;
        start=tmp;
        return start;
    }
    while (p->link!=NULL)
    {
        if(p->link->info==item){
            tmp=(struct node*)malloc(sizeof(struct node));
            tmp->info=data;
            tmp->link=p->link;
            p->link=tmp;
            return start;
        }
        p=p->link;
    }
    printf("Item not found\n");
    return start;
}

struct node* addAtPos(struct node* start,int data,int pos){
    struct node* tmp,*p=start;
    if(pos==1){
        tmp=(struct node*)malloc(sizeof(struct node));
        tmp->info=data;
        tmp->link=start;
        start=tmp;
        return start;
    }
    for (int i = 1; i < pos-1 && p!=NULL; i++){
        p=p->link;
    }

    if(p==NULL){
        printf("There are less elements than position\n");
        return start;
    }
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->link=p->link;
    p->link=tmp;
    return start;
}

struct node* deleteNode(struct node* start,int data){
    struct node* tmp,*p=start;

    if(start==NULL){
        printf("List is empty\n");
        return start;
    }
    if(start->info==data){
        tmp=start;
        start=start->link;
        free(tmp);
        return start;
    }

    while(p->link!=NULL){
        if(p->link->info==data){
            tmp=p->link;
            p->link=tmp->link;
            free(tmp);
            return start;
        }
        p=p->link;
    }
    printf("data not found\n");
    return start;
}

struct node* reverse(struct node* start){
    struct node* prev,*ptr,*next;
    prev=NULL;
    ptr=start;

    while (ptr!=NULL)
    {
        next=ptr->link;
        ptr->link=prev;
        prev=ptr;
        ptr=next;
    }
    start=prev;
    return start;
}