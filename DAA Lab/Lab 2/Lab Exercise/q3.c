// Write a program to find factors of a number using prime factorisation method

#include <stdio.h>

int prime_factorisation(int n)
{
    // find all prime factors of given numbers
    int i, j, k, flag = 0;
    for (i = 2; i <= n / 2; i++)
    {
        flag = 0;
        for (j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    int number;
    printf("Enter a positive integer: ");
    scanf("%d", &number);
    if (number < 0)
    {
        printf("Error: n must be positive.\n");
        return 0;
    }
    printf("Prime factors of the given number are: ");
    printf("%d\n", prime_factorisation(number));
    return 0;
}