#include <stdio.h>
#include <time.h>
#include "functions.h"

int main(){
    int n_values[] = {20,100,1000};
    FILE *f = fopen("output.txt","w");

    for(int k=0;k<3;k++){
        int n = n_values[k];

        int cols = 4;             
        int rows = n / cols;       

        double *A = generateArray(n);

    
        double **B = createMatrix(rows, cols);

    
        int index = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                B[i][j] = A[index++];
            }
        }

        clock_t start = clock();

    
        for(int i = 0; i < rows; i++){
            if(i % 2 == 0)
                bubbleSort(B[i], cols, 1);
            else
                bubbleSort(B[i], cols, 0);
        }

        double *max = maxInColumns(matrix, rows, cols);

        clock_t end = clock();
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

        size_t space = sizeof(double)*n + sizeof(double)*rows*cols;

        fprintf(f,"%d %d %lf %zu\n",k+1,n,time_spent,space);

        freeMemory(A, B, max, rows);
    }

    fclose(f);
    return 0;
}