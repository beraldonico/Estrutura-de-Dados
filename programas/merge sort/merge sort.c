#include<stdio.h>
#include<stdlib.h>
#define min(a,b) (a<b)?a:b
#define max(a,b) (a>b)?a:b

int merge ( int * vector, int sizeA, int sizeB){
    int *vectorA;
    int *vectorB;
    vectorA = malloc(sizeof(int)*sizeA);
    if (vectorA == NULL){
        return 0;
    }
    vectorB = malloc (sizeof(int)*sizeB);
    if (vectorB == NULL){
        return 0;
    }
    int i;
    for(i = 0; i<sizeA; i++){
        vectorA[i] = vector[i];
    }
    for(i = 0; i<sizeB; i++){
        vectorB[i] = vector[i + sizeA];
    }
    int iV, iA, iB;
    iV = iA = iB = 0;
    for(iV = 0; iV < sizeA + sizeB ; iV++){
        if(iA == sizeA){
            vector[iV] = vectorB[iB++];
        }else if(iB == sizeB){
            vector[iV] = vectorA[iA++];
        }else{
            if(vectorA[iA] < vectorB[iB]){
                vector[iV] = vectorA[iA++];
            }else{
                vector[iV] = vectorB[iB++];
            }
        }
    }
    free(vectorA);
    free(vectorB);
    return 1;
}

///recursivo
void mergeSort( int * vector, int size){
    if( size < 2) {
        return;
    }
    int m = size + 0.5;
    mergeSort(vector,m);
    mergeSort(&(vector[m]), size - m);
    merge (vector ,m ,size - m);
}

///iterativo
void mergesort( int *vector, int size){
    int svs;
    for(svs = 1; svs <= size; svs *= 2){
        int i;
        for(i = 0; i < size; i += (2*svs)){
            int sizeA = min(size-i, 2*svs);
            int sizeB = max(0 , min(size-(i+svs), 2*svs));
            merge(&(vector[i]), sizeA, sizeB);
        }
    }
}

int main(){
    int vector[10] = {8,10,1,5,3,7,2,4,6,9};
    mergesort(vector, 10);
    int c;
    for(c =0;c<10;c++){
        printf("%i,", vector[c]);
    }
    printf("\n");
    int vetor[10] = {8,10,1,5,3,7,2,4,6,9};
    mergeSort(vetor, 10);
    for(c =0;c<10;c++){
        printf("%i,", vetor[c]);
    }
    printf("\n");
    return 0;
}
