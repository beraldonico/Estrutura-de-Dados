#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int valor;
	struct elemento * prox;
}Lista;

Lista * novaLista(){
    Lista * lista = malloc(sizeof(Lista));
	if (lista == NULL){
        return NULL;
	}
	lista -> prox = NULL;
	return lista;
}

void insere (Lista*lista, int valor){
    if(lista == NULL){
        return;
	}
	Lista * novo = malloc(sizeof(Lista));
	if (novo == NULL){
        return;
	}
	novo -> valor = valor;
	novo -> prox = lista -> prox;
	lista -> prox = novo;
}

void apagarLista(Lista*lista){
	while(lista != NULL){
		Lista * aux = lista -> prox;
		free(lista);
		lista = aux;
	}
}

void apagarListarecursivo(Lista * lista){
	if(lista == NULL) return;
	apagarListarecursivo(lista -> prox);
	free(lista);
}

void remover (Lista * lista, int indice){
    int i;
	if(lista == NULL){
        return;
    }
	Lista *anterior = lista;
	for(i=0; i < indice; i++){
		if(anterior == NULL){
            return;
		}
		anterior = anterior -> prox;
	}
	if(anterior == NULL || anterior -> prox == NULL){
        return;
	}
	Lista * aux = anterior -> prox;
	anterior -> prox = anterior -> prox -> prox;
	free (aux);
}

int busca (Lista * lista , int valor){
    int i;
    if (lista == NULL){
        return -1;
    }
    lista = lista -> prox;
    for(i = 0 ; lista != NULL && lista -> valor != valor; i++){
        lista = lista -> prox;
    }
    if(lista == NULL){
        return -1;
    }
    return i;
}
//formas difenrete de busca

Lista * buscar ( Lista * lista, int valor){
    if (lista == NULL){
        return NULL;
    }
    do {
        lista = lista -> prox;
    }while(lista != NULL && lista -> valor != valor);
    return lista;
}

int main(){
    return 0;
}
