#include <stdio.h>
#include "functions.h"

void sudoku(int s[N][N], int i, int j) {
    int v[N];
    numbers(v);

    int a[N];
    auxiliar(a);

    if (i < N && j < N && s[i][j] == 0) {
        // Check row and column
        for (int m = 0; m < N; ++m) {
            for (int n = 0; n < N; ++n) {
                if (v[m] == s[i][n]) {
                    a[m] = 0;
                    printf("\n* Checking index(%d, %d)\n", i, j);
                    printf("- Row: Could not add %d\n", v[m]);
                }
                else if (v[m] == s[n][j]) {
                    a[m] = 0;
                    printf("\n* Checking index(%d, %d)\n", i, j);
                    printf("- Column: Could not add %d\n", v[m]);
                }
            }
        }
        // Store value in sudoku
        for (int k = 0; k < N; ++k) {
            if (a[k] == 1) {
                s[i][j] = v[k];
                printf("\n+ Added value %d at index(%d, %d)\n", v[k], i, j);
                printSudoku(s);
            }
        }
    }

    if (j + 1 < N) sudoku(s, i, j + 1);
    else if (i + 1 < N) sudoku(s, i + 1, 0);
    else {
        printf("* Solved Sudoku\n");
        printSudoku(s);
        return;
    };
}

void numbers(int v[]) {
    for (int i = 0; i < N; ++i) v[i] = i + 1;
}

void auxiliar(int a[]) {
    for (int i = 0; i < N; ++i) a[i] = 1;
}

void printSudoku(int s[N][N]) {
    for (int i = 0; i < N; ++i) {
        printf("[ ");
        for (int j = 0; j < N; ++j) printf("%d ", s[i][j]);
        printf("]\n");
    }
    printf("\n");
}
