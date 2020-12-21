#include"HeapSort.h"

void criarheap(int *vet, int i, int f){
    int aux = vet[i];
    int j=i*2+1;
    while(j<=f){
        if(j<f){
            if(vet[j] < vet[j+1]){
                j=j+1;
            }
        }
        if(aux<vet[j]){
            vet[i] = vet[j];
            i=j;
            j=2*i+1;
        }
        else{
            j=f+1;
        }
    }
    vet[i] = aux;
}

void heapsort(int *vet, int n){
    int i, aux;
    for(i = (n-1)/2 ; i >= 0 ; i--){
        criarheap(vet,i,n-1);
    }
    for(i = n-1 ; i>= 1; i--){
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        criarheap(vet,0,i-1);
    }
}
