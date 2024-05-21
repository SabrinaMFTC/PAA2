#include <stdio.h>
#include <stdlib.h>
#define INFINITY -1000000


int max(int a, int b) { return a > b ? a : b; }


int cuttingRod(int p[], int n) {

    int *r = (int *)calloc((n + 1), sizeof(int));
    
    int q;

    for (int j = 1; j <= n; ++j) {
        q = INFINITY;

        for (int i = 1; i <= j; ++i)
            q = max(q, p[i] + r[j - i]);
        
        r[j] = q;
    }
    
    return r[n];
}


int main() {

    int p[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n = 10;

    int ans = cuttingRod(p, n);     // 30
    printf("===== Cutting Rod Bottom Up =====\n");
    printf("Maximum Recipe: R$ %d\n", ans);

    return 0;
}
