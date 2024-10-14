# include<stdio.h>
#define MAX 7

enum type_of_record{
    EMPTY,
    DELETED,
    OCCUPIED
};

struct Employee{
    int empid;
    char name[20];
    int age;
};

struct Record{
    struct Employee info;
    enum type_of_record status;
};

int hash(int key){
    return key%MAX;
}

void insertLinear(struct Employee emp,struct Record table[]){
    int i,loc,h;
    int key=emp.empid;
    h=hash(key);
    loc=h;
    for(i=1;i!=MAX-1;i++){
        if(table[loc].status==EMPTY || table[loc].status==DELETED){
            table[loc].info=emp;
            table[loc].status=OCCUPIED;
            return;
        }
        if(table[loc].info.empid==key){
            printf("Duplicate key\n");
            return;
        }
        loc=(h+i)%MAX;
    }
}

int search(int key,struct Record table[]){
    int i,loc,h;
    h=hash(key);
    loc=h;
    for(i=1;i!=MAX-1;i++){
        if(table[loc].status==EMPTY){
            return -1;
        }
        if(table[loc].status==OCCUPIED && table[loc].info.empid==key){
            return loc;
        }
        loc=(h+i)%MAX;
    }
    return -1;
}

void insertQuadratic(struct Employee emp,struct Record table[]){
    int i,loc,h;
    int key=emp.empid;
    h=hash(key);
    loc=h;
    for(i=1;i!=MAX-1;i++){
        if(table[loc].status==EMPTY || table[loc].status==DELETED){
            table[loc].info=emp;
            table[loc].status=OCCUPIED;
            return;
        }
        if(table[loc].info.empid==key){
            printf("Duplicate key\n");
            return;
        }
        loc=(h+i*i)%MAX;
    }
}

int hash2(int key){
    return 7-(key%7);
}

void insertDoubleHash(struct Employee emp,struct Record table[]){
    int i,loc,h,h2;
    int key=emp.empid;
    h=hash(key);
    h2=hash2(key);
    loc=h;
    for(i=1;i!=MAX-1;i++){
        if(table[loc].status==EMPTY || table[loc].status==DELETED){
            table[loc].info=emp;
            table[loc].status=OCCUPIED;
            return;
        }
        if(table[loc].info.empid==key){
            printf("Duplicate key\n");
            return;
        }
        loc=(h+i*h2)%MAX;
    }
}

void delete(int key,struct Record table[]){
    int loc=search(key,table);
    if(loc==-1){
        printf("Record not found\n");
        return;
    }
    table[loc].status=DELETED;
    printf("Record deleted\n");
}

void display(struct Record table[]){
    for(int i=0;i!=MAX;i++){
        printf("Record: %d\n",i);
        if(table[i].status==OCCUPIED){
            printf("Location: %d\n",i);
            printf("Employee ID: %d\n",table[i].info.empid);
            printf("Name: %s\n",table[i].info.name);
            printf("Age: %d\n",table[i].info.age);
        }
        else if(table[i].status==DELETED){
            printf("Record deleted\n");
        }
        else{
            printf("Empty record\n");
        }
    }
}

int main(){
    struct Record table[MAX];
    for (int i = 0; i < MAX; i++) {
        table[i].status = EMPTY;
    }

    int choice, key, hashType;
    struct Employee emp;

    printf("Choose type of hashing:\n");
    printf("1. Linear Probing\n");
    printf("2. Quadratic Probing\n");
    printf("3. Double Hashing\n");
    printf("Enter your choice: ");
    scanf("%d", &hashType);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Employee ID: ");
                scanf("%d", &emp.empid);
                printf("Enter Name: ");
                scanf("%s", emp.name);
                printf("Enter Age: ");
                scanf("%d", &emp.age);
                if (hashType == 1) {
                    insertLinear(emp, table);
                } else if (hashType == 2) {
                    insertQuadratic(emp, table);
                } else if (hashType == 3) {
                    insertDoubleHash(emp, table);
                } else {
                    printf("Invalid hash type\n");
                }
                break;
            case 2:
                printf("Enter Employee ID to search: ");
                scanf("%d", &key);
                int loc = search(key, table);
                if (loc == -1) {
                    printf("Record not found\n");
                } else {
                    printf("Record found at location %d\n", loc);
                }
                break;
            case 3:
                printf("Enter Employee ID to delete: ");
                scanf("%d", &key);
                delete(key, table);
                break;
            case 4:
                display(table);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }


return 0;
}