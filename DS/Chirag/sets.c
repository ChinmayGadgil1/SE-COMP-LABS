//23B-CO-015
#include <stdio.h>
#include <stdlib.h>

int PR_NUM=202311095;
char ROLL_NUM[]="23B-CO-015";
void footer(){
    printf("\n================================\n");
    printf("PR NUMBER: %d\n", PR_NUM);
    printf("ROLL NUMBER: %s ",ROLL_NUM);
    printf("\n================================\n");

}

struct Node {
    int value;
    struct Node *next;
};

void printList(struct Node *head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    struct Node *current = head;

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

struct Node *insert(struct Node *head, int data) {
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->value = data;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        return head;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = temp;

    return head;
}

struct Node *unionOfLists(struct Node *list1, struct Node *list2) {
    struct Node *result = NULL;
    struct Node *current = list1;

    while (current != NULL) {
        result = insert(result, current->value);
        current = current->next;
    }

    for (struct Node *i = list2; i != NULL; i = i->next) {
        int found = 0;
        for (struct Node *j = list1; j != NULL; j = j->next) {
            if (i->value == j->value) {
                found = 1;
                break;
            }
        }
        if (!found) {
            result = insert(result, i->value);
        }
    }
    return result;
}

struct Node *intersectionOfLists(struct Node *list1, struct Node *list2) {
    struct Node *result = NULL;
    for (struct Node *i = list1; i != NULL; i = i->next) {
        for (struct Node *j = list2; j != NULL; j = j->next) {
            if (i->value == j->value) {
                result = insert(result, i->value);
            }
        }
    }

    return result;
}

struct Node *differenceOfLists(struct Node *list1, struct Node *list2) {
    struct Node *result = NULL;
    struct Node *p, *q;
    int found;

    for (p = list1; p != NULL; p = p->next) {
        found = 0;
        for (q = list2; q != NULL; q = q->next) {
            if (p->value == q->value) {
                found = 1;
                break;
            }
        }
        if (!found) {
            result = insert(result, p->value);
        }
    }

    return result;
}

struct Node *createNewList(struct Node *head) {
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    head = NULL;
    if (n == 0) {
        return head;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &data);
        head = insert(head, data);
    }

    return head;
}

int main() {
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;

    printf("Start by creating two lists:\n");
    list1 = createNewList(list1);
    list2 = createNewList(list2);

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    int choice;
    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Union\n2. Intersection\n3. Difference\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nUnion:\n");
                struct Node *unionResult = unionOfLists(list1, list2);
                printList(unionResult);
                break;
            case 2:
                printf("\nIntersection:\n");
                struct Node *intersectionResult = intersectionOfLists(list1, list2);
                printList(intersectionResult);
                break;
            case 3:
                printf("\nDifference:\n");
                struct Node *differenceResult = differenceOfLists(list1, list2);
                printList(differenceResult);
                break;
            case 4:
                printf("\nExiting...\n");
                footer();
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    footer();
    return 0;
}
