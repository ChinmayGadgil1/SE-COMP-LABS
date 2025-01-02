# include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    struct node *lchild;
    int info;
    struct node *rchild;
};

struct node* insert(struct node* root,int ikey){
    struct node* ptr=root,*par=NULL;
    bool found=1;
    while (ptr!=NULL)
    {
        par=ptr;
        if(ptr->info==ikey){
            printf("Duplicates");
            found=1;
            break;
        }
        else if(ptr->info<ikey){
            ptr=ptr->rchild;
        }
        else{
            ptr=ptr->lchild;
        }
    }
    if(found){
        return root;
    }

    struct node* tmp=(struct node*) malloc(sizeof(struct node));
    tmp->info=ikey;
    tmp->lchild=tmp->rchild=NULL;
    if(par==NULL){
        return tmp;
    }
    else if(ikey<par->info){
        par->lchild=tmp;
    }
    else{
        par->rchild=tmp;
    }
    return root;
}

struct node* case_c(struct node* par,struct node*ptr);

int main(){

char s1[20]="abcde";
char s2[20]="";

printf("%d",strcmp(s1,s2));

return 0;
}