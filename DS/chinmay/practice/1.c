# include<stdio.h>

struct listnode{
    int info;
    struct listnode* link;
};

struct node{
    int info;
    struct node* lchild;
    struct node* rchild;
};

struct node* constructInPost(struct listnode* inptr,struct listnode* postptr,int n){
    if(n==0) return NULL;
    int i;
    struct node* tmp=(struct node*)malloc(sizeof(struct node));
    struct listnode *q=postptr ;
    tmp->lchild=NULL;
    for ( i=1;i<n;i++)
    {
        q=q->link;
    }
    tmp->info=q->info;
    tmp->rchild=NULL;
    if(n==1) return tmp;

    struct listnode* p=inptr;
    for(i=0;p->info!=q->info;i++){
        p=p->link;
    }

    tmp->lchild=constructInPost(inptr,postptr,i);

    for(int j=0;j<i;j++){
        postptr=postptr->link;
    }
    tmp->rchild=constructInPost(p->link,postptr,n-i-1);
    return tmp;
}


int main(){



return 0;
}