// weight              profit
// 10                  20000
// 20                  30000
// 30                  66000
// 40                  40000
// 50                  60000

// Fractional Knapsack

#include <stdio.h>
#include <stdlib.h>

struct item
{
    int value;
    int weight;
};

int main()
{
    int number;
    int KnapSack;
    printf("Enter the number of items: ");
    scanf("%d", &number);
    printf("Enter the size of the knapsack: ");
    scanf("%d", &KnapSack);
    struct item arr[number];
    for (int i = 0; i < number; i++)
    {
        printf("Enter the value and weight of item %d: ", i + 1);
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }
    int ratio[number];
    for (int i = 0; i < number; i++)
    {
        ratio[i] = arr[i].value / arr[i].weight;
    }
    printf("The initial ratio array is :");
    printArray(ratio, number);
    for (int i = 0; i < number; i++)
    {
        for (int j = i + 1; j < number; j++)
        {
            if (ratio[i] < ratio[j])
            {
                swap(&ratio[i], &ratio[j]);
                swap(&arr[i].value, &arr[i].value);
                swap(&arr[i].weight, &arr[i].weight);
            }
        }
    }
    printf("The sorted ratio array is :");
    printArray(ratio, number);
    int max = 0;
    int i = 0;
    while (KnapSack > 0)
    {
        if (KnapSack > arr[i].weight)
        {
            max += arr[i].value;
            KnapSack -= arr[i].weight;
        }
        else
        {
            max += (KnapSack * arr[i].value) / arr[i].weight;
            KnapSack = 0;
        }
        i++;
    }
    printf("Maximum value is: %d", max);
    return 0;
}
