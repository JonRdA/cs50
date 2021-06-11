#include <stdio.h>

int main(void)
{
    int x;
    printf("x: ");
    // Address of x needs to be passed to scanf so it can change its value
    scanf("%i", &x);
    printf("x: %i\n", x);
}
