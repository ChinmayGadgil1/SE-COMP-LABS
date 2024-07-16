#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

void displayList(struct node *start) {
    if (start == NULL) {
        printf("List Empty\n");
        return;
    }
    struct node *p = start;

    while (p != NULL) {
        printf("%d ", p->info);
        p = p->link;
    }
    printf("\n");
}

struct node *add(struct node *start, int data) {
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = NULL;

    if (start == NULL) {
        start = tmp;
        return start;
    }

    struct node* p = start;
    while (p->link != NULL) {
        p = p->link;
    }

    p->link = tmp;

    return start;
}

struct node *unionList(struct node *L1, struct node *L2) {
    struct node *result = NULL;
    struct node *p = L1;

    while (p != NULL) {
        result = add(result, p->info);
        p = p->link;
    }

    for (struct node *i = L2; i != NULL; i = i->link) {
        int seen = 0;
        for (struct node *j = L1; j != NULL; j = j->link) {
            if (i->info == j->info) {
                seen = 1;
                break;
            }
        }
        if (!seen) {
            result = add(result, i->info);
        }
    }
    return result;
}

struct node *intersectList(struct node *L1, struct node *L2) {
    struct node *result = NULL;
    for (struct node *i = L1; i != NULL; i = i->link) {
        for (struct node *j = L2; j != NULL; j = j->link) {
            if (i->info == j->info) {
                result = add(result, i->info);
            }
        }
    }

    return result;
}

struct node *differenceList(struct node *L1, struct node *L2) {
    struct node *result = NULL;
    struct node *p, *q;
    int found;

    for (p = L1; p != NULL; p = p->link) {
        found = 0;
        for (q = L2; q != NULL; q = q->link) {
            if (p->info == q->info) {
                found = 1;
                break;
            }
        }
        if (!found) {
            result = add(result, p->info);
        }
    }

    for (p = L2; p != NULL; p = p->link) {
        found = 0;
        for (q = L1; q != NULL; q = q->link) {
            if (p->info == q->info) {
                found = 1;
                break;
            }
        }
        if (!found) {
            result = add(result, p->info);
        }
    }

    return result;
}

struct node *createList(struct node *start) {
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    start = NULL;
    if (n == 0) {
        return start;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &data);
        start = add(start, data);
    }

    return start;
}

int main() {
    struct node *s1 = NULL;
    struct node *s2 = NULL;

    printf("Start by creating two lists:\n");
    s1 = createList(s1);
    s2 = createList(s2);

    printf("List 1: ");
    displayList(s1);
    printf("List 2: ");
    displayList(s2);

    int choice;
    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Union\n2. Intersection\n3. Difference\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nUnion:\n");
                struct node *unionOfList = unionList(s1, s2);
                displayList(unionOfList);
                break;
            case 2:
                printf("\nIntersection:\n");
                struct node *intersection = intersectList(s1, s2);
                displayList(intersection);
                break;
            case 3:
                printf("\nDifference:\n");
                struct node *difference = differenceList(s1, s2);
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
