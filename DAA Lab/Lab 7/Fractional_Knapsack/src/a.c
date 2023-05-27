// Dedicate Length
// Nikhil wants to bring sofa(s) to his room. But
// he wants to dedicate the entire length of the room to the sofa(s).
// Now Nikhil's room length is W meters, and
// when he went to the shop he found out sofas of two types, one of length N
// and other of length M.
// Now, let Nikhil know how many sofas of the first and second type he
// should buy to reduce wastage of space. First minimize the space wastage
// then, if similar result arises always prefer the sofa with a larger
// length. In case N==M
// give preference to second sofa.Input format
// The first line contains an integer T, denoting the number of test cases.
// Each test case contains three integers W,N and M
// . Output format
// For every testcase print two integers a and b, number of sofa of type 1 and 2

// respectively.
// Constraints
// 1<=T<=10
// 1<=N,M,W<=10000
// Time Limit

// 1 second
// Example Input
// 1

// 24 3 5
// Output
// 3 3

// imp condtion minimise the space wastage

#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int w, n, m;
        scanf("%d %d %d", &w, &n, &m);
        // algorithm to minimise the wastage of space
        // INPUT 38 3 5
        // OUTPUT 1 7
        int a = w / n;
        int b = w / m;
        int c = w % n;
        int d = w % m;

        if (c == 0 && d == 0)
        {
            if (n > m)
            {
                printf("%d %d", a, 0);
            }
            else
            {
                printf("%d %d", 0, b);
            }
        }
        else if (c == 0 && d != 0)
        {
            printf("%d %d", a, 0);
        }
        else if (c != 0 && d == 0)
        {
            printf("%d %d", 0, b);
        }
        else
        {
            if (n > m)
            {
                printf("%d %d", a, b);
            }
            else
            {
                printf("%d %d", a, b);
            }
        }
        printf("%d %d", a, b);
    }
    return 0;
}