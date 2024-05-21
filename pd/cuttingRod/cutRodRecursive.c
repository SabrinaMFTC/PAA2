#include <stdio.h>
#define INFINITY -1000000


int max(int a, int b) { return a > b ? a : b; }


int cuttingRod(int p[], int n) {
    if (n == 0) return 0;

    int q = INFINITY;

    for (int i = 1; i <= n; ++i)
        q = max(q, p[i] + cuttingRod(p, n - i));
    
    return q;
}


int main() {

    int p[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n = 10;

    int ans = cuttingRod(p, n);     // 30
    printf("===== Cutting Rod Recursive =====\n");
    printf("Maximum Recipe: R$ %d\n", ans);

    return 0;
}
