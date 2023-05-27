// Write a program using insertion sort to sort the alphabets of your full name
// Using the Insertion Sort. Find the computation time for 10 inputs and stored in an array and
// display.

#include <stdio.h>
#define MAX_NUMS 10

void InsertionSort(char list[]);

int main()
{
    int index = 0;
    char letters[MAX_NUMS];

    printf("Enter a word: ");
    scanf("%s", letters);

    printf("%s\n", letters);

    InsertionSort(letters);

    printf("pass");

    printf("\nThe input set, in ascending order:\n");
    while (letters[index] != '\0')
    {
        printf("%c\n", letters[index]);
        index += 1;
    }
}

void InsertionSort(char list[])
{
    int unsorted;
    int sorted;
    char unsortedItem;
    char lowUnsortedItem;

    for (unsorted = 0; list[unsorted] != '\0'; unsorted++)
    {
        unsortedItem = list[unsorted];

        if (unsortedItem >= 'A' && unsortedItem <= 'Z')
        {
            lowUnsortedItem = unsortedItem + 32;
        }

        for (sorted = unsorted - 1;
             (sorted >= 0) && (list[sorted] > unsortedItem);
             sorted--)
            list[sorted + 1] = list[sorted];

        list[sorted + 1] = unsortedItem;
    }
}