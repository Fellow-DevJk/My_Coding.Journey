#include <stdio.h>
#include <malloc.h>
#include <limits.h>

void print_optimal_parens(int **s, int i, int j)
{
    if (i == j)
        printf("A%d", i);
    else
    {
        printf("(");
        print_optimal_parens(s, i, s[i][j]);
        print_optimal_parens(s, s[i][j] + 1, j);
        printf(")");
    }
}

void MatrixChainOrder(int *arr, int n)
{
    int m[n][n];
    int **s = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        s[i] = malloc(sizeof(int));
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;
    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + ((arr[i - 1]) * (arr[k]) * (arr[j]));
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("The minimum number of scalar multiplications: %d\n", m[1][n - 1]);
    print_optimal_parens(s, 1, n - 1);
}

int main()
{
    int arr[] = {100, 50, 200, 100, 50, 400}; // you can change the inputs here
    int size = sizeof(arr) / sizeof(arr[0]);
    MatrixChainOrder(arr, size);
    return 0;
}