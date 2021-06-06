#include<stdio.h>
#include<cs50.h>

int main(void)
{
	int n = get_int("Please enter integer:\n");

	if (n % 2 == 0)
	{
		printf("%i is an even number.\n", n);
	}
	else
	{
		printf("%i is an odd number.\n", n);
	}
}
