#include <stdio.h>
#define INFINITY 1000000

int matrixChainOrder(int p[], int n) {

    int m[n][n];
    int min;

    for (int i = 1; i < n; ++i)
        m[i][i] = 0;

    for (int l = 2; l < n; ++l) {
        for (int i = 1; i < n - l + 1; ++i) {
             int j = i + l - 1;
             m[i][j] = INFINITY;

             for (int k = i; k <= j - 1; ++k) {
                min = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (min < m[i][j])
                    m[i][j] = min;
             }
        }
    }
    
    return m[1][n - 1];
}

int main() {

    // Matrix dimensions: A = A1 (200 x 2) x A2 (2 x 30) x A3 (30 x 20) x A4 (20 x 5)
    int p[5] = {200, 2, 30, 20, 5};
    int n = sizeof(p) / sizeof(p[0]);

    int ans = matrixChainOrder(p, n);
    printf("========== Bottom Up ==========\n");
    printf("Minimum number of multiplications = %d\n", ans);

    return 0;
}
