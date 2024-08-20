#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* addNode(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("[Address: %p | Data: %d] <-> ", (void*)temp, temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* swapAlternateNodes(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        struct Node* nextNode = current->next;

        if (current->prev != NULL) {
            current->prev->next = nextNode;
        }
        if (nextNode->next != NULL) {
            nextNode->next->prev = current;
        }

        current->next = nextNode->next;
        nextNode->prev = current->prev;
        nextNode->next = current;
        current->prev = nextNode;

        if (nextNode->prev == NULL) {
            head = nextNode;
        }

        current = current->next;
    }

    return head;
}

int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        head = addNode(head, data);
    }

    printf("Original list: ");
    displayList(head);

    head = swapAlternateNodes(head);

    printf("List after swapping alternate nodes: ");
    displayList(head);

    return 0;
}