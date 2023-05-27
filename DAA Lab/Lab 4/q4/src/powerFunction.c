#include <stdio.h>
#include <stdlib.h>

void powerFunction(int power, int base)
{

    int *array = (int *)malloc(sizeof(int) * power);
    int i;
    for (i = 0; i < power; i++)
    {
        array[i] = base;
    }
    printf("The array is: ");
    for (i = 0; i < power; i++)
    {
        printf("%d ", array[i]);
    }
    int result = 1;
    for (i = 0; i < power; i++)
    {
        result = result * array[i];
    }
    printf("\nThe result is %d", result);
}
