#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "banco.h"

Lista* newBanco(){
    Lista* lista=malloc(sizeof(Lista));
    if (lista==NULL) return NULL;
    lista->primeiro=NULL;
    lista->ultimo=NULL;
    return lista;
}

void freeBanco(Lista* lista){
    if (lista==NULL) return;
    if (lista->primeiro==NULL && lista->ultimo==NULL) {
        free(lista);
        return;
    } else {
        elemento* aux=lista->primeiro;
        if (aux==lista->ultimo && aux!=lista->primeiro) {
            aux->ant->prox=NULL;
            lista->ultimo=aux->ant;
        } else
        if (aux==lista->primeiro && aux!=lista->ultimo) {
            aux->prox->ant=NULL;
            lista->primeiro=aux->prox;
        } else
        if (aux!=lista->primeiro && aux!=lista->ultimo){
            aux->ant->prox=aux->prox;
            aux->prox->ant=aux->ant;
        } else
        if (aux==lista->primeiro && aux==lista->ultimo){
            lista->primeiro=NULL;
            lista->ultimo=NULL;
        }
        freeAluno(aux->aluno);
        free(aux);
        freeBanco(lista);
    }
}

void insereAlunoLista(Lista* lista, char* nome, int matricula, char* cpf, char* curso, char* dn, float patrimonio){
    if (lista==NULL) return;
    if (nome==NULL) return;
    if (matricula<0) return;
    if (cpf<0) return;
    if (curso==NULL) return;
    if (dn==NULL) return;
    if (patrimonio<0.00) return;
    Aluno* aluno=newAluno();
    if (aluno==NULL) return;
    char temp[250]="";
    editaAluno(aluno, 0, nome);
    sprintf(temp, "%i", matricula);
    editaAluno(aluno, 1, temp);
    editaAluno(aluno, 2, cpf);
    editaAluno(aluno, 3, curso);
    editaAluno(aluno, 4, dn);
    sprintf(temp, "%.2f", patrimonio);
    editaAluno(aluno, 5, temp);
    elemento* el=malloc(sizeof(elemento));
    if (el==NULL) return;
    if (lista->primeiro==NULL && lista->ultimo==NULL) {
        lista->primeiro=el;
        lista->ultimo=el;
        el->aluno=aluno;
        el->ant=NULL;
        el->prox=NULL;
        return;
    }
    el->aluno=aluno;
    el->ant=NULL;
    el->prox=lista->primeiro;
    lista->primeiro->ant=el;
    lista->primeiro=el;
    return;
}

elemento* buscaAlunoLista(Lista*lista, int param, char* valor){
    if (lista==NULL) return NULL;
    if (lista->primeiro==NULL && lista->ultimo==NULL) return NULL;
    if (param<0 || param>5) return NULL;
    if (valor==NULL) return NULL;
    elemento* aux=lista->primeiro;
    switch(param){
    case 0:
        while(aux->aluno->nome!=valor && aux->prox!=NULL){
            aux=aux->prox;
        }
        if (aux->aluno->nome!=valor || aux==NULL) return NULL;
        return aux;
        break;

    case 1:
        while(aux->aluno->matricula!=atoi(valor) && aux->prox!=NULL){
            aux=aux->prox;
        }
        if (aux->aluno->matricula!=atoi(valor)) return NULL;
        return aux;
        break;

    case 2:
        while(aux->aluno->cpf!=valor && aux->prox!=NULL){
            aux=aux->prox;
        }
        if (aux->aluno->cpf!=valor || aux==NULL) return NULL;
        return aux;
        break;

    case 3:
        while(aux->aluno->curso!=valor && aux->prox!=NULL){
            aux=aux->prox;
        }
        if (aux->aluno->curso!=valor || aux==NULL) return NULL;
        return aux;
        break;

    case 4:
        while(aux->aluno->dn!=valor && aux->prox!=NULL){
            aux=aux->prox;
        }
        if (aux->aluno->dn!=valor || aux==NULL) return NULL;
        return aux;
        break;

    case 5:
        while(aux->aluno->patrimonio!=atof(valor) && aux->prox!=NULL){
            aux=aux->prox;
        }
        if (aux->aluno->patrimonio!=atof(valor) || aux==NULL) return NULL;
        return aux;
        break;
    }
    return NULL;
}

void removeAlunoLista(Lista* lista, int param, char* valor){
    if (lista==NULL) return;
    if (lista->primeiro==NULL && lista->ultimo==NULL) return;
    if (param<0 || param>5) return;
    if (valor==NULL) return;

    elemento* aux=buscaAlunoLista(lista, param, valor);
    if (aux==NULL) return;
    if (aux==lista->ultimo && aux!=lista->primeiro) {
        aux->ant->prox=NULL;
        lista->ultimo=aux->ant;
    } else
    if (aux==lista->primeiro && aux!=lista->ultimo) {
        aux->prox->ant=NULL;
        lista->primeiro=aux->prox;
    } else
    if (aux!=lista->primeiro && aux!=lista->ultimo){
        aux->ant->prox=aux->prox;
        aux->prox->ant=aux->ant;
    } else
    if (aux==lista->primeiro && aux==lista->ultimo){
        lista->primeiro=NULL;
        lista->ultimo=NULL;
    }
    freeAluno(aux->aluno);
    free(aux);
}

void editaAlunoLista(Lista* lista, int paramBusca, char* buscaValor, int param, char* valor) {
    if (lista==NULL) return;
    if (lista->primeiro==NULL && lista->ultimo==NULL) return;
    if (paramBusca<0 || paramBusca>5) return;
    if (buscaValor==NULL) return;
    if (param<0 || param>5) return;
    if (valor==NULL) return;
    elemento* el=buscaAlunoLista(lista, paramBusca, buscaValor);
    if (el==NULL) return;
    editaAluno(el->aluno, param, valor);
}

void mostraBanco(Lista* lista){
    if (lista==NULL) return;
    if (lista->primeiro==NULL && lista->ultimo==NULL) return;
    elemento* aux=lista->ultimo;
    while (aux!=NULL){
        mostraAluno(aux->aluno);
        aux=aux->ant;
    }
}

int compData(char *recebido, char *dnBanco){
    int dia, mes, ano, diaH, mesH, anoH;

    sscanf(recebido, "%i/%i/%i", &dia, &mes, &ano);
    sscanf(dnBanco, "%i/%i/%i", &diaH, &mesH, &anoH);


    if((mes > 12 || mes < 1) && (mesH > 12 || mesH < 1)){
        printf("Data invalida\n");
        return -2;
    }

    if(ano > anoH){
        return 1;
    }else if(ano < anoH){
        return -1;
    }else{
        if(mes > mesH){
            return 1;
        }else if(mes < mesH){
            return -1;
        }else{
            if(dia > diaH){
                return 1;
            }else if(dia < diaH){
                 return -1;
            } else return 0;
        }
    }
}
