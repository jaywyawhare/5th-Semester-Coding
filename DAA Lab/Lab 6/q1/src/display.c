#include <stdio.h>

void display(int *ptr, int size)
{
    printf("The arrray is : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", ptr[i]);
    }
}