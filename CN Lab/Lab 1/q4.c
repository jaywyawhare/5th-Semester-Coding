// WAP to store todays date using structure(dd,mm,yyyy) add some days with inputted date and display new date use time function

#include <stdio.h>

struct date
{
    int dd;
    int mm;
    int yyyy;
};

void add_days(struct date *d, int n)
{
    d->dd += n;
    if (d->dd > 31)
    {
        d->dd -= 31;
        d->mm++;
    }
    if (d->mm > 12)
    {
        d->mm -= 12;
        d->yyyy++;
    }
}

int main()
{
    struct date d;
    int n;
    printf("Enter date in dd/mm/yyyy format: ");
    scanf("%d/%d/%d", &d.dd, &d.mm, &d.yyyy);
    printf("Enter number of days to add: ");
    scanf("%d", &n);
    add_days(&d, n);
    printf("%d/%d/%d\n", d.dd, d.mm, d.yyyy);
    return 0;
}
