#include <stdio.h>
#include <stdlib.h>

void quickSort(int *ptr, int size)
{
    if (size <= 1)
    {
        return;
    }
    int pivot = ptr[size / 2];
    int i = 0;
    int j = size - 1;
    while (i <= j)
    {
        while (ptr[i] < pivot)
        {
            i++;
        }
        while (ptr[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            int temp = ptr[i];
            ptr[i] = ptr[j];
            ptr[j] = temp;
            i++;
            j--;
        }
    }
    quickSort(ptr, i);
    quickSort(ptr + i, size - i);
}