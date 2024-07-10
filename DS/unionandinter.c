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
        printf("List Empty\n");
        return;
    }
    struct node *p = start;

    printf("\nYour list:\n");
    while (p != NULL)
    {
        printf("%d ", p->info);
        p = p->link;
    }
    return;
}

struct node *addAtBegin(struct node *start, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = start;
    start = tmp;
    return start;
}

struct node *addAtEnd(struct node *start, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;

    struct node *p = start;

    while (p->link != NULL)
    {
        p = p->link;
    }

    p->link = tmp;
    tmp->link = NULL;

    return start;
}

int existsList(struct node *start, int item)
{
    struct node *p = start;
    while (p != NULL)
    {
        if (p->info == item)
        {
            return 1;
        }
        p = p->link;
    }
    return 0;
}

struct node *unionList(struct node *L1, struct node *L2)
{
    struct node *tmp = NULL, *p = L1;
    int count = 0;

    while (p != NULL)
    {
        if (count == 0)
        {
            tmp = addAtBegin(tmp, p->info);
        }
        else
        {
            tmp = addAtEnd(tmp, p->info);
        }
        count++;
        p = p->link;
    }

    for (struct node *i = L2; i != NULL; i = i->link)
    {
        int seen = 0;
        for (struct node *j = L1; j != NULL; j = j->link)
        {
            if (i->info == j->info)
            {
                //    tmp=addAtEnd(tmp,j->info);
                seen = 1;
                break;
            }

        }
            if (!seen)
            {
                tmp = addAtEnd(tmp, i->info);
            }
    }
    return tmp;
}
struct node *intersectList(struct node *L1, struct node *L2)
{
    struct node *tmp = NULL;
    int count = 0;
    for (struct node *i = L1; i != NULL; i = i->link)
    {
        for (struct node *j = L2; j != NULL; j = j->link)
        {
            if (i->info == j->info)
            {

                if (count == 0)
                {
                    tmp = addAtBegin(tmp, i->info);
                }
                else
                {
                    tmp = addAtEnd(tmp, i->info);
                }

                count++;
            }
        }
    }

    return tmp;
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

    printf("Enter element: ");
    scanf("%d", &data);
    start = addAtBegin(start, data);
    for (int i = 1; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &data);
        start = addAtEnd(start, data);
    }

    return start;
}

int main()
{
    struct node *s1 = NULL;
    struct node *s2 = NULL;
    s1 = createList(s1);
    s2 = createList(s2);

    displayList(s1);
    displayList(s2);

    struct node *intersection = intersectList(s1, s2);
    displayList(intersection);

    struct node *unionOfList = unionList(s1, s2);
    displayList(unionOfList);

   
    return 0;
}