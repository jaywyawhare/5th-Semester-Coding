#include <stdio.h>

void buildMinHeap(int *ptr, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        minHeapify(ptr, size, i);
    }
}