#include <stdio.h>

int fact(int n);

int main(void)
{
    int n = 8;
    int q = fact(n);
    printf("Factorial of %i is: %i\n", n, q);
}

int fact(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}
