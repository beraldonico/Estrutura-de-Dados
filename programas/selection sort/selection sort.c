#include<stdio.h>
#include<stdlib.h>

void selectionSort ( int *vector, unsigned int vectorSize){
    int fst;
    for(fst = 0; fst < vectorSize -1; fst++){
        int smlr = fst;
        int i;
        for(i = fst + 1; i < vectorSize; i ++){
            if(vector[smlr] > vector[i]){
                smlr = i;
            }
        }
        if(smlr != fst){
            int aux = vector[fst];
            vector[fst] = vector[smlr];
            vector[smlr] = aux;
        }
        int c;
        for(c =0;c<10;c++){
            printf("%i,", vector[c]);
        }
        printf("\n");
    }
}

int main(){
    int vector[10] = {8,10,1,5,3,7,2,4,6,9};
    selectionSort(vector, 10);
    return 0;
}
