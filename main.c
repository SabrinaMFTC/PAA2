/*=======================================================
    Joao Pedro Rodrigues Vieira                 10403595
    Sabrina Midori Futami Teixeira de Carvalho  10410220
    Disciplina: Projeto e Analise de Algoritmos II
    Professor Leonardo Takuno
    Turma: 04G
=======================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main() {

    // Open original file, in read mode
    FILE *file = fopen("labirinth.txt", "r");

    if (file == NULL) {
        printf("The file \"labirinth.txt\" could not be opened.\n");
        return -1;
    } else printf("The file \"labirinth.txt\" was successfully opened.\n");
        
    // Read number of rows and columns
    int rows, cols;
    fscanf(file, "%d %d", &rows, &cols);

    // Dynamically allocate a matrix to store the labirinth
    char **matrix = createMatrix(rows, cols);

    // Read the file and store the labirinth in the matrix
    readFile(file, matrix);

    // Close file
    fclose(file);

    // Print the original matrix with the unsolved labirinth
    printf("\nOriginal Labirinth\n");
    printMatrix(matrix, rows, cols);

    // Solve the labirinth
    solveLabirinth(matrix, rows, cols, 1, 0);

    // Open the file that contains the solved labirinth, in read mode
    FILE *newFile = fopen("solvedLabirinth.txt", "r");

    if (newFile == NULL) {
        printf("The file \"solvedLabirinth.txt\" could not be opened.\n");
        return -1;
    } else printf("The file \"solvedLabirinth.txt\" was successfully opened.\n");

    // Read the new file and store the solved labirinth in the matrix
    readFile(newFile, matrix);

    // Close new file
    fclose(newFile);

    // Print the new matrix with the solved labirinth
    printf("\nSolved Labirinth\n");
    printMatrix(matrix, rows, cols);

    // Free matrix
    //freeMatrix(matrix, rows);

    return 0;
}
