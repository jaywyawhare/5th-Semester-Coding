// Assume that you are given a rudimentary programming language which contains only
// four operators, viz., +, −, abs and div. + and − have their usual meanings, while div(a, b)
// returns the quotient of a/b and abs(a) returns the absolute value of a. Write a program to
// solve this problem by using a function max(a, b) that takes two integers a and b as input
// and returns the maximum of the two. Note that you can only use the operators provided;
// in particular, the constructs ”if”, “while”, or “for” are not available

#include <stdio.h>
#include <math.h>

int max(int a, int b)
{
    int max = ((a + b) + abs(a - b)) / 2;
    return max;
}

int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Maximum of %d and %d is %d\n", a, b, max(a, b));
    return 0;
}