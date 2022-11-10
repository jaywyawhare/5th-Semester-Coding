#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LCS(char *ptr, char *prt2)
{
    int m = strlen(ptr);
    int n = strlen(prt2);
    int **L = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++)
    {
        L[i] = (int *)malloc((n + 1) * sizeof(int));
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                L[i][j] = 0;
            }
            else if (ptr[i - 1] == prt2[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
            }
            else
            {
                L[i][j] = L[i - 1][j] > L[i][j - 1] ? L[i - 1][j] : L[i][j - 1];
            }
        }
    }
    int index = L[m][n];
    char *lcs = (char *)malloc((index + 1) * sizeof(char));
    lcs[index] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (ptr[i - 1] == prt2[j - 1])
        {
            lcs[index - 1] = ptr[i - 1];
            i--;
            j--;
            index--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    printf("Longest common subsequnce of both file is : %s\n", lcs);
    printf("The size of the longest common subsequence is : %d\n", L[m][n]);
    printf("The percentage of similarity is : %f", (float)L[m][n] / (m > n ? m : n) * 100);
}