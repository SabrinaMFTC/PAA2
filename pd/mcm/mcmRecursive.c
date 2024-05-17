#include <stdio.h>
#define INFINITY 1000000

int matrixChainRecursive(int p[], int i, int j) {
    // Base case
    if (i == j) return 0;

    // Recursion
    int min = INFINITY;
    int count;

    for (int k = i; k < j; ++k) {
        count = matrixChainRecursive(p, i, k) + matrixChainRecursive(p, k + 1, j) + p[i - 1] * p[k] * p[j];

        if (count < min)
            min = count;
    }

    return min;
}

int main() {

    // Matrix dimensions: A = A1 (200 x 2) x A2 (2 x 30) x A3 (30 x 20) x A4 (20 x 5)
    int p[5] = {200, 2, 30, 20, 5};
    int n = sizeof(p) / sizeof(p[0]);

    int ans = matrixChainRecursive(p, 1, n - 1);
    printf("========== Recursive ==========\n");
    printf("Minimum number of multiplications = %d\n", ans);

    return 0;
}
