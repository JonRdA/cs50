#include<stdio.h>
#include<cs50.h>

int main(void)
{
	printf("You are at least %i days old!\n", get_int("What is your age?") * 365);
}

