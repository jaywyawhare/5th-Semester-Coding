#include <stdio.h>
#include <stdlib.h>
#include "my_functions.h"

int main()
{
    int power;
    printf("Enter the power :");
    scanf("%d", &power);
    int base = rand() % 10;
    printf("The base is %d\n", base);
    printf("The power is %d\n", power);
    powerFunction(power, base);
    return 0;
}
