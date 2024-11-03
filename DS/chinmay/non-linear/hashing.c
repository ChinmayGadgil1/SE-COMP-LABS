#include <stdio.h>
#include<stdlib.h>
#define MAX 17

enum type_of_record
{
    EMPTY,
    DELETED,
    OCCUPIED
};

struct Record
{
    int info;
    enum type_of_record status;
};

struct chainNode{
    int info;
    struct chainNode*link;
};

int hash(int key)
{
    return key % MAX;
}

void insertLinear(int ikey, struct Record table[])
{
    int i, loc, h;
    h = hash(ikey);
    loc = h;
    for (i = 1; i != MAX - 1; i++)
    {
        if (table[loc].status == EMPTY || table[loc].status == DELETED)
        {
            table[loc].info = ikey;
            table[loc].status = OCCUPIED;
            return;
        }
        if (table[loc].info == ikey)
        {
            printf("Duplicate key\n");
            return;
        }
        loc = (h + i) % MAX;
    }
}

int searchLinear(int key, struct Record table[])
{
    int i, loc, h;
    h = hash(key);
    loc = h;
    for (i = 1; i != MAX - 1; i++)
    {
        if (table[loc].status == EMPTY)
        {
            return -1;
        }
        if (table[loc].status == OCCUPIED && table[loc].info == key)
        {
            return loc;
        }
        loc = (h + i) % MAX;
    }
    return -1;
}
int searchQuadratic(int key, struct Record table[])
{
    int i, loc, h;
    h = hash(key);
    loc = h;
    for (i = 1; i != MAX - 1; i++)
    {
        if (table[loc].status == EMPTY)
        {
            return -1;
        }
        if (table[loc].status == OCCUPIED && table[loc].info == key)
        {
            return loc;
        }
        loc = (h + i*i) % MAX;
    }
    return -1;
}
int searchDouble(int key, struct Record table[])
{
    int i, loc, h;
    h = hash(key);
    int h2=hash2(key);
    loc = h;
    for (i = 1; i != MAX - 1; i++)
    {
        if (table[loc].status == EMPTY)
        {
            return -1;
        }
        if (table[loc].status == OCCUPIED && table[loc].info == key)
        {
            return loc;
        }
        loc = (h + i*h2) % MAX;
    }
    return -1;
}

void insertQuadratic(int ikey, struct Record table[])
{
    int i, loc, h;
    h = hash(ikey);
    loc = h;
    for (i = 1; i != MAX - 1; i++)
    {
        if (table[loc].status == EMPTY || table[loc].status == DELETED)
        {
            table[loc].info = ikey;
            table[loc].status = OCCUPIED;
            return;
        }
        if (table[loc].info == ikey)
        {
            printf("Duplicate key\n");
            return;
        }
        loc = (h + i * i) % MAX;
    }
}

int hash2(int key)
{
    int n;
    n = 7 + (key % 7);
    // printf("\n hash value of key%d-> %d", key, n);
    return n;
}

void insertDoubleHash(int ikey, struct Record table[])
{
    int i, loc, h, h2;
    h = hash(ikey);
    h2 = hash2(ikey);
    loc = h;
    for (i = 1; i != MAX - 1; i++)
    {
        if (table[loc].status == EMPTY || table[loc].status == DELETED)
        {
            table[loc].info = ikey;
            table[loc].status = OCCUPIED;
            return;
        }
        if (table[loc].info == ikey)
        {
            printf("Duplicate key\n");
            return;
        }
        loc = (h + i * h2) % MAX;
        
    }
}

void deleteLinear(int key, struct Record table[])
{
    int loc = searchLinear(key, table);
    if (loc == -1)
    {
        printf("Record not found\n");
        return;
    }
    table[loc].status = DELETED;
    printf("Record deleted\n");
}
void deleteQuadratic(int key, struct Record table[])
{
    int loc = searchQuadratic(key, table);
    if (loc == -1)
    {
        printf("Record not found\n");
        return;
    }
    table[loc].status = DELETED;
    printf("Record deleted\n");
}
void deleteDouble(int key, struct Record table[])
{
    int loc = searchDouble(key, table);
    if (loc == -1)
    {
        printf("Record not found\n");
        return;
    }
    table[loc].status = DELETED;
    printf("Record deleted\n");
}

void display(struct Record table[])
{
    for (int i = 0; i < MAX; i++)
    {
        printf("     ------\n");
        printf("[%2d] ", i);
        if (table[i].status == OCCUPIED)
        {
            printf("|%4d|\n", table[i].info);
        }
        else if (table[i].status == DELETED)
        {
            printf("|DELD|\n");
        }
        else
        {
            printf("|EMPT|\n");
        }
        printf("     ------\n");
    }
}



int searchChained(int key,struct chainNode* table[] ){
    int h=hash(key);
    struct chainNode* ptr=table[h];
    while (ptr)
    {
        if (ptr->info==key)
        {
            return h;
        }
        ptr=ptr->link;
        
    }
    return -1;
    
}

void insertChained(int key, struct chainNode* table[]){
    int h;
    struct chainNode* tmp;
    if (searchChained(key,table)!=-1)
    {
        printf("Duplicate key");
        return;
    }
    h=hash(key);
    tmp=(struct chainNode*)malloc(sizeof(struct chainNode));
    tmp->info=key;
    tmp->link=table[h];
    table[h]=tmp;
}

void deleteChained(int key,struct chainNode* table[]){
    int h=hash(key);
    struct chainNode* tmp;
    if (table[h]==NULL)
    {
        printf("Key not found\n");
        return;
    }
    if(table[h]->info==key){
        tmp=table[h];
        table[h]=table[h]->link;
        free(tmp);
        return;
    }
    struct chainNode* ptr=table[h];
    while (ptr->link)
    {
        if (ptr->link->info==key)
        {
            tmp=ptr->link;
            ptr->link=tmp->link;
            free(tmp);
            return;
        }
        ptr=ptr->link;
    }
    printf("Key not found\n");
}

void displayChained(struct chainNode* table[]){
    for (int i = 0; i < MAX; i++)
    {
        if(table[i]==NULL){
            printf("    --------\n");
            printf("[%2d]| NULL |\n",i);
            printf("    --------\n");
            continue;
        }
        struct chainNode* ptr=table[i];
        printf("    ------------\n");
        printf("[%2d]| %8p |--> ",i,table[i]);
        while (ptr)
        {
            printf("%d ",ptr->info);
        ptr=ptr->link;
        }
        
        printf("\n    ------------\n");
    }
    
}

int main()
{

    int n;
    printf("Enter number of keys to insert: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter %d keys:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    struct Record tableLinear[MAX];
    struct Record tableQuadratic[MAX];
    struct Record tableDoubleHash[MAX];
    struct chainNode* tableChaining[MAX];
    for (int i = 0; i < MAX; i++)
    {
        tableLinear[i].status = EMPTY;
        tableQuadratic[i].status = EMPTY;
        tableDoubleHash[i].status = EMPTY;
        tableChaining[i]=NULL;
    }

    int choice;
    while (1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        int key, loc;

        switch (choice)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                insertLinear(arr[i], tableLinear);
                insertQuadratic(arr[i], tableQuadratic);
                insertDoubleHash(arr[i], tableDoubleHash);
                insertChained(arr[i],tableChaining);
            }
            break;
        case 2:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            deleteLinear(key, tableLinear);
            deleteQuadratic(key, tableQuadratic);
            deleteDouble(key, tableDoubleHash);
            deleteChained(key,tableChaining);
            break;
        case 3:
            printf("Enter key to search: ");
            scanf("%d", &key);
            loc = searchLinear(key, tableLinear);
            if (loc != -1)
                printf("Key found in Linear Probing at index %d\n", loc);
            else
                printf("Key not found in Linear Probing\n");

            loc = searchQuadratic(key, tableQuadratic);
            if (loc != -1)
                printf("Key found in Quadratic Probing at index %d\n", loc);
            else
                printf("Key not found in Quadratic Probing\n");

            loc = searchDouble(key, tableDoubleHash);
            if (loc != -1)
                printf("Key found in Double Hashing at index %d\n", loc);
            else
                printf("Key not found in Double Hashing\n");
            loc = searchChained(key, tableChaining);
            if (loc != -1)
                printf("Key found in separate chaining at index %d\n", loc);
            else
                printf("Key not found in Separate chaining\n");
            break;
        case 4:
            printf("Linear Probing:\n");
            display(tableLinear);
            printf("Quadratic Probing:\n");
            display(tableQuadratic);
            printf("Double Hashing:\n");
            display(tableDoubleHash);
            printf("Separate Chaining\n");
            displayChained(tableChaining);
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}