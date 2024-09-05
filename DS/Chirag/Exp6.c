#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX_SIZE 4

int front = -1, rear = -1;

int queue[MAX_SIZE];

int isFull() {
    return rear == MAX_SIZE - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int element) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) {
        front++;
    }
    rear++;
    queue[rear] = element;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    int element = queue[front];
    front++;
    return element;
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        exit(1);
    }
    return queue[front];
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, element;

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                element = dequeue();
                if (element != INT_MIN) {
                    printf("Dequeued element: %d\n", element);
                }
                break;
            case 3:
                element = peek();
                if (element != INT_MIN) {
                    printf("Front element: %d\n", element);
                }
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
