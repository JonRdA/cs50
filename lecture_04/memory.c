#include <stdlib.h>
#include <stdio.h>


void f(void)
{
    int *x = malloc(10 * sizeof(double));
    x[1] = 90;
    free(x);
    printf("%i\n", x[0]);
    printf("%i\n", x[1]);
}

int main(void)
{
    f();
    return 0;
}

