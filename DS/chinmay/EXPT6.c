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
printf("\ndelete()\n");
delete();
display();
printf("\ninsert(13)\n");
insert(13);
display();
printf("\ninsert(86)\n");
insert(86);
display();
printf("\ninsert(109)\n");
insert(109);
display();
printf("\ninsert(68)\n");
insert(68);
display();
printf("\ndelete()\n");
delete();
display();
printf("\ndelete()\n");
delete();
display();
printf("\ninsert(100)\n");
insert(100);
display();
printf("\ninsert(11)\n");
insert(11);
display();
printf("\ninsert(89)\n");
insert(89);
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




return 0;
}