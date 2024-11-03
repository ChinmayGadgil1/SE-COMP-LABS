// ! BINARY TREE FROM INORDER AND PREORDER

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct listNode
{
    int info;
    struct listNode *link;
} *inptr = NULL, *preptr = NULL, *postptr = NULL;

struct treeNode
{
    struct treeNode *lchild;
    int info;
    struct treeNode *rchild;
};

struct treeNode *stack[MAX];
int top = -1;
void push(struct treeNode *ptr)
{
    if (top == MAX - 1)
    {
        return;
    }
    stack[++top] = ptr;
}
struct treeNode *pop()
{
    if (top == -1)
    {
        return NULL;
    }
    return stack[top--];
}

struct treeNode *queueArr[MAX];
int front = -1, rear = -1;

int isFull()
{
    return rear == MAX - 1;
}

int isEmpty()
{
    return front == -1 || front > rear;
}

void insert(struct treeNode *item)
{
    if (isFull())
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
    {
        front++;
    }

    rear++;
    queueArr[rear] = item;
}

struct treeNode *delete()
{
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        return NULL;
    }
    struct treeNode *item = queueArr[front];
    front++;
    return item;
}

struct listNode *addAtBegin(struct listNode *start, int data)
{
    struct listNode *tmp;
    tmp = (struct listNode *)malloc(sizeof(struct listNode));
    tmp->info = data;
    tmp->link = start;
    start = tmp;
    return start;
}

struct listNode *addAtEnd(struct listNode *start, int data)
{
    struct listNode *tmp;
    tmp = (struct listNode *)malloc(sizeof(struct listNode));
    tmp->info = data;

    struct listNode *p = start;

    while (p->link != NULL)
    {
        p = p->link;
    }

    p->link = tmp;
    tmp->link = NULL;

    return start;
}

struct listNode *createList(struct listNode *start, int n)
{
    int data;
    start = NULL;
    if (n == 0)
    {
        return start;
    }
    printf("\n");
    printf("Enter element: ");
    scanf("%d", &data);
    start = addAtBegin(start, data);
    for (int i = 1; i < n; i++)
    {
        // printf("Enter element: ");
        scanf("%d", &data);
        start = addAtEnd(start, data);
    }

    return start;
}

struct treeNode *constructPreIn(struct listNode *preptr, struct listNode *inptr, int n)
{

    struct treeNode *tmp;
    struct listNode *q;
    int i, j;
    if (n == 0)
        return NULL;
    tmp = (struct treeNode *)malloc(sizeof(struct treeNode));
    tmp->lchild = NULL;
    tmp->info = preptr->info;
    tmp->rchild = NULL;

    if (n == 1)
        return tmp;

    q = inptr;
    for (i = 0; q->info != preptr->info; i++)
        q = q->link;

    tmp->lchild = constructPreIn(preptr->link, inptr, i);

    for (j = 1; j <= i + 1; j++)
        preptr = preptr->link;

    tmp->rchild = constructPreIn(preptr, q->link, n - i - 1);

    return tmp;
}

struct treeNode *constructPostIn(struct listNode *postptr, struct listNode *inptr, int n)
{
    int i, j;
    struct treeNode *tmp;
    struct listNode *q, *p;

    if (n == 0)
        return NULL;
    tmp = (struct treeNode *)malloc(sizeof(struct treeNode));
    tmp->lchild = NULL;
    q = postptr;
    for (i = 1; i < n; i++)
        q = q->link;
    tmp->info = q->info;
    tmp->rchild = NULL;
    if (n == 1)
        return tmp;

    p = inptr;
    for (i = 0; p->info != q->info; i++)
        p = p->link;
    tmp->lchild = constructPostIn(postptr, inptr, i);

    for (j = 1; j <= i; j++)
        postptr = postptr->link;

    tmp->rchild = constructPostIn(postptr, p->link, n - i - 1);
}

void preorder(struct treeNode *root)
{
    struct treeNode *ptr = root;
    if (root == NULL)
        return;
    top = -1;
    push(root);
    while (top != -1)
    {
        ptr = pop();
        printf("%d ", ptr->info);
        if (ptr->rchild)
            push(ptr->rchild);
        if (ptr->lchild)
            push(ptr->lchild);
    }
}
void inorder(struct treeNode *root)
{
    struct treeNode *ptr = root;
    if (ptr == NULL)
        return;
    while (1)
    {
        while (ptr->lchild)
        {
            push(ptr);
            ptr = ptr->lchild;
        }
        while (!ptr->rchild)
        {
            printf("%d ", ptr->info);
            if (top == -1)
                return;
            ptr = pop();
        }
        printf("%d ", ptr->info);
        ptr = ptr->rchild;
    }
}

void postorder(struct treeNode *root)
{
    struct treeNode *ptr = root, *q;
    if (ptr == NULL)
        return;
    q = root;
    while (1)
    {
        while (ptr->lchild)
        {
            push(ptr);
            ptr = ptr->lchild;
        }
        while ((!ptr->rchild) || q == ptr->rchild)
        {
            printf("%d ", ptr->info);
            q = ptr;
            if (top == -1)
                return;
            ptr = pop();
        }
        push(ptr);
        ptr = ptr->rchild;
    }
}

int height(struct treeNode *ptr)
{
     int hL, hR;
    if (ptr == NULL)
        return 0;
    hL = height(ptr->lchild);
    hR = height(ptr->rchild);
    if (hL > hR)
        return 1 + hL;
    else
        return 1 + hR;
}

void levelorder(struct treeNode *root)
{
    struct treeNode *ptr = root;
    if (!ptr)
    {
        return;
    }
    insert(ptr);
    while (!isEmpty())
    {
        ptr = delete ();
        printf("%d ", ptr->info);
        if (ptr->lchild)
        {
            insert(ptr->lchild);
        }
        if (ptr->rchild)
        {
            insert(ptr->rchild);
        }
    }
}

int main()
{

    printf("Enter size of tree: ");
    int n;
    scanf("%d", &n);

    printf("Enter the inorder list: ");
    inptr = createList(inptr, n);
    printf("Enter the preorder list: ");
    preptr = createList(preptr, n);

    struct treeNode *root;
    root = constructPreIn(preptr, inptr, n);

    printf("\nTraversals of constructed tree:\n");
    printf("\nPreorder traversal:\n");
    preorder(root);
    printf("\n");
    printf("\nInorder traversal:\n");
    inorder(root);
    printf("\n");
    printf("\nPostorder traversal:\n");
    postorder(root);
    printf("\n");
    printf("\nLevelorder traversal:\n");
    levelorder(root);
    printf("\n");

    printf("\nHeight of tree: %d\n", height(root));
    printf("\n\n");

    return 0;
}