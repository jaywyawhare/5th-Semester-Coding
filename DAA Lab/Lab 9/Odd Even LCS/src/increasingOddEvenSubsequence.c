#include <stdio.h>
#include <stdlib.h>
#include "my_functions.h"

void increasingOddEvenSubsequence(int *ptr, int size)
{
    int i, j, k, count = 0, max = 0, index = 0;
    int *temp = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        count = 0;
        for (j = i + 1; j < size; j++)
        {
            if ((*(ptr + j) - *(ptr + i) > 0) && ((*(ptr + i) % 2 == 0 && *(ptr + j) % 2 != 0) || (*(ptr + j) - *(ptr + i) > 0) && (*(ptr + i) % 2 != 0 && *(ptr + j) % 2 == 0)))
            {
                count++;
                i = j;
            }
        }
        if (count > max)
        {
            max = count;
            index = i;
        }
    }
    for (k = index - max; k <= index; k++)
    {
        printf("%d ", *(ptr + k));
    }
    printf("The length of the longest subsequence is %d", max + 1);
    free(temp);
}