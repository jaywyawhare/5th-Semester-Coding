#include <stdio.h>
#include <limits.h>

void fileToString(char *fileName, char *str)
{
    FILE *file = fopen(fileName, "r");
    fgets(str, INT_MAX, file);
    fclose(file);
}