#include<stdio.h>
#include<stdlib.h>
#define N 6
#define linha 9

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
    int c;
    for(c =0;c<N;c++){
        printf("%i ", vet[c]);
    }
    printf("\n");
}

int main()
{
    FILE *arq = fopen("texto.txt", "r");

    if(arq == NULL)
        printf("Erro, nao foi possivel abrir o arquivo\n");
    else{
        int i = 0, vet[N], e, j, z = 0, r, L, V;
        for(r = 0; r < linha; r++){
            fscanf(arq, "%i \n",&L);
            if(L == 1)
                fscanf(arq, "%i \n",&V);
            if(L == 1){  /// inserir
                vet[i++] = V;
            }
            if(r == N)
                heapsort(vet, N);
            if(L == 2){  /// remover
                printf("%i\n",vet[0]);
                for(j = 0; j < N - z; j++){
                    vet[j] = vet[j + 1];
                }
                z++;
            }
            if(L == 3){  /// imprimir
                for(e = 0; e < N - z; e++){
                    printf("%i ", vet[e]);
                }
            }
        }
    }
    return 0;
}
