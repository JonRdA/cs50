#include<stdio.h>
#include<cs50.h>


int main(void)
{
	int n = get_int("Enter integer: ");

	string int_type;
	if (n % 2 == 0)
	{
		int_type = "even";
	}
	else
	{
		int_type = "odd";
	}

	printf("The number 'n' is an %s number.\n", int_type);
}


