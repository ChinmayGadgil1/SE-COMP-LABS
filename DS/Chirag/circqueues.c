//23B-CO-015
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>  

#define MAX 4

int front = -1, rear = -1;
int cqueue[MAX];

int isFull(){
    if((front == 0 && rear == MAX-1)||(front == rear + 1))
        return 1;
    else
        return 0;
}

int isEmpty(){
     if(front == -1)
        return 1;
    else
        return 0;
}
void insert(int x){
    if(isFull()){
        printf("Circular queue overflow");
        return;
    }
    if(front == -1)
        front = 0;
    if(rear == MAX-1)
        rear = 0;
    else
        rear++;
    cqueue[rear] = x;
    printf("\ninsert(%d)\n", x);
}

int del()
{
    int item;
    printf("\ndelete(%d)\n", item);
    
    if (isEmpty())
    {
        printf("cqueue Underflow\n");
        exit(1);
    }
    item = cqueue[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else if(front == MAX-1)
        front = 0;
    else
        front++;
    return item;
}

int peek()
{
    if (isEmpty())
    {
        printf("Empty\n");
        exit(1);
    }
    return cqueue[front];
}

void display()
{
    int i;
    if(isEmpty()){
        printf("cqueue is empty");
        return;
    }
    printf("cqueueArr:  ");
    i = front;
    if(front<=rear){
        while(i<=rear)
            printf("%d ",cqueue[i++]);
    }
    else{
        while(i<=MAX-1)
            printf("%d ",cqueue[i++]);
        i=0;
        while(i<=rear)
            printf("%d ",cqueue[i++]);
    }
    printf("\nfront = %d\n",front);
    printf("rear = %d\n\n",rear);
}

int main()
{
    printf("\nInitially:\n");
    display();
    insert(74);
    display();
    insert(27);
    display();
    insert(64);
    display();
    insert(20);
    display();
    del();
    display();
    del();
    display();
    del();
    display();
    insert(41);
    display();
    insert(109);
    display();
    insert(84);
    display();
    del();
    display();
    insert(102);
    display();
    del();
    display();
    del();
    display();
    del();
    display();
    return 0;
}



