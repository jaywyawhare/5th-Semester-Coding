// Write a program to store random numbers into an array of n integers, where the array
// must contains some duplicates. Do the following:
// a) Find out the total number of duplicate elements.
// b) Find out the most repeating element in the array.

#include <stdio.h>
#include <stdlib.h>

int duplicate_number(int n, int arr[n])
{
    int i, j, count = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
    }
    return count;
}

int most_repeating_element(int n, int arr[n])
{
    int i, j, count = 0, max_count = 0, max_element = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > max_count)
        {
            max_count = count;
            max_element = arr[i];
        }
        count = 0;
    }
    return max_element;
}

int main()
{
    int n;
    printf("Enter the number of elements in the array : ");
    scanf("%d", &n);
    int arr[n];
    int p = n - 2;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % p;
    }

    printf("Your random array is : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t ", arr[i]);
    }

    printf("Select the option you want to do:\n");
    printf("1. Find out the total number of duplicate elements.\n");
    printf("2. Find out the most repeating element in the array.\n");
    int option;
    scanf("%d", &option);
    if (option == 1)
    {
        int ans = duplicate_number(n, arr);
        printf("The total number of duplicate elements is %d\n", ans);
    }
    else if (option == 2)
    {
        printf("The most repeating element is %d\n", most_repeating_element(n, arr));
    }
    else
    {
        printf("Invalid option\n");
    }
    return 0;
}