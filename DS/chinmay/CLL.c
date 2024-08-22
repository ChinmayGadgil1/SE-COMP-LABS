#include <stdio.h>
#include <stdlib.h>

struct node
{
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

void display(struct node *last)
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
            printf("             |       ");
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
    struct node *last = NULL;
    printf("Create a Circular Linked List\n");
    last = createList(last);
    printf("Before Deleting alternate nodes\n");
    display(last);
    printf("After Deleting alternate nodes\n");
    last = deleteAlternateNodes(last);
    display(last);

    deleteList(last);
    return 0;
}