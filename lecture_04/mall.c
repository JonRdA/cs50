#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Statically otained integer
    int x = 8;
    int xx;

    // Dynamicalli obtained memory
    int *px = malloc(sizeof(int));

    // Print results
    printf("Pointer to xx: %p\n", &xx);
    printf("Value of to px: %i\n", *px);
    printf("Pointer to px: %p\n", px);
}
