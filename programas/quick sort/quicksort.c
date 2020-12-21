#include<stdio.h>
#include<stdlib.h>

int separa( int *vetor, int tam){
    if(tam <= 1 ){
        return 0;
    }
    int i = 0;
    int f = tam - 1;
    while(f > i){
        for(; i < tam && vetor[i] < vetor[0]; i++);
        for(; f > 0 && vetor[f] >= vetor[0]; f--);
        if(f > i){
            int temp = vetor[i];
            vetor[i] = vetor[f];
            vetor[f] = temp;
        }
    }
    if(f!= 0){
        int temp = vetor[f];
        vetor[f] = vetor[0];
        vetor[0] = temp;
    }
    return f;
}

void quicksort(int *vetor, int tam){
    int p = separa(vetor, tam);
    quicksort(vetor, p);
    quicksort(vetor +(p+1), tam - p -1);
}

int main(){
    int vector[10] = {8,10,1,5,3,7,2,4,6,9};
    quicksort(vector, 10);
    int c;
    for(c =0;c<10;c++){
        printf("%i,", vector[c]);
    }
    printf("\n");
    return 0;
}

