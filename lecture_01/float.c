#include<stdio.h>
#include<cs50.h>

int main(void)
{
	float price = get_float("What is the original price\n");
	float new_price = price * 1.0625;
	printf("The total price is: %.2f\n", new_price);
}
