#include <stdio.h>
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

    // quickSort(arr, size);
    return 0;
}
