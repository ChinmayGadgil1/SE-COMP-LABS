# include<stdio.h>
#include<stdlib.h>

struct listNode{
    int info;
    struct listNode *link;
}*inptr=NULL,*preptr=NULL,*postptr=NULL;

struct treeNode{
    struct treeNode *lchild;
    int info;
    struct treeNode *rchild;
}; 



struct listNode* addAtBegin(struct listNode* start,int data){
    struct listNode* tmp;
    tmp=(struct listNode*)malloc(sizeof(struct listNode));
    tmp->info=data;
    tmp->link=start;
    start=tmp;
    return start;
}

struct listNode* addAtEnd(struct listNode* start,int data){
    struct listNode* tmp;
    tmp=(struct listNode*)malloc(sizeof(struct listNode));
    tmp->info=data;
    
    struct listNode* p=start;

    while (p->link!=NULL)
    {
        p=p->link;
    }
    
    p->link=tmp;
    tmp->link=NULL;

    return start;
}

struct listNode* createList(struct listNode* start,int n){
    int data;
    start=NULL;
    if (n==0)
    {
        return start;
    }
    printf("\n");
    printf("Enter element: ");
    scanf("%d",&data);
    start=addAtBegin(start,data);
    for (int i = 1 ; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d",&data);
        start=addAtEnd(start,data);
    }
    
    return start;
}



struct treeNode* constructPreIn(struct listNode *preptr, struct listNode *inptr,int n){

struct treeNode *tmp;
struct listNode *q;
int i,j;
if(n==0)
    return NULL;
tmp=(struct treeNode*)malloc(sizeof(struct treeNode));
tmp->lchild=NULL;
tmp->info=preptr->info;
tmp->rchild=NULL;

if(n==1)
    return tmp;

q=inptr;
for(i=0;q->info!=preptr->info;i++)
    q=q->link;

tmp->lchild=constructPreIn(preptr->link,inptr,i);

for(j=1;j<=i+1;j++)
    preptr=preptr->link;

tmp->rchild=constructPreIn(preptr,q->link,n-i-1);

return tmp;
}

struct treeNode* constructPostIn(struct listNode *postptr, struct listNode *inptr,int n){
    int i,j;
    struct treeNode *tmp;
    struct listNode *q,*p;

    if(n==0)
        return NULL;
    tmp=(struct treeNode*)malloc(sizeof(struct treeNode));
    tmp->lchild=NULL;
    q=postptr;
    for(i=1;i<n;i++)
        q=q->link;
    tmp->info=q->info;
    tmp->rchild=NULL;
    if(n==1)
        return tmp;

    p=inptr;
    for(i=0;p->info!=q->info;i++)
        p=p->link;
    tmp->lchild=constructPostIn(postptr,inptr,i);

    for(j=1;j<=i;j++)
        postptr=postptr->link;

    tmp->rchild=constructPostIn(postptr,p->link,n-i-1);
}



void preorder(struct treeNode *ptr){
    if(ptr==NULL)
        return;
    printf("%d ",ptr->info);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}
void inorder(struct treeNode *ptr){
    if(ptr==NULL)
        return;
    inorder(ptr->lchild);
    printf("%d ",ptr->info);
    inorder(ptr->rchild);
}

void postorder(struct treeNode *ptr){
    if(ptr==NULL)
        return;
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d ",ptr->info);
}


                                                                                     

int main(){

printf("Enter size of tree: ");
int n;
scanf("%d",&n);


printf("Enter the inorder list: ");
inptr=createList(inptr,n);
printf("Enter the preorder list: ");
preptr=createList(preptr,n);

struct treeNode *root;
root=constructPreIn(preptr,inptr,n);

preorder(root);
printf("\n");
inorder(root);
printf("\n");
postorder(root);
printf("\n");

return 0;
}