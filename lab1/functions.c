
#include <stdlib.h>
#include "functions.h"

double* generateArray(int n) {
    double *arr = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
        arr[i] = ((double)rand()/RAND_MAX)*10 - 5;
    return arr;
}

double** createMatrix(double *A, int rows) {
    double **B = malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        B[i] = malloc(4 * sizeof(double));
        for (int j = 0; j < 4; j++)
            B[i][j] = A[i*4+j];
    }
    return B;
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
    double *max = malloc(4*sizeof(double));
    for(int j=0;j<4;j++){
        max[j]=B[0][j];
        for(int i=1;i<rows;i++)
            if(B[i][j]>max[j]) max[j]=B[i][j];
    }
    return max;
}

void freeMemory(double *A, double **B, double *max, int rows){
    free(A);
    for(int i=0;i<rows;i++) free(B[i]);
    free(B);
    free(max);
}
