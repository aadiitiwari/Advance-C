#include <stdio.h>
int nonzero_ele(int n, int arr[][n])
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
                count++;
        }
    }
    printf("the number of non zero elements are %d", count);
    return 0;
}

int upper_triangular_matrix(int n , int arr[][n])
{
    printf("\nUPPER TRIANGULAR MATRIX\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j>=i)
            printf("%d\t",arr[i][j]);
            else
            printf("\t");
        }
        printf("\n");
    }
    return 0;
}

int above_below_diagonal(int n , int arr[][n])
{
    printf("\nELEMENTS BELOW OR ABOVE DIAGONAL\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j==i)
            printf(" \t");
            else
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
int main()
{
    int n;
    printf("Enter size of the square matrix ");
    scanf("%d", &n);
    int arr[n][n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("The matrix is \n");

    for (j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            printf("%d\t", arr[j][k]);
        }
        printf("\n");
    }
    nonzero_ele(n,arr);
    upper_triangular_matrix(n,arr);
    above_below_diagonal(n,arr);
    return 0;
}