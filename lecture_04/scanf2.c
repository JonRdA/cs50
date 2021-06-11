#include <stdio.h>

int main(void)
{
    //char *s = NULL;
    char s[5];
    printf("s: ");
    // char *x is already an address so it can be passed in scanf without `&`
    scanf("%s", s);
    printf("s: %s\n", s);
}
