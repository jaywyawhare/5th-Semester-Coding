// Write a program to find out GCD (greatest common divisor) using the following three
// algorithms.
// a) Euclid’s algorithm
// b) Consecutive integer checking algorithm.
// c) Middle school procedure which makes use of common prime factors. For finding
// list of primes implement sieve of Eratosthenes algorithm.
// Page 8 of 30
// Write a program to find out which algorithm is faster for the following data. Estimate
// how many times it will be faster than the other two by step/frequency count method in
// each case.
// i. Find GCD of two numbers when both are very large i.e.GCD(31415, 14142) by
// applying each of the above algorithms.
// ii. Find GCD of two numbers when one of them can be very large i.e.GCD(56,
// 32566) or GCD(34218, 56) by applying each of the above algorithms.
// iii. Find GCD of two numbers when both are very small i.e.GCD(12,15) by applying
// each of the above algorithms.
// iv. Find GCD of two numbers when both are same i.e.GCD(31415, 31415) or
// GCD(12, 12) by applying each of the above algorithms.
// Write the above data in the following format and decide which algorithm is faster for
// the particular data.

#include <stdio.h>
#include <stdlib.h>

int Euclid(int a, int b)
{
    int r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int Consecutive_integer_checking(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

int primeFactorisation_method(int a, int b)
{
    int temp1, temp2, gcd;
    temp1 = a;
    temp2 = b;
    for (int i = 2; i <= temp1 && i <= temp2; ++i)
    {
        while (temp1 % i == 0 && temp2 % i == 0)
        {
            gcd = i;
            temp1 /= gcd;
            temp2 /= gcd;
        }
    }
    return gcd;
}

int main()
{
    int number1, number2;
    printf("Enter two positive integers: ");
    scanf("%d %d", &number1, &number2);
    if (number1 < 0 || number2 < 0)
    {
        printf("Error: n must be positive.\n");
        return 0;
    }
    int gcd = 0;
    int i = 1;

    printf("Select the algorithm to be used:\n");
    printf("1. Euclid's algorithm\n");
    printf("2. Consecutive integer checking algorithm\n");
    printf("3. Middle school procedure\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        gcd = Euclid(number1, number2);
        printf("The GCD of %d and %d is %d\n", number1, number2, gcd);
        break;
    case 2:
        gcd = Consecutive_integer_checking(number1, number2);
        printf("The GCD of %d and %d is %d\n", number1, number2, gcd);
        break;
    case 3:
        gcd = primeFactorisation_method(number1, number2);
        printf("The GCD of %d and %d is %d\n", number1, number2, gcd);
        break;
    default:
        printf("Invalid choice.\n");
        break;
    }
    return 0;
}