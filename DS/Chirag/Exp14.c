#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *addEnd(struct Node *last, int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    if (last == NULL) {
        last = temp;
        last->next = last;
        return last;
    }
    temp->next = last->next;
    last->next = temp;
    last = temp;
    return last;
}

void display(struct Node *last) {
    struct Node *p;
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    p = last->next;
    do {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != last->next);
    printf("NULL\n");
}

struct Node *addToEmpty(struct Node *last, int data) {
    if (last != NULL) {
        return last;
    }
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    last = temp;
    last->next = last;
    return last;
}

struct Node *addBegin(struct Node *last, int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    if (last == NULL) {
        last = temp;
        last->next = last;
        return last;
    }
    temp->next = last->next;
    last->next = temp;
    return last;
}

struct Node *addAfter(struct Node *last, int data, int item) {
    struct Node *temp, *p;
    p = last->next;
    do {
        if (p->data == item) {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = data;
            temp->next = p->next;
            p->next = temp;
            if (p == last)
                last = temp;
            return last;
        }
        p = p->next;
    } while (p != last->next);
    printf("%d not present in the list\n", item);
    return last;
}

struct Node *addBefore(struct Node *last, int data, int item) {
    struct Node *temp, *p;
    if (last == NULL) {
        printf("List is empty\n");
        return last;
    }
    if (last->next->data == item) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
        temp->next = last->next;
        last->next = temp;
        return last;
    }
    p = last->next;
    do {
        if (p->next->data == item) {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = data;
            temp->next = p->next;
            p->next = temp;
            return last;
        }
        p = p->next;
    } while (p != last->next);
    printf("%d not present in the list\n", item);
    return last;
}

struct Node *addPos(struct Node *last, int data, int pos) {
    struct Node *temp, *p;
    int i;
    if (pos == 1) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
        temp->next = last->next;
        last->next = temp;
        return last;
    }
    p = last->next;
    for (i = 1; i < pos - 1 && p != last; i++) {
        p = p->next;
    }
    if (p == last && i < pos - 1) {
        printf("There are less than %d elements\n", pos);
        return last;
    }
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = p->next;
    p->next = temp;
    return last;
}

struct Node *del(struct Node *last, int data) {
    struct Node *temp, *p;
    if (last == NULL) {
        printf("List is empty\n");
        return last;
    }
    if (last->next == last && last->data == data) {
        temp = last;
        last = NULL;
        free(temp);
        return last;
    }
    if (last->next->data == data) {
        temp = last->next;
        last->next = temp->next;
        free(temp);
        return last;
    }
    p = last->next;
    while (p->next != last) {
        if (p->next->data == data) {
            temp = p->next;
            p->next = temp->next;
            free(temp);
            return last;
        }
        p = p->next;
    }
    if (last->data == data) {
        temp = last;
        p->next = last->next;
        last = p;
        free(temp);
        return last;
    }
    printf("%d not present in the list\n", data);
    return last;
}

struct Node *createList(struct Node *last) {
    int nodes, data;
    printf("Enter number of nodes: ");
    scanf("%d", &nodes);
    if (nodes == 0) {
        return last;
    }
    printf("Enter element 1: ");
    scanf("%d", &data);
    last = addBegin(last, data);
    for (int i = 2; i <= nodes; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &data);
        last = addEnd(last, data);
    }
    return last;
}

int count(struct Node *last) {
    struct Node *p;
    int count = 0;
    if (last == NULL) {
        return count;
    }
    p = last->next;
    do {
        count++;
        p = p->next;
    } while (p != last->next);
    return count;
}

void search(struct Node *last, int data) {
    struct Node *p;
    int pos = 1;
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    p = last->next;
    do {
        if (p->data == data) {
            printf("%d found at position %d\n", data, pos);
            return;
        }
        pos++;
        p = p->next;
    } while (p != last->next);
    printf("%d not found in the list\n", data);
}




int main() {
    struct Node *last = NULL;
    int choice, data, item;
    while (1) {
        printf("1. Create List\n");
        printf("2. Display\n");
        printf("3. Add at empty\n");
        printf("4. Add at beginning\n");
        printf("5. Add at End\n");
        printf("6. Add after\n");
        printf("7. Add before\n");
        printf("8. Add at position\n");
        printf("9. Delete\n");
        printf("10. Search\n");
        printf("11. Count\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            last = createList(last);
            break;
        case 2:
            display(last);
            break;
        case 3:
            printf("Enter element to add: ");
            scanf("%d", &data);
            last = addToEmpty(last, data);
            break;
        case 4:
            printf("Enter element to add: ");
            scanf("%d", &data);
            last = addBegin(last, data);
            break;
        case 5:
            printf("Enter element to add: ");
            scanf("%d", &data);
            last = addEnd(last, data);
            break;
        case 6:
            printf("Enter element to add: ");
            scanf("%d", &data);
            printf("Enter element to add after: ");
            scanf("%d", &item);
            last = addAfter(last, data, item);
            break;
        case 7:
            printf("Enter element to add: ");
            scanf("%d", &data);
            printf("Enter element to add before: ");
            scanf("%d", &item);
            last = addBefore(last, data, item);
            break;
        case 8:
            printf("Enter element to add: ");
            scanf("%d", &data);
            printf("Enter position to add: ");
            scanf("%d", &item);
            last = addPos(last, data, item);
            break;
        case 9:
            printf("Enter element to delete: ");
            scanf("%d", &data);
            last = del(last, data);
            break;
        case 10:
            printf("Enter element to search: ");
            scanf("%d", &data);
            search(last, data);
            break;
        case 11:
            printf("Number of elements: %d\n", count(last));
            break;
        case 12:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}