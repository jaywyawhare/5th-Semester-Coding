#include <stdio.h>

void printArray(int *ptr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
}