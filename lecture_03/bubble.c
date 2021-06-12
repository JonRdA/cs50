// Jon attempt at implementing bubble sort

#include <stdio.h>
#include <cs50.h>

void print_array(int arr[], int size);
void bubble_sort(int arr[], int size);

int main(void)
{
    int a[10] = {3, 4, 6, 5, 7, 8, 1, 2, 9, 0};

    print_array(a, 10);
    bubble_sort(a, 10);
    print_array(a, 10);
}


void bubble_sort(int arr[], int size)
{
    int tmp;
    bool swap;
    do
    {
        swap = false;
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                tmp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = tmp;
                swap = true;
            }
        }
    }
    while (swap);
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
