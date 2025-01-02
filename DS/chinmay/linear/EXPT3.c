#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

void displayList(struct node *start)
{
    if (start == NULL)
    {
        printf("Empty\n");
        return;
    }
    struct node *p = start;

    while (p != NULL)
    {
        printf("%d ", p->info);
        p = p->link;
    }
    printf("\n");
}

struct node *add(struct node *start, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = NULL;

    if (start == NULL)
    {
        start = tmp;
        return start;
    }

    if(start->info==data){
        printf("\nDuplicates not allowed! Enter new data: ");
        scanf("%d",&data);
        tmp->info=data;
    }

    if(start->info>data){
        tmp->link=start;
        start=tmp;
        return start;
    }

    struct node *p = start;
    while (p->link != NULL)
    {
        if(p->link->info==data){
            printf("\nDuplicates not allowed! Enter new data: ");
            scanf("%d",&data);
            tmp->info=data;
        }
        if (p->link->info > data)
        {
            break;
        }
        p = p->link;
    }

    tmp->link = p->link;
    p->link = tmp;
    return start;
}

struct node *unionList(struct node *L1, struct node *L2)
{
    struct node *result = NULL;
    struct node *p = L1;

    while (p != NULL)
    {
        result = add(result, p->info);
        p = p->link;
    }

    for (struct node *i = L2; i != NULL; i = i->link)
    {
        int seen = 0;
        for (struct node *j = L1; j != NULL; j = j->link)
        {
            if (i->info == j->info)
            {
                seen = 1;
                break;
            }
        }
        if (!seen)
        {
            result = add(result, i->info);
        }
    }
    return result;
}

struct node *intersectList(struct node *L1, struct node *L2)
{
    struct node *result = NULL;
    for (struct node *i = L1; i != NULL; i = i->link)
    {
        for (struct node *j = L2; j != NULL; j = j->link)
        {
            if (i->info == j->info)
            {
                result = add(result, i->info);
            }
    
        }
    }

    return result;
}

struct node *differenceList(struct node *L1, struct node *L2)
{
    struct node *result = NULL;
    struct node *p, *q;
    int found;

    for (p = L1; p != NULL; p = p->link)
    {
        found = 0;
        for (q = L2; q != NULL; q = q->link)
        {
            if (p->info == q->info)
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            result = add(result, p->info);
        }
    }

    return result;
}

struct node *unionL(struct node *l1, struct node *l2)
{
    struct node* l3;
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    while(l1 && l2)
    {
        if(l1->info==l2->info){
            l3=add(l3,l1->info);
            l1=l1->link;
            l2=l2->link;
        }
        else{
            l3=add(l3,l1->info);
            l3=add(l3,l2->info);
            l1=l1->link;
            l2=l2->link;
        }
    }
    while(l1){
        l3=add(l3,l1->info);
        l1=l1->link;
    }
    while (l2)
    {
        l3=add(l3,l2->info);
        l2=l2->link;
    }
    return l3;
}

struct node *sortList(struct node *start)
{
    if (start == NULL)
        return NULL;
    if (start->link == NULL)
    {
        return start;
    }
    int tmp, k = 0;
    for (struct node *i = start; i != NULL; i = i->link)
    {
        for (struct node *j = i->link; j != NULL; j = j->link)
        {
            if (i->info > j->info)
            {
                tmp = i->info;
                i->info = j->info;
                j->info = tmp;
            }
        }
    }

    return start;
}

struct node *createList(struct node *start)
{
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    start = NULL;
    if (n == 0)
    {
        return start;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &data);
        start = add(start, data);
    }

    return start;
}

int main()
{
    struct node *s1 = NULL;
    struct node *s2 = NULL;

    printf("Start by creating two lists:\n");
    s1 = createList(s1);
    s1 = sortList(s1);
    s2 = createList(s2);
    s2 = sortList(s2);

    printf("List 1: ");
    displayList(s1);
    printf("List 2: ");
    displayList(s2);

    int choice;
    while (1)
    {
        printf("\nChoose an operation:\n");
        printf("1. Union\n2. Intersection\n3. Difference\n4. Exit\n");
        printf("Enter your choice=>  ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nList 1: ");
            displayList(s1);
            printf("List 2: ");
            displayList(s2);
            struct node *unionOfList = unionL(s1, s2);
            // unionOfList = sortList(unionOfList);
            printf("Union:\n");
            displayList(unionOfList);
            break;
        case 2:
            printf("\nList 1: ");
            displayList(s1);
            printf("List 2: ");
            displayList(s2);
            struct node *intersection = intersectList(s1, s2);
            intersection = sortList(intersection);
            printf("Intersection:\n");
            displayList(intersection);
            break;
        case 3:
            printf("\nList 1: ");
            displayList(s1);
            printf("List 2: ");
            displayList(s2);
            struct node *difference = differenceList(s1, s2);
            difference = sortList(difference);
            printf("Difference:\n");
            displayList(difference);
            break;
        case 4:
            printf("\nExiting...\n");
            exit(0);
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}
