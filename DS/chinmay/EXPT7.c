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
    printf("\ninsert(64)\n");
    insert(64);
    display();
    
    printf("\ninsert(105)\n");
    insert(105);
    display();
    
    printf("\ninsert(100)\n");
    insert(100);
    display();
    
    printf("\ninsert(89)\n");
    insert(89);
    display();
    
    printf("\ninsert(100)\n");
    insert(100);
    display();
    
    printf("\ndelete()\n");
    delete();
    display();
    
    printf("\ndelete()\n");
    delete();
    display();
    
    printf("\ndelete()\n");
    delete();
    display();
    
    printf("\ndelete()\n");
    delete();
    display();
    
    printf("\ninsert(27)\n");
    insert(27);
    display();
    
    printf("\ndelete()\n");
    delete();
    display();
    
    printf("\ndelete()\n");
    delete();
    display();
    
    printf("\ninsert(45)\n");
    insert(45);
    display();  

    return 0;
}
                                                                                                                                                                                   