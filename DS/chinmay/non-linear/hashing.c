#include <stdio.h>
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
        loc = (h + i) % MAX;
    }
    return -1;
}
int searchDouble(int key, struct Record table[])
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
    return 7 + (key % 7);
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
        printf("Record: %d =>", i);
        if (table[i].status == OCCUPIED)
        {
            printf("Key: %d\n", table[i].info);
        }
        else if (table[i].status == DELETED)
        {
            printf("Record deleted\n");
        }
        else
        {
            printf("Empty record\n");
        }
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
    for (int i = 0; i < MAX; i++)
    {
        tableLinear[i].status = EMPTY;
        tableQuadratic[i].status = EMPTY;
        tableDoubleHash[i].status = EMPTY;
    }

    int choice;
    while(1){
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
                for(int i=0;i<n;i++){
                    insertLinear(arr[i], tableLinear);
                    insertQuadratic(arr[i], tableQuadratic);
                    insertDoubleHash(arr[i], tableDoubleHash);
                }
            break;
            case 2:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            deleteLinear(key, tableLinear);
            deleteQuadratic(key, tableQuadratic);
            deleteDouble(key, tableDoubleHash);
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
            break;
            case 4:
            printf("Linear Probing:\n");
            display(tableLinear);
            printf("Quadratic Probing:\n");
            display(tableQuadratic);
            printf("Double Hashing:\n");
            display(tableDoubleHash);
            break;
            case 5:
            return 0;
            default:
            printf("Invalid choice\n");
        }
    }
  
    return 0;
}