#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *front = NULL, *rear = NULL;

int isEmpty() {
    return (front == NULL);
}

int peek() {
    if (!isEmpty()) {
        return front->data;
    } else {
        printf("Queue Underflow \n");
        exit(1);
    }
}
void insert(int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Queue Overflow \n");
        return;
    }
    temp->data = data;
    temp->next = NULL;
    if (isEmpty()) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}
int delete() {
    struct Node *temp;
    int data;
    if (isEmpty()) {
        printf("Queue Underflow \n");
        return '\0';
    }
    temp = front;
    data = temp->data;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
    return data;
}
void display() {
    struct Node *temp;
    if (isEmpty()) {
        printf("Queue is empty \n");
        return;
    }
    temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    int choice, item;
    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d", &item);
            insert(item);
            break;
        case 2:
            item = delete();
            if (item != '\0') {
                printf("Deleted item is : %d\n", item);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Front element is : %d\n", peek());
            break;
        case 5:
            exit(1);
        default:
            printf("Invalid choice\n");
        }
    }
    
    return 0;
}