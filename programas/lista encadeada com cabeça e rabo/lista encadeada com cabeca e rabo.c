#include <stdio.h>
#include <stdlib.h>

typedef struct el{
    int valor;
    struct el*prox;
}elemento;

typedef struct {
    elemento * primeiro;
    elemento * ultimo;
}Lista;

void insere_no_fim (Lista * lista, int valor){
    if(lista == NULL){
        return;
    }
    elemento * novo = malloc(sizeof(elemento));
    if(novo == NULL){
        return;
    }
    novo -> valor = valor;
    novo -> prox = NULL;
    if(lista -> primeiro == NULL){
        lista -> primeiro = novo;
        lista -> ultimo = novo;
        return;
    }
    lista -> ultimo -> prox = novo;
    lista -> ultimo = novo;
    return;
}

int main(){
    return 0;
}
