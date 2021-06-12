// Jon trying to replicate linux 'cp' command

#include <stdio.h>

int main(int argc, char *argv[])
{
    // Copy from first file (argument) to second
    if (argc != 3)
    {
        return 1;
    }

    // Open original file to copy from
    FILE *of = fopen(argv[1], "r");

    // Create new destination file
    FILE *nf = fopen(argv[2], "w");
    if (nf == NULL)
    {
        return 1;
    }

    // Copy all characters
    char c;
    while ((c = fgetc(of)) != EOF)
    {
        fputc(c, nf);
    }
}

