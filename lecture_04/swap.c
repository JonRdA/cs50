// Swaps two integers using pointers

#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    // Pointers passed as args, `&` address of
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}

// Arguments are pointers to an int
void swap(int *a, int *b)
{
    int temp = *a;
    // Put in the addres of 'a' what is in the address of 'b'
    *a = *b;
    *b = temp;
}

