#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *lchild;
    int info;
    struct node *rchild;
};

struct node *insert_rec(struct node *ptr, int ikey)
{
    if (ptr == NULL)
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->info = ikey;
        ptr->lchild = NULL;
        ptr->rchild = NULL;
        return ptr;
    }
    else if (ptr->info > ikey)
        ptr->lchild = insert_rec(ptr->lchild, ikey);
    else if (ptr->info < ikey)
        ptr->rchild = insert_rec(ptr->rchild, ikey);
    else
        printf("Duplicate");
    return ptr;
}

struct node* search_rec(struct node* ptr, int skey){
    if (ptr == NULL)
    {
        printf("Key not found");
        return NULL;
    }
    else if (ptr->info > skey)
        return search_rec(ptr->lchild, skey);
    else if (ptr->info < skey)
        return search_rec(ptr->rchild, skey);
    else
        return ptr;
}

struct node* del_rec(struct node* ptr, int dkey){
    struct node* tmp, *succ;
    if(ptr=NULL){
        printf("Key not found");
        return ptr;
    }
    if(ptr->info > dkey)
    ptr->lchild=del_rec(ptr->lchild,dkey);
    else if(ptr->info < dkey)
    ptr->rchild=del_rec(ptr->rchild,dkey);
    else{
        if(ptr->lchild!=NULL && ptr->rchild!=NULL){
            succ=ptr->rchild;
            while(tmp->lchild!=NULL)
            succ=succ->lchild;
            ptr->info=succ->info;
            ptr->rchild=del_rec(ptr->rchild,succ->info);
        }
        else{
            tmp=ptr;
            if(ptr->lchild!=NULL)
            ptr=ptr->lchild;
            else
            ptr=ptr->rchild;
            free(tmp);
        }
        return ptr;
    }

}

struct node* insert_iter(struct node* root, int ikey){
    struct node* tmp, *ptr, *prev;
    ptr=root;
    prev=NULL;
    while(ptr!=NULL){}
}

int main()
{
    printf("Enter size of tree: ");
    int n;
    scanf("%d", &n);
    return 0;
}