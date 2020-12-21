#include <stdio.h>
#include <stdlib.h>
#include"HeapSort.h"

int main(int argc, char *argv[]){
    if (argc != 2){
        printf("Argc Erro");
        return 0;
    }

    FILE *arq = fopen(argv[1], "r");

    if(arq == NULL)
        printf("Erro, nao foi possivel abrir o arquivo\n");
    else{
        int N = 1, Ta = 0, L, V;
        do{
            fscanf(arq, "%i ",&L);
            if(L == 1)
                fscanf(arq, "%i \n",&V);
            if(L == 1){
                Ta++;
            }
        }while(! feof(arq));

        int i = 0, vet[Ta], e, j, z = 0;
        if(arq == NULL)
            printf("Erro, nao foi possivel abrir o arquivo\n");
        FILE *arq = fopen(argv[1], "r");
        do{
            fscanf(arq, "%i \n",&L);
            if(L == 1)
                fscanf(arq, "%i \n",&V);
            if(L == 1){  /// inserir
                vet[i++] = V;
                if(i  == Ta)
                    heapsort(vet, Ta);
            }
            if(L == 2){  /// remover
                printf("%i\n",vet[0]);
            for(j = 0; j < Ta - z; j++){
                    vet[j] = vet[j + 1];
                }
                z++;
            }
            if(L == 3){  /// imprimir
                for(e = 0; e < Ta - z; e++){
                   printf("%i ", vet[e]);
                }
            }
        }while(! feof(arq));
    }
    return 0;
}
