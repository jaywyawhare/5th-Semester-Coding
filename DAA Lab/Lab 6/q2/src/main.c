#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my_functions.h"

int main()
{
    clock_t start, end;
    int size;
    printf("Enter the size of array : ");
    scanf("%d", &size);
    int arr[size];
    randomFill(arr, size);
    printf("The array is ");
    printArray(arr, size);
    start = clock();
    buildMinHeap(arr, size);
    end = clock();
    printf("\nThe sorted array is: ");
    printArray(arr, size);
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken by heap sort is %f", time);
    return 0;
}
