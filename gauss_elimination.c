#include <stdio.h>
#include <math.h>

void elimination(int n, float arr[n][n + 1])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            float factor = arr[j][i] / arr[i][i];
            for (int k = i; k <= n; k++)
            {
                arr[j][k] -= factor * arr[i][k];
            }
        }
    }
}
void printans(int n, float ans[n], float arr[n][n + 1])
{
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = arr[i][n];
        for (int j = i + 1; j < n; j++)
        {
            ans[i] -= arr[i][j] * ans[j];
        }
        ans[i] /= arr[i][i];
    }
}
int main()
{
    int n;
    printf("Enter number of equations: ");
    scanf("%d", &n);
    float arr[n][n + 1];
    printf("Enter the coefficients and constants:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            scanf("%f", &arr[i][j]);
        }
    }
    elimination(n, arr);

    float ans[n];

    printans(n, ans, arr);

    printf("Solution\n");
    for (int i = 0; i < n; i++)
    {
        printf("x[%d] = %.2f\n", i, ans[i]);
    }
}
