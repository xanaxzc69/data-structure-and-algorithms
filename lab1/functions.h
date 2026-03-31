
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

double* generateArray(int n);
double** createMatrix(double *A, int rows);
void bubbleSort(double *arr, int n, int asc);
double* maxInColumns(double **B, int rows);
void freeMemory(double *A, double **B, double *max, int rows);

#endif
