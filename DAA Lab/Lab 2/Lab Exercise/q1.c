// Write a program to test whether a number n, entered through keyboard is prime or
// not by using different algorithms you know for atleast 10 inputs and note down the time
// complexity by step/frequency count method for each algorithm & for each input.
// Finally make a comparision of time complexities found for different inputs, plot an
// appropriate graph & decide which algothm is faster.

#include <stdio.h>
#include <stdlib.h>

int halfN_method(int n)
{
    int i, count = 0, flag = 0;
    for (i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("%d is prime number.\n", n);
    else
        printf("%d is not a prime number.\n", n);
}

int fullN_method(int n)
{
    int i, count = 0, flag = 0;
    for (i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("%d is prime number.\n", n);
    else
        printf("%d is not prime number.\n", n);
}

int factorial_Method(int n)
{

    // if ((n-1)!+1)%n == 0 then n is prime
    int count = 0;
    int factm = 1;
    int m = n - 1;

    for (int i = 1; i <= m; i++)
    {
        factm *= i;
    }

    // add 1 to (n-1)!
    int factn = factm + 1;
    if (factn % n == 0)
    {
        printf(" %d  is prime number.\n", n);
    }
    else
    {
        printf("%d  is not prime number.\n", n);
    }
    return 0;
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
    printf("Choose the option from one of the following:\n");
    printf("1. Half N method\n");
    printf("2. Full N method\n");
    printf("3. Factorial method\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        halfN_method(number);
        break;
    case 2:
        fullN_method(number);
        break;
    case 3:
        factorial_Method(number);
        break;
    default:
        printf("Invalid choice.\n");
    }
    return 0;
}