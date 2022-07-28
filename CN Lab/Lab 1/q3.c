// WAP to input a sentance and print the avarage number of letters in each word, where spaces are not uniform

#include <stdio.h>
#include <string.h>
double length(const char *string);
int main()
{
    char string[100];
    int i = 0;
    double avglen;
    printf("Enter Statement:");
    while ((string[i] = getchar()) != '\n')
        i++;
    string[i] = '\n';
    avglen = length(string);
    printf("average length of word is:%f.\n ", avglen);
}
double length(const char *string)
{
    int charcount = 0;
    int wordcount = 1;
    while (*string != '\n')
    {
        if (*string != ' ')
            charcount++;
        else if (*string == ' ')
            wordcount++;
        string++;
    }
    return (double)charcount / wordcount;
}