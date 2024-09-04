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

struct node* in_succ(struct node* ptr){
    if(ptr->rthread==true)
        return ptr->right;
    ptr=ptr->right;
    while(ptr->lthread==false)
        ptr=ptr->left;
    return ptr;
}

struct node* in_pred(struct node* ptr){
    if(ptr->lthread==true)
        return ptr->left;
    ptr=ptr->left;
    while(ptr->rthread==false)
        ptr=ptr->right;
    return ptr;
}  

struct node* case_a(struct node* root,struct node* par,struct node* ptr){
    if(par==NULL)
        root=NULL;
    else if(ptr==par->left){
        par->lthread=true;
        par->left=ptr->left;
    }
    else{
        par->rthread=true;
        par->right=ptr->right;
    }
    free(ptr);
    return root;
}

struct node* case_b(struct node* root,struct node* par,struct node* ptr){
    struct node* child,*s,*p;
    if(ptr->lthread==false)
        child=ptr->left;
    else
        child=ptr->right;
    if(par==NULL)
        root=child;
    else if(ptr==par->left)
        par->left=child;
    else
        par->right=child;
    s=in_succ(ptr);
    p=in_pred(ptr);
    if(ptr->lthread==false)
        p->right=s;
    else{
        if(ptr->rthread==false)
            s->left=p;
    }
    free(ptr);
    return root;
}

struct node* case_c(struct node* root,struct node* par,struct node* ptr){
    struct node* succ,*parsucc;
    parsucc=ptr;
    succ=ptr->right;
    while(succ->left!=NULL){
        parsucc=succ;
        succ=succ->left;
    }
    ptr->info=succ->info;
    if(succ->lthread==true && succ->rthread==true)
        root=case_a(root,parsucc,succ);
    else
        root=case_b(root,parsucc,succ);
    return root;
}

struct node* delete(struct node* root,int dkey){
    struct node* ptr=root,*par=NULL,*child,*succ,*parsucc;
    bool found=false;
    while(ptr!=NULL){
        if(dkey==ptr->info){
            found=true;
            break;
        }
        par=ptr;
        if(dkey<ptr->info){
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
    if(!found){
        printf("Key not found\n");
        return root;
    }
    else if(ptr->lthread==false && ptr->rthread==false)
        root=case_c(root,par,ptr);
    else if(ptr->lthread==false || ptr->rthread==false)
        root=case_b(root,par,ptr);
    else
        root=case_a(root,par,ptr);
    return root;
}

int main(){

    struct node* root=NULL;
    int choice,ikey;
    struct node* ptr;
    while(1){
        printf("1.Insert\n2.Search\n3.Delete\n4.Exit\n");
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
                printf("Enter the key to delete:");
                scanf("%d",&ikey);
                root=delete(root,ikey);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

deleteAllocation(root);
return 0;
}