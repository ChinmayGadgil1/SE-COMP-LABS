#include <stdio.h>

struct node
{
    int info;
    struct node *lchild;
    struct node *rchild;
    int balance;
};

struct node *rightrotate(struct node *pptr)
{
    struct node *aptr = pptr->lchild;
    pptr->lchild = aptr->rchild;
    aptr->rchild = pptr;
    return aptr;
}

struct node *leftrotate(struct node *pptr)
{
    struct node *aptr = pptr->rchild;
    pptr->rchild = aptr->lchild;
    aptr->lchild = pptr;
    return aptr;
}

struct node *insert_left_balance(struct node *pptr)
{
    struct node *aptr = pptr->lchild, *bptr;
    if (aptr->balance == 1)
    {
        pptr->balance = 0;
        aptr->balance = 0;
        pptr = rightrotate(pptr);
    }
    else
    {
        bptr = aptr->rchild;
        switch (bptr->balance)
        {
        case -1:
            pptr->balance = 0;
            aptr->balance = 1;
            break;
        case 1:
            pptr->balance = -1;
            aptr->balance = 0;
            break;
        case 0:
            pptr->balance = 0;
            aptr->balance = 0;
            break;
        default:
            break;
        }
        bptr->balance = 0;
        pptr->lchild = leftrotate(aptr);
        pptr = rightrotate(pptr);
    }
    return pptr;
}

struct node *insert_left_check(struct node *pptr, int *taller)
{
    switch (pptr->balance)
    {
    case 0:
        pptr->balance = 1;
        break;
    case -1:
        pptr->balance = 0;
        *taller = 0;
        break;
    case 1:
        pptr = insert_left_balance(pptr);
        *taller = 0;
        break;
    }
    return pptr;
}

struct node *insert_right_balance(struct node *pptr)
{
    struct node *aptr = pptr->rchild, *bptr;
    if (aptr->balance == -1)
    {
        pptr->balance = 0;
        aptr->balance = 0;
        pptr = leftrotate(pptr);
    }
    else
    {
        bptr = aptr->lchild;
        switch (bptr->balance)
        {
        case -1:
            pptr->balance = 1;
            aptr->balance = 0;
            break;
        case 1:
            pptr->balance = 0;
            aptr->balance = -1;
            break;
        case 0:
            pptr->balance = 0;
            aptr->balance = 0;
            break;
        default:
            break;
        }
        bptr->balance = 0;
        pptr->rchild = rightrotate(aptr);
        pptr = leftrotate(pptr);
    }
}

struct node *insert_right_check(struct node *pptr, int *taller)
{
    switch (pptr->balance)
    {
    case 0:
        pptr->balance = -1;
        break;
    case 1:
        pptr->balance = 0;
        *taller = 0;
        break;
    case -1:
        pptr = insert_right_balance(pptr);
        *taller = 0;
        break;
    }
    return pptr;
}

struct node *insert(struct node *ptr, int ikey)
{
    static int taller;
    if (ptr == NULL)
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->info = ikey;
        ptr->lchild = NULL;
        ptr->rchild = NULL;
        ptr->balance = 0;
        taller = 1;
    }
    else if (ikey < ptr->info)
    {
        ptr->lchild = insert(ptr->lchild, ikey);
        if (taller == 1)
        {
            ptr = insert_left_check(ptr, &taller);
        }
    }
    else if (ikey > ptr->info)
    {
        ptr->rchild = insert(ptr->rchild, ikey);
        if (taller == 1)
        {
            ptr = insert_right_check(ptr, &taller);
        }
    }
    else
    {
        printf("Duplicate\n");
        taller = 0;
    }
    return ptr;
}

void inorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->lchild);
        printf("%d ", ptr->info);
        inorder(ptr->rchild);
    }
}

void preorder(struct node *ptr){
    if(ptr!=NULL){
        printf("%d ",ptr->info);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}

void postorder(struct node *ptr){
    if(ptr!=NULL){
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("%d ",ptr->info);
    }

}
void freeMemory(struct node *ptr) {
    if (ptr != NULL) {
        freeMemory(ptr->lchild);
        freeMemory(ptr->rchild);
        free(ptr);
    }
}

int main()
{
    struct node *root = NULL;
    int choice, key;

    do
    {
        printf("\n----- AVL Tree Menu -----\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 5:
            freeMemory(root);
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 5);
    
    freeMemory(root);   
    return 0;
}