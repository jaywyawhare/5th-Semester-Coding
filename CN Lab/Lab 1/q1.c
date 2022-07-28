// WAP to to display result of two number based on operator using function

#include <stdio.h>

int add(int a, int b)
{
    printf("%d", a + b);
}
int sub(int a, int b)
{
    printf("%d", a - b);
}
int mult(int a, int b)
{
    printf("%d", a * b);
}
int div(int a, int b)
{
    printf("%d", a / b);
}
int mod(int a, int b)
{
    printf("%d", a % b);
}

int main()
{
    int a, b, c;
    char op;
    printf("Enter two numbers and operator: ");
    scanf("%d %d %c", &a, &b, &op);
    switch (op)
    {
    case '+':
        add(a, b);
        break;
    case '-':
        sub(a, b);
        break;
    case '*':
        mult(a, b);
        break;
    case '/':
        div(a, b);
        break;
    case '%':
        mod(a, b);
        break;
    default:
        printf("Invalid operator");
    }
    return 0;
}
