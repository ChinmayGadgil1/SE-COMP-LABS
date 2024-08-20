#include <stdio.h>
#include <stdlib.h>

struct listnode{
    int info;
    struct listnode* link;
}*preptr=NULL,
*postptr=NULL;

struct treenode{
    struct treenode*lchild;
    int info;
    struct treenode*rchild;
};

struct treenode *construct(struct listnode* preptr, struct listnode* inptr, int num){
struct treenode *tmp;
struct listnode *q;
int i,j;



if(num==0){
    return NULL;
}
tmp=(struct treenode*)malloc(sizeof(struct treenode));
tmp->lchild=NULL;
tmp->info=preptr->info;
tmp->rchild=NULL;

if(num==1){
    return tmp;
}
q=inptr;
for(i=0;q->info!=preptr->info;i++){
    q=q->link;
}
tmp->lchild=construct(preptr->link,inptr,i);

for(j=1;j<=i+1;j++){
    preptr=preptr->link;
}
tmp->rchild=construct(preptr,q->link,num-i-1);
return tmp;
}

struct listnode *addAtBegin(struct listnode *start, int data)
{
    struct listnode *tmp;
    tmp = (struct listnode *)malloc(sizeof(struct listnode));
    tmp->info = data;
    tmp->link = start;
    start = tmp;
    return start;
}

struct listnode *addAtEnd(struct listnode *start, int data)
{
    struct listnode *tmp;
    tmp = (struct listnode *)malloc(sizeof(struct listnode));
    tmp->info = data;

    struct listnode *p = start;

    while (p->link != NULL)
    {
        p = p->link;
    }

    p->link = tmp;
    tmp->link = NULL;

    return start;
}

struct listnode *createList(struct listnode *start)
{

    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    start = NULL;
    if (n == 0)
    {
        return start;
    }

    printf("Enter element: ");
    scanf("%d", &data);
    start = addAtBegin(start, data);
    for (int i = 1; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &data);
        start = addAtEnd(start, data);
    }

    return start;
}



int main(){
    struct listnode* start;
    int data;

    start=createList(start);
    return 0;
}