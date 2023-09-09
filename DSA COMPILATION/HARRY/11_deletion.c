#include <stdio.h>
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void indDeletion(int arr[], int size, int index)
{
    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
}
int main()
{
    int arr[100] = {1, 5, 8, 15, 7};
    int size = 5, index = 0;
    display(arr, size);
    indDeletion(arr, size, index);
    size-=1;
    display(arr, size);
}