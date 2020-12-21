#include<stdio.h>
#include<stdlib.h>

void insertionSort( int *vector, int vectorSize){
    int i;
    for( i = 1 ; i < vectorSize ; i ++){
        int aux = vector[i];
        int j;
        for(j = i - 1; j >= 0 && vector[j] > aux ; j--){
            vector[j +1] = vector[j];
        }
        vector[j+1] = aux;
        int c;
        for(c =0;c<10;c++){
            printf("%i,", vector[c]);
        }
        printf("\n");
    }
}

int main(){
    int vector[10] = {8,10,1,5,3,7,2,4,6,9};
    insertionSort(vector, 10);
    return 0;
}
