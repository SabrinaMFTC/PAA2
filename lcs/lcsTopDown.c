#include <stdio.h>
#include <stdlib.h>

char text1[7] = {'A','T','C','T','G','A','T'};
char text2[7] = {'T','G','C','A','T','T','A'};
int memo[7][7];

int max(int a, int b) { return a > b ? a : b; }

void createMemo(int memo[7][7]) {
    for (int i = 0; i < 7; ++i)
        for (int j = 0; j < 7; ++j)
            memo[i][j] = -1;
}

int longestCommonSubsequence(int r, int c) {

    // Base case
    if (r < 0 || c < 0) return 0;

    // Check memo array
    if (memo[r][c] != -1) return memo[r][c];

    // Recursion
    if (text1[r] == text2[c])
        memo[r][c] = (1 + longestCommonSubsequence(r - 1, c - 1));
    else
        memo[r][c] = max(longestCommonSubsequence(r - 1, c), longestCommonSubsequence(r, c - 1));

    return memo[r][c];
}

int main() {
    
    createMemo(memo);

    int ans = longestCommonSubsequence(6, 6);
    printf("===== Top Down =====\n");
    printf("Longest Common Subsequence = %d\n", ans);   // 4 = TCTA

    return 0;
}
