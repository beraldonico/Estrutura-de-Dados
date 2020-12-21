#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"
//autor: Matheus Padilha Marques

Aluno* novoAluno(){
 Aluno *aluno = malloc(sizeof(Aluno));
 if (aluno == NULL) retun NULL;
}

void liberaLista(Aluno* aluno){
    if (aluno==NULL) return;
    if ((aluno->nome!=NULL) || (aluno->curso!=NULL) || (aluno->nasc!=NULL)){
        free(aluno->nome);
        free(aluno->curso);
        free(aluno->nasc);
    }
    free(aluno);
}

void edita(Aluno* aluno, int op, char* valor) {
    if(aluno==NULL) return;
    if(op<0 && op>5) return; // ESCOLHER O CAMPO QUE QUER EDITAR
    if(valor==NULL) return;

    char* aux=malloc(strlen(valor)*sizeof(char));
    aux=valor;

    if (op == 0){
        aluno->nome=aux;
    }
    if (op == 1){
        aluno->matricula=atoi(valor);

    if (op == 2){
        aluno->cpf=valor;
    }

    if (op == 3) {
        aluno->curso=aux;
    }

    if (op == 4) {
        aluno->nasc=aux;
    }

    if (op == 5) {
        aluno->patrimonio=atof(valor);
    }
}


void mostraAluno(Aluno* aluno) {
    if (aluno==NULL) return;
     printf("Nome : %s\n", aluno->nome);
     printf("CPF  : %s\n", aluno->cpf);
     printf("Curso: %s\n", aluno->curso);
     printf("Nasc : %s\n", aluno->nasc);
     printf("Patrimonio: %.2f\n", aluno->patrimonio);
 }


/***
int insereAluno()
  lista *head;
  head = (lista*)malloc(sizeof(lista));
   if (head = NULL){
     printf("ERRO!")
     return 0;
   }
   head->prox = NULL;
    if (inicio==NULL){
        inicio = head;
    }
   else {
     head->prox = inicio;
     inicio = head;
   }
   return 1;
***/
 }


