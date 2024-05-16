#include <stdio.h>
#include <stdlib.h>

char text1[7] = {'A','T','C','T','G','A','T'};
char text2[7] = {'T','G','C','A','T','T','A'};

int max(int a, int b) { return a > b ? a : b; }

int longestCommonSubsequence(int i, int j) {
    // Base case
    if (i == 0 || j == 0) return 0;

    // Recursion
    if (text1[i] == text2[j]) return (1 + longestCommonSubsequence(i - 1, j - 1));
    else return max(longestCommonSubsequence(i - 1, j), longestCommonSubsequence(i, j - 1));
}

int main() {
    
    int ans = longestCommonSubsequence(7, 7);
    printf("===== Recursive =====\n");
    printf("Longest Common Subsequence = %d\n", ans);   // 4 = TCTA

    return 0;
}
