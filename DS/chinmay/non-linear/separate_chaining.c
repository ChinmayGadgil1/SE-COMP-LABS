# include<stdio.h>
#define MAX 17

struct Record{
    int info;
    struct Record* link;
};

int hash(int key){
    return key%MAX;
}

int search(int ikey, struct Record* table[]){
    int h = hash(ikey);
    struct Record* ptr = table[h];
    while(ptr != NULL){
        if(ptr->info == ikey){
            return h;
        }
        ptr = ptr->link;
    }
    return -1;
}

void insert(int ikey, struct Record* table[]){
    int h,key;
    struct Record* temp;
    key = ikey;
    if(search(key,table) != -1){
        printf("Duplicate key\n");
        return;
    }
    h = hash(key);
    temp = (struct Record*)malloc(sizeof(struct Record));
    temp->info = key;
    temp->link = table[h];
    table[h] = temp;
}

void delete(int key,struct Record* table[]){
    int h;
    struct Record* ptr,*temp;
    h = hash(key);
    if(table[h] == NULL){
        printf("Key not present\n");
        return;
    }
    if(table[h]->info == key){
        temp = table[h];
        table[h] = table[h]->link;
        free(temp);
        return;
    }
    ptr = table[h];
    while(ptr->link != NULL){
        if(ptr->link->info == key){
            temp = ptr->link;
            ptr->link = temp->link;
            free(temp);
            return;
        }
        ptr = ptr->link;
    }
    printf("Key not present\n");
}

void display(struct Record* table[]){
    int i;
    struct Record* ptr;
    for(i=0;i<MAX;i++){
        printf("\n[%d]-->",i);
        if(table[i] != NULL){
            ptr = table[i];
            while(ptr != NULL){
                printf("%d-->",ptr->info);
                ptr = ptr->link;
            }
        }
    }
}

int main(){

    struct Record* table[MAX] = {NULL};
    int choice, key;

    while(1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key, table);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(key, table);
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int result = search(key, table);
                if(result != -1) {
                    printf("Key found at index %d\n", result);
                } else {
                    printf("Key not found\n");
                }
                break;
            case 4:
                display(table);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    for(int i = 0; i < MAX; i++) {
        struct Record* ptr = table[i];
        while(ptr != NULL) {
            struct Record* temp = ptr;
            ptr = ptr->link;
            free(temp);
        }
    }


return 0;
}