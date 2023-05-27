#include <stdio.h>
#include <stdlib.h>
#include "my_functions.h"
void logic()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *ptr = (int *)malloc(size * sizeof(int));
    printf("Enter the elements of the array: ");
    inputArray(ptr, size);
    printf("The array is: ");
    printArray(ptr, size);
    sortArray(ptr, size);
    printf("The sorted array is: ");
    printArray(ptr, size);
    printf("The longest increasing odd-even subsequence is: ");
    increasingOddEvenSubsequence(ptr, size);
    free(ptr);
}