#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *vetor;
    int tam_lista;
    int tam_vetor;
}lista;

lista* novalista(){
    lista* L = malloc(sizeof(L));
    if(L == NULL){
        return NULL;
    }
    L -> tam_vetor = 10;
    L -> vetor = malloc(L -> tam_vetor* sizeof(int));
    if(L -> vetor == NULL){
        free(L);
        return NULL;
    }
    L -> tam_lista = 0;
    return L;
}

void apagarlista(lista* L){
    if(L == NULL){
        return;
    }
    if(L -> vetor != NULL){
        free(L -> vetor);
    }
    free(L);
}

void insere (lista* L, int valor){
    int i;
    if(L == NULL){
        return;
    }
    if(L -> tam_vetor == L -> tam_lista){
        int* vetornovo = malloc(sizeof(int)*L -> tam_vetor*2);
        if(vetornovo == NULL){
            return;
        }
        for(i=0; i < L -> tam_vetor; i++){
            vetornovo[i] = L -> vetor[i];
        }
        free(L -> vetor);
        L -> tam_vetor *= 2;
        L -> vetor = vetornovo;
    }
    L -> vetor[L -> tam_lista++] = valor;
}

void remover (lista* L, int indice){
    int i;
    if(indice < 0 || indice > L -> tam_lista){
        return;
    }
    for(i = indice; i <= (L -> tam_lista -1); i++){
        L -> vetor[i] = L -> vetor[i+1];
    }
    L -> tam_lista --;
    if( L -> tam_lista <= (0.2 * L -> tam_vetor) && L -> tam_vetor > 10){
        int* vetornovo = malloc(sizeof(int)*L -> tam_vetor * 0.5);
        if( vetornovo == NULL){
            return;
        }
        for( i=0; i < L -> tam_lista; i++){
            vetornovo[i]=L -> vetor [i];
            free(L -> vetor);
            L -> tam_vetor *= 0.5;
            L -> vetor = vetornovo;
        }
    }
}
/*
int main(){
    int i,exit;
    lista L;
    do{
    scanf("%i", &i);
    switch (1){
        case 1:novalista();
        break;
        case 2:apagarlista(L);
        break;
        case 3:insere (L,valor);
        break;
        case 4:remover (L,valor);
        break;
        case 5:
            printf("deseja sair (1 para sim ou 0 para nao)? : ");
            scanf("%i",&exit);
            printf("\n");
        break;
        default:printf("opcao invalida, tente outra !");
        break;
    }
    }while(exit!= 1);
    return 0;
}
*/

int main(){
    return 0;
}
