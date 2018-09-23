#include <stdio.h>

int main() {
    int i, size, max, min;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("The size of the array is: %d elements long\n", size);

    printf("Now enter each element into the array: ");
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    for(i = 0; i < size; i++) {
        printf("Element[%d]: %d\n", i, arr[i]);
    }
    
    max = arr[0];
    for(i = 1; i < size; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    printf("Max value of array is: %d\n", max);

    min = arr[0];
    for(i = 1; i < size; i++) {
        if(min > arr[i]) {
            min = arr[i];
        }
    }
    printf("Min value of array is: %d\n", min);

    printf("Range of array is: %d\n", max - min);

    return 0;
}