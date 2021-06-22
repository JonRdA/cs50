#include <stdio.h>
#include <cs50.h>

int main(void)
{
	string names[4];
	names[0] = "EMMA";
	names[1] = "RODRIGO";
	names[2] = "BRIAN";
	names[3] = "DAVID";

	for (int i = 0; i < 4; i++)
	{
		printf("%s\n", names[i]);
	}
	
	printf("%s\n", names[0]);
}

