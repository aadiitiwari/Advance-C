#include <stdio.h>

int main() {
    int n, m;

    printf("Enter the number of rows and columns of the array: ");
    scanf("%d %d", &n, &m);

    int arr[n][m];

    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != 0) {
                count++;
            }
        }
    }

    int sparseMatrix[count][3]; 
    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != 0) {
                sparseMatrix[index][0] = i;
                sparseMatrix[index][1] = j;
                sparseMatrix[index][2] = arr[i][j];
                index++;
            }
        }
    }

    printf("Sparse matrix in 3-tuple format:\n");
    printf("%d %d %d\n", n, m, count);
    for (int i = 0; i < count; i++) {
        printf("%d %d %d\n", sparseMatrix[i][0], sparseMatrix[i][1], sparseMatrix[i][2]);
    }

    int transposeMatrix[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            transposeMatrix[i][j] = arr[j][i];
        }
    }

    printf("Transpose matrix: \n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", transposeMatrix[i][j]);
        }
        printf("\n");
    }

    int transposesparseMatrix[count][3]; 
    int index1 = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (transposeMatrix[i][j] != 0) {
                transposesparseMatrix[index1][0] = i;
                transposesparseMatrix[index1][1] = j;
                transposesparseMatrix[index1][2] = transposeMatrix[i][j];
                index1++;
            }
        }
    }
    
    printf("Transpose sparse matrix in 3-tuple format:\n");
    printf("%d %d %d\n", m, n, count);
    for (int i = 0; i < count; i++) {
        printf("%d %d %d\n", transposesparseMatrix[i][0], transposesparseMatrix[i][1], transposesparseMatrix[i][2]);
    }

    return 0;
}