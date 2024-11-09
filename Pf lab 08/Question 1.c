#include <stdio.h>

int main() {
    int n = 3;  
    int A[n][n];  
    int i, j;
    int rowsum[n];  
    int colsum[n];  

    printf("Enter the elements of the 3x3 matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        rowsum[i] = 0;
        colsum[i] = 0;
        for (j = 0; j < n; j++) {
            rowsum[i] += A[i][j];  
            colsum[i] += A[j][i];  
        }
    }

    for (i = 0; i < n; i++) {
        printf("Row %d sum = %d\n", i + 1, rowsum[i]);
    }

    for (i = 0; i < n; i++) {
        printf("Column %d sum = %d\n", i + 1, colsum[i]);
    }

    return 0;
}
