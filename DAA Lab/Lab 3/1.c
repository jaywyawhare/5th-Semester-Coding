// 1. write a menu driven program as given below, to sort an array of n integers in ascending order by
// insertion sort algorithm and determine the time required (in terms of step/frequency count) to sort the elements. Repeat the experiment for different values of n and different nature of data (i.e.apply insertion sort algorithm on the data of array that are already sorted, reversely sorted and random data). Finally plot a graph of the time taken versus n for each type of data. The elements can be read from a file or can be generated using the random number generator.
// O. Quit
// 1. n Random numbers=>Array
// 2. Display
// 3. Sort the Array in Ascending Order
// 4. Sort the Array in Descending Order
// 5. Time Complexity to sort ascending of random data
// 6. Time Complexity to sort ascending of data already sorted in ascending order
// 7. Time Complexity to sort ascending of data already sorted in descending order
// 8. Time Complexity to sort ascending of data for all Cases (Data Ascending, Data in Descending & Random Data) in Tabular form for values n=5000 to 50000, step=5000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randInt()
{
    return rand() % 1000;
}

int *creation(int n)
{
    int *arr, i;

    arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        arr[i] = rand();
    return arr;
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

int *insertion_sort_inc(int *arr, int n)
{
    int key, i;
    for (i = 0; i < n; i++)
    {
        int j = i - 1;
        key = arr[i];
        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return arr;
}

int *insertion_sort_dec(int *arr, int n)
{
    int key, i;
    for (i = 0; i < n; i++)
    {
        int j = i - 1;
        key = arr[i];
        while (key > arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return arr;
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
    insertion_sort_inc(arr1, n);
    insertion_sort_dec(arr2, n);
    t = clock();
    insertion_sort_inc(arr1, n);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;
    double count1 = time_taken;
    t = clock();
    insertion_sort_inc(arr2, n);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;
    double count2 = time_taken;
    t = clock();
    insertion_sort_inc(arr3, n);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;
    double count3 = time_taken;
    printf("%5d\t%5d\t%10f\t%10f\t%10f", n / 5000, n, count1, count2, count3);
}

int main()
{
    int choice = 1, n, *arr, *a;
    clock_t start, end;
    do
    {
        printf("\n\n****MENU****\n\n");
        printf("0. Quit\n");
        printf("1. n Random numbers->Array\n");
        printf("2. Display\n");
        printf("3. Sort the array in Ascending Order\n");
        printf("4. Sort the array in Descending Order\n");
        printf("5. Computation time to sort ascending of random data\n");
        printf("6. Computation time to sort ascending of data already sorted in ascending order\n");
        printf("7. Computation time to sort ascending of data already sorted in descending order\n");
        printf("8. Computation time to sort ascending of data for a 17 Cases ");
        printf("(Data Ascending. Data in Descendina & Random Data) in Tabular form for values n=5000 to 50000, step=5000\n");
        printf("Select an option : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("You have selected to quit");
            break;
        case 1:
            printf("\nEnter the size of required array : ");
            scanf("%d", &n);
            arr = creation(n);
            break;
        case 2:
            display(arr, n);
            break;
        case 3:
            a = insertion_sort_inc(arr, n);
            printf("After sorting in increasing order:");
            display(a, n);
            break;
        case 4:
            a = insertion_sort_dec(arr, n);
            printf("\nAfter sorting in decreasing order:");
            display(a, n);
            break;
        case 5:
            start = clock();
            a = insertion_sort_inc(arr, n);
            end = clock();
            double tot_time = end - start;
            printf("Computation time = %f", tot_time);
        case 6:
            a = insertion_sort_inc(arr, n);
            start = clock();
            a = insertion_sort_inc(arr, n);
            end = clock();
            tot_time = end - start;
            printf("Computation time = %f", tot_time);
            break;
        case 7:
            a = insertion_sort_dec(arr, n);
            start = clock();
            a = insertion_sort_inc(arr, n);
            end = clock();
            tot_time = end - start;
            printf("Computation time = %f", tot_time);
            break;
        case 8:
            printf("S.No\tVal N\tBest Case\tWorst Case\tRandom Data\n");
            for (int i = 5000; i <= 50000; i += 5000)
            {
                analyze(i);
                printf("\n");
            }
            break;
        }
    } while (choice != 0);
}
