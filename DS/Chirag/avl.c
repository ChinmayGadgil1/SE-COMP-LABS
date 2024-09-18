#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 struct node{
    int info;
    struct node *left;
    struct node *right;
    int balance;
 };

struct node *insert_left_check(struct node *pptr, int *ptaller){
    switch(pptr->balance){
        case 0:
            pptr->balance = 1;
            *ptaller = true;
            break;
        case -1:
            pptr->balance = 0;
            *ptaller = false;
            break;
        case 1:
            pptr = insert_left_balance(pptr);
            *ptaller = false;
            break;
    }
    return pptr;
}

struct node *insert_left_balance(struct node *pptr){
    struct node *aptr, *bptr;
    aptr = pptr->left;
    if(aptr->balance == 1){
        pptr->balance = 0;
        aptr->balance = 0;
        pptr = rotate_right(pptr);
    }
    else{
        bptr = aptr->right;
        switch(bptr->balance){
            case -1:
                pptr->balance = 0;
                aptr->balance = 1;
                break;
            case 0:
                pptr->balance = 0;
                aptr->balance = 0;
                break;
            case 1:
                pptr->balance = -1;
                aptr->balance = 0;
        }
        bptr->balance = 0;
        pptr->left = rotate_left(aptr);
        pptr = rotate_right(pptr);
    }
    return pptr;
}

struct node* rotate_right(struct node *pptr){
    struct node *aptr;
    aptr = pptr->left;
    pptr->left = aptr->right;
    aptr->right = pptr;
    return aptr;
}

struct node * rotate_left(struct node *pptr){
    struct node *aptr;
    aptr = pptr->right;
    pptr->right = aptr->left;
    aptr->left = pptr;
    return aptr;
struct node *insert_right_check(struct node *pptr, int *ptaller){
    switch(pptr->balance){
        case 0:
            pptr->balance = -1;
            *ptaller = true;
            break;
        case 1:
            pptr->balance = 0;
            *ptaller = false;
            break;
        case -1:
            pptr = insert_right_balance(pptr);
            *ptaller = false;
            break;
    }
    return pptr;
}   }
    return pptr;
}

struct node *insert_right_balance(struct node *pptr){
    struct node *aptr, *bptr;
    aptr = pptr->right;
    if(aptr->balance == -1){
        pptr->balance = 0;
        aptr->balance = 0;
        pptr = rotate_left(pptr);
    }
    else{
        bptr = aptr->left;
        switch(bptr->balance){
            case -1:
                pptr->balance = 1;
                aptr->balance = 0;
                break;
            case 0:
                pptr->balance = 0;
                aptr->balance = 0;
                break;
            case 1:
                pptr->balance = 0;
                aptr->balance = -1;
        }
        bptr->balance = 0;
        pptr->right = rotate_right(aptr);
        pptr = rotate_left(pptr);
    }
    return pptr;
}

void inorder(struct node *pptr){
    if(pptr != NULL){
        inorder(pptr->left);
        printf("%d(%d) ", pptr->info, pptr->balance);
struct node *insert(struct node *pptr, int key){
    int taller;
    if(pptr == NULL){
        pptr = (struct node *)malloc(sizeof(struct node));
        pptr->info = key;
        pptr->left = NULL;
        pptr->right = NULL;
        pptr->balance = 0;
        taller = true;
    }
    else if(key < pptr->info){
        pptr->left = insert(pptr->left, key);
        if(taller==true)
            pptr = insert_left_check(pptr, &taller);
    }
    else if(key > pptr->info){
        pptr->right = insert(pptr->right, key);
        if(taller==true)
            pptr = insert_right_check(pptr, &taller);
    }
    else{
        printf("Duplicate key\n");
        taller = false;
    }
    return pptr;
}       printf("Duplicate key\n");
        taller = false;
    }
    return pptr;
}

struct node *delete_left_balance(struct node *pptr, int *pshorter){
    struct node *aptr, *bptr;
    aptr = pptr->left;
    if(aptr->balance == 1){
        pptr->balance = 0;
        aptr->balance = 0;
        pptr = rotate_right(pptr);
        *pshorter = false;
    }
    else{
        bptr = aptr->right;
        switch(bptr->balance){
            case -1:
                pptr->balance = 0;
                aptr->balance = 1;
                break;
            case 0:
                pptr->balance = 0;
                aptr->balance = 0;
                break;
            case 1:
                pptr->balance = -1;
                aptr->balance = 0;
        }
        bptr->balance = 0;
        pptr->left = rotate_left(aptr);
        pptr = rotate_right(pptr);
    }
    return pptr;
}

struct node *delete_left_check(struct node *pptr, int *pshorter){
    switch(pptr->balance){
        case 0:
            pptr->balance = 1;
            *pshorter = false;
            break;
        case -1:
            pptr->balance = 0;
            break;
        case 1:
            pptr = delete_left_balance(pptr, pshorter);
    }
    return pptr;
}

struct node *delete_right_balance(struct node *pptr, int *pshorter){
    struct node *aptr, *bptr;
    aptr = pptr->right;
    if(aptr->balance == -1){
        pptr->balance = 0;
        aptr->balance = 0;
        pptr = rotate_left(pptr);
        *pshorter = false;
    }
    else{
        bptr = aptr->left;
        switch(bptr->balance){
            case -1:
                pptr->balance = 1;
                aptr->balance = 0;
                break;
            case 0:
                pptr->balance = 0;
                aptr->balance = 0;
                break;
            case 1:
                pptr->balance = 0;
                aptr->balance = -1;
        }
        bptr->balance = 0;
        pptr->right = rotate_right(aptr);
        pptr = rotate_left(pptr);
    }
    return pptr;
}
struct node *delete_right_check(struct node *pptr, int *pshorter){
    switch(pptr->balance){
        case 0:
            pptr->balance = -1;
            *pshorter = false;
            break;
        case 1:
            pptr->balance = 0;
            break;
        case -1:
            pptr = delete_right_balance(pptr, pshorter);
    }
struct node *delete(struct node *pptr, int key){
    struct node *tmp, *succ;
    int shorter;
    if(pptr == NULL){
        printf("Key not present\n");
        shorter = false;
        return pptr;
    }
    else if(key < pptr->info){
        pptr->left = delete(pptr->left, key);
        if(shorter==true){
            pptr = delete_left_check(pptr, &shorter);
        }
    }
    else if(key > pptr->info){
        pptr->right = delete(pptr->right, key);
        if(shorter==true){
            pptr = delete_right_check(pptr, &shorter);
        }
    }
    else{
        if(pptr->left != NULL && pptr->right != NULL){
            succ = pptr->right;
            while(succ->left != NULL)
                succ = succ->left;
            pptr->info = succ->info;
            pptr->right = delete(pptr->right, pptr->info);
            if(shorter==true){
                pptr = delete_right_check(pptr, &shorter);
            }
        }
        else{
            tmp = pptr;
            if(pptr->left != NULL)
                pptr = pptr->left;
            else if(pptr->right != NULL)
                pptr = pptr->right;
            else
                pptr = NULL;
            free(tmp);
            shorter = true;
        }
    }
    return pptr;
}           shorter = true;
        }
    }
    return pptr;
}

int main(){
int ch,key;
struct node *root = NULL;

while(1){
    printf("\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Inorder Traversal\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch(ch)
    {
        case 1: 
            printf("Enter the key to be inserted: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("Enter the key to be deleted: ");
            scanf("%d", &key);
            root = delete(root, key);
            break;
        case 3:   
            inorder(root);
            break;
        case 4:
            exit(1);
        default:
            printf("Invalid choice\n"); 
    }
}
}