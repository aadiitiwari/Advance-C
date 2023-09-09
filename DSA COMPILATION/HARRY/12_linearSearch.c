#include <stdio.h>

int linearsearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == element)
            return i;
    return -1;
}

int main()
{
    int n = 8, e, i;
    printf("Enter the element to search in the array ");
    scanf("%d", &e);
    int arr[] = {4, 8, 10, 12, 15, 16, 2, 58};
    i = linearsearch(arr, n, e);
    printf("%d is found at %d th index in array .\n", e, i);
    return 0;
}