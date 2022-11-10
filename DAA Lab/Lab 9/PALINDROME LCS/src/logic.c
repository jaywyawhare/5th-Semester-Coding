#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_functions.h"

void logic()
{
    int size;
    printf("Enter the size of the string: ");
    scanf("%d", &size);
    char *ptr = (char *)malloc(size * sizeof(char));
    printf("Enter the string: ");
    scanf("%s", ptr);
    longestPalindromicSubsequence(ptr, size);
    free(ptr);
}