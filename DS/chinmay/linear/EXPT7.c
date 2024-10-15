#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 4

int front = -1, rear = -1;
int cqueueArr[MAX];

int isFull() {
    return front>rear ||(front==0 && rear==MAX-1);
}

int isEmpty() {
    return front == -1;
}

void insert(int item) {
    if (isFull()) {
        printf("Circular Queue Overflow\n");
        return;
    }
    if (front==-1 && rear==-1) {
        front = 0;
        rear= 0;
    }
    
    else
    {
     rear= (rear + 1) % MAX;
    }
    cqueueArr[rear] = item;
}

int delete() {
    if (isEmpty()) {
        printf("Circular Queue Underflow\n");
        return INT_MIN;
    }
    int item = cqueueArr[front];
    if (front == rear) {
        front = rear = -1; 
    }
    else if (front==MAX-1)
    {
        front=0;
    }
    else{
        front++;
    }
    
    return item;
}

int peek() {
    if (isEmpty()) {
        printf("Circular Queue Underflow\n");
        exit(1);
    }
    return cqueueArr[front];
}

void display() {
    if (isEmpty()) {
        printf("Circular Queue Empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", cqueueArr[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, item;

    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                item = delete();
                if (item != INT_MIN) {
                    printf("Deleted element: %d\n", item);
                }
                break;
            case 3:
                item = peek();
                printf("Front element: %d\n", item);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
                                                                                                                                                                                   