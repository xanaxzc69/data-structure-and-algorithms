#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// generate array
double* generateArray(int n) {
    double *arr = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
        arr[i] = ((double)rand()/RAND_MAX)*10 - 5;
    return arr;
}

// create matrix
double** createMatrix(int rows, int cols) {
    double** matrix = malloc(rows * sizeof(double*));

    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(double));
    }

    return matrix;
}

// bubble sort
void bubbleSort(double *arr, int n, int asc) {
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - i - 1; j++){
            int cond = asc ? arr[j] > arr[j+1] : arr[j] < arr[j+1];
            if(cond){
                double t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
}

// max in columns
double* maxInColumns(double** matrix, int rows, int cols){
    double *max = malloc(cols * sizeof(double));

    for(int j = 0; j < cols; j++){
        max[j] = matrix[0][j];
        for(int i = 1; i < rows; i++){
            if(matrix[i][j] > max[j])
                max[j] = matrix[i][j];
        }
    }

    return max;
}

// free memory
void freeMemory(double* A, double** matrix, double* max, int rows){
    free(A);

    for(int i = 0; i < rows; i++)
        free(matrix[i]);

    free(matrix);
    free(max);
}