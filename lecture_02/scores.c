#include <cs50.h>
#include <stdio.h>

int main(void)
{
	int score1 = 72;
	int score2 = 73;
	int score3 = 33;

	printf("Average: %.2f\n", (float) (score1 + score2 + score3) / 3);
}

