
#include <stdlib.h>
#include "functions.h"

double* generateArray(int n) {
    double *arr = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
        arr[i] = ((double)rand()/RAND_MAX)*10 - 5;
    return arr;
}

// Task 1: create matrix
double** createMatrix(int rows, int cols) {
    double** matrix = (double**)malloc(rows * sizeof(double*));

    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
    }

    return matrix;
}

void bubbleSort(double *arr, int n, int asc) {
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++){
            int cond = asc ? arr[j]>arr[j+1] : arr[j]<arr[j+1];
            if(cond){
                double t=arr[j]; arr[j]=arr[j+1]; arr[j+1]=t;
            }
        }
}

double* maxInColumns(double **B, int rows){
    double *max = malloc(cols * sizeof(double));
    for(int j=0;j<4;j++){
        max[j]=B[0][j];
        for(int i=1;i<rows;i++)
            if(B[i][j]>max[j]) max[j]=B[i][j];
    }
    return max;
}

void freeMemory(double** matrix, int rows, int cols){
    free(A);
    for(int i=0;i<rows;i++) free(B[i]);
    free(B);
    free(max);
}
// Task 2: print matrix
void printMatrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}
// Task 3: free memory
void freeMatrix(double** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}