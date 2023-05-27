// WAP to find factorial using recursion using function

#include <stdio.h>

int factorial_recursion(int n)
{
    if (n >= 1)
    {
        return n * factorial_recursion(n - 1);
    }
    else
    {
        return 1;
    }
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial of %d is %d", n, factorial_recursion(n));
    return 0;
}