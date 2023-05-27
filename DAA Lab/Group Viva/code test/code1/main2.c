// If the food items are order by different customer in every 5 mins interval then find
// the maximum item that can be prepared by the item for the sequence "CDAIHGFEB".
// Assume the preparation time start from 0 to until the maximum completion time of
// ordering the item

// item Preparation    Time
// a                   10min
// b                   15min
// c                   30mins
// d                   5mins
// e                   8mins
// f                   12mins
// g                   15mins
// h                   10mins
// i                   5mins

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    char *item = (char *)malloc(n * sizeof(char));
    int *time = (int *)malloc(n * sizeof(int));
    printf("Enter the item name: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &item[i]);
    }
    printf("Enter the preparation time: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &time[i]);
    }
    char *order = (char *)malloc(n * sizeof(char));
    printf("Enter the order of item: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &order[i]);
    }
    int *time1 = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (order[i] == item[j])
            {
                time1[i] = time[j];
            }
        }
    }
    int *time2 = (int *)malloc(n * sizeof(int));
    time2[0] = time1[0];
    for (int i = 1; i < n; i++)
    {
        time2[i] = time2[i - 1] + time1[i];
    }
    int max = time2[0];
    for (int i = 1; i < n; i++)
    {
        if (time2[i] > max)
        {
            max = time2[i];
        }
    }
    printf("Maximum time taken to prepare the item is: %d", max);
    return 0;
}