#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct dllnode{
    int info;
    struct dllnode* prev,*next;
};

struct dllnode* dlladdEmpty(struct dllnode* start,int data){
    struct dllnode* tmp = (struct dllnode*)malloc(sizeof(struct dllnode));
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = NULL;
    start = tmp;
    return start;
}

struct dllnode* dlladdBegin(struct dllnode* start,int data){
    struct dllnode* tmp = (struct dllnode*)malloc(sizeof(struct dllnode));
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = start;
    start->prev = tmp;
    start = tmp;
    return start;
}

struct dllnode* dlladdEnd(struct dllnode* start,int data){
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

struct dllnode* dlladdAfter(struct dllnode* start,int data,int item){
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

struct dllnode* createDLL(struct dllnode* start){
    int n,data;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    if(n==0){
        return start;
    }
    printf("Enter the first element: ");
    scanf("%d",&data);
    start = dlladdEmpty(start,data);
    for(int i=1;i<n;i++){
        printf("Enter the next element: ");
        scanf("%d",&data);
        start = dlladdEnd(start,data);
    }
    return start;
}

void displayDLL(struct dllnode* start){
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


struct dllnode* dllswapAlternate(struct dllnode* start) {
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

void printAddresses(struct dllnode* start){

    struct dllnode* p=start;
    while(p!=NULL){
        printf("%p  ",p);
        p=p->next;
    }
    printf("\n");
}


struct node *addEmpty(struct node *last, int data)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = tmp;
    last = tmp;
    return last;
}

struct node *addBegin(struct node *last, int data)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = last->link;
    last->link = tmp;
    return last;
}

struct node *addEnd(struct node *last, int data)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = last->link;
    last->link = tmp;
    last = tmp;
    return last;
}

struct node *addAfter(struct node *last, int data, int item)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = last->link;
    do
    {
        if (ptr->info == item)
        {
            tmp->info = data;
            tmp->link = ptr->link;
            ptr->link = tmp;
            if (ptr == last)
            {
                last = tmp;
            }
            return last;
        }
        ptr = ptr->link;
    } while (ptr != last->link);
    printf("Element not found\n");
    return last;
}

struct node *createList(struct node *last)
{
    int n, data;
    last = NULL;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if (n == 0)
    {
        return last;
    }
    printf("Enter element: ");
    scanf("%d", &data);
    last = addEmpty(last, data);
    for (int i = 2; i <= n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &data);
        last = addEnd(last, data);
    }
    return last;
}

void displayCLL(struct node *last)
{
    if (last == NULL)
    {
        printf("\n last\n");
        printf("------\n");
        printf("|NULL|\n");
        printf("------\n");
        return;
    }
    struct node *p = last->link;
    printf("\n");

    p = last->link;
    do
    {
        printf("                     ");
        p = p->link;
    } while (p != last->link);

    printf("   last\n");

    p = last->link;
    do
    {
        printf("                     ");

        p = p->link;
    } while (p != last->link);
    printf("----------\n");

    p = last->link;
    do
    {
        if(p==last){
            printf("             |-------");
        }
        else
            printf("                     ");

        p = p->link;
    } while (p != last->link);

    printf("|%8p|\n", last);

    p = last->link;
    do
    {
        if(p==last){
            printf("             V       ");
        }
        else
            printf("                     ");

        p = p->link;
    } while (p != last->link);
    printf("----------\n");
    

    printf("      ");
    p = last->link;
    do
    {
        printf("----------------     ");
        p = p->link;
    } while (p != last->link);
    printf("\n");

    printf("  |-->");
    p = last->link;
    do
    {
        if (p == last)
        {
            printf("| %3d |%8p|------", p->info, p->link);
        }
        else
        {
            printf("| %3d |%8p|---> ", p->info, p->link);
        }
        p = p->link;
    } while (p != last->link);
    printf("|");
    printf("\n");
   

    printf("  |   ");
    p = last->link;
    do
    {
        printf("----------------     ");
        p = p->link;
    } while (p != last->link);
    printf(" |");

    printf("\n");
    printf("  |    ");
    p = last->link;
    do
    {
        printf("   %8p          ", p);
        p = p->link;
    } while (p != last->link);
    printf("|");
    printf("\n");
    printf("  |___");
    p = last->link;
    do
    {
        printf("_____________________", p);
        p = p->link;
    } while (p != last->link);
    printf("_|");
    printf("\n\n");
}

struct node * deleteNode(struct node *last, int data) {
    if (last == NULL) {
        return last;
    }

    struct node* tmp,*p;

    if(last==last->link && last->info==data){
        tmp=last;
        last=NULL;
        free(tmp);
        return last;
    }

    if(last->link->info==data){
        tmp=last->link;
        last->link=tmp->link;
        free(tmp);
        return last;
    }
    p=last->link;
    while (p->link != last) {
        if (p->link->info == data) {
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            return last;
        }
        p = p->link;
    }

    if (last->info == data) {
        tmp = last;
        p->link = last->link;
        last = p;
        free(tmp);
    }

    return last;
}

struct node *deleteAlternateNodes(struct node *last) {
    if (last == NULL || last->link == last) {
        return last; 
    }

    struct node *ptr = last->link;
    struct node *tmp;

    while (ptr != last && ptr->link != last) {
        tmp = ptr->link; 
        ptr->link = tmp->link; 
        free(tmp); 
        ptr = ptr->link;
    }

    if (ptr->link == last) {
        tmp = last;
        ptr->link = last->link;
        free(tmp);
        last = ptr;
    }

    return last;
}

struct node *deleteList(struct node *last)
{
    struct node *ptr = last->link;
    struct node *tmp;
    while (ptr != last)
    {
        tmp = ptr;
        ptr = ptr->link;
        free(tmp);
    }
    free(last);
    last = NULL;
    return last;
}

int main()
{
    struct dllnode* dll=createDLL(dll);
    printf("\nBefore swapping alternate nodes:\n\n");
    displayDLL(dll);
    dllswapAlternate(dll);
    printf("\nAfter swapping alternate nodes\n\n");
    displayDLL(dll);

    struct node* cll=createList(cll);
    printf("\nBefore deleting alternate nodes\n\n");
    displayCLL(cll);
    deleteAlternateNodes(cll);
    printf("\nAfter deleting alternate nodes\n\n");
    displayCLL(cll);
    
    return 0;
}