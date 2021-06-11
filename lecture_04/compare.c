#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = malloc(strlen(s));

    strcpy(t, s);

    t[0] = toupper(t[0]);
 
    printf("%s\n", s);
    printf("%s\n", t);

    free(t);
}
