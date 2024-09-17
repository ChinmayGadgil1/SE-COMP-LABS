#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 4

int front=-1,rear=-1;

int queueArr[MAX];

int isFull(){
    return rear==MAX-1;
}

int isEmpty(){
    return front==-1  || front>rear;
}

void insert(int item){
    if (isFull())
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front==-1)
    {
        front++;
    }
    
    rear++;
    queueArr[rear]=item;
}

int delete(){
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        return INT_MIN;
    }
    int item=queueArr[front];
    front++;
    return item;
}

int peek(){
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    return queueArr[front];
}

void display(){
    if (isEmpty())
    {
        printf("Queue Empty\n");
        return;
    }
    for (int i = front; i <=rear; i++)
    {
        printf("%d ",queueArr[i]);
    }
    printf("\n");
}

int main(){

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
                if (item != INT_MIN) {
                    printf("Front element: %d\n", item);
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