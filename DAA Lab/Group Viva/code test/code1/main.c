// write a program that can be completed in O( n log n ) times and also stores the
// result in the array by trying the different inputs.

#include <stdio.h>
#include <stdlib.h>

// O(nlogn) time complexity i.e. binary search on sorted array

void binarySearch(int *ptr, int size, int key)
{

    int low = 0;
    int high = size - 1;
    int mid = (low + high) / 2;
    int flag = 0;
    while (low <= high)
    {
        if (ptr[mid] == key)
        {
            flag = 1;
            break;
        }
        else if (ptr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        mid = (low + high) / 2;
    }
    if (flag == 1)
    {
        printf("Element found at index %d", mid);
    }
    else
    {
        printf("Element not found");
    }
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *ptr = (int *)malloc(size * sizeof(int));
    printf("Enter the elements of sorted array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &ptr[i]);
    }
    int key;
    printf("Enter the key to be searched: ");
    scanf("%d", &key);
    binarySearch(ptr, size, key);
    return 0;
}
