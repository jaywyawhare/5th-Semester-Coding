#include <stdio.h>

void printArray(int *ptr, int size)
{
    printf("\nThe sorted array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", ptr[i]);
    }
}