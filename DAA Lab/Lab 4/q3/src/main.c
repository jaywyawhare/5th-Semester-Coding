#include <stdio.h>
#include <stdlib.h>
#include "my_functions.h"

int main()
{
    int size;
    printf("Enter the size of array :");
    scanf("%d", &size);
    int temp = size + 5;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % temp;
    }
    printf("The array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    mergeSort(arr, size);
    printArray(arr, size);
    printf("\nThe min is %d and the max is %d", arr[0], arr[size - 1]);
    return 0;
}
