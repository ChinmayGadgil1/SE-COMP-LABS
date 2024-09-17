#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *link;
};


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

struct node* addBefore(struct node* last,int item,int data){
    struct node* tmp,*p;
    if(last==NULL){
        printf("List is empty\n");
        return last;
    }
    if(last->link->info==item){
        last=addEnd(last,data);
        return last;
    }
    p=last->link;
    while(p->link!=last){
        if(p->link->info==item){
            tmp=(struct node*)malloc(sizeof(struct node));
            tmp->info=data;
            tmp->link=p->link;
            p->link=tmp;
            return last;
        }
        p=p->link;
    }
    if(last->info==item){
        last=addEnd(last,data);
        return last;
    }
    printf("Element not found\n");
    return last;
}


struct node* search(struct node* last,int item){
    struct node* p=last->link;
    do{
        if(p->info==item){
            return p;
        }
        p=p->link;
    }while(p!=last->link);
    return NULL;
}

int count(struct node* last){
    struct node* p=last->link;
    int c=0;
    do{
        c++;
        p=p->link;
    }while(p!=last->link);
    return c;
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

struct node* reverse(struct node* last){
    struct node* prev,*ptr,*next;
    if(last==NULL){
        return last;
    }
    prev=last;
    ptr=last->link;
    while(ptr!=last){
        next=ptr->link;
        ptr->link=prev;
        prev=ptr;
        ptr=next;
    }
    ptr->link=prev;
    last=last->link;
    return last;
}

int main()
{
    struct node *last = NULL;
    int choice, data, item;

    do
    {
        printf("\n\n********* MENU *********\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Add to Empty List\n");
        printf("4. Add at Beginning\n");
        printf("5. Add at End\n");
        printf("6. Add After\n");
        printf("7. Add Before\n");
        printf("8. Delete\n");
        printf("9. Search\n");
        printf("10. Count\n");
        printf("11. Reverse\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            last = createList(last);
            break;
        case 2:
            displayCLL(last);
            break;
        case 3:
            printf("Enter element to be inserted: ");
            scanf("%d", &data);
            last = addEmpty(last, data);
            break;
        case 4:
            printf("Enter element to be inserted: ");
            scanf("%d", &data);
            last = addBegin(last, data);
            break;
        case 5:
            printf("Enter element to be inserted: ");
            scanf("%d", &data);
            last = addEnd(last, data);
            break;
        case 6:
            printf("Enter element to be inserted: ");
            scanf("%d", &data);
            printf("Enter element after which to insert: ");
            scanf("%d", &item);
            last = addAfter(last, data, item);
            break;
        case 7:
            printf("Enter element to be inserted: ");
            scanf("%d", &data);
            printf("Enter element before which to insert: ");
            scanf("%d", &item);
            last = addBefore(last, item, data);
            break;
        case 8:
            printf("Enter element to be deleted: ");
            scanf("%d", &data);
            last = deleteNode(last, data);
            break;
        case 9:
            printf("Enter element to be searched: ");
            scanf("%d", &data);
            struct node *result = search(last, data);
            if (result != NULL)
            {
                printf("Element found\n");
            }
            else
            {
                printf("Element not found\n");
            }
            break;
        case 10:
            printf("Number of nodes: %d\n", count(last));
            break;
        case 11:
            last = reverse(last);
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 12);

    return 0;
}