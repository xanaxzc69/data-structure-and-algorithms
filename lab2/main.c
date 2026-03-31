
#include <stdio.h>
#include <stdlib.h>

void sortEvenOdd(int *A,int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(A[j]>A[j+1]){
                int t=A[j];A[j]=A[j+1];A[j+1]=t;
            }

    int *tmp=malloc(n*sizeof(int));
    int k=0;

    for(int i=0;i<n;i++)
        if(A[i]%2==0) tmp[k++]=A[i];

    for(int i=n-1;i>=0;i--)
        if(A[i]%2!=0) tmp[k++]=A[i];

    for(int i=0;i<n;i++) A[i]=tmp[i];
    free(tmp);
}

void removeLessThanX(int *A,int n,int X){
    int k=0;
    for(int i=0;i<n;i++)
        if(A[i]>X) A[k++]=A[i];
    while(k<n) A[k++]=0;
}

int main(){
    int A[10]={5,2,8,1,3,6,7,4,9,0};

    sortEvenOdd(A,10);
    removeLessThanX(A,10,4);

    for(int i=0;i<10;i++)
        printf("%d ",A[i]);

    return 0;
}
