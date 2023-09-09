#include <stdio.h>
int main()
{
    int m, n;
    int i=0;
    int j=0;
    printf("Enter size of sparce matrix : ");
    scanf("%d%d", &m, &n);
    int arr[m][n];
    printf("\nEnter elements of sparce matrix: \n");
    int c = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);

            if (arr[i][j] != 0)
                c++;
        }
    }

    printf("Sparce matrix in 3 tuple format\n ");
    int s[c + 1][3];
    int k=1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] != 0){
            s[k][0]=i;
            s[k][1]=j;
            s[k][2]=arr[i][j];
            k++;
            }
        }
    }
    s[0][0]=m;
    s[0][1]=n;
    s[0][2]=c;

    for (i = 0; i < c+1; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t",s[i][j]);
        }
        printf("\n");
    }

    return 0;
}