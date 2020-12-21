/* main.c
 * 13/04/2017
 * author: gustavo
 */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Alunos.h"
#include "Lista.h"

/* TODO Incluir o cabeçalho para a lista que você implementou */

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
bool parseLine(char *line, lista *L );

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
	lista *L;
	L = iniciar_lista();

    char line[BUFFER_SIZE];

    int i;
    for (i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i],"r");
        if (file == NULL) {
            printf("Não foi possivel abrir o arquivo %s para leitura\n",argv[i]);
            continue;
        }

        printf("\nTransacao %d: [%s]\n", i, argv[i]);

        int l;
        for (l = 1; fgets(line,BUFFER_SIZE,file); l++) {
            if (!parseLine(line,L))
                printf("Arquivo \'%s\' Linha %d esta mal formatada\n", argv[i], l);
        }

        fclose(file);

    }

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

    /*printf("token [%s] -> [%s]\n", beg, begNext);*/
    return beg;
}

/* TODO habilitar lista como parâmetro nesta função */
bool parseLine(char *line, lista *L) {
    char *cmd = nextToken(line,WHITE,WHITE,NULL);
    if (cmd == NULL) return false;
    if (*cmd == '\0') return true;

    strlwr(cmd);
    if (strcmp(cmd,"insere") == 0) {
        char *args[6];
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

        inserir_inicio(L, args[0], atoi(args[1]), args[2], args[3], args[4], atof(args[5]));
        printf ("\n- insere: \n");
        int j;
        char *argName[] = { "Nome", "Matricula", "CPF", "Curso", "Data", "Patrimonio"};
        for (j = 0; j < 6; j++) {
            printf ("%s: [%s]\n", argName[j], args[j]);
        }
    } else if (strcmp(cmd,"remove") == 0) {
        char *args[2];
        char cmp;
        if (!parse2(args,&cmp))
            return false;

        strlwr(args[0]);
        printf("\n");
        if (strcmp(args[0],"nome") == 0 && cmp == '=') {
            /* TODO Remover alunos com Nome igual a args[1] */
            printf("- Remove: Nome: [%s]\n", args[1]);
            buscar_remover_nome(L, args[1]);

        } else if (strcmp(args[0], "matricula") == 0 && cmp == '=') {
            /* TODO Remover alunos com Matricula igual a args[1] */
            printf("- Remove: Matricula: [%s]\n", args[1]);
            buscar_remover_matricula(L, args[1]);

        } else if (strcmp(args[0], "cpf") == 0 && cmp == '=') {
            /* TODO Remover alunos com CPF igual a args[1] */
            printf("- Remove: CPF: [%s]\n", args[1]);
            buscar_remover_CPF(L, args[1]);

        } else if (strcmp(args[0], "curso") == 0 && cmp == '=') {
            /* TODO Remover alunos com Curso igual a args[1] */
            printf("- Remove: Curso: [%s]\n", args[1]);
            buscar_remover_curso(L, args[1]);

        } else if (strcmp(args[0], "data") == 0) {
            switch (cmp) {
                case '=': /* TODO Remover alunos cuja data seja igual a args[1] */
                    printf("- Remove: Data: [%s]\n", args[1]);
                    buscar_remover_data_igual(L, args[1]);
                    break;

                case '<': /* TODO Remover alunos cuja data seja menor que args[1] */
                    printf("- Remove: Data(menor que): [%s]\n", args[1]);
                    buscar_remover_data_menor(L, args[1]);
                    break;

                case '>': /* TODO Remover alunos cuja data seja maior que args[1] */
                    printf("- Remove: Data(maior que): [%s]\n", args[1]);
                    buscar_remover_data_maior(L, args[1]);
                    break;

                default: return false;
            }
        } else if (strcmp(args[0], "patrimonio") == 0) {
            switch (cmp) {
                case '=': /* TODO Remover alunos cujo patrimônio seja igual a args[1] */
                    printf("- Remove: Patrimonio: [%s]\n", args[1]);
                    buscar_remover_renda_igual(L, args[1]);
                    break;

                case '<': /* TODO Remover alunos cujo patrimônio seja menor que args[1] */
                    printf("- Remove: Patrimonio(menor que): [%s]\n", args[1]);
                    buscar_remover_renda_menor(L, args[1]);
                    break;

                case '>': /* TODO Remover alunos cujo patrimônio seja maior que args[1] */
                    printf("- Remove: Patrimonio(maior que): [%s]\n", args[1]);
                    buscar_remover_renda_maior(L, args[1]);
                    break;

                default: return false;
            }
        }
    } else if (strcmp(cmd,"busca") == 0) {
        char *args[2];
        char cmp;
        if (!parse2(args,&cmp))
        return false;

        printf("\n");
        strlwr(args[0]);
        if (strcmp(args[0],"nome") == 0 && cmp == '=') {
            /* TODO Buscar e imprimir alunos com Nome igual a args[1] */
            printf("- Busca: Nome: [%s]\n", args[1]);
            buscar_imprimir_nome(L,args[1]);

        } else if (strcmp(args[0], "matricula") == 0 && cmp == '=') {
            /* TODO Buscar e imprimir alunos com Matricula igual a args[1] */
            printf("- Busca: Matricula: [%s]\n", args[1]);
            buscar_imprimir_matricula(L,args[1]);

        } else if (strcmp(args[0], "cpf") == 0 && cmp == '=') {
            /* TODO Buscar e imprimir alunos com CPF igual a args[1] */
            printf("- Busca: CPF: [%s]\n", args[1]);
            buscar_imprimir_CPF(L,args[1]);

        } else if (strcmp(args[0], "curso") == 0 && cmp == '=') {
            /* TODO Buscar e imprimir alunos com Curso igual a args[1] */
            printf("- Busca: Curso: [%s]\n", args[1]);
            buscar_imprimir_curso(L,args[1]);

        } else if (strcmp(args[0], "data") == 0) {
            switch (cmp) {
                case '=': /* TODO Buscar e imprimir alunos cuja data seja igual a args[1] */
                    printf("- Busca: Data: [%s]\n", args[1]);
                    buscar_imprimir_data_igual(L,args[1]);
                    break;

                case '<': /* TODO Buscar e imprimir alunos cuja data seja menor que args[1] */
                    printf("- Busca: Data(menor que): [%s]\n", args[1]);
                    buscar_imprimir_data_menor(L,args[1]);
                    break;

                case '>': /* TODO Buscar e imprimir alunos cuja data seja maior que args[1] */
                    printf("- Busca: Data(maior que): [%s]\n", args[1]);
                    buscar_imprimir_data_maior(L,args[1]);
                    break;

                default: return false;
            }
        } else if (strcmp(args[0], "patrimonio") == 0) {
              switch (cmp) {
                case '=': /* TODO Buscar e imprimir alunos cujo patrimônio seja igual a args[1] */
                    printf("- Busca: Patrimonio: [%s]\n", args[1]);
                    buscar_imprimir_renda_igual(L,args[1]);
                    break;

                case '<': /* TODO Buscar e imprimir alunos cujo patrimônio seja menor que args[1] */
                    printf("- Busca: Patrimonio(menor que): [%s]\n", args[1]);
                    buscar_imprimir_renda_menor(L,args[1]);
                    break;

                case '>': /* TODO Buscar e imprimir alunos cujo patrimônio seja maior que args[1] */
                    printf("- Busca: Patrimonio(maior que): [%s]\n", args[1]);
                    buscar_imprimir_renda_menor(L,args[1]);
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
