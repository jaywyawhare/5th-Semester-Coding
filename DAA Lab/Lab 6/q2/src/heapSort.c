#include <stdio.h>

void heapSort(int *ptr, int size)
{
    buildMinHeap(*ptr, size);
}