// Rewrite the program no-1 (Insertion Sort) with the following details.
// i. Compare the best case, worst case and average case time complexity with the same data except time complexity will count the CPU clock time. ii. Plot a graph showing the above comparison (n, the input data vs. CPU times for best, worst & average case) iii. Compare manually program no-2.1 graph vs program no-3.1 graph and draw your
// inference.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int randInt()
{

    return rand() % 100;
}

void display(int *arr, int n)
{
    int i = 0;
    printf("\nThe array is : \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void insertionSort(int arr[], int n, int p)
{
    for (int j = 1; j < n; ++j)
    {
        int temp = arr[j];
        int i = j - 1;
        while (arr[i] > temp && i >= 0)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = temp;
    }
    if (p == 1)
    {
        for (int i = 0; i < n; ++i)
            printf("%d ", arr[i]);
        printf("\n");
    }
}

void insertionSortDescending(int arr[], int n, int p)
{
    for (int j = 1; j < n; ++j)
    {
        int temp = arr[j];
        int i = j - 1;
        while (arr[i] < temp && i >= 0)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = temp;
    }
    if (p == 1)
    {
        for (int i = 0; i < n; ++i)
            printf("%d ", arr[i]);
        printf("\n");
    }
}

void analyze(int n)
{
    int *arr1 = malloc(n * sizeof(int)), *arr2 = malloc(n * sizeof(int)), *arr3 = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
    {
        int num = randInt();
        arr1[i] = num;
        arr2[i] = num;
        arr3[i] = num;
    }
    clock_t t;
    double time_taken;
    insertionSort(arr1, n, 0);
    insertionSortDescending(arr2, n, 0);
    t = clock();
    insertionSort(arr1, n, 0);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;
    double count1 = time_taken;
    t = clock();
    insertionSort(arr2, n, 0);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;
    double count2 = time_taken;
    t = clock();
    insertionSort(arr3, n, 0);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;
    double count3 = time_taken;
    printf("%5d\t%5d\t%10f\t%10f\t%10f", n / 5000, n, count1, count2, count3);
}

void main()
{
    int *arr;
    int n;
    int ch = 0;
    double count = 0;
    clock_t t;
    double time_taken;
    do
    {
        printf("\n\n****MENU****\n\n");
        printf("Select An Option :");
        printf("\n0. Quit\n1. n Random numbers=>Array\n2. Display the Array\n3. Sort the Array in Ascending Order by using Insertion Sort Algorithm\n4. Sort the Array in Descending Order by using any sorting algorithm\n5. Time Complexity to sort ascending of random data\n6. Time Complexity to sort ascending of data already sorted in ascending order\n7. Time Complexity to sort ascending of data already sorted in descending order\n8. Time Complexity to sort ascending of data for all Cases\n\t\t(DataAscending, Data Descending & Random Data) in a table for values n=5000 to 50000,step=5000\n");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 0:
            break;
        case 1:
        {
            printf("Enter length of array\n");
            scanf("%d", &n);
            arr = malloc(n * sizeof(int));
            for (int i = 0; i < n; ++i)
                arr[i] = randInt();
            break;
        }
        case 2:
        {
            printf("The array is \n");
            for (int i = 0; i < n; ++i)
                printf("%d ", arr[i]);
            printf("\n");
            break;
        }
        case 3:
        {
            insertionSort(arr, n, 1);
            break;
        }
        case 4:
        {
            insertionSortDescending(arr, n, 1);
            break;
        }
        case 5:
        {
            t = clock();
            insertionSort(arr, n, 0);
            t = clock() - t;
            time_taken = ((double)t) / CLOCKS_PER_SEC;
            double count = time_taken;
            printf("Array of length %d sorted in %f seconds \n", n, count);
            break;
        }
        case 6:
        {
            t = clock();
            insertionSort(arr, n, 0);
            insertionSort(arr, n, 0);
            t = clock() - t;
            time_taken = ((double)t) / CLOCKS_PER_SEC;
            double count = time_taken;
            printf("An already sorted array was sorted in %f seconds\n", count);
            break;
        }
        case 7:
        {
            t = clock();
            insertionSortDescending(arr, n, 0);
            insertionSort(arr, n, 0);
            t = clock() - t;
            time_taken = ((double)t) / CLOCKS_PER_SEC;
            double count = time_taken;
            printf("Array sorted in descending order was sorted in %f seconds\n",
                   count);
            break;
        }
        case 8:
        {
            printf("S.No\tVal N\tBest Case\tWorst Case\tRandom Data\n");
            for (int i = 5000; i <= 50000; i += 5000)
            {
                analyze(i);
                printf("\n");
            }
            break;
        }
        }
    } while (ch != 0);
}