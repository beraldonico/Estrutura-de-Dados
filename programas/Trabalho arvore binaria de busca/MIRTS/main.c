#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"
#include "Ordem.h"

int main()
{
    FILE *arq = fopen("texto.txt","r");

    if(arq == NULL){
        printf("Erro ao ler o arquivo");
        return -1;
    }

    int value;
    node *n = NULL;

    do{
        do{
            do {
                value = fgetc(arq);
            } while (value == ' ');
            if(value == '\n'){
                break;
            }
            if(feof(arq)){
                break;
            }

            n = insere( n, value);

        }while(1);

        printf("\n");
        dfspre(n);
        printf("\n");
        dfsin(n);
        printf("\n");
        dfspos(n);
        printf("\n");

        while(n != NULL)
            n = RemRaiz(n);

        if(feof(arq)){
                break;
        }
    }while(1);

    fclose(arq);

    return 0;
}
