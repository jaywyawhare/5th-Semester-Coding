#include <stdio.h>
#include "my_functions.h"

struct actiivity
{
    int start;
    int finish;
};

void sortActivity(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (ptr[i] > ptr[j])
            {
                swap(&ptr[i], &ptr[j]);
            }
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int number;
    printf("Enter the number of activities: ");
    scanf("%d", &number);
    struct actiivity arr[number];
    for (int i = 0; i < number; i++)
    {
        printf("Enter the start and finish time of activity %d: ", i + 1);
        scanf("%d %d", &arr[i].start, &arr[i].finish);
    }
    printf("The initial array is :");
    for (int i = 0; i < number; i++)
    {
        printf("%d %d", arr[i].start, arr[i].finish);
        printf("\n");
    }
    sortActivity(arr, number);
    printf("The sorted array is :");
    for (int i = 0; i < number; i++)
    {
        printf("%d %d", arr[i].start, arr[i].finish);
        printf("\n");
    }
    int count = 1;
    int i = 0;
    for (int j = 1; j < number; j++)
    {
        if (arr[j].start >= arr[i].finish)
        {
            count++;
            i = j;
        }
    }
    printf("The maximum number of activities that can be performed is %d", count);
    return 0;
}
