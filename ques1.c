#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    int *arr;
    int largest;

    printf("Enter the no of numbers:");
    scanf("%d", &n);

    arr = (int*) malloc(n*sizeof(int));
    if (arr == NULL){
        printf("Memory Allocation Failed\n");
        return 1;

    }
    printf("Enter Numbers:\n");

    for(int i = 0; i <= n; i++){
        scanf("%d", &arr[i]);
    }
    largest = arr[0];
    for(int i = 1; i<n; i++){
        if (arr[i]> largest)
        {
           largest = arr[i];
        }
        
    }
printf("largest number is %d\n", largest);

free(arr);
    return 0;
}