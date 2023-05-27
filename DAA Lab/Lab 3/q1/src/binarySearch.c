#include <stdio.h>
#include <stdlib.h>

void binarySearch(int *ptr, int size)
{
    int search;
    int high;
    int low;
    printf("The array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\nEnter the numbers in the array to be search: ");
    scanf("%d", &search);
    int mid = (high + low) / 2;
    if (ptr[mid] == search)
    {
        printf("\n%d is found at index %d\n", search, mid);
    }
    else if (ptr[mid] > search)
    {
        binarySearch(ptr);
    }
    else
    {
        binarySearch(ptr);
    }
}