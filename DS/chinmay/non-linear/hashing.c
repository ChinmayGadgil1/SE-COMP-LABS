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

void insert(struct Employee emp,struct Record table[]){
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
    }
}

int main(){



return 0;
}