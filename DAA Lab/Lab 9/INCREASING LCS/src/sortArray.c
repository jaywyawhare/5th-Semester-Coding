#include "my_functions.h"

void sortArray(int *ptr, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (*(ptr + i) > *(ptr + j))
            {
                swap((ptr + i), (ptr + j));
            }
        }
    }
}