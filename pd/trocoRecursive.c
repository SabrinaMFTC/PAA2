#include <stdio.h>

#define INFINITY 1000000

int *m;

int min(int x, int y) {
    if (x < 0) return y;
    else if (y < 0) return x;
    else return x < y ? x : y;
}


int coins(int change, int *M, int n) {
    if (change == 0) return 0;
    else if (change < 0) return INFINITY;
    int menor = INFINITY;
    for (int i = 0; i < n; ++i) {
        menor = min(menor, coins(change - M[i], M, n) + 1);
    }
    return menor;
}

int main() {
    int change = 8;
    int M[] = {1, 4, 6};
    int n = 3;

    printf("Number of coins used: %d\n", coins(change, M, n));
    return 0;
}