# include<stdio.h>
# include<stdlib.h>

struct listnode{
    int info;
    struct listNode *link;
};

struct treeNode {
    struct treeNode *lchild;
    int info;
    struct treeNode *rchild;
};

struct treeNode* constructInPre(struct listnode* preptr,struct listnode* inptr,int n){
    struct treeNode* tmp;
    struct listnode* p,*q;
    int i,j;
    if(n==0) return NULL;
    tmp=(struct treeNode*)malloc(sizeof(struct treeNode));
    tmp->lchild=NULL;
    tmp->info=preptr->info;
    tmp->rchild=NULL;
    if(n==1) return tmp;

    p=inptr;
    q=preptr;
    for (i=0 ;p->info!=q->info ; i++)
    {
        p=p->link;
    }
    tmp->lchild=constructInPre(preptr->link,p,i);

    for (int j = 0; j <=i+1; j++)
    {
        preptr=preptr->link;
    }
    tmp->rchild=constructInPre(preptr,p->link,n-i-1);
    return tmp;
}



int main(){



return 0;
}