#ifndef BANCO_H_INCLUDED
#define BANCO_H_INCLUDED
#include "aluno.h"

typedef struct el{
    Aluno* aluno;
    struct el* prox;
    struct el* ant;
}elemento;

typedef struct{
    elemento* primeiro;
    elemento* ultimo;
}Lista;

Lista* newBanco();

void freeBanco(Lista* lista);

void insereAlunoLista(Lista* lista, char* nome, int matricula, char* cpf, char* curso, char* dn, float patrimonio);

elemento* buscaAlunoLista(Lista*lista, int param, char* valor);

void removeAlunoLista(Lista* lista, int param, char* valor);

void editaAlunoLista(Lista* lista, int paramBusca, char* buscaValor, int param, char* valor);

void mostraBanco(Lista* lista);

int compData(char *dn, char *buffer);

#endif // BANCO_H_INCLUDED
