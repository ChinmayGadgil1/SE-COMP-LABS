#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* prev;
    struct node* next;
};

struct node* last = NULL; 

void insertAtBeginning(int data) {
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;

    if (last == NULL) {
        tmp->prev = tmp;
        tmp->next = tmp;
    } else {
        struct node* last = last->prev;

        tmp->prev = last;
        tmp->next = last;

        last->next = tmp;
        last->prev = tmp;
    }

    last = tmp;
}

struct node* addAtEnd(int data) {
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;

    if (last == NULL) {
        tmp->prev = tmp;
        tmp->next = tmp;
        last = tmp;
    } else {
        struct node* last = last->prev;

        tmp->prev = last;
        tmp->next = last;

        last->next = tmp;
        last->prev = tmp;
    }

    return tmp;
}

struct node* addAfter(struct node* prevNode, int data) {
    if (prevNode == NULL) {
        return NULL;
    }

    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;

    tmp->prev = prevNode;
    tmp->next = prevNode->next;

    prevNode->next->prev = tmp;
    prevNode->next = tmp;

    return tmp;
}

struct node* addBefore(struct node* nextNode, int data) {
    if (nextNode == NULL) {
        return NULL;
    }

    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;

    tmp->prev = nextNode->prev;
    tmp->next = nextNode;

    nextNode->prev->next = tmp;
    nextNode->prev = tmp;

    return tmp;
}

void deleteNode(struct node* node) {
    if (node == NULL) {
        return;
    }

    if (node->next == node) {
        last = NULL;
    } else {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        if (node == last) {
            last = node->prev;
        }
    }

    free(node);
}

void deleteNodes(int data) {
    if (last == NULL) {
        return;
    }

    struct node* current = last->next;
    struct node* next;

    while (current != last) {
        next = current->next;

        if (current->info == data) {
            deleteNode(current);
        }

        current = next;
    }

    if (last->info == data) {
        deleteNode(last);
    }
}

void deleteItem(int data) {
    if (last == NULL) {
        return;
    }

    struct node* current = last->next;
    struct node* next;

    while (current != last) {
        next = current->next;

        if (current->info == data) {
            deleteNode(current);
            return;
        }

        current = next;
    }

    if (last->info == data) {
        deleteNode(last);
    }
}


void swapAlternateNodes() {
    if (last == NULL) {
        return;
    }

    struct node* current = last->next;
    while (current != last) {
        int tmp = current->info;
        current->info = current->next->info;
        current->next->info = tmp;

        current = current->next->next;
    }
}

void createList(int n) {
    int data;
    struct node* tmp;

    for (int i = 0; i < n; i++) {
        printf("Enter the data: ");
        scanf("%d", &data);

        if (i == 0) {
            tmp = addAtEnd(data);
        } else {
            tmp = addAfter(tmp, data);
        }
    }
}

int main() {
    createList(5);

    
    return 0;
}