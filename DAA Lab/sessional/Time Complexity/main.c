#include <stdio.h>
#include <stdlib.h>

int recurssion(int n)
{
    if (n == 1)
        return 0;
    else
    {
        recurssion(n / 2);
    }
}
int main()
{
    int l, h;
    printf("Enter the Lenght and bredth of 2-D matrix : ");
    scanf("%d %d", &l, &h);
    int arr[l][h];
    printf("Enter the elements in 2D matrix :\n");
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < h; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("The 2D matrix is \n");
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < h; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < h; j++)
        {
            recurssion(arr[i][j]);
        }
    }

    return 0;
}
