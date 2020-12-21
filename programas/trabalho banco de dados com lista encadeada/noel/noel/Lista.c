
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"
#include "Lista.h"
//CRIA LISTA DUPLAMENTE ENCADEADA

Lista *novaLista(){
 Lista *lista = malloc(sizeof(Lista));
 if (lista==NULL) return NULL;
    lista->cabeca=NULL;
    lista->calda=NULL;
    return lista;
}
/** INSERE ALUNO COM UMA UNICA FUNÇÃO!
/* SUBSTITUIDO - DESATUALIZADO!
void insereAluno(Lista* lista, char* nome, int matricula, char* cpf, char* curso, char* nasc, float patrimonio, char* valor){
 if (lista == NULL) return;
  Aluno* aluno=novoAluno();
  char* aux = malloc(strlen(valor)*sizeof(char));
  aluno->nome;
  aluno->cpf;
  aluno->matricula;
  aluno->curso;
  aluno->nasc;
  aluno->patrimonio=atof(valor);
  char temp[250]="";
**/

/***************************************************
* INSEREÇÕES UMA POR UMA, TESTAR E VER NO QUE DEU! *
* ATUALIZADAS PARA CASO A CASO                     *
***************************************************/
void insereAlunoNome(Lista* lista, char* nome){
 if(lista == NULL) return;
 aluno->nome=nome;
 Aluno* aluno=novoAluno();
}
void insereAlunoCPF(Lista* lista, char* cpf){
if (lista == NULL) return;
aluno->nome=cpf;
Aluno *aluno=novoAluno();
}
void insereAlunoMatricula(Lista* lista, char* matricula){
if (lista == NULL) return;
aluno->matricula=matricula;
Aluno *aluno=novoAluno();
}
void insereAlunoCurso(Lista* lista, char* curso){
if (lista == NULL) return;
aluno->curso=curso;
Aluno *aluno=novoAluno();
}
void insereAlunoNasc(Lista* lista, char* nasc){
if (lista == NULL) return;
aluno->nasc=nasc;
Aluno *aluno=novoAluno();
}
void insereAlunoPatri(Lista* lista, float patrimonio, char* valor){
if (lista == NULL) return;
aluno->patrimonio=atolf(valor);
Aluno *aluno=novoAluno();
}

/************************************************************
* ARRUMAR, FAZER INSERE SEM PARAMETROS.                     *
* INSERE ALUNO ORIGINAL USANDO A FUNÇÃO EDITE DO ALUNO.C    *
*************************************************************/
/*
void insereAluno(Lista* lista, char* nome, int matricula, char* cpf, char* curso, char* nasc, float patrimonio){
    if (lista==NULL) return;
    Aluno* aluno=novoAluno();
    char temp[250]="";
    edita(aluno, 0, nome);
    edita(aluno, 1, curso);
    edita(aluno, 2, cpf);
    edita(aluno, 3, curso);
    edita(aluno, 4, nasc);
    sprintf(temp, "%.2f", patrimonio);
    edita(aluno, 5, temp);
    elemento* elm=malloc(sizeof(elemento));
    if (elm==NULL) return;
    if (lista->cabeca==NULL && lista->calda==NULL) {
        lista->cabeca=elm;
        lista->calda=elm;
        elm->aluno=aluno;
        elm->ant=NULL;
        elm->prox=NULL;
        return;
    }
    elm->aluno=aluno;
    elm->ant=NULL;
    elm->prox=lista->head;
    lista->cabeca->ant=elm;
    lista->calda=elm;
    return;
}
*/
/******************************
* FREE LISTA, DESALOCA MEMÓRIA*
******************************/
void liberaLista(Lista* lista){
    while (lista!= NULL){
     lista *aux = lista->prox;
     free(lista);
     lista=aux;
    }
    }

/****************************************
*  BUSCA ALUNO ORGINAL                  *
*  SUBSTITUIDA POR UMA CASO A CASO      *
****************************************/
/*
int buscaLista(Lista* lista, int valor){
 if(Lista == NULL) return -1;
 if (lista->cabeca==NULL && lista->calda==NULL) return -1;
 int i;

   lista = lista->prox;
    for(i=0; lista != NULL && lista->valor!=valor{
      lista=lista->prox;
      if (lista == NULL) return -1;
    }
   return i;
}
*/

/*** BUSCA NOME ***/
elemento *buscaAlunoNome(Lista*lista, char* valor){
  if (lista == NULL) return NULL;
  elemento *aux = lista->cabeca;
    while(aux->aluno->nome!=valor && aux->prox!=NULL){
            aux=aux->prox;
        }
        if (aux->aluno->nome!=valor || aux==NULL) return NULL;
        return aux;
}

/*** BUSCA MATRICULA ***/
elemento *buscaAlunoMatricula(Lista*lista, char* valor){
 if(lista == NULL) return NULL;
 elemento *aux = lista->cabeca;
   while(aux->aluno->matricula!=valor && aux->prox!=NULL){
     aux=aux->prox;
   }
    if (aux->aluno->matricula!=valor || aux == NULL) return NULL;
    return aux;
}
/*** BUSCA CPF ***/
elemento *buscaAlunoCPF(Lista *lista, char* valor){
 if (lista == NULL) return NULL;
 elemento *aux = lista->cabeca;
  while(aux->aluno->cpf!=valor && aux->prox!=NULL){
    aux=aux->prox;
  }
  if (aux->aluno->cpf!=valor && aux == NULL) return NULL;
  return aux;
}

/*** BUSCA CURSO ***/
elemento *buscaAlunoCurso(Lista*lista, char* valor){
 if(lista == NULL) return NULL;
 elemento *aux = lista->cabeca;
  while(aux->aluno->curso!=valor && aux!=valor){
    aux=aux->prox;
  }
   if(aux->aluno->curso!=valor || aux == NULL) return NULL;
   return aux;
}

/*** BUSCA DATA DE NASCIMENTO ***/
elemento *buscaAlunoNasc(Lista *lista, char* valor){
if(lista == NULL) return NULL;
elemento *aux = lista->cabeca;
 while(aux->aluno->nasc!=valor && aux->prox!=valor){
    aux=aux->prox;
 }
 if(aux->aluno->nasc!=valor || aux == NULL) return NULL;
 return aux;
}

/*** BUSCA PATRIMONIO ***/
elemento *buscaAlunoPatrimonio(Lista *lista, char* valor){
 if(lista == NULL) return NULL;
 elemento *aux = lista->cabeca;
  while(aux->aluno->patrimonio!=valor && aux->prox!=valor){
    aux=aux->prox;
  }
  if(aux->aluno->patrimonio!=valor || aux == NULL) return NULL;
  return aux
}


/*** REMOVE ALUNO NOME ***/
void removeAlunoNome(Lista* lista, char* valor){

    elemento* aux=buscaAlunoNome(lista, valor);
    if (aux==NULL) return;
    if (aux==lista->calda && aux!=lista->cabeca) {
        aux->ant->prox=NULL;
        lista->calda=aux->ant;
    } else
    if (aux==lista->cabeca && aux!=lista->calda) {
        aux->prox->ant=NULL;
        lista->cabeca=aux->prox;
    } else
    if (aux!=lista->cabeca && aux!=lista->calda){
        aux->ant->prox=aux->prox;
        aux->prox->ant=aux->ant;
    } else
    if (aux==lista->cabeca && aux==lista->calda){
        lista->calda=NULL;
        lista->cabeca=NULL;
    }
    liberaLista(aux->aluno);
    free(aux);
}

/*** REMOVE ALUNO MATRICULA ***/
void removeAlunoMatricula(Lista* lista, char* valor){

    elemento* aux=buscaAlunoMatricula(lista, valor);
    if (aux==NULL) return;
    if (aux==lista->calda && aux!=lista->cabeca) {
        aux->ant->prox=NULL;
        lista->calda=aux->ant;
    } else
    if (aux==lista->cabeca && aux!=lista->calda) {
        aux->prox->ant=NULL;
        lista->cabeca=aux->prox;
    } else
    if (aux!=lista->cabeca && aux!=lista->calda){
        aux->ant->prox=aux->prox;
        aux->prox->ant=aux->ant;
    } else
    if (aux==lista->cabeca && aux==lista->calda){
        lista->calda=NULL;
        lista->cabeca=NULL;
    }
    liberaLista(aux->aluno);
    free(aux);
}

/*** REMOVE ALUNO CPF ***/
void removeAlunoCPF(Lista* lista, char* valor){

    elemento* aux=buscaAlunoCPF(lista, valor);
    if (aux==NULL) return;
    if (aux==lista->calda && aux!=lista->cabeca) {
        aux->ant->prox=NULL;
        lista->calda=aux->ant;
    } else
    if (aux==lista->cabeca && aux!=lista->calda) {
        aux->prox->ant=NULL;
        lista->cabeca=aux->prox;
    } else
    if (aux!=lista->cabeca && aux!=lista->calda){
        aux->ant->prox=aux->prox;
        aux->prox->ant=aux->ant;
    } else
    if (aux==lista->cabeca && aux==lista->calda){
        lista->calda=NULL;
        lista->cabeca=NULL;
    }
    liberaLista(aux->aluno);
    free(aux);
}

/*** REMOVE ALUNO CURSO ***/
void removeAlunoCurso(Lista* lista, char* valor){

    elemento* aux=buscaAlunoCurso(lista, valor);
    if (aux==NULL) return;
    if (aux==lista->calda && aux!=lista->cabeca) {
        aux->ant->prox=NULL;
        lista->calda=aux->ant;
    } else
    if (aux==lista->cabeca && aux!=lista->calda) {
        aux->prox->ant=NULL;
        lista->cabeca=aux->prox;
    } else
    if (aux!=lista->cabeca && aux!=lista->calda){
        aux->ant->prox=aux->prox;
        aux->prox->ant=aux->ant;
    } else
    if (aux==lista->cabeca && aux==lista->calda){
        lista->calda=NULL;
        lista->cabeca=NULL;
    }
    liberaLista(aux->aluno);
    free(aux);
}

/*** REMOVE ALUNO DATA NASCIMENTO ***/
void removeAlunoNasc(Lista* lista, char* valor){

    elemento* aux=buscaAlunoNasc(lista, valor);
    if (aux==NULL) return;
    if (aux==lista->calda && aux!=lista->cabeca) {
        aux->ant->prox=NULL;
        lista->calda=aux->ant;
    } else
    if (aux==lista->cabeca && aux!=lista->calda) {
        aux->prox->ant=NULL;
        lista->cabeca=aux->prox;
    } else
    if (aux!=lista->cabeca && aux!=lista->calda){
        aux->ant->prox=aux->prox;
        aux->prox->ant=aux->ant;
    } else
    if (aux==lista->cabeca && aux==lista->calda){
        lista->calda=NULL;
        lista->cabeca=NULL;
    }
    liberaLista(aux->aluno);
    free(aux);
}

/*** REMOVE ALUNO PATRIMONIO ***/
void removeAlunoPatrimonio(Lista* lista, char* valor){

    elemento* aux=buscaAlunoPatrimonio(lista, valor);
    if (aux==NULL) return;
    if (aux==lista->calda && aux!=lista->cabeca) {
        aux->ant->prox=NULL;
        lista->calda=aux->ant;
    } else
    if (aux==lista->cabeca && aux!=lista->calda) {
        aux->prox->ant=NULL;
        lista->cabeca=aux->prox;
    } else
    if (aux!=lista->cabeca && aux!=lista->calda){
        aux->ant->prox=aux->prox;
        aux->prox->ant=aux->ant;
    } else
    if (aux==lista->cabeca && aux==lista->calda){
        lista->calda=NULL;
        lista->cabeca=NULL;
    }
    liberaLista(aux->aluno);
    free(aux);
}

