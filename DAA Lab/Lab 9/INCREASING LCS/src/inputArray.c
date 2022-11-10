#include <stdio.h>

void inputArray(int *ptr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", (ptr + i));
    }
}