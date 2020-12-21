#ifndef BANCO_H_INCLUDED
#define BANCO_H_INCLUDED
#include "Aluno.h"

//DUPLAMENTE ENCADEADA CABECA E CALDA
typedef struct elm{
    Aluno* aluno;
    struct elm* prox;
    struct elm* ant;
}elemento;

//DUPLAMENTE ENCADEADA CABECA E CALDA
typedef struct{
    elemento* cabeca;
    elemento* calda;
}Lista;

Lista *novaLista();

void insereAluno(Lista* lista, char* nome, int matricula, char* cpf, char* curso, char* nasc, float patrimonio);

void liberaLista(Lista* lista);

elemento *buscaAlunoNome(Lista*lista, char* valor);

elemento *buscaAlunoMatricula(Lista*lista, char* valor);

elemento *buscaAlunoCPF(Lista *lista, char* valor);

elemento *buscaAlunoCurso(Lista*lista, char* valor);

elemento *buscaAlunoNasc(Lista *lista, char* valor);

elemento *buscaAlunoPatrimonio(Lista *lista, char* valor);

void removeAlunoNome(Lista* lista, char* valor);

void removeAlunoMatricula(Lista* lista, char* valor);

void removeAlunoCPF(Lista* lista, char* valor);

void removeAlunoCurso(Lista* lista, char* valor);

void removeAlunoNasc(Lista* lista, char* valor);

void removeAlunoPatrimonio(Lista* lista, char* valor);

#endif

