#include <stdio.h>
#include <time.h>

clock_t start, end;
double randomTime;
double bestTime;
double worstTime;

void menuDriven(int *ptr, int size)
{
    int choice;
    do
    {
        printf("00. Quit");
        printf("01. Fill random numbers");
        printf("02. Display the Array");
        printf("03. Sort the Array in Ascending Order by using Max-Heap Sort technique");
        printf("04. Sort the Array in Descending Order by using any algorithm");
        printf("05. Time Complexity to sort ascending of random data");
        printf("06. Time Complexity to sort ascending of already sorted data in ascending order");
        printf("07. Time Complexity to sort ascending of already sorted data in descending order");
        printf("08. Extract largest element from the array");
        printf("09. Replace value at a node with new value");
        printf("10. Insert a new node");
        printf("11. Delete a node");
    } while (choice != 0);

    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 0:
        exit(0);
        break;
    case 1:
        fillRandom(*ptr, size);
        break;
    case 2:
        display(*ptr, size);
        break;
    case 3:
        start = clock();
        ascendingHeap(*ptr, size);
        end = clock();
        randomTime = (double)(end - start) / CLOCKS_PER_SEC;
        break;
    case 4:
        descendingAny(*ptr, size);
        break;
    case 5:
        printf("The time taken to sort random array is %f", randomTime);
        break;
    case 6:
        bestTimeComplexity(*ptr, size);
        break;
    case 7:
        worstTimeComplecity(*ptr, size);
        break;
    case 8:
        extractLargest(*ptr, size);
        break;
    case 9:
        replaceValue(*ptr, size);
        break;
    case 10:
        insertElement(*ptr, size);
        break;
    case 11:
        deleteElement(*ptr, size);
        break;
    default:
        printf("Invalid choice");
    }
}
