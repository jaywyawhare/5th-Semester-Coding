#include <stdlib.h>

void fillRandom(int *ptr, int size)
{
    int temp = size + 10;

    for (int i = 0; i < size; i++)
    {
        ptr[i] = rand() % temp;
    }
}