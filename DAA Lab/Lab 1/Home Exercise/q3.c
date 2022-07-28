// Write a program to display an array of n integers (n>1), where at every index of the
// array should contain the product of all elements in the array except the element at the
// given index. Solve this problem by taking single loop and without an additional array.
// Input Array : 3 4 5 1 2
// Output Array :40 30 24 120 60

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    if (size > 1)
    {
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
        int prod = 1;
        for (int i = 0; i < size; i++)
        {
            prod *= arr[i];
        }
        for (int i = 0; i < size; i++)
        {
            arr[i] = prod / arr[i];
        }
        printf("The array after multiplication is: ");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Size of array should be greater than 1");
    }
    return 0;
}