#include <stdio.h>
#include <stdlib.h>
#include "my_functions.h"

void logic()
{
    int size;
    printf("Enter the size of the sequence : ");
    scanf("%d", &size);
    int *ptr = (int *)malloc(size * sizeof(int));
    inputArray(ptr, size);
    printf("The given array is : ");
    printArray(ptr, size);
    sortArray(ptr, size);
    printf("The sorted array is : ");
    printArray(ptr, size);
    printf("The longest increasing subsequence is : ");
    strinctlyIncreasingSubsequence(ptr, size);
}