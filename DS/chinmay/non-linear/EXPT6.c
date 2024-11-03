#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

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
        printf("P%d: CASE L_C1\n",pptr->info);
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
        printf("P%d: CASE L_C2A\n",pptr->info);
            pptr->balance = 0;
            aptr->balance = 1;
            break;
        case 1:
        printf("P%d: CASE L_C2B\n",pptr->info);
            pptr->balance = -1;
            aptr->balance = 0;
            break;
        case 0:
        printf("P%d: CASE L_C2C\n",pptr->info);
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
        printf("P%d: CASE L_A\n",pptr->info);
        pptr->balance = 1;
        break;
    case -1:
        printf("P%d: CASE L_B\n",pptr->info);
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
        printf("P%d: CASE R_C1\n",pptr->info);

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
            printf("P%d: CASE R_C2A\n",pptr->info);
            pptr->balance = 1;
            aptr->balance = 0;
            break;
        case 1:
            printf("P%d: CASE R_C2B\n",pptr->info);
            pptr->balance = 0;
            aptr->balance = -1;
            break;
        case 0:
            printf("P%d: CASE R_C2C\n",pptr->info);
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
    return pptr;  
}

struct node *insert_right_check(struct node *pptr, int *taller)
{
    switch (pptr->balance)
    {
    case 0:
            printf("P%d: CASE R_A\n",pptr->info);
        pptr->balance = -1;
        break;
    case 1:
            printf("P%d: CASE R_B\n",pptr->info);
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

struct node *del_LeftBalance(struct node *pptr, int *pshorter) {
    struct node *aptr, *bptr;
    aptr = pptr->lchild;

    if (aptr->balance == 0) { /* Case R_C1 */
        printf("P%d: CASE R_C1\n", pptr->info);
        pptr->balance = 1;
        aptr->balance = -1;
        *pshorter = false;
        pptr = rightrotate(pptr);
    } else if (aptr->balance == 1) { /* Case R_C2 */
        printf("P%d: CASE R_C2\n", pptr->info);
        pptr->balance = 0;
        aptr->balance = 0;
        pptr = rightrotate(pptr);
    } else { /* Case R_C3 */
        printf("P%d: CASE R_C3\n", pptr->info);
        bptr = aptr->rchild;

        switch (bptr->balance) {
            case 0: /* Case R_C3a */
                printf("P%d: CASE R_C3a\n", pptr->info);
                pptr->balance = 0;
                aptr->balance = 0;
                break;
            case 1: /* Case R_C3b */
                printf("P%d: CASE R_C3b\n", pptr->info);
                pptr->balance = -1;
                aptr->balance = 0;
                break;
            case -1: /* Case R_C3c */
                printf("P%d: CASE R_C3c\n", pptr->info);
                pptr->balance = 0;
                aptr->balance = 1;
                break;
        }
        bptr->balance = 0;
        pptr->lchild = leftrotate(aptr);
        pptr = rightrotate(pptr);
    }
    return pptr;
} 


struct node *RightBalance(struct node *pptr, int *pshorter) {
    struct node *aptr, *bptr;
    aptr = pptr->rchild;

    if (aptr->balance == 0) { /* Case L_C1 */
        printf("P%d: CASE L_C1\n", pptr->info);
        pptr->balance = -1;
        aptr->balance = 1;
        *pshorter =false;
        pptr = leftrotate(pptr);
    } else if (aptr->balance == -1) { /* Case L_C2 */
        printf("P%d: CASE L_C2\n", pptr->info);
        pptr->balance = 0;
        aptr->balance = 0;
        pptr = leftrotate(pptr);
    } else { /* Case L_C3 */
        printf("P%d: CASE L_C3\n", pptr->info);
        bptr = aptr->lchild;

        switch (bptr->balance) {
            case 0: /* Case L_C3a */
                printf("P%d: CASE L_C3a\n", pptr->info);
                pptr->balance = 0;
                aptr->balance = 0;
                break;
            case -1: /* Case L_C3b */
                printf("P%d: CASE L_C3b\n", pptr->info);
                pptr->balance = 1;
                aptr->balance = 0;
                break;
            case 1: /* Case L_C3c */
                printf("P%d: CASE L_C3c\n", pptr->info);
                pptr->balance = 0;
                aptr->balance = -1;
                break;
        }
        bptr->balance = 0;
        pptr->rchild = rightrotate(aptr);
        pptr = leftrotate(pptr);
    }
    return pptr;
} /* End of RightBalance() */

struct node *del_right_check(struct node *pptr, int *pshorter) {
    switch (pptr->balance) {
        case 0: /* Case R_A : was balanced */
            printf("P%d: CASE R_A\n", pptr->info);
            pptr->balance = 1;
            *pshorter = false; /* now left heavy */
            break;
        case -1: /* Case R_B : was right heavy */
            printf("P%d: CASE R_B\n", pptr->info);
            pptr->balance = 0; /* now balanced */
            break;
    }
    return pptr;
} 

struct node *del_left_check(struct node *pptr, int *pshorter) {
    switch (pptr->balance) {
        case 0: /* Case L_A : was balanced */
            printf("P%d: CASE L_A\n", pptr->info);
            pptr->balance = -1;
            *pshorter = false; /* now right heavy */
            break;
        case 1: /* Case L_B : was left heavy */
            printf("P%d: CASE L_B\n", pptr->info);
            pptr->balance = 0; /* now balanced */
            break;
    }
    return pptr;
} /* End of del_left_check() */



struct node *delete (struct node *root, int dkey)
{
    static int shorter;
    struct node *tmp;
    if (root == NULL)
    {
        printf("Key not present\n");
        return root;
    }
    if (dkey < root->info)
    {
        root->lchild = delete (root->lchild, dkey);
        if (shorter == 1)
        {
            root = del_left_check(root, &shorter);
        }
    }
    else if (dkey > root->info)
    {
        root->rchild = delete (root->rchild, dkey);
        if (shorter == 1)
        {
            root = del_right_check(root, &shorter);
        }
    }
    else
    {
        if (root->lchild != NULL && root->rchild != NULL)
        {
            tmp = root->rchild;
            while (tmp->lchild != NULL)
            {
                tmp = tmp->lchild;
            }
            root->info = tmp->info;
            root->rchild = delete (root->rchild, tmp->info);
            if (shorter == 1)
            {
                root = del_right_check(root, &shorter);
            }
        }
        else
        {
            tmp = root;
            if (root->lchild != NULL)
            {
                root = root->lchild;
            }
            else if (root->rchild != NULL)
            {
                root = root->rchild;
            }
            else
            {
                root = NULL;
            }
            free(tmp);
            shorter = 1;
        }
    }
    return root;
}

void preorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        printf("%d ", ptr->info);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}

void postorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("%d ", ptr->info);
    }
}

void freeMemory(struct node *ptr)
{
    if (ptr != NULL)
    {
        freeMemory(ptr->lchild);
        freeMemory(ptr->rchild);
        free(ptr);
    }
}

int main()
{
    struct node *root = NULL;
    int choice, key;

        printf("\n----- AVL Tree Menu -----\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Delete\n");
        printf("6. Exit\n");
    do
    {
        printf("\nEnter your choice: ");
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
            printf("Enter the key to delete: ");
            scanf("%d", &key);
            root = delete(root, key);
            break;
        case 6:
            freeMemory(root);
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 6);

    freeMemory(root);
    return 0;
}
