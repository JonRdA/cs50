#include <stdio.h>
#include <cs50.h>

const int N = 3;

int main(void)
{
	int scores[3];
	scores[0] = 72;
	scores[1] = 73;
	scores[2] = 33;

	float avg = (scores[0] + scores[1] + scores[2]) / N;
	printf("Scores are: %.2f\n", avg);
}

