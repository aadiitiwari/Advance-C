#include <stdio.h>

int binarysearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
            return mid;
        if (arr[mid] < element)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int s, e, i;
    printf("Enter the element to search in the array ");
    scanf("%d", &e);
    int arr[] = {4, 8, 10, 12, 15, 16, 54, 58};
    s = sizeof(arr) / sizeof(int);
    i = binarysearch(arr, s, e);
    printf("%d is found at %d th index in array .\n", e, i);
    return 0;
}