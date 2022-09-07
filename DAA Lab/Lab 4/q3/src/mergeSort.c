#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *ptr, int size)
{
    if (size > 1)
    {
        int mid = size / 2;
        int *left = (int *)malloc(mid * sizeof(int));
        int *right = (int *)malloc((size - mid) * sizeof(int));
        for (int i = 0; i < mid; i++)
        {
            left[i] = ptr[i];
        }
        for (int i = mid; i < size; i++)
        {
            right[i - mid] = ptr[i];
        }
        mergeSort(left, mid);
        mergeSort(right, size - mid);

        merge(left, right, ptr, mid, size - mid);
        free(left);
        free(right);
    }
}
