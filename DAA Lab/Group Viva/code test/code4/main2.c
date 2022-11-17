// Assume nine process are there. Each process execution time is given below.
// If each process comes to processor after each 2sec interval then write a program
// to find the maximum number of process that can be completed with in the start
// and end time(Assume start time of P0 is 0)
// item                    Duration
// P0                      2sec
// P1                      1sec
// P2                      3sec
// P3                      1sec
// P4                      4sec
// P5                      2 sec
// P6                      3 sec
// P7                      5sec
// P8                      4 sec

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of process: ");
    scanf("%d", &n);
    char *process = (char *)malloc(n * sizeof(char));
    int *time = (int *)malloc(n * sizeof(int));
    printf("Enter the process name: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &process[i]);
    }
    printf("Enter the execution time: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &time[i]);
    }
    int *time1 = (int *)malloc(n * sizeof(int));
    time1[0] = time[0];
    for (int i = 1; i < n; i++)
    {
        time1[i] = time1[i - 1] + time[i] + 2;
    }
    int max = time1[0];
    for (int i = 1; i < n; i++)
    {
        if (time1[i] > max)
        {
            max = time1[i];
        }
    }
    printf("The maximum number of process that can be completed is: %d", max);
    return 0;
}
