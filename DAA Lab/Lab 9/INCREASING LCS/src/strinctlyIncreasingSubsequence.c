#include <stdio.h>
#include <stdlib.h>

void strinctlyIncreasingSubsequence(int *ptr, int size)
{
    int i, j, k, count = 0, max = 0, index = 0;
    int *temp = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        count = 0;
        for (j = i + 1; j < size; j++)
        {
            if (*(ptr + j) - *(ptr + i) == 1)
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
    printf("\nThe length of the longest strictly increasing subsequence is %d", max + 1);
    free(temp);
}
