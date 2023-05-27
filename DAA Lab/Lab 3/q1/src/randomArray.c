#include <stdlib.h>

int randomArray(int size)
{
    int arr[size];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10;
    }
    // return array
    return arr;
}
