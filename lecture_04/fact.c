#include <stdio.h>

int fact(int n);

int main(void)
{
    int n = 5;
    printf("\nThe factorial of %i is: %i\n", n, fact(n));
}

int fact(int n)
{
    printf("Calling fact(%i)\n", n);
    if (n == 1)
        return 1;
    else
        return fact(n - 1) * n;    
}
