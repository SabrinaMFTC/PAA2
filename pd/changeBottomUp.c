#include <stdio.h>
#define INFINITY 1000000
#define MAX 8

// coins values
int coins[] = {1, 4, 6};
// length of coins values array
int coinsLength = sizeof(coins) / sizeof(int);


int calcMin(int x, int y) {
    if (x < 0) return y;
    if (y < 0) return x;
    else return x < y ? x : y;
}


int countCoins(int change) {
    int tab[MAX];

    for (int i = 1; i < change; ++i) tab[i] = INFINITY;

    tab[0] = 0;

    for (int i = 0; i < change; ++i)
        for (int j = 0; j < coinsLength; ++j)
            if (i >= coins[j])
                tab[i] = calcMin(tab[i], tab[i - coins[j]] + 1);
        
    return tab[change - 1];
}


int main() {
    // total change
    int change = 8;

    printf("=== Change Bottom Up ===\nMinimum number of coins used: %d\n\n", countCoins(change));

    return 0;
}
