#include <stdio.h>
#include <stdlib.h>

char text1[7] = {'A','T','C','T','G','A','T'};
char text2[7] = {'T','G','C','A','T','T','A'};

int max(int a, int b) { return a > b ? a : b; }

int longestCommonSubsequence(int m, int n) {

    // Initialize a (m + 1) x (n + 1) matrix with 0's
    int **matrix = (int **)calloc(m + 1, sizeof(int *));
    for (int i = 0; i <= n; ++i) matrix[i] = (int *)calloc(n + 1, sizeof(int));

    // Traverse the matrix from the first position [0, 0] to the last [m - 1, n - 1]
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {

            // If characters are equal, matrix in that index receives the value from the left up diagonal value + 1)
            if (text1[i] == text2[j]) matrix[i][j] = 1 + matrix[i - 1][j - 1];

            // Else, matrix in that index receives the max value between the left and the up value
            else matrix[i][j] = max(matrix[i][j - 1], matrix[i - 1][j]);
        }
    }
    
    return matrix[m - 1][n - 1];
}

int main() {
 
    int ans = longestCommonSubsequence(8, 8);
    printf("===== Bottom Up =====\n");
    printf("Longest Common Subsequence = %d\n", ans);   // 4 = TCTA

    return 0;
}
