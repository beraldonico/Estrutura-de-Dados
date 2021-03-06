/*
 * main.c
 * 13/04/2017
 * author: gustavo
 */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* TODO Incluir o cabeçalho para a lista que você implementou */
#include "aluno.h"
#include "banco.h"

/* definição de variável booleana */
#define bool	int
#define false	0
#define true	1

/* Tamanho do buffer de entrada, equivalente a tamanho máximo da linha no arquivo de entrada -1 */
#define BUFFER_SIZE	512

/* caracteres considerados whitespace */
#define WHITE		" \t"

/* converte a string para lower case */
char* strlwr(char *string);

/* Busca o próximo token na string
 *  - Na primeira chamada passar a string de entrada
 *  - Nas chamadas subsequentes passar NULL no lugar da string
 *
 * white: string contendo os caracteres considerados espaço em branco
 * delim: string contendo os caracteres delimitadores (e.g., ";");
 * df: ponteiro para retornar o caractere delimitador encontrado
 *
 * retorna ponteiro para próximo token encontrado e NULL caso não tenha sido possível
 */
char* nextToken(char *string, char *white, char *delim, char *df);

/* parsear uma linha da entrada
 *
 * line: string contendo uma linha do arquivo de entrada
 * TODO habilitar lista como parâmetro nesta função
 *
 * retorna true se tudo correu bem, false caso contrário
 */
bool parseLine(char *line, Lista* lista);

/* parsear os argumentos do comando 'inserir'
 *
 * args: array com 5 strings (char*) para retornar os argumentos (tokens) encontrados
 *
 * retorna true se tudo correu bem, false caso contrário
 */
bool parse1(char **args);

/* parsear os argumentos dos comandos 'remover' e 'buscar'
 *
 * args: array com 2 strings (char*) para retornar os argumentos (tokens) encontrados
 * cmp: ponteiro para um caractere para retornar o operador
 */
bool parse2(char **args, char *cmp);

int main (int argc, char** argv) {
  if (argc < 2) {
    printf ("Informe pelo menos um arquivo de entrada\n");
    return 0;
  }

  /* TODO: Inicializa Lista */
  Lista* banco=newBanco();


  //insereAlunoLista(banco, "Lightning McQueen", 987654, "123.123.123-00", "Ufologia", "13/11/2013", 100000.00);
  //insereAlunoLista(banco, "Guido", 10101010, "001.001.001-00", "Engenharia Mecânica", "10/10/1910", 5000.00);
  //insereAlunoLista(banco, "Guido", 90909090, "001.001.001-00", "Engenharia Mecânica", "10/10/1910", 5000.00);

  char line[BUFFER_SIZE];

  int i;
  for (i = 1; i < argc; i++) {
    FILE *file = fopen(argv[i],"r");
    if (file == NULL) {
      printf("Não foi possível abrir o arquivo %s para leitura\n",argv[i]);
      continue;
    }

    printf("Transação %d: [%s]\n", i, argv[i]);

    int l;
    for (l = 1; fgets(line,BUFFER_SIZE,file); l++) {
      if (!parseLine(line, banco)) printf("Arquivo \'%s\' Linha %d está mal formatada\n", argv[i], l);
    }

    fclose(file);

  }

  printf("\n\nBanco:\n");
  freeBanco(banco);
  return 0;
}

char* strlwr(char* string) {
  unsigned char *s;

  for (s = (unsigned char*)string; *s != '\0'; s++) {
    *s = tolower(*s);
  }

  return string;
}

char* nextToken(char *str, char *white, char *delim, char *df) {
  static char *begNext = NULL;
  if (str == NULL) str = begNext;
  if (str == NULL) return NULL;

  char *beg = str + strspn(str,white);
  if (*beg == '\0' || *beg == '\n') {
    begNext = NULL;
    *beg = '\0';
    return beg;
  }

  char *d = beg + strcspn(beg,delim);

  if (df != NULL) *df = *d;

  begNext = d+1;

  for (d = d - 1; strchr(white,*d) != NULL; d--);
  *(d+1) = '\0';

  printf("token [%s] -> [%s]\n", beg, begNext);
  return beg;
}

/* TODO habilitar lista como parâmetro nesta função */
bool parseLine(char *line, Lista* lista) {
  char *cmd = nextToken(line,WHITE,WHITE,NULL);
  if (cmd == NULL) return false;
  if (*cmd == '\0') return true;

  strlwr(cmd);
  if (strcmp(cmd,"insere") == 0) {
    char *args[5];
    if (!parse1(args)) return false;

    /* TODO: inserir aluno no banco de dados (lista)
     * Considere
     * Nome: args[0]
     * Matricula: args[1]
     * CPF: args[2]
     * Curso: args[3]
     * Data: args[4]
     * Patrimônio: args[5]
     */

     insereAlunoLista(lista, args[0], atoi(args[1]), args[2], args[3], args[4], atof(args[5]));

     printf ("- Insere: \n");
     int j;
     char *argName[] = { "Nome", "Matrícula", "CPF", "Curso", "Data", "Patrimônio"};
     for (j = 0; j < 6; j++) {
       printf ("%s: [%s]\n", argName[j], args[j]);
     }
     printf("\n");

  } else if (strcmp(cmd,"remove") == 0) {
    char *args[1];
    char cmp;
    if (!parse2(args,&cmp)) return false;

    strlwr(args[0]);
    if (strcmp(args[0],"nome") == 0 && cmp == '=') {
      /* TODO Remover alunos com Nome igual a args[1] */
      elemento* aux=buscaAlunoLista(lista, 0, args[1]);
      while(aux!=NULL) {
        removeAlunoLista(lista, 0, args[1]);
        aux=buscaAlunoLista(lista, 0, args[1]);
      }
      printf("- Remove: Nome: [%s]\n", args[1]);
    } else if (strcmp(args[0], "matricula") == 0 && cmp == '=') {
      /* TODO Remover alunos com Matricula igual a args[1] */
      elemento* aux=buscaAlunoLista(lista, 1, args[1]);
      while(aux!=NULL) {
        removeAlunoLista(lista, 1, args[1]);
        aux=buscaAlunoLista(lista, 1, args[1]);
      }
      printf("- Remove: Matricula: [%s]\n", args[1]);
    } else if (strcmp(args[0], "cpf") == 0 && cmp == '=') {
      /* TODO Remover alunos com CPF igual a args[1] */
      elemento* aux=buscaAlunoLista(lista, 2, args[1]);
      while(aux!=NULL) {
        removeAlunoLista(lista, 2, args[1]);
        aux=buscaAlunoLista(lista, 2, args[1]);
      }
      printf("- Remove: CPF: [%s]\n", args[1]);
    } else if (strcmp(args[0], "curso") == 0 && cmp == '=') {
      /* TODO Remover alunos com Curso igual a args[1] */
      elemento* aux=buscaAlunoLista(lista, 3, args[1]);
      while(aux!=NULL) {
        removeAlunoLista(lista, 3, args[1]);
        aux=buscaAlunoLista(lista, 3, args[1]);
      }
      printf("- Remove: Curso: [%s]\n", args[1]);
    } else if (strcmp(args[0], "data") == 0) {
      elemento* aux=buscaAlunoLista(lista, 4, args[1]);
      elemento* auxD=lista->primeiro;
      elemento* auxE=auxD;
      switch (cmp) {
        case '=': /* TODO Remover alunos cuja data seja igual a args[1] */
          while(aux!=NULL) {
            removeAlunoLista(lista, 4, args[1]);
            aux=buscaAlunoLista(lista, 4, args[1]);
          }
          printf("- Remove: Data: [%s]\n", args[1]);
          break;
        case '<': /* TODO Remover alunos cuja data seja menor que args[1] */
          while(auxE!=NULL){
            if(compData(args[1], auxE->aluno->dn) == 1){
                auxD = auxE->prox;
                removeAlunoLista(lista, 4, auxE->aluno->dn);
                auxE = auxD;
            }else{
                auxE = auxE->prox;
            }

          }
          printf("- Remove: Data(menor que): [%s]\n", args[1]);
          break;
        case '>': /* TODO Remover alunos cuja data seja maior que args[1] */
          while(auxE!=NULL){
            if(compData(args[1], auxE->aluno->dn) == -1){
                auxD = auxE->prox;
                removeAlunoLista(lista, 4, auxE->aluno->dn);
                auxE = auxD;
            }else{
                auxE = auxE->prox;
            }
          }
          printf("- Remove: Data(maior que): [%s]\n", args[1]);
          break;
        default: return false;
      }
    } else if (strcmp(args[0], "patrimonio") == 0) {
      elemento* aux=buscaAlunoLista(lista, 5, args[1]);
      elemento* auxD=lista->primeiro;
      elemento* auxE=auxD;
      char temp[250];
      switch (cmp) {
        case '=': /* TODO Remover alunos cujo patrimônio seja igual a args[1] */
          while(aux!=NULL){
            removeAlunoLista(lista, 5, args[1]);
            aux=buscaAlunoLista(lista, 5, args[1]);
          }
          printf("- Remove: Patrimônio: [%s]\n", args[1]);
          break;
        case '<': /* TODO Remover alunos cujo patrimônio seja menor que args[1] */
          while(auxE!=NULL){
                if(auxE->aluno->patrimonio < atof(args[1])){
                    auxD=auxE->prox;
                    sprintf(temp, "%.2f", auxE->aluno->patrimonio);
                    removeAlunoLista(lista, 5, temp);
                    auxE = auxD;
                }else{
                    auxE=auxE->prox;
                }
          }
          printf("- Remove: Patrimônio(menor que): [%s]\n", args[1]);
          break;
        case '>': /* TODO Remover alunos cujo patrimônio seja maior que args[1] */
          while(auxE!=NULL){
           if(auxE->aluno->patrimonio > atof(args[1])){
                    auxD=auxE->prox;
                    sprintf(temp, "%.2f", auxE->aluno->patrimonio);
                    removeAlunoLista(lista, 5, temp);
                    auxE = auxD;
                }else{
                    auxE=auxE->prox;
                }
          }
          printf("- Remove: Patrimônio(maior que): Data: [%s]\n", args[1]);
        break;
        default: return false;
      }
    }
  } else if (strcmp(cmd,"busca") == 0) {
    char *args[1];
    char cmp;
    if (!parse2(args,&cmp)) return false;

    strlwr(args[0]);
    if (strcmp(args[0],"nome") == 0 && cmp == '=') {
      /* TODO Buscar e imprimir alunos com Nome igual a args[1] */
      Lista* auxL=lista;
      elemento* auxE=buscaAlunoLista(lista, 0, args[1]);
      while(auxE!=NULL){
            mostraAluno(auxE->aluno);
            auxL->primeiro=auxE->prox;
            auxE=buscaAlunoLista(auxL, 0, args[1]);
      }
      printf("- Busca: Nome: [%s]\n", args[1]);
    } else if (strcmp(args[0], "matricula") == 0 && cmp == '=') {
      /* TODO Buscar e imprimir alunos com Matricula igual a args[1] */
      Lista* auxL=lista;
      elemento* auxE=buscaAlunoLista(lista, 1, args[1]);
      while(auxE!=NULL){
            mostraAluno(auxE->aluno);
            auxL->primeiro=auxE->prox;
            auxE=buscaAlunoLista(auxL, 1, args[1]);
      }
      printf("- Busca: Matricula: [%s]\n", args[1]);
    } else if (strcmp(args[0], "cpf") == 0 && cmp == '=') {
      /* TODO Buscar e imprimir alunos com CPF igual a args[1] */
      Lista* auxL=lista;
      elemento* auxE=buscaAlunoLista(lista, 2, args[1]);
      while(auxE!=NULL){
            mostraAluno(auxE->aluno);
            auxL->primeiro=auxE->prox;
            auxE=buscaAlunoLista(auxL, 2, args[1]);
      }
      printf("- Busca: CPF: [%s]\n", args[1]);
    } else if (strcmp(args[0], "curso") == 0 && cmp == '=') {
      /* TODO Buscar e imprimir alunos com Curso igual a args[1] */
      Lista* auxL=lista;
      elemento* auxE=buscaAlunoLista(lista, 3, args[1]);
      while(auxE!=NULL){
            mostraAluno(auxE->aluno);
            auxL->primeiro=auxE->prox;
            auxE=buscaAlunoLista(auxL, 3, args[1]);
      }
      printf("- Busca: Curso: [%s]\n", args[1]);
    } else if (strcmp(args[0], "data") == 0) {
      Lista* auxL=lista;
      elemento* auxE=buscaAlunoLista(lista, 4, args[1]);
      elemento* auxD=lista->primeiro;
      elemento* auxA=auxD;
      switch (cmp) {
        case '=': /* TODO Buscar e imprimir alunos cuja data seja igual a args[1] */
          while(auxE!=NULL){
            mostraAluno(auxE->aluno);
            auxL->primeiro=auxE->prox;
            auxE=buscaAlunoLista(auxL, 4, args[1]);
          }
          printf("- Busca: Data: [%s]\n", args[1]);
          break;
        case '<': /* TODO Buscar e imprimir alunos cuja data seja menor que args[1] */
          while(auxA!=NULL){
            if(compData(args[1], auxA->aluno->dn) == 1){
                auxD = auxA->prox;
                mostraAluno(auxA->aluno);
                auxA = auxD;
            }else{
                auxA = auxA->prox;
            }
          }
          printf("- Busca: Data(menor que): [%s]\n", args[1]);
          break;
        case '>': /* TODO Buscar e imprimir alunos cuja data seja maior que args[1] */
          while(auxA!=NULL){
            if(compData(args[1], auxA->aluno->dn) == -1){
                auxD = auxA->prox;
                mostraAluno(auxA->aluno);
                auxA = auxD;
            }else{
                auxA = auxA->prox;
            }
          }
          printf("- Busca: Data(maior que): [%s]\n", args[1]);
          break;
        default: return false;
      }
    } else if (strcmp(args[0], "patrimonio") == 0) {
      Lista* auxL=lista;
      elemento* auxE=buscaAlunoLista(lista, 5, args[1]);
      elemento* auxD=lista->primeiro;
      elemento* auxA=auxD;
      switch (cmp) {
        case '=': /* TODO Buscar e imprimir alunos cujo patrimônio seja igual a args[1] */
          while(auxE!=NULL){
            mostraAluno(auxE->aluno);
            auxL->primeiro=auxE->prox;
            auxE=buscaAlunoLista(auxL, 5, args[1]);
          }
          printf("- Busca: Patrimônio: [%s]\n", args[1]);
          break;
        case '<': /* TODO Buscar e imprimir alunos cujo patrimônio seja menor que args[1] */
          while(auxA!=NULL){
                if(auxA->aluno->patrimonio < atof(args[1])){
                    auxD=auxA->prox;
                    mostraAluno(auxA->aluno);
                    auxA = auxD;
                }else{
                    auxA=auxA->prox;
                }
          }
          printf("- Busca: Patrimônio(menor que): [%s]\n", args[1]);
          break;
        case '>': /* TODO Buscar e imprimir alunos cujo patrimônio seja maior que args[1] */
          while(auxA!=NULL){
                if(auxA->aluno->patrimonio > atof(args[1])){
                    auxD=auxA->prox;
                    mostraAluno(auxA->aluno);
                    auxA = auxD;
                }else{
                    auxA=auxA->prox;
                }
          }
          printf("- Busca: Patrimônio(maior que): Data: [%s]\n", args[1]);
          break;
        default: return false;
      }
    }
  } else return false;

  return true;
}

bool parse1(char **args) {
  int i;
  for (i = 0; i < 6; i++) {
    args[i] = nextToken(NULL,WHITE,";",NULL);
    if (args[i] == NULL) return false;
  }

  return true;
}

bool parse2(char **args, char *cmp) {
  args[0] = nextToken(NULL,WHITE,"=<>",cmp);
  if (args[0] == NULL) return false;
  args[1] = nextToken(NULL,WHITE,";",NULL);
  return args[1] != NULL;
}
