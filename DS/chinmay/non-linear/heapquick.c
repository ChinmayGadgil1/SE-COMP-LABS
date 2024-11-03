# include<stdio.h>
#define MAX 100

void restoreDown(int arr[], int i, int size) {
    int left = 2 * i, right = left + 1;
    int num = arr[i];
    
    while (right <= size) {
        if (num <= arr[left] && num <= arr[right]) {
            arr[i] = num;
            return;
        } else if (arr[left] < arr[right]) {
            arr[i] = arr[left];
            i = left;
        } else {
            arr[i] = arr[right];
            i = right;
        }
        left = 2 * i;
        right = left + 1;
    }
    
    if (left == size && num > arr[left]) {
        arr[i] = arr[left];
        i = left;
    }
    
    arr[i] = num;
}

void buildHeap(int arr[], int size) {
    for (int i = size / 2; i >= 1; i--) {
        restoreDown(arr, i, size);
    }
}

int del_root(int arr[], int *size) {
    int min = arr[1];
    arr[1] = arr[*size];
    (*size)--;
    restoreDown(arr, 1, *size);
    return min;
}

void heap_sort(int arr[], int size) {
    buildHeap(arr, size);
    while (size > 1) {
        int min = del_root(arr, &size);
        arr[size + 1] = min;  
    }
}
int partition(int arr[], int low, int up)
{
    int temp, i, j, pivot;
    i = low + 1;
    j = up;
    pivot = arr[low];

    while(i <= j)
    {

        while((arr[i] > pivot) && (i < up))
            i++;
        while(arr[j] < pivot)
            j--;

        if(i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        else
        {
            i++;
        }
    }

    arr[low] = arr[j];
    arr[j] = pivot;
    return j;
}

void quick(int arr[], int low, int up)
{
    int pivloc;
    if (low >= up)
        return;

    pivloc = partition(arr, low, up);
    quick(arr, low, pivloc - 1); 
    quick(arr, pivloc + 1, up);  
}



int main(){
    int choice, n, i;
  int arr[MAX];



    while (1) {
        printf("\nMenu:\n");
        printf("1. Heap Sort\n");
        printf("2. Quick Sort\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                printf("Enter the elements: ");
                for (i = 1; i <= n; i++) {
                    scanf("%d", &arr[i]);
                }
                heap_sort(arr, n);
                printf("Sorted array: ");
                for (i = 1; i <= n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 2:
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                printf("Enter the elements: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                quick(arr, 0, n - 1);
                printf("Sorted array: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }


return 0;
}