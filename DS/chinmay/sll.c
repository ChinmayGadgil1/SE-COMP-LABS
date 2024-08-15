# include<stdio.h>

struct node{
    int info;
    struct node* link;
};

struct node* addEmpty(struct node* start,int data){
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = tmp;
    start = tmp;
    return start;
}

struct node* addBegin(struct node* start,int data){
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    struct node* ptr = start;
    tmp->info = data;
    while(ptr->link!=start){
        ptr = ptr->link;
    }
    tmp->link = start;
    ptr->link = tmp;
    start = tmp;
    return start;
}

struct node* addEnd(struct node* start,int data){
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    struct node* ptr = start;
    tmp->info = data;
    while(ptr->link!=start){
        ptr = ptr->link;
    }
    tmp->link = start;
    ptr->link = tmp;
    return start;
}

struct node* addAfter(struct node* start,int data,int item){
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    struct node* ptr = start;
    while(ptr->link!=start){
        if(ptr->info==item){
            tmp->info = data;
            tmp->link = ptr->link;
            ptr->link = tmp;
            return start;
        }
        ptr = ptr->link;
    }
    printf("Element not found\n");
    return start;
}

struct node* del(struct node* start,int data){
    struct node* tmp = start;
    struct node* ptr = start;
    while(ptr->link!=start){
        if(ptr->link->info==data){
            tmp = ptr->link;
            ptr->link = tmp->link;
            free(tmp);
            return start;
        }
        ptr = ptr->link;
    }
    if(ptr->link->info==data){
        tmp = ptr->link;
        ptr->link = start;
        free(tmp);
        return start;
    }
    printf("Element not found\n");
    return start;
}

void display(struct node* start){
    struct node* ptr = start;
    do{
        printf("%d ",ptr->info);
        ptr = ptr->link;
    }while(ptr!=start);
    printf("\n");
}

struct node* reverse(struct node* start){
    struct node* prev = NULL;
    struct node* current = start;
    struct node* next = NULL;
    
    do {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    } while (current != start);
    
    start->link = prev;
    start = prev;
    
    return start;
}

struct node* swap(struct node* start){
    struct node* ptr = start;
    struct node* tmp = NULL;
    while(ptr->link->link!=start){
        tmp = ptr->link;
        ptr->link = ptr->link->link;
        tmp->link = ptr->link->link;
        ptr->link->link = tmp;
        ptr = ptr->link->link;
    }
    return start;
}

struct node* createList(struct node* start){
    int n,data;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    if(n==0){
        return start;
    } 
    
    printf("Enter the first element: ");
    scanf("%d",&data);
    start = addEmpty(start,data);
    for(int i=1;i<n;i++){
        printf("Enter the next element: ");
        scanf("%d",&data);
        start = addEnd(start,data);
    }
    return start;
}


int main(){

int choice;
int data,item;
struct node* start = NULL;
while (1)
{
    printf("1. Create List\n");
    printf("2. Add Empty\n");
    printf("3. Add Begin\n");
    printf("4. Add End\n");
    printf("5. Add After\n");
    printf("6. Delete\n");
    printf("7. Display\n");
    printf("8. Reverse\n");
    printf("9. Swap\n");
    printf("10. Exit\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter the first element: ");
            scanf("%d",&data);
            start = addEmpty(start,data);
            break;
        case 2:
            printf("Enter the element: ");
            scanf("%d",&data);
            start = addBegin(start,data);
            break;
        case 3:
            printf("Enter the element: ");
            scanf("%d",&data);
            start = addEnd(start,data);
            break;
        case 4:
            printf("Enter the element: ");
            scanf("%d",&data);
            printf("Enter the element after which to add: ");
            scanf("%d",&item);
            start = addAfter(start,data,item);
            break;
        case 5:
            printf("Enter the element to delete: ");
            scanf("%d",&data);
            start = del(start,data);
            break;
        case 6:
            display(start);
            break;
        case 7:
            start = reverse(start);
            break;
        case 8:
            start = swap(start);
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice\n");
    }

}

    return 0;
}

