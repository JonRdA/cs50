#include<stdio.h>
#include<cs50.h>

int get_positive_integer(void);

int main(void){
	int pos_int = get_positive_integer();
	printf("The entered and accepted positive integer is: %i", pos_int);
}

int get_positive_integer(void){
	int n;
	do{
		n = get_int("Enter positive integer: ");
	}
	while (n < 1);
	return n;
}

