#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char info;
    struct node* link;
};

struct node* top = NULL;
struct node* front = NULL;
struct node* rear = NULL;

void push(char item) {
    struct node* tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    tmp->info = item;
    tmp->link = top;
    top = tmp;
}

char pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return CHAR_MIN;
    }

    char item = top->info; // Changed int to char
    struct node* p = top;
    top = top->link;
    free(p);
    return item;
}

void insert(char data) {
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    if (tmp == NULL) {
        printf("Queue Overflow\n");
        return;
    }
    tmp->info = data;
    tmp->link = NULL;
    if (front == NULL) {
        front = tmp;
    } else {
        rear->link = tmp;
    }
    rear = tmp;
}

char delete() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return CHAR_MIN;
    }
    struct node* tmp = front;
    char data = tmp->info;
    front = front->link;
    free(tmp);
    return data;
}

void displayStack(){
    if (top==NULL)
    {
    printf("\n top\n");
    printf("------\n");
    printf("|NULL|\n");
    printf("------\n\n");
        return;
    }
    printf("\n   top\n");
    printf("----------\n");
    printf("|%8p|\n",top);
    printf("----------\n");
    printf("     |               ");
    for (struct node* p = top; p !=NULL; p=p->link)
    {
        printf("----------------     ");
    }
    printf("\n");
    printf("     |-------------->");
    

    for (struct node* p = top; p !=NULL; p=p->link)
    {
        if (p->link!=NULL)
        {
            printf("| '%c' |%8p|---> ",p->info,p->link);
        }
        else{
            printf("| '%c' |%8s| ",p->info,"NULL");

        }

    }
    printf("\n");
    printf("                     ");
    for (struct node* p = top; p !=NULL; p=p->link)
    {
        printf("----------------     ");
    }
    printf("\n");
    printf("                     ");
    

    
    for (struct node* p = top; p !=NULL; p=p->link)
    {
        printf("    %8p         ",p);
    }
    printf("\n\n");
    
}

void displayQueue() {
    if (front==NULL)
    {
    printf("\n front           rear\n");
    printf("------          ------\n");
    printf("|NULL|          |NULL|\n");
    printf("------          ------\n\n");
        return;
    }
    printf("\n   front");
    printf("             ");
    for (struct node* i = front; i !=NULL; i=i->link)
    {
        printf("                     ");
    }
    printf("             ");
    printf("rear\n");
    printf("----------");
    printf("             ");
    for (struct node* i = front; i !=NULL; i=i->link)
    {
        printf("                      ");
    }
    printf("       ");
    printf("----------\n");

    printf("|%8p|",front);
     printf("          ");
  
    for (struct node* i = front; i !=NULL; i=i->link)
    {
        printf("                      ");
    }
    printf("          ");
    
    printf("|%8p|\n",rear);
    printf("----------");
    printf("             ");
    for (struct node* i = front; i !=NULL; i=i->link)
    {
        printf("                      ");
    }
    printf("       ");
    printf("----------\n");    printf("     |               ");
    for (struct node* p = front; p !=NULL; p=p->link)
    {
        printf("----------------     ");
    }
    printf("                 |\n");
    printf("     |-------------->");
    

    for (struct node* p =front; p !=NULL; p=p->link)
    {
        if (p->link!=NULL)
        {
            printf("| '%c' |%8p|---> ",p->info,p->link);
        }
        else{
            printf("| '%c' |%8s| ",p->info,"NULL");

        }
    }
        printf("<--------------------|")
    ;
    printf("\n");
    printf("                     ");
    for (struct node* p = front; p !=NULL; p=p->link)
    {
        printf("----------------     ");
    }
    printf("\n");
    printf("                     ");

    
    for (struct node* p = front; p !=NULL; p=p->link)
    {
        printf("    %8p         ",p);
    }
    printf("\n\n");
}

int palindrome(const char str[]) {
    int i = 0;
    while (str[i] != '\0') {
          push(str[i]);
        printf("push('%c')\n", str[i]);
        displayStack();
        insert(str[i]);
        printf("insert('%c')\n", str[i]);
        displayQueue();
      
        i++;
    }

    while(top!=NULL && front!=NULL){
        printf("pop()\n");
        char a=pop();
        displayStack();
        printf("delete()\n",front->info);
        char b=delete();
        displayQueue();
        if (a!=b){
            return 0;   
        }
    }
    
    return 1;
}
char peek(){
    if (top==NULL)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return top->info;
}

int match(char a,char b){
    if (a=='(' && b==')' || a=='[' && b==']' || a=='{' && b=='}')
    {
        return 1;
    }
    return 0;
}

int validParentheses(const char inp[]){
    
    for (int i = 0; i < strlen(inp); i++)
    {
        if (inp[i]=='('|| inp[i]=='['|| inp[i]=='{')
        {
            push(inp[i]);
            printf("push('%c')\n",inp[i]);
            displayStack();
            
        }
        else if (inp[i]==')' || inp[i]==']' || inp[i]=='}')
        {
            if (top==NULL)
            {
                return 0;
            }
            if (!match(peek(),inp[i]))
            {
                return 0;
            }
            pop();
            printf("pop()\n");
            displayStack();
        }
    }
    if (top==NULL)
    {
        return 1;
    }
    return 0;
}




int main() {

    int choice;

    while (1)
    {
        printf("\n1. Check if a string is a palindrome\n");
        printf("2. Check valid parentheses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            char str[10];
            printf("Enter a string: ");
            scanf("%s", str);
            if (palindrome(str)) {
                printf("==> %s is a palindrome\n", str);
            
            } else {
                printf("==> %s is not a palindrome\n", str);
            }
        }
        
            
        else if (choice == 2)   
        {
            char inp[10];
            printf("Enter a string: ");
            scanf("%s", inp);
            if (validParentheses(inp)) {
                printf("==> %s has valid parentheses\n", inp);
            } else {
                printf("==> %s does not have valid parentheses\n", inp);
            } 
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
       
    }
    

    return 0;
}