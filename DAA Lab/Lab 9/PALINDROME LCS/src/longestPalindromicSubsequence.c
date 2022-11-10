#include <stdio.h>
#include "my_functions.h"

void longestPalindromicSubsequence(char *ptr, int size)
{
    int i, j, k;
    int table[size][size];
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            table[i][j] = 0;
        }
    }
    for (i = 0; i < size; i++)
    {
        table[i][i] = 1;
    }
    for (i = 2; i <= size; i++)
    {
        for (j = 0; j < size - i + 1; j++)
        {
            k = j + i - 1;
            if (ptr[j] == ptr[k] && i == 2)
            {
                table[j][k] = 2;
            }
            else if (ptr[j] == ptr[k])
            {
                table[j][k] = table[j + 1][k - 1] + 2;
            }
            else
            {
                table[j][k] = max(table[j][k - 1], table[j + 1][k]);
            }
        }
    }
    printf("The length of the longest palindromic subsequence is %d", table[0][size - 1]);
}