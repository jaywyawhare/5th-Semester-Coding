// Write a program using a function for computing ⌊√n⌋ for any positive integer. Besides
// assignment and comparison, your algorithm may only use the four basic arithmetic
// operations.
// Hints: In number theory, the integer square root (isqrt) of a positive integer n is the
// positive integer m which is the greatest integer less than or equal to the square root of n,
// isqrt(n)=⌊√n⌋

#include <stdio.h>
#include <stdlib.h>

int square_root(int n)
{
    // Too late to code this one.
}

int main()
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    if (n < 0)
    {
        printf("Error: n must be positive.\n");
        return 0;
    }
    printf("The square root of %d is %d\n", n, square_root(n));
    return 0;
}