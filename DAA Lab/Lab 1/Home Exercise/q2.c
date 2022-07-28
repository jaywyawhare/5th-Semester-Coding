// Write a program to swap pair of elements of an array of n integers from starting. If n is
// odd, then last number will be remain unchanged.

#include <stdio.h>
#include <stdlib.h>

int pair_swap(int *arr, int n)
{
    if (n % 2 == 0)
    {
        for (int i = 0; i < n; i += 2)
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    else
    {
        for (int i = 0; i < n - 1; i += 2)
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
}
int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
    printf("The array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("The array after swapping is: ");
    pair_swap(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}