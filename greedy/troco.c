#include <stdio.h>
#include <stdlib.h>


void print(int s[], int n) {
    for (int i = 0; i < n; ++i) printf("%d ", s[i]);
    printf("\n");
}


int calcCoins(int change, int coins[], int n, int *s) {
    int i = n - 1;
    int j = 0;

    while (i >= 0 && change > 0) {
        if (coins[i] <= change) {
            change = change - coins[i];
            s[j] = coins[i];
            ++j;
        } else --i;
    }
    if (change == 0) {
        print(s, j);
        return 1;
    } else return 0;
}


int main() {
    int change = 12;
    int coins[3] = {1, 2, 5};
    int n = 3;

    int *s = (int*)calloc(change, sizeof(int));

    int ans = calcCoins(change, coins, n, s);

    if (!ans) printf("There is no solution.\n");
    
    return 0;
}
