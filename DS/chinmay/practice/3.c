# include<stdio.h>
#include <stdlib.h>

struct node
{
    struct node *lchild;
    int info;
    struct node *rchild;
};

struct node* insert(struct node* root,int info){

}

struct node* delete(struct node* ptr,int dkey){
    struct node* tmp;
    if(ptr==NULL){
        printf("Dkey not found");
    }
    else if(ptr->info<dkey){
        ptr->rchild= delete(ptr->rchild,dkey);
    }
    else if(ptr->info>dkey){
        ptr->lchild=delete(ptr->lchild,dkey);
    }
    else{
        if(ptr->lchild!=NULL && ptr->rchild!=NULL){
            struct node* succ=ptr->rchild;
            while(ptr->lchild!=NULL)
                succ=ptr->lchild;
            ptr->info=succ->info;
            ptr->rchild=delete(ptr->rchild,succ->info);
        }
        else if(ptr->lchild!=NULL){
            tmp=ptr;
            ptr=ptr->lchild;
        }
        else if(ptr->rchild!=NULL){
            tmp=ptr;
            ptr=ptr->rchild;
        }
        else{
            tmp=ptr;
            ptr=NULL;
        }
        free(tmp);
        return ptr;
    }
}

int main(){



return 0;
}