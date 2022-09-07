#include <stdio.h>
#include "my_functions.h"

int main()
{
    int size;
    printf("Enter the size of array :");
    scanf("%d", &size);
    randomArray(size);
    return 0;
};
