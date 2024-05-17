#include <stdio.h>
#define INFINITY 1000000

// coins values
int coins[] = {1, 4, 6};
// length of coins values array
int coinsLength = sizeof(coins) / sizeof(int);
// memoization array
int memo[] = {-1, -1, -1, -1, -1, -1, -1, -1};


int calcMin(int x, int y) {
    if (x < 0) return y;
    if (y < 0) return x;
    else return x < y ? x : y;
}


int countCoins(int change) {
    if (change == 0) return 0;

    if (change < 0) return INFINITY;

    if (memo[change - 1] != -1) return memo[change - 1];

    int min = INFINITY;

    for (int i = 0; i < coinsLength; ++i)
        min = calcMin(min, countCoins(change - coins[i]) + 1);
    
    return memo[change - 1] = min;
}


int main() {
    // total change
    int change = 8;

    printf("=== Change Top Down ===\nMinimum number of coins used: %d\n\n", countCoins(change));

    return 0;
}
