// Write a program to rearrange the elements of an array of n integers such that all even numbers are followed by all odd numbers. How many different ways you can solve this problem. Write your approaches & strategy for solving this problem.

#include <stdio.h>

int main()
{
    int n;
    int arr[n];
    int odd[n];
    int even[n];
    int odd_count = 0;
    int even_count = 0;

    printf("Enter the size of array : ");
    scanf("%d", &n);
    printf("Enter the elements of array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The original array is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            even[even_count] = arr[i];
            even_count++;
        }
        else
        {
            odd[odd_count] = arr[i];
            odd_count++;
        }
    }

    printf("\nThe odd array is :\n");
    for (int i = 0; i < odd_count; i++)
    {
        printf("%d\t", odd[i]);
    }
    printf("\nThe even array is :\n");
    for (int i = 0; i < even_count; i++)
    {
        printf("%d\t", even[i]);
    }
    printf("\nAfter rearranging the array :\n");
    for (int i = 0; i < even_count; i++)
    {
        printf("%d\t", even[i]);
    }
    for (int i = 0; i < odd_count; i++)
    {
        printf("%d\t", odd[i]);
    }
}
