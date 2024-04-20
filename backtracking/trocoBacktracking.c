#include <stdio.h>
#include <stdlib.h>


void print(int s[], int n) {
    for (int i = 0; i < n; ++i) printf("%d ", s[i]);
    printf("\n");
}


void calcCoins(int change, int c[], int lc, int *s, int ls) {

    int *p = (int*)calloc(change, sizeof(int)); // array of possible solutions
    int lp = 0;     // size of array p
    
    int i = lc - 1;
    int newChange = change;

    while (i >= 0 && newChange > 0) {
        if (c[i] <= newChange) {
            newChange = newChange - c[i];
            p[lp++] = c[i];
        } else --i;
    }
    // if array of possible solution is shorter than array of best solution
    // best solution array receives possible solution array
    if (lp < ls) {
        ls = lp;
        for (int i = 0; i < ls; ++i) s[i] = p[i];
    }

    // when array of coins is over, print best solution array
    if (lc - 1 < 0) {
        printf("Best Solution: ");
        print(s, sizeof(s) / sizeof(int));
        free(p);
        return;
    }

    // when change reaches 0, recursively call function starting from the coin before
    if (newChange == 0) calcCoins(change, c, lc - 1, s, ls);
}


int main() {

    int change = 8;
    
    int c[3] = {1, 4, 6};   // array of c
    int lc = 3;             // size of array c
        
    int *s = (int*)calloc(change, sizeof(int)); // array of best solution
    int ls = change;        // size of array s

    calcCoins(change, c, lc, s, ls);
    free(s);
    
    return 0;
}
