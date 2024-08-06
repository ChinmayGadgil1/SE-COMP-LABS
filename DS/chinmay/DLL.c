# include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* prev,*next;
};

struct node* addEmpty(struct node* start,int data){
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = NULL;
    start = tmp;
    return start;
}

struct node* addBegin(struct node* start,int data){
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = start;
    start->prev = tmp;
    start = tmp;
    return start;
}

struct node* addEnd(struct node* start,int data){
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    struct node* ptr = start;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    tmp->info = data;
    tmp->prev = ptr;
    tmp->next = NULL;
    ptr->next = tmp;
    return start;
}

struct node* addAfter(struct node* start,int data,int item){
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    struct node* ptr = start;
    while(ptr!=NULL){
        if(ptr->info==item){
            tmp->info = data;
            tmp->prev = ptr;
            tmp->next = ptr->next;
            if(ptr->next!=NULL){
                ptr->next->prev = tmp;
            }
            ptr->next = tmp;
            return start;
        }
        ptr = ptr->next;
    }
    printf("Element not found\n");
    return start;
}

struct node* createDLL(struct node* start){
    int n,data;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    if(n==0){
        return start;
    }
    printf("Enter the first element: ");
    scanf("%d",&data);
    start = addEmpty(start,data);
    for(int i=1;i<n;i++){
        printf("Enter the next element: ");
        scanf("%d",&data);
        start = addEnd(start,data);
    }
    return start;
}

struct node* display(struct node* start){
    struct node* ptr = start;
    while(ptr!=NULL){
        printf("%d ",ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
    return start;
}


struct node* swapAlternate(struct node* start) {
    if (start == NULL || start->next == NULL) {
        return start;
    }

    struct node* p = start;
    struct node* q = start->next;
    start = q;
    struct node* tmp;


    while (1) {
        tmp = q->next;
        q->next = p;
        q->prev = p->prev;
        p->prev = q;
        p->next = tmp;
        if (tmp == NULL || tmp->next == NULL)
            break;
        p->next = tmp->next;
        p = tmp;
        q = p->next;
    }

    return start;
}

void printAddresses(struct node* start){

    struct node* p=start;
    while(p!=NULL){
        printf("%p  ",p);
        p=p->next;
    }
    printf("\n");
}

int main(){

struct node* start=NULL;
start=createDLL(start);
printAddresses(start);
start=swapAlternate(start);
printAddresses(start);

return 0;
}