//! BST

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *lchild;
    int info;
    struct node *rchild;
};

struct node *insert(struct node *ptr, int ikey)
{

    if (ptr == NULL)
    {
        struct node *tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = ikey;
        tmp->lchild = NULL;
        tmp->rchild = NULL;
        return tmp;
    }
    else if (ikey < ptr->info)
    {
        ptr->lchild = insert(ptr->lchild, ikey);
    }
    else if (ikey > ptr->info)
    {
        ptr->rchild = insert(ptr->rchild, ikey);
    }
    else
    {
        printf("\nDuplicates Not Allowed\n");
    }
    return ptr;
}

struct node *delete(struct node *ptr, int dkey)
{
    if (ptr == NULL)
    {
        printf("Dkey not found\n");
        return ptr;
    }
    if (dkey < ptr->info)
    {
        ptr->lchild = delete (ptr->lchild, dkey);
    }
    else if (dkey > ptr->info)
    {
        ptr->rchild = delete (ptr->rchild, dkey);
    }
    else
    {
        if (ptr->lchild != NULL && ptr->rchild != NULL)
        {
            struct node *succ = ptr->rchild;
            while (succ->lchild != NULL)
                succ = succ->lchild;
            ptr->info = succ->info;
            ptr->rchild = delete (ptr->rchild, succ->info);
        }
        else if (ptr->lchild != NULL)
        {
            struct node *tmp = ptr;
            ptr = ptr->lchild;
            free(tmp);
        }
        else if (ptr->rchild != NULL)
        {
            struct node *tmp = ptr;
            ptr = ptr->rchild;
            free(tmp);
        }
        else
        {
            ptr = NULL;
        }
    }
    return ptr;
}

void deleteAlloc(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->lchild == NULL && root->rchild == NULL)
    {
        free(root);
        return;
    }
    deleteAlloc(root->lchild);
    deleteAlloc(root->rchild);
}

void preorder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    printf("%d ", ptr->info);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}
void inorder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    inorder(ptr->lchild);
    printf("%d ", ptr->info);
    inorder(ptr->rchild);
}

void postorder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d ", ptr->info);
}

int height(struct node *ptr)
{
    int lh, rh;
    if (ptr == NULL)
    {
        return 0;
    }
    lh = height(ptr->lchild);
    rh = height(ptr->rchild);
    if (lh > rh)
        return lh + 1;
    return rh + 1;
}

void displayLevelOrder(struct node *ptr, int level)
{
    if (ptr == NULL)
        return;
    if (level == 1)
        printf("%d ", ptr->info);
    else if (level > 1)
    {
        displayLevelOrder(ptr->lchild, level - 1);
        displayLevelOrder(ptr->rchild, level - 1);
    }
}
void levelorder(struct node *ptr)
{
    int h = height(ptr);
    for (int i = 0; i <= h; i++)
    {
        displayLevelOrder(ptr, i);
    }
}

struct node *createBST(struct node *root)
{
    root = NULL;
    int n, data;
    printf("Enter number of nodes:\n");
    scanf("%d", &n);
    if (n == 0)
        return root;

        printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }

    return root;
}

struct node *max(struct node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    while (root->rchild != NULL)
    {
        root = root->rchild;
    }
    return root;
}

struct node *min(struct node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    while (root->lchild != NULL)
    {
        root = root->lchild;
    }
    return root;
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->info == key)
        return root;
    if (key < root->info)
        return search(root->lchild, key);
    else
    {
        return search(root->rchild, key);
    }
}
int main()
{

    int choice;
    struct node *root, *ptr;

        printf("\nMenu:\n");
        printf("1. Create BST\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Max and Min\n");
        printf("5. Search\n");
        printf("6. Exit\n");
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            root = createBST(root);
        }
        else if (choice == 2)
        {
            int data;
            printf("Enter element to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
        }
        else if (choice == 3)
        {
            int data;
            printf("Enter element: ");
            scanf("%d", &data);
            root = delete (root, data);
        }
       
        else if (choice == 4)
        {
            ptr = max(root);
            printf("Max element is: %d\n", ptr->info);
            ptr = min(root);
            printf("Min element is: %d\n", ptr->info);
        }
        else if (choice == 5)
        {
            int key;
            printf("Enter key to search: ");
            scanf("%d", &key);
            ptr = search(root, key);
            if (ptr != NULL)
                printf("Key found\n");
        }
        else if (choice == 6)
        {
            break;
        }
    }

    deleteAlloc(root);
    return 0;
}