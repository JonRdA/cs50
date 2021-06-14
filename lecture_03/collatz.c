#include <stdio.h>

// Return number of operations until it reaches 1 while doing:
// * if n is 1, stop
// * if n is even, `n/2`
// * if n is odd, `3*n + 1`

int collatz(int n);

int main(void)
{
    for (int i = 1; i < 10; i++)
    {
        int numcalls = collatz(i);
        printf("collatz(%i) =  %i\n", i, numcalls);
    }
}

int collatz(int n)
{
    if (n == 1)
        return 0;
    else if (n % 2 == 0)
        return collatz(n / 2) + 1;
    else
        return collatz(3 * n + 1) + 1;
}
