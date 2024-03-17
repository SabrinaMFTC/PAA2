/*=======================================================
    Joao Pedro Rodrigues Vieira                 10403595
    Sabrina Midori Futami Teixeira de Carvalho  10410220
    Disciplina: Projeto e Analise de Algoritmos II
    Professor Leonardo Takuno
    Turma: 04G
=======================================================*/

#include <stdio.h>

char **createMatrix(int rows, int cols);
void readFile(FILE *file, char **matrix);
void writeFile(char *fileName, char **matrix, int rows, int cols);
void printMatrix(char **matrix, int rows, int cols);
void solveLabirinth(char **matrix, int rows, int cols, int i, int j);
void freeMatrix(char **matrix, int rows);