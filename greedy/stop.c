#include <stdio.h>
#include <stdlib.h>


int *stop(int p[], int n, int c, int *ls) {
    // Array of stops
    int *s = (int *)calloc(n, sizeof(int));

    int lastStop = 0;

    for (int i = 1; i < n; ++i) {
        if (p[i] - lastStop > c) {
            lastStop = p[i - 1];
            s[*ls] = p[i - 1];
            (*ls)++;
        }
    }
    s[*ls] = p[n - 1];
    (*ls)++;
    return s;
}


void print(int *a, int n) {
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");
}


int main() {

    int p[6] = {1, 2, 3, 5, 6, 7};  // 2 3 5 7
    int n = 6;
    int c = 2;
    int ls = 0;

    int *ans = stop(p, n, c, &ls);
    print(ans, ls);

    return 0;
}
