#include <stdio.h>

void changeval(int i);

int main(void)
{
    int a = 7;
    int b = 10;

    printf("'a' value: %i\n", a);
    printf("'b' value: %i\n", b);

    changeval(a);
    changeval(b);

    printf("'a' value: %i\n", a);
    printf("'b' value: %i\n", b);
}

void changeval(int i)
{
    i = i * 2;
}


