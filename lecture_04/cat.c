// Jon Tying to replicate linux 'cat' programm

#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    // Open file
    FILE *f = fopen(argv[1], "r");
    char c;
    while ((c = fgetc(f)) != EOF)
    {
        printf("%c", c);
    }
}
