#include <stdio.h>
#include <cs50.h>

void arr2d(int arr2[], int len_i, int len_j);
void arr1d(int arr[], int len);


int main(void)
{
    int a[2][4] = {{1, 2, 3, 4}, {11, 12, 13, 14}};

//    arr2d(a, 2, 4);
}

void arr2d(int arr2[], int len_i, int len_j)
{
    printf("[");
    for (int i = 0; i < len_i; i++)
    {
        arr1d(arr2[i], len_j);
    }
    printf("]");
}


void arr1d(int arr[], int len)
{
    printf("[%i", arr[0]);
    for (int i = 1; i < len; i++)
    {
        printf(", %i", arr[i]);
    }
    printf("]\n");
}
