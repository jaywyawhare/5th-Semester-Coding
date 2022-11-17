// Write a program that can be completed in O( n ^ 1/2 ) times and also stores the result
// in the array by trying the different inputs.

#include <stdio.h>
#include <stdlib.h>

int isPrime(int n)
{
    if (n <= 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}
int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    if (isPrime(n))
        printf("The number is prime");
    else
        printf("The number is not prime");
    return 0;
}