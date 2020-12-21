#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"

Aluno* newAluno(){
    Aluno* aluno = malloc(sizeof(Aluno));
    if (aluno==NULL) return NULL;
    return aluno;
}

void freeAluno(Aluno* aluno){
    if (aluno==NULL) return;
    if ((aluno->nome!=NULL) || (aluno->curso!=NULL) || (aluno->dn!=NULL)){
        free(aluno->nome);
        free(aluno->curso);
        free(aluno->dn);
    }
    free(aluno);
}

void editaAluno(Aluno* aluno, int param, char* valor) {
    if(aluno==NULL) return;
    if(param<0 && param>5) return;
    if(valor==NULL) return;

    char* aux=malloc((strlen(valor)*sizeof(char))+1);
    aux=valor;

    switch(param){
    case 0:
        aluno->nome=aux;
        break;

    case 1:
        aluno->matricula=atoi(valor);
        break;

    case 2:
        aluno->cpf=valor;
        break;

    case 3:
        aluno->curso=aux;
        break;

    case 4:
        aluno->dn=aux;
        break;

    case 5:
        aluno->patrimonio=atof(valor);
        break;
    }
}

void mostraAluno(Aluno* aluno) {
    if (aluno==NULL) return;
    printf("Nome: %s\nMatricula: %i\nCPF: %s\nCurso: %s\nData de Nascimento: %s\nPatrimonio: %.2f\n\n",
        aluno->nome, aluno->matricula, aluno->cpf, aluno->curso, aluno->dn, aluno->patrimonio);
}
