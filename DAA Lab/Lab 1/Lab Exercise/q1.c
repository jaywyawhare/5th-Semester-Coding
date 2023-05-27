// Write a program to store random numbers into an array of n integers and then find out the smallest and largest number stored in it. n is the user input.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    // fill the array with random numbers
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
    int min = arr[0];
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("The smallest element in the array is %d\n", min);
    printf("The largest element in the array is %d\n", max);
    return 0;
}