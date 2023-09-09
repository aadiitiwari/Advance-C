#include <stdio.h>
void display(int arr[], int size)
{
    //CODE FOR TRAVERSAL 
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indInsertion(int arr[], int size, int element, int capacity, int index)
{
    //CODE FOR INSERTION
    if (size >= capacity)
        return -1;
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}
int main()
{
    int capacity = 100, size = 5, index = 3, element = 45;
    int arr[100] = {7, 8, 12, 27, 88};
    display(arr, size);
    indInsertion(arr, size, element, capacity, index);
    size+=1;
    display(arr, size);
    return 0;
}