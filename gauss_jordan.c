#include <stdio.h>

#define N 3 // Number of variables

void printMatrix(float mat[][N + 1], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%0.2f\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void gaussJordan(float mat[][N + 1], int n)
{
    for (int i = 0; i < n; i++)
    {
        // Make the diagonal elements 1
        float divisor = mat[i][i];
        for (int j = i; j <= n; j++)
        {
            mat[i][j] /= divisor;
        }

        // Zero out the rest of the column
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                float factor = mat[j][i];
                for (int k = i; k <= n; k++)
                {
                    mat[j][k] -= factor * mat[i][k];
                }
            }
        }
    }
}

int main()
{
    float augmentedMatrix[N][N + 1];

    printf("Enter the augmented matrix (coefficients and constants):\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            scanf("%f", &augmentedMatrix[i][j]);
        }
    }

    printf("Original augmented matrix:\n");
    printMatrix(augmentedMatrix, N);

    gaussJordan(augmentedMatrix, N);

    printf("Augmented matrix after Gauss-Jordan elimination:\n");
    printMatrix(augmentedMatrix, N);

    printf("Solution:\n");
    for (int i = 0; i < N; i++)
    {
        printf("x%d = %0.2f\n", i + 1, augmentedMatrix[i][N]);
    }

    return 0;
}
