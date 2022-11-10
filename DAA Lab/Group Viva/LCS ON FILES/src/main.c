#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "my_functions.h"

int main()
{
    char *S1 = (char *)malloc(INT_MAX * sizeof(char));
    char *S2 = (char *)malloc(INT_MAX * sizeof(char));
    fileToString("file1.txt", S1);
    fileToString("file2.txt", S2);
    printf("The first file contains : %s\n", S1);
    printf("The second file contains : %s\n", S2);
    LCS(S1, S2);
    free(S1);
    free(S2);
    return 0;
}
