# include<stdio.h>
#include<stdlib.h>

struct dllnode{
    int info;
    struct dllnode* prev,*next;
};

struct dllnode* addEmpty(struct dllnode* start,int data){
    struct dllnode* tmp = (struct dllnode*)malloc(sizeof(struct dllnode));
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = NULL;
    start = tmp;
    return start;
}

struct dllnode* addBegin(struct dllnode* start,int data){
    struct dllnode* tmp = (struct dllnode*)malloc(sizeof(struct dllnode));
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = start;
    start->prev = tmp;
    start = tmp;
    return start;
}

struct dllnode* addEnd(struct dllnode* start,int data){
    struct dllnode* tmp = (struct dllnode*)malloc(sizeof(struct dllnode));
    struct dllnode* ptr = start;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    tmp->info = data;
    tmp->prev = ptr;
    tmp->next = NULL;
    ptr->next = tmp;
    return start;
}

struct dllnode* addAfter(struct dllnode* start,int data,int item){
    struct dllnode* tmp = (struct dllnode*)malloc(sizeof(struct dllnode));
    struct dllnode* ptr = start;
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

struct dllnode* addBefore(struct dllnode* start,int item,int data){
    struct dllnode* tmp,*p=start;
    if (start==NULL)
    {
        printf("\nList is Empty\n");
        return start;
    }
    if (start->info==item){
        tmp=(struct dllnode*)malloc(sizeof(struct dllnode));
        tmp->info=data;
        tmp->next=start;
        start=tmp;
        return start;
    }
    while (p->next!=NULL)
    {
        if(p->next->info==item){
            tmp=(struct dllnode*)malloc(sizeof(struct dllnode));
            tmp->info=data;
            tmp->next=p->next;
            p->next=tmp;
            return start;
        }
        p=p->next;
    }
    printf("\nItem not found\n");
    return start;
}

struct dllnode* createDLL(struct dllnode* start){
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

void display(struct dllnode* start){
    if (start==NULL)
    {
    printf("\n start\n");
    printf("------\n");
    printf("|NULL|\n");
    printf("------\n\n");
        return;
    }
  
     printf("\n  start\n");
    printf("----------\n");
    printf("|%8p|\n",start);
    printf("----------\n");
    printf("     |               ");
    for (struct dllnode* i = start; i->next !=NULL; i=i->next)
    {
        printf(" -----------------------  --> ");
    }
    printf(" -----------------------      ");

    printf("\n");
    printf("     |-------------->");
    for (struct dllnode* i = start; i !=NULL; i=i->next)
    {
        if (i->next!=NULL && i->prev!=NULL)
        {
            printf("|%8p| %3d |%8p|     ",i->prev,i->info,i->next);
        }
        else if(i->next==NULL && i->prev!=NULL){
            printf("|%8p| %3d |%8s|     ",i->prev,i->info,"NULL");

        }
        else if (i->next!=NULL && i->prev==NULL)
        {
            printf("|%8s| %3d |%8p|     ", "NULL", i->info, i->next);
        }
        else
        {
            printf("|%8s| %3d |%8s|     ", "NULL", i->info, "NULL");
        }
    }
    printf("\n");
    printf("                     ");
    for (struct dllnode* p = start; p ->next!=NULL; p=p->next)
    {
        printf(" -----------------------  <-- ");
    }
    printf(" -----------------------      ");

    printf("\n");
    printf("                   ");
                    
    printf("          ");
    for (struct dllnode* p = start; p !=NULL; p=p->next)
    {
        printf("%8p                      ",p);
    }
    printf("\n\n");
}

int count(struct dllnode* start){
    int c=0;
    for(struct dllnode* p=start;p!=NULL;p=p->next){
        c++;
    }
    return c;
}

struct dllnode* search(struct dllnode* start,int item){
    struct dllnode* ptr = start;
    while(ptr!=NULL){
        if(ptr->info==item){
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

struct dllnode* del(struct dllnode* start,int data){
    struct dllnode* tmp = start;
    struct dllnode* ptr = start;
    while(ptr->next!=NULL){
        if(ptr->next->info==data){
            tmp = ptr->next;
            ptr->next = tmp->next;
            if(tmp->next!=NULL){
                tmp->next->prev = ptr;
            }
            free(tmp);
            return start;
        }
        ptr = ptr->next;
    }
    if(ptr->next==NULL && ptr->info==data){
        tmp = ptr;
        ptr->prev->next = NULL;
        free(tmp);
        return start;
    }
    printf("Element not found\n");
    return start;
}

struct dllnode* reverse(struct dllnode* start){
    struct dllnode* tmp;
    struct dllnode* p = start;
    while(p!=NULL){
        tmp = p->prev;
        p->prev = p->next;
        p->next = tmp;
        p = p->prev;
    }
    if(tmp!=NULL){
        start = tmp->prev;
    }
    return start;
}



struct dllnode* swapAlternate(struct dllnode* start) {
    if (start == NULL || start->next == NULL) {
        return start;
    }

    struct dllnode* p = start;
    struct dllnode* q = start->next;
    start = q;
    struct dllnode* tmp;


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


int main(){
    int choice, data, item;
    struct dllnode* start = NULL;

    do {
        printf("\n\n********* MENU *********\n");
        printf("1. Create DLL\n");
        printf("2. Display DLL\n");
        printf("3. Count DLL\n");
        printf("4. Search DLL\n");
        printf("5. Add to Empty DLL\n");
        printf("6. Add at Beginning of DLL\n");
        printf("7. Add at End of DLL\n");
        printf("8. Add After a Node in DLL\n");
        printf("9. Add Before a Node in DLL\n");
        printf("10. Delete a Node from DLL\n");
        printf("11. Reverse DLL\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Exiting...\n");
                break;
            case 1:
                start = createDLL(start);
                break;
            case 2:
                display(start);
                break;
            case 3:
                printf("Number of nodes in DLL: %d\n", count(start));
                break;
            case 4:
                printf("Enter the element to search: ");
                scanf("%d", &item);
                struct dllnode* result = search(start, item);
                if (result != NULL) {
                    printf("Element found at address %p\n", result);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 5:
                printf("Enter the element to add: ");
                scanf("%d", &data);
                start = addEmpty(start, data);
                break;
            case 6:
                printf("Enter the element to add: ");
                scanf("%d", &data);
                start = addBegin(start, data);
                break;
            case 7:
                printf("Enter the element to add: ");
                scanf("%d", &data);
                start = addEnd(start, data);
                break;
            case 8:
                printf("Enter the element to add: ");
                scanf("%d", &data);
                printf("Enter the element after which to add: ");
                scanf("%d", &item);
                start = addAfter(start, data, item);
                break;
            case 9:
                printf("Enter the element to add: ");
                scanf("%d", &data);
                printf("Enter the element before which to add: ");
                scanf("%d", &item);
                start = addBefore(start, item, data);
                break;
            case 10:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                start = del(start, data);
                break;
            case 11:
                start = reverse(start);
                printf("DLL reversed\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 12);

return 0;
}