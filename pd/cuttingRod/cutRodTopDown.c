#include <stdio.h>
#include <stdlib.h>
#define INFINITY -1000000

int *p;
int *r;


int max(int a, int b) { return a > b ? a : b; }


int cuttingRod(int p[], int r[], int n) {

    if (r[n] >= 0) return r[n];
    if (n == 0) return 0;

    int q = INFINITY;

    for (int i = 1; i <= n; ++i)
        q = max(q, p[i] + cuttingRod(p, r, n - i));

    r[n] = q;    
    return q;
}


int main() {

    int p[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n = 10;

    r = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; ++i) r[i] = INFINITY;
    
    int ans = cuttingRod(p, r, n);     // 30
    printf("===== Cutting Rod Top Down =====\n");
    printf("Maximum Recipe: R$ %d\n", ans);

    free(r);

    return 0;
}
