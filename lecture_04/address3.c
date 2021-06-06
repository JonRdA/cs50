#include <stdio.h>

int main (void)
{
	int n = 50;
	int *p = &n;
	printf("%p This is the pointer's value\n", p);
	printf("%i This is the ingeger's value\n", *p);
}

