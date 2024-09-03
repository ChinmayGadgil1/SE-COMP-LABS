#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    struct node *left;
    int info;
    struct node *right;
    bool lthread;
    bool rthread;
};

struct node* insert(struct node* root,int ikey){
    struct node* ptr=root,*par=NULL,*tmp;
    bool found=false;
    while(ptr!=NULL){
        if(ikey==ptr->info){
            found=true;
            break;
        }
        par=ptr;
        if(ikey<ptr->info){
            if(ptr->lthread==false)
                ptr=ptr->left;
            else{
                break;
            }
        }
        else{
            if(ptr->rthread==false)
                ptr=ptr->right;
            else{
                break;
            }
        }
    }
    if(found){
        printf("Duplicate\n");
    }
    else{
        tmp=(struct node*)malloc(sizeof(struct node));
        tmp->info=ikey;
        tmp->lthread=true;
        tmp->rthread=true;
        if(par==NULL){
            root=tmp;
            tmp->left=NULL;
            tmp->right=NULL;
        }
        else if(ikey<par->info){
            tmp->left=par->left;
            tmp->right=par;
            par->lthread=false;
            par->left=tmp;
        }
        else{
            tmp->left=par;
            tmp->right=par->right;
            par->rthread=false;
            par->right=tmp;
        }
    }
    return root;
}

struct node* search(struct node* root,int ikey){
    struct node* ptr=root;
    while(ptr!=NULL){
        if(ikey==ptr->info){
            return ptr;
        }
        if(ikey<ptr->info){
            if(ptr->lthread==false)
                ptr=ptr->left;
            else
                break;
        }
        else{
            if(ptr->rthread==false)
                ptr=ptr->right;
            else
                break;
        }
    }
    printf("Key not found\n");
    return NULL;
}

void deleteAllocation(struct node* root){
    struct node* ptr=root,*tmp;
    while(ptr!=NULL){
        while(ptr->lthread==false)
            ptr=ptr->left;
        while(ptr!=NULL){
            if(ptr->rthread==true){
                tmp=ptr;
                ptr=ptr->right;
                free(tmp);
            }
            else{
                ptr=ptr->right;
                break;
            }
        }
    }
}

int main(){

    struct node* root=NULL;
    int choice,ikey;
    struct node* ptr;
    while(1){
        printf("1.Insert\n2.Search\n3.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d",&ikey);
                root=insert(root,ikey);
                break;
            case 2:
                printf("Enter the key to search:");
                scanf("%d",&ikey);
                ptr=search(root,ikey);
                if(ptr!=NULL)
                    printf("\nKey found\n\n");
                break;
            case 3:
                exit(0);
        }
    }

deleteAllocation(root);
return 0;
}