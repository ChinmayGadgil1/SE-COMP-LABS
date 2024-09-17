#include <stdio.h> 
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *addToEmpty(struct Node *start, int data) {
    if (start != NULL) {
        return start;
    }
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    start = temp;
    return start;
}

struct Node *addBeg(struct Node *start, int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = start;
    temp->prev = NULL;
    if (start != NULL) {
        start->prev = temp;
    }
    start = temp;
    return start;
}

struct Node *addEnd(struct Node *start, int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr;
    temp->data = data;
    temp->next = NULL;
    if (start == NULL) {
        temp->prev = start;
        start = temp;
    } else {
        ptr = start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
    }
    return start;
}

struct Node *addAfter(struct Node *start, int data, int item) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr, *preptr;
    temp->data = data;
    ptr = start;
    preptr = ptr;
    while (preptr->data != item) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = temp;
    temp->prev = preptr;
    temp->next = ptr;
    ptr->prev = temp;
    return start;
}

struct Node *addBefore(struct Node *start, int data, int item) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr, *preptr;
    temp->data = data;
    ptr = start;
    if (ptr->data == item) {
        temp->next = ptr;
        ptr->prev = temp;
        temp->prev = NULL;
        start = temp;
        return start;
    }
    while (ptr->data != item) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = temp;
    temp->prev = preptr;
    temp->next = ptr;
    ptr->prev = temp;
    return start;
}
struct Node *addPos(struct Node *start, int data, int pos) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr;
    int i;
    temp->data = data;
    ptr = start;
    for (i = 1; i < pos - 1; i++) {
        ptr = ptr->next;
        if (ptr == NULL) {
            printf("There are less than %d elements\n", pos);
            return start;
        }
    }
    temp->next = ptr->next;
    temp->prev = ptr;
    ptr->next = temp;
    ptr->next->prev = temp;
    return start;
}

struct Node *createList(struct Node *start) {
    int nodes, data;
    printf("Enter number of nodes: ");
    scanf("%d", &nodes);
    if (nodes == 0) {
        return start;
    }
    for (int i = 1; i <= nodes; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &data);
        start = addEnd(start, data);
    }
    return start;
}

struct Node *del(struct Node *start, int data) {
    struct Node *temp;
    if (start == NULL) {
        printf("List is empty\n");
        return start;
    }
    if (start->data == data) {
        temp = start;
        start = start->next;
        start->prev = NULL;
        free(temp);
        return start;
    }
    temp = start;
    while (temp->next != NULL) {
        if (temp->data == data) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            return start;
        }
        temp = temp->next;
    }
    if (temp->data == data) {
        temp->prev->next = NULL;
        free(temp);
        return start;
    }
    printf("Element %d not found\n", data);
    return start;
}

void display(struct Node *start) {
    struct Node *temp = start;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int count(struct Node *start) {
    struct Node *temp = start;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}


struct Node *reverse(struct Node *start) {
    struct Node *ptr, *temp;
    ptr = start;
    while (ptr != NULL) {
        temp = ptr->next;
        ptr->next = ptr->prev;
        ptr->prev = temp;
        if (ptr->prev == NULL) {
            start = ptr;
        }
        ptr = ptr->prev;
    }
    return start;
}

void search(struct Node *start, int data) {
    struct Node *temp = start;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("Element %d found\n", data);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found\n", data);
}

int main () {
    struct Node *start = NULL;
    int choice, data, item, pos;
    while (1) {
        printf("1. Create List\n");
        printf("2. Add at empty\n");
        printf("3. Add at beginning\n");
        printf("4. Add at end\n");
        printf("5. Add after\n");
        printf("6. Add before\n");
        printf("7. Add at position\n");
        printf("8. Delete\n");
        printf("9. Display\n");
        printf("10. Count\n");
        printf("11. Reverse\n");
        printf("12. Search\n");
        printf("13. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                start = createList(start);
                break;
            case 2:
                printf("Enter element to add: ");
                scanf("%d", &data);
                start = addToEmpty(start, data);
                break;
            case 3:
                printf("Enter element to add: ");
                scanf("%d", &data);
                start = addBeg(start, data);
                break;
            case 4:
                printf("Enter element to add: ");
                scanf("%d", &data);
                start = addEnd(start, data);
                break;
            case 5:
                printf("Enter element to add: ");
                scanf("%d", &data);
                printf("Enter element after which to add: ");
                scanf("%d", &item);
                start = addAfter(start, data, item);
                break;
            case 6:
                printf("Enter element to add: ");
                scanf("%d", &data);
                printf("Enter element before which to add: ");
                scanf("%d", &item);
                start = addBefore(start, data, item);
                break;
            case 7:
                printf("Enter element to add: ");
                scanf("%d", &data);
                printf("Enter position at which to add: ");
                scanf("%d", &pos);
                start = addPos(start, data, pos);
                break;
            case 8:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                start = del(start, data);
                break;
            case 9:
                display(start);
                break;
            case 10:
                printf("Number of elements: %d\n", count(start));
                break;
            case 11:
                start = reverse(start);
                break;
            case 12:
                printf("Enter element to search: ");
                scanf("%d", &data);
                search(start, data);
                break;
            case 13:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}