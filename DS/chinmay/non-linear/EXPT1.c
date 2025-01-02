// !BINARY TREE CONSTRUCTION FROM INORDER AND POSTORDER TRAVERSALS

#include<stdio.h>
#include<stdlib.h>

struct listNode {
    int info;
    struct listNode *link;
} *inptr = NULL, *postptr = NULL;

struct treeNode {
    struct treeNode *lchild;
    int info;
    struct treeNode *rchild;
};

struct listNode* addAtBegin(struct listNode* start, int data) {
    struct listNode* tmp;
    tmp = (struct listNode*)malloc(sizeof(struct listNode));
    tmp->info = data;
    tmp->link = start;
    start = tmp;
    return start;
}

struct listNode* addAtEnd(struct listNode* start, int data) {
    struct listNode* tmp;
    tmp = (struct listNode*)malloc(sizeof(struct listNode));
    tmp->info = data;

    if (start == NULL) {
        tmp->link = NULL;
        return tmp;
    }

    struct listNode* p = start;
    while (p->link != NULL) {
        p = p->link;
    }

    p->link = tmp;
    tmp->link = NULL;

    return start;
}

struct listNode* createList(struct listNode* start, int n) {
    int data;
    start = NULL;
    if (n == 0) {
        return start;
    }
    printf("\n");
    printf("Enter element: ");
    scanf("%d", &data);
    start = addAtBegin(start, data);
    for (int i = 1; i < n; i++) {
        // printf("Enter element: ");
        scanf("%d", &data);
        start = addAtEnd(start, data);
    }

    return start; 
}

struct treeNode* constructPostIn(struct listNode *postptr, struct listNode *inptr, int n) {
    int i, j;
    struct treeNode *tmp;
    struct listNode *q, *p;

    if (n == 0)
        return NULL;
    tmp = (struct treeNode*)malloc(sizeof(struct treeNode));
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

    return tmp; 
}

void construct(struct listNode* inptr, struct listNode* postptr, int n){
    
}

void preorder(struct treeNode *ptr) {
    if (ptr == NULL)
        return;
    printf("%d ", ptr->info);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}

void inorder(struct treeNode *ptr) {
    if (ptr == NULL)
        return;
    inorder(ptr->lchild);
    printf("%d ", ptr->info);
    inorder(ptr->rchild);
}

void postorder(struct treeNode *ptr) {
    if (ptr == NULL)
        return;
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d ", ptr->info);
}


void displayLevelOrder(struct treeNode *ptr, int level)
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

void levelorder(struct treeNode *ptr)
{
    int h = height(ptr);
    for (int i = 0; i <= h; i++)
    {
        displayLevelOrder(ptr, i);
    }
}


int height(struct treeNode *ptr) {
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

int main() {
    printf("Enter size of tree: ");
    int n;
    scanf("%d", &n);

    printf("Enter the inorder list: ");
    inptr = createList(inptr, n);
    printf("Enter the postorder list: ");
    postptr = createList(postptr, n);

    struct treeNode *root;
    root = constructPostIn(postptr, inptr, n);

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