# include<stdio.h>
#include<stdlib.h>

int max(int arr[], int);
int min(int arr[], int);

int main(){

int size;
printf("Enter size of array: ");
scanf("%d",&size);
int *arr=(int*)malloc(size*sizeof(int));

printf("Enter %d elements: ",size);
for (int i = 0; i < size; i++)
{
    scanf("%d",&arr[i]);
}


int minimum=min(arr,size);
int maximum=max(arr,size);

int difference=maximum-minimum;

printf("Minimum value: %d\n",minimum);
printf("Maximum value: %d\n",maximum);
printf("Difference between minimum and maximum is %d\n",difference);

return 0;
}

int max(int arr[], int size) {
    int max = arr[0];
    for(int i=1; i<size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int min(int arr[], int size) {
    int min = arr[0];
    for(int i=1; i<size; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}