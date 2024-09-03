#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    struct node *left;
    bool lthread;
    int info;
    bool rthread;
    struct node *right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->lthread = true;
    newNode->rthread = true;
    return newNode;
}

struct node* Insert(struct node* root, int ikey) {
    struct node *par = NULL, *ptr = root, *tmp;
    int found = 0;
    while (ptr != NULL) {
        if (ptr->info == ikey) {
            found = 1;
            break;
        }
        par = ptr;
        if (ikey < ptr->info) {
            if (!ptr->lthread) {
                ptr = ptr->left;
            } else {
                break;
            }
        } else if (ikey > ptr->info) {
            if (!ptr->rthread) {
                ptr = ptr->right;
            } else {
                break;
            }
        }
    }
    if (found) {
        printf("Duplicate key\n");
        return root;
    } else {
        tmp = createNode(ikey);
        if (par == NULL) {
            root = tmp;
            tmp->left = tmp->right = NULL;
        } else if (ikey < par->info) {
            tmp->left = par->left;
            tmp->right = par;
            par->lthread = false;
            par->left = tmp;
        } else {
            tmp->right = par->right;
            tmp->left = par;
            par->rthread = false;
            par->right = tmp;
        }
    }
    return root;
}

struct node* create(struct node *root) {
    int n;
    printf("Enter the number of nodes you want to insert: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &data);
        root = Insert(root, data);
    }
    return root;
}

int main() {
    struct node* root = NULL;
    root = create(root);
    // Add code to display or further manipulate the tree if needed
    return 0;
}