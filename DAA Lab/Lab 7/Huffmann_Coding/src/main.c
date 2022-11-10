#include <stdio.h>
#include "my_functions.h"

struct hoffmann
{
    char data;
    int freq;
    struct hoffmann *left;
    struct hoffmann *right;
};

void swap(struct hoffmann *a, struct hoffmann *b)
{
    struct hoffmann temp = *a;
    *a = *b;
    *b = temp;
}

void sort(struct hoffmann arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].freq > arr[j].freq)
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of characters: ");
    scanf("%d", &n);
    struct hoffmann arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the character and its frequency: ");
        scanf(" %c %d", &arr[i].data, &arr[i].freq);
    }
    sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%c %d", arr[i].data, arr[i].freq);
    }
    return 0;
}
