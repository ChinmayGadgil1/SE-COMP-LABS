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

int main()
{
    printf("Enter size of tree: ");
    int n;
    scanf("%d", &n);
    return 0;
}