#include <stdio.h>
#include <cs50.h>
#include <string.h>

int whereis(string elem, string arr[], int size);
bool isin(string elem, string arr[], int size);

int main(void)
{
	string namelist[3] = {"Jon", "Txema", "Sara"};
	string name = "Jon";

	// int result = whereis(name, namelist, 3);
	int result = isin(name, namelist, 3);
	printf("%i", result);
}

int whereis(string elem, string arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i], elem) == 0)
        {
        	printf("found");
            return i;
        }
    }
    return 100;
}


bool isin(string elem, string arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(elem, arr[i]) == 0)
        {
            return true;
        }
    }
    return false;
}
