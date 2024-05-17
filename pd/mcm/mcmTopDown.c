#include <stdio.h>
#include <stdlib.h>
#define INFINITY 1000000

int **memo;

int min(int a, int b) { return a < b ? a : b; }

int matrixChainMemoised(int *p, int i, int j) {

    if (i == j) return 0;

    if (memo[i][j] != -1) return memo[i][j];

    memo[i][j] = INFINITY;

    for (int k = i; k < j; ++k) {
        memo[i][j] = min(memo[i][j], matrixChainMemoised(p, i, k) + matrixChainMemoised(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
    }

    return memo[i][j];
}

int main() {

    // Matrix dimensions: A = A1 (200 x 2) x A2 (2 x 30) x A3 (30 x 20) x A4 (20 x 5)
    int p[5] = {200, 2, 30, 20, 5};
    int n = sizeof(p) / sizeof(p[0]);

    memo = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i < n + 1; ++i)
        memo[i] = (int *)malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            memo[i][j] = -1;

    int ans = matrixChainMemoised(p, 1, n - 1);
    printf("========== Top Down ==========\n");
    printf("Minimum number of multiplications = %d\n", ans);

    for (int i = 0; i <= n; ++i) free(memo[i]);
    free(memo);

    return 0;
}
