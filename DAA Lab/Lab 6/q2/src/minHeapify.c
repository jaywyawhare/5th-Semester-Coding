#include <stdio.h>

void minHeapify(int *ptr, int size, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && ptr[left] < ptr[smallest])
    {
        smallest = left;
    }

    if (right < size && ptr[right] < ptr[smallest])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        int temp = ptr[i];
        ptr[i] = ptr[smallest];
        ptr[smallest] = temp;

        minHeapify(ptr, size, smallest);
    }
}