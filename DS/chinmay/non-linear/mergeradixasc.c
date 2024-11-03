# include<stdio.h>
#include<stdlib.h>
#define MAX 100


struct node {
    int info;
    struct node* link;
} *start = NULL;

void copy(int arr[], int tmp[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = tmp[i];
    }
}

int large_dig() {
    struct node* ptr;
    int large = 0, dig = 0;
    ptr = start;
    while (ptr != NULL) {
        if (ptr->info > large) {
            large = ptr->info;
        }
        ptr = ptr->link;
    }
    while (large != 0) {
        dig++;
        large = large / 10;
    }
    return dig;
}

int digit(int number, int k) {
    int digit, i;
    for (i = 1; i <= k; i++) {
        digit = number % 10;
        number = number / 10;
    }
    return digit;
}


void radix_sort() {
    int i, k, dig, least_sig, most_sig;
    struct node* rear[10];
    struct node* front[10];
    least_sig = 1;
    most_sig = large_dig();
    for (k = least_sig; k <= most_sig; k++) {
        for (i = 0; i < 10; i++) {
            rear[i] = NULL;
            front[i] = NULL;
        }
        for (struct node* ptr = start; ptr != NULL; ptr = ptr->link) {
            dig = digit(ptr->info, k);
            if (front[dig] == NULL) {
                front[dig] = ptr;
            } else {
                rear[dig]->link = ptr;
            }
            rear[dig] = ptr;
        }
        i = 0;
        while (front[i] == NULL && i < 10) {
            i++;
        }
        if (i < 10) {
            start = front[i];
            while (i < 9) {
                if (rear[i + 1] != NULL) {
                    rear[i]->link = front[i + 1];
                } else {
                    rear[i + 1] = rear[i];
                }
                i++;
            }
            rear[9]->link = NULL;
        }
    }
}


void merge(int arr[], int tmp[], int low1, int up1, int low2, int up2) {
    int i = low1;
    int j = low2;
    int k = low1;
    while (i <= up1 && j <= up2) {
        if (arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
        }
    }
    while (i <= up1) {
        tmp[k++] = arr[i++];
    }
    while (j <= up2) {
        tmp[k++] = arr[j++];
    }
}

void merge_pass(int arr[], int tmp[], int size, int n) {
    int low1, up1, low2, up2, i;
    low1 = 0;
    while (low1 + size < n) {
        up1 = low1 + size - 1;
        low2 = low1 + size;
        up2 = low2 + size - 1;
        if (up2 >= n) {
            up2 = n - 1;
        }
        merge(arr, tmp, low1, up1, low2, up2);
        low1 = up2 + 1;
    }
    for (i = low1; i < n; i++) {
        tmp[i] = arr[i];
    }
    copy(arr, tmp, n);
}

void merge_sort(int arr[], int n) {
    int size = 1;
    int tmp[MAX];
    while (size < n) {
        merge_pass(arr, tmp, size, n);
        size = size * 2;
    }
}

int main(){
int choice, n, i;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];


    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
  
        printf("\nMenu:\n");
        printf("1. Perform Radix Sort \n");
        printf("2. Perform Merge Sort \n");
        printf("3. Display Array\n");
        printf("4. Exit");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                start = NULL;
                for (i = n - 1; i >= 0; i--) {
                    struct node* new_node = (struct node*)malloc(sizeof(struct node));
                    new_node->info = arr[i];
                    new_node->link = start;
                    start = new_node;
                }
                radix_sort();
                printf("Sorted array: ");
                struct node* ptr = start;
                while (ptr != NULL) {
                    printf("%d ", ptr->info);
                    ptr = ptr->link;
                }
                printf("\n");

                while (start != NULL) {
                    struct node* temp = start;
                    start = start->link;
                    free(temp);
                }
                break;

            case 2:
                merge_sort(arr, n);
                printf("Sorted array: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 3:
                printf("Array: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}