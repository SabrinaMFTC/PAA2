#include <stdio.h>
#include <stdlib.h>


void print(int *a, int n) {
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");
}


int frog(int *s, int p[], int n, int d) {
    s[0] = p[0];
    int last = p[0];
    int j = 1;

    for (int i = 1; i < n; ++i) {
        if (p[i] - last > d) {
            last = p[i - 1];
            s[j] = last;
            j++;
        } 
    }
    s[j] = p[n - 1];
    print(s, j + 1);
}


int main() {

    // int p[4] = {1, 2, 3, 4};        // 1 2 3 4
    // int n = 4;
    // int delta = 1;

    int p[6] = {1, 2, 3, 5, 6, 7};  // 1 3 5 7
    int n = 6;
    int delta = 2;

    int *s = (int *)calloc(n, sizeof(int));

    frog(s, p, n, delta);
    free(s);

    return 0;
}
