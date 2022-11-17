// find number of words in string with ununiform spaces without counting spaces as words

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];
    printf("Enter string: ");
    gets(str);
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            count++;
        }
    }
    printf("Number of words: %d", count);
    return 0;
}