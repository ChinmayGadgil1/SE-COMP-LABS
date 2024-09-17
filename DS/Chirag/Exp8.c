#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

int isEmpty() {
    return top == NULL;
}

struct Node *push(int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp) {
        printf("\nHeap Overflow");
        exit(1);
    }
    temp->data = data;
    temp->next = top;
    top = temp;
    return top;
}

int pop() {
    if (top == NULL) {
        printf("\nStack Underflow");
        exit(1);
    }
    struct Node *temp = top;
    top = top->next;
    int data = temp->data;
    free(temp);
    return data;
}

int peek() {
    if (!isEmpty()) {
        return top->data;
    } else {
        printf("Stack Underflow\n");
        exit(1);
    }
}

void display() {
    struct Node *temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, item;
    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            item = pop();
            if (item != '\0') {
                printf("Popped item is : %d\n", item);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            item = peek();
            if (item != '\0') {
                printf("Top element is : %d\n", item);
            }
            break;
        case 5:
            exit(1);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}