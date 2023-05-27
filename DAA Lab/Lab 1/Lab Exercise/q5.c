// Let A be n*n square matrix array. WAP by using appropriate user defined functions for the following:
// a) Find the number of nonzero elements in A
// b) Find the sum of the elements above the leading diagonal.
// c) Display the elements below the minor diagonal.
// d) Find the product of the diagonal elements.

#include <stdio.h>
#include <stdlib.h>

int nonzero_elements(int n, int arr[n][n])
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                count++;
            }
        }
    }
    return count;
}

int sum_above_diagonal(int n, int arr[n][n])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)
            {
                sum += arr[i][j];
            }
        }
    }
    return sum;
}

int display_elements_below_minor_diagonal(int n, int arr[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                printf("%d\t", arr[i][j]);
            }
        }
        printf("\n");
    }
}
int product_diagonal(int n, int arr[n][n])
{
    int product = 1;
    for (int i = 0; i < n; i++)
    {
        product *= arr[i][i];
    }
    return product;
}

int main()
{
    int n;
    int count = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n][n];
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("The maxtrix is: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    int option;
    printf("Choose the option you want to do: \n");
    printf("1. Find the number of nonzero elements in A\n");
    printf("2. Find the sum of the elements above the leading diagonal\n");
    printf("3. Display the elements below the minor diagonal\n");
    printf("4. Find the product of the diagonal elements\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        count = nonzero_elements(n, arr);
        printf("The number of nonzero elements in A is %d\n", count);
        break;
    case 2:
        count = sum_above_diagonal(n, arr);
        printf("The sum of the elements above the leading diagonal is %d\n", count);
        break;
    case 3:
        display_elements_below_minor_diagonal(n, arr);

        break;
    case 4:
        count = product_diagonal(n, arr);
        printf("The product of the diagonal elements is %d\n", count);
        break;
    case 5:
        printf("Thank you for using the program!\n");
        break;
    default:
        printf("Invalid option\n");
        break;
    }
    return 0;
}
