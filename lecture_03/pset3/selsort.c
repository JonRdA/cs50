#include <stdio.h>

void selsort(int arr[], int size);
void print_array(int arr[], int size);

int main(void)
{
    int list[5] = {1, 3, 5, 9, 1};
    print_array(list, 5);
    selsort(list, 5);
    print_array(list, 5);
}

void selsort(int arr[], int size)
{
    int max_index, temp;
    for (int i = 0; i < size; i++)
    {
        max_index = arr[i]; 
        for (int j = i; j < size; j++)
        {
            if (arr[j] > arr[max_index])
            {
                max_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[max_index];
        arr[max_index] = temp;
    }
}



void print_array(int arr[], int size)
{
    printf("[%i", arr[0]);

    for (int i = 1; i < size; i++)
    {
        printf(", %i", arr[i]);
    }

    printf("]\n");
}


