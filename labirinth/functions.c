/*=======================================================
    Joao Pedro Rodrigues Vieira                 10403595
    Sabrina Midori Futami Teixeira de Carvalho  10410220
    Disciplina: Projeto e Analise de Algoritmos II
    Professor Leonardo Takuno
    Turma: 04G
=======================================================*/

#include <stdio.h>
#include <stdlib.h>

char **createMatrix(int rows, int cols) {
    
    char **matrix = (char **)calloc(rows, sizeof(char *));
    for (int i = 0; i < rows; i++) matrix[i] = (char *)calloc(cols, sizeof(char));
    return matrix;
}


void readFile(FILE *file, char **matrix) {

    int i = 0;
    while (!feof(file)) {
        fscanf(file, "%s", matrix[i]);
        ++i;
    } 
}   


void writeFile(char *fileName, char **matrix, int rows, int cols) {

    FILE *file = fopen(fileName, "wb");
    for (int i = 0; i < rows; ++i) fprintf(file, "%s\n", matrix[i]);
    fclose(file);
}


void printMatrix(char **matrix, int rows, int cols) {
    
    printf("\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) printf("%c", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}


void solveLabirinth(char **matrix, int rows, int cols, int i, int j) {
    
    // Base case
    if (matrix[i - 1][j] == 'S' || matrix[i + 1][j] == 'S' || matrix[i][j - 1] == 'S' || matrix[i][j + 1] == 'S') {
        writeFile("solvedLabirinth.txt", matrix, rows, cols);
        return;
    }

    // Recursion
    // Up
    if ((i - 1 >= 0) && (matrix[i - 1][j] == '.')) {
        matrix[i - 1][j] = 'o';
        solveLabirinth(matrix, rows, cols, i - 1, j);
        matrix[i - 1][j] = '.';
    }
    // Down
    if ((i + 1 < rows) && (matrix[i + 1][j] == '.')) {
        matrix[i + 1][j] = 'o';
        solveLabirinth(matrix, rows, cols, i + 1, j);
        matrix[i + 1][j] = '.';
    }
    // Left
    if ((j - 1 >= 0) && (matrix[i][j - 1] == '.')) {
        matrix[i][j - 1] = 'o';
        solveLabirinth(matrix, rows, cols, i, j - 1);
        matrix[i][j - 1] = '.';
    }
    // Right
    if ((j + 1 < cols) && (matrix[i][j + 1] == '.')) {
        matrix[i][j + 1] = 'o';
        solveLabirinth(matrix, rows, cols, i, j + 1);
        matrix[i][j + 1] = '.';
    }
}


void freeMatrix(char **matrix, int rows) {

    for (int i = 0; i < rows; ++i) free(matrix[i]);
    free(matrix);
}
