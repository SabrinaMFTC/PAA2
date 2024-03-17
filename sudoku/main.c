// Escreva um programa em linguagem C, que resolva o sudoku simples. Suponha que a tabela do sudoku já tenha algumas posições preenchidas.

#include <stdio.h>
#include "functions.h"
#define N 4

int main() {

    int s[N][N] = {{0, 2, 4, 0}, {1, 0, 0, 3}, {4, 0, 0, 2}, {0, 1, 3, 0}};
    int i = 0;
    int j = 0;

    sudoku(s, i, j);

    return 0;
}
