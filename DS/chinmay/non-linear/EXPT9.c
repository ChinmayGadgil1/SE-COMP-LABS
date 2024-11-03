# include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int adj[MAX][MAX];
int state[MAX];
int n;

int stackArr[MAX];
int top = -1;

int stackisFull()
{
    return (top == MAX - 1);
}

int stackisEmpty()
{
    return (top == -1);
}


void push(int x)
{
    if (stackisFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stackArr[top] = x;
}

int pop()
{
    if (stackisEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    int item = stackArr[top];
    top--; 
    return item;
}


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


void create(){
    int max_edges,origin,destin;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    max_edges = n*(n-1);
    for (int i = 1; i <= max_edges; i++)
    {
        printf("Enter edge %d((-1 -1) to quit): ",i);
        scanf("%d %d",&origin,&destin);
        if((origin == -1) && (destin == -1)){
            break;
        }
        if(origin >= n || destin >= n || origin < 0 || destin < 0){
            printf("Invalid edge\n");
            i--;
        }else{
            adj[origin][destin] = 1;
        }
    }
}

void BFS(int v){
    insert(v);
    state[v]=waiting;
    while(!isEmpty()){
        v=delete();
        printf("%d ",v);
        state[v]=visited;
        for(int i=0;i<n;i++){
            if(adj[v][i]==1 && state[i]==initial){
                insert(i);
                state[i]=waiting;
            }
        }
    }
}

void BFS_traversal(){
    for (int v = 0; v < n; v++)
    {
        state[v]=initial;
    }
    printf("Enter starting vertex for BFS: ");
    int v;
    scanf("%d",&v);
    BFS(v);
    for(int i=0;i<n;i++){
        if(state[i]==initial){
            BFS(i);
        }
    }
    printf("\n");
}

void DFSNR(int v){
    push(v);
    state[v]=waiting;
    while(!stackisEmpty()){
        v=pop();
        printf("%d ",v);
        state[v]=visited;
        for(int i=0;i<n;i++){
            if(adj[v][i]==1 && state[i]==initial){
                push(i);
                state[i]=waiting;
            }
        }
    }
}

void DFS_traversalNR(){
    for (int v = 0; v < n; v++)
    {
        state[v]=initial;
    }
    printf("Enter starting vertex for DFS: ");
    int v;
    scanf("%d",&v);
    DFSNR(v);
    for(int i=0;i<n;i++){
        if(state[i]==initial){
            DFSNR(i);
        }
    }
    printf("\n");
}

void DFSR(int v){
    printf("%d ",v);
    state[v]=visited;
    for(int i=0;i<n;i++){
        if(adj[v][i]==1 && state[i]==initial){
            DFSR(i);
        }
    }
}

void DFS_traversalR(){
    for (int v = 0; v < n; v++)
    {
        state[v]=initial;
    }
    printf("Enter starting vertex for DFS: ");
    int v;
    scanf("%d",&v);
    DFSR(v);
    for(int i=0;i<n;i++){
        if(state[i]==initial){
            DFSR(i);
        }
    }
    printf("\n");
}
    

int main(){

int choice;
    printf("\n1. Create graph\n");
    printf("2. BFS Traversal\n");
    printf("3. DFS Traversal (Non-Recursive)\n");
    printf("4. DFS Traversal (Recursive)\n");
    printf("5. Exit\n");
while(1){
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        create();
        break;
    case 2:
        BFS_traversal();
        break;
    case 3:
        DFS_traversalNR();
        break;
    case 4:
        DFS_traversalR();
        break;
    case 5:
        exit(1);
    default:
        printf("Invalid choice\n");
        break;
    }
}


return 0;
}