// Write a program that shows the use of substitution method for the computation
// of time complexity.
// 1.
// Example : Input
// { 3T(n-1), if n>0,
// T(n) = { 1, otherwise
// n represent the input size and on the basis of n, output should be display as
// OUTPUT :
// N=4
// T(n) =3X3X3X3(4-1)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printResult(int n)
{
    if (n > 0)
    {
        printf("3");
        if (n > 1)
        {
            printf("X");
            printResult(n - 1);
        }
    }
    else
    {
        printf("1");
    }
}
int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    if (n < 0)
    {
        printf("The value of n is invalid");
        exit(0);
    }

    printResult(n);
}