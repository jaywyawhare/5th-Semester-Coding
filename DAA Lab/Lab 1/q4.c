// Write a program that takes three variable (a, b. c) as separate parameters and rotates the values stored so that value a goes to be, b, b to c and c to a by using SWAP(x,y) function that swaps/exchanges the numbers x & y.

#include <stdio.h>

int swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a, b, c;
    printf("Enter value of a : ");
    scanf("%d", &a);
    printf("\nEnter value of b : ");
    scanf("%d", &b);
    printf("\nEnter value of c : ");
    scanf("%d", &c);
    swap(&a, &b);

    swap(&b, &c);
    swap(&a, &c);
    printf("\nAfter swapping, the values are: a = %d, b = %d, c = %d", a, b, c);
    return 0;
}