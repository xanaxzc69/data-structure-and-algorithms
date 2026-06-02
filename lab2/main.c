void sortEvenOdd(int *array, int size){
    for(int i=0;i<size-1;i++)
        for(int j=0;j<size-i-1;j++)
            if(array[j]>array[j+1]){
                int t=array[j];
                array[j]=array[j+1];
                array[j+1]=t;
            }

    int *tmp=malloc(size*sizeof(int));
    int k=0;

    for(int i=0;i<size;i++)
        if(array[i]%2==0) tmp[k++]=array[i];

    for(int i=size-1;i>=0;i--)
        if(array[i]%2!=0) tmp[k++]=array[i];

    for(int i=0;i<size;i++) array[i]=tmp[i];
    free(tmp);
}

void removeLessThanX(int *array, int size, int threshold){
    int k=0;
    for(int i=0;i<size;i++)
        if(array[i]>threshold) array[k++]=array[i];

    while(k<size) array[k++]=0;
}