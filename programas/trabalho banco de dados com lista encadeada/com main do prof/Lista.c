#include "Alunos.h"
#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

lista *iniciar_lista(){
    lista *L = malloc(sizeof(lista));
    if(L == NULL){
        printf("Sem memoria disponivel!\n");
        return NULL;
    }
    L->prox = NULL;
    return L;
}

void inserir_inicio(lista *L, char *nome, int matricula, char *CPF, char *curso, char *data, float renda){
    Dados *novo=malloc(sizeof(Dados));
	if(novo == NULL){
		printf("Sem memoria disponivel!\n");
		return;
	}
	novo -> prox = L -> prox;
	L -> prox = novo;
	completar(novo ,nome, matricula, CPF, curso, data, renda);
}
/*remover*/
void buscar_remover_nome(lista *L, char args[1]){
	Dados *aux1,*aux2;
	aux1 = L -> prox;
	aux2 = aux1 -> prox;
	int i = 0;
    while (aux2 != NULL){
        if(strcmp((aux1 -> nome),args) == 0){
            L -> prox = aux1 -> prox;
            free(aux1);
            aux1 = L -> prox;
            aux2 = aux1 -> prox;
            i++;
        }
        else if(strcmp((aux2 -> nome),args) == 0){
            aux1 -> prox = aux2 -> prox;
            free(aux2);
            aux2 = aux1 -> prox;
            i ++;
        }else{
            aux1 = aux1 -> prox;
            aux2 = aux2 -> prox;
        }
	}
	if(i == 0){
        printf("nao exise elemtento de busca !\n");
	}
}

void buscar_remover_matricula(lista *L, char args[1]){
	Dados *aux1,*aux2;
	aux1 = L -> prox;
	aux2 = L -> prox;
	int i = 0;
    while (aux2 != NULL){
        if((aux1 -> matricula) == atoi(args)){
            L -> prox = aux1 -> prox;
            free(aux1);
            aux1 = L -> prox;
            aux2 = aux1 -> prox;
            i++;
        }
        else if((aux2 -> matricula) == atoi(args)){
            aux1 -> prox = aux2 -> prox;
            free(aux2);
            aux2 = aux1 -> prox;
            i ++;
        }else{
            aux1 = aux1 -> prox;
            aux2 = aux2 -> prox;
        }
    }
	if(i == 0){
        printf("nao exise elemtento de busca !\n");
	}
}

void buscar_remover_CPF(lista *L, char args[1]){
	Dados *aux1,*aux2;
	aux1 = L -> prox;
	aux2 = L -> prox;
	int i = 0;
    while (aux2 != NULL){
        if(strcmp((aux1 -> CPF),args) == 0){
            L -> prox = aux1 -> prox;
            free(aux1);
            aux1 = L -> prox;
            aux2 = aux1 -> prox;
            i++;
        }
        else if(strcmp((aux2 -> CPF),args) == 0){
            aux1 -> prox = aux2 -> prox;
            free(aux2);
            aux2 = aux1 -> prox;
            i ++;
        }else{
            aux1 = aux1 -> prox;
            aux2 = aux2 -> prox;
        }
    }
	if(i == 0){
        printf("nao exise elemtento de busca !\n");
	}
}

void buscar_remover_curso(lista *L, char args[1]){
	Dados *aux1,*aux2;
	aux1 = L -> prox;
	aux2 = aux1 -> prox;
	int i = 0;
    while (aux2 != NULL){
        if(strcmp((aux1 -> curso),args) == 0){
            L -> prox = aux1 -> prox;
            free(aux1);
            aux1 = L -> prox;
            aux2 = aux1 -> prox;
            i++;
        }
        else if(strcmp((aux2 -> curso),args) == 0){
            aux1 -> prox = aux2 -> prox;
            free(aux2);
            aux2 = aux1 -> prox;
            i ++;
        }else{
            aux1 = aux1 -> prox;
            aux2 = aux2 -> prox;
        }
    }
	if(i == 0){
        printf("nao exise elemtento de busca !\n");
	}
}

void buscar_remover_data_igual(lista *L, char args[1]){
	Dados *aux1,*aux2;
	aux1 = L -> prox;
	aux2 = L -> prox;
	int i = 0;
    while (aux2 != NULL){
        if(strcmp((aux1 -> data),args) == 0){
            L -> prox = aux1 -> prox;
            free(aux1);
            aux1 = L -> prox;
            aux2 = aux1 -> prox;
            i++;
        }
        else if(strcmp((aux1 -> data),args) == 0){
            aux1 -> prox = aux2 -> prox;
            free(aux2);
            aux2 = aux1 -> prox;
            i ++;
        }else{
            aux1 = aux1 -> prox;
            aux2 = aux2 -> prox;
        }
    }
	if(i == 0){
        printf("nao exise elemtento de busca !\n");
	}
}

void buscar_remover_data_maior(lista *L, char args[1]){
	Dados *aux1,*aux2;
	aux1 = L -> prox;
	aux2 = L -> prox;
	int i = 0;
    while (aux2 != NULL){
        if(strcmp((aux1 -> data),args) > 0){
            L -> prox = aux1 -> prox;
            free(aux1);
            aux1 = L -> prox;
            aux2 = aux1 -> prox;
            i++;
        }
        else if(strcmp((aux1 -> data),args) > 0){
            aux1 -> prox = aux2 -> prox;
            free(aux2);
            aux2 = aux1 -> prox;
            i ++;
        }
        else{
            aux1 = aux1 -> prox;
            aux2 = aux2 -> prox;
        }
    }
	if(i == 0){
        printf("nao exise elemtento de busca !\n");
	}
}

void buscar_remover_data_menor(lista *L, char args[1]){
	Dados *aux1,*aux2;
	aux1 = L -> prox;
	aux2 = L -> prox;
	int i = 0;
    while (aux2 != NULL){
        if(strcmp((aux1 -> data),args) < 0){
            L -> prox = aux1 -> prox;
            free(aux1);
            aux1 = L -> prox;
            aux2 = aux1 -> prox;
            i++;
        }
        else if(strcmp((aux1 -> data),args) < 0){
            aux1 -> prox = aux2 -> prox;
            free(aux2);
            aux2 = aux1 -> prox;
            i ++;
        }else{
            aux1 = aux1 -> prox;
            aux2 = aux2 -> prox;
        }
    }
	if(i == 0){
        printf("nao exise elemtento de busca !\n");
	}
}

void buscar_remover_renda_igual(lista *L, char args[1]){
	Dados *aux1,*aux2;
	aux1 = L -> prox;
	aux2 = L -> prox;
	int i = 0;
    while (aux2 != NULL){
        if((aux1 -> renda) == atof(args)){
            L -> prox = aux1 -> prox;
            free(aux1);
            aux1 = L -> prox;
            aux2 = aux1 -> prox;
            i++;
        }else if((aux2 -> renda) == atof(args)){
            aux1 -> prox = aux2 -> prox;
            free(aux2);
            aux2 = aux1 -> prox;
            i ++;
        }else{
            aux1 = aux1 -> prox;
            aux2 = aux2 -> prox;
        };
    }
	if(i == 0){
        printf("nao exise elemtento de busca !\n");
	}
}

void buscar_remover_renda_menor(lista *L, char args[1]){
	Dados *aux1,*aux2;
	aux1 = L -> prox;
	aux2 = L -> prox;
	int i = 0;
    while (aux2 != NULL){
        if((aux1 -> renda) < atof(args)){
            L -> prox = aux1 -> prox;
            free(aux1);
            aux1 = L -> prox;
            aux2 = aux1 -> prox;
            i++;
        }
        else if((aux2 -> renda) < atof(args)){
            aux1 -> prox = aux2 -> prox;
            free(aux2);
            aux2 = aux1 -> prox;
            i ++;
        }else{
            aux1 = aux1 -> prox;
            aux2 = aux2 -> prox;
        };
    }
	if(i == 0){
        printf("nao exise elemtento de busca !\n");
	}
}

void buscar_remover_renda_maior(lista *L, char args[1]){
	Dados *aux1,*aux2;
	aux1 = L -> prox;
	aux2 = L -> prox;
	int i = 0;
    while (aux2 != NULL){
        if((aux1 -> renda) > atof(args)){
            L -> prox = aux1 -> prox;
            free(aux1);
            aux1 = L -> prox;
            aux2 = aux1 -> prox;
            i++;
        }
        else if((aux2 -> renda) > atof(args)){
            aux1 -> prox = aux2 -> prox;
            free(aux2);
            aux2 = aux1 -> prox;
            i ++;
        }else{
            aux1 = aux1 -> prox;
            aux2 = aux2 -> prox;
        };
    }
	if(i == 0){
        printf("nao exise elemtento de busca !\n");
	}
}

/*buscar*/
void buscar_imprimir_nome(lista *L, char args[1]){
	Dados *aux;
	aux = L -> prox;
	int i = 0;
    while (aux != NULL){
        if(strcmp((aux -> nome),args) == 0){
            printf("\nNome: %s \n", aux -> nome);
            printf("Matricula: %i \n", aux -> matricula);
            printf("CPF: %s \n", aux -> CPF);
            printf("Curso: %s \n", aux -> curso);
            printf("Nascimento: %s\n",aux -> data);
            printf("Renda: %f \n", aux -> renda);
            aux = aux -> prox;
            i ++;
        }else{
            aux = aux -> prox;
        }
    }
	if(i == 0){
        printf("nao exise elemtento de busca !\n");
	}
}

void buscar_imprimir_matricula(lista *L, char args[1]){
	Dados *aux;
	aux = L -> prox;
	int i = 0;
    while (aux != NULL){
        if((aux -> matricula) == atoi(args)){
            printf("\nNome: %s \n", aux -> nome);
            printf("Matricula: %i \n", aux -> matricula);
            printf("CPF: %s \n", aux -> CPF);
            printf("Curso: %s \n", aux -> curso);
            printf("Nascimento: %s \n",aux -> data);
            printf("Renda: %f \n", aux -> renda);
            aux = aux -> prox;
            i ++;
        }else{
            aux = aux -> prox;
        }
    }
	if(i == 0){
        printf("nao exise elemtento de busca !\n");
	}
}

void buscar_imprimir_CPF(lista *L, char args[1]){
	Dados *aux;
	aux = L -> prox;
	int i = 0;
    while (aux != NULL){
        if(strcmp((aux -> CPF),args) == 0){
            printf("\nNome: %s \n", aux -> nome);
            printf("Matricula: %i \n", aux -> matricula);
            printf("CPF: %s \n", aux -> CPF);
            printf("Curso: %s \n", aux -> curso);
            printf("Nascimento: %s \n",aux -> data);
            printf("Renda: %f \n", aux -> renda);
            aux = aux -> prox;
            i ++;
        }else{
            aux = aux -> prox;
        }
    }
	if(i == 0){
        printf("nao exise elemtento de busca !\n");
	}
}

void buscar_imprimir_curso(lista *L, char args[1]){
	Dados *aux;
	aux = L -> prox;
	int i = 0;
    while (aux != NULL){
        if(strcmp((aux -> curso),args) == 0){
            printf("\nNome: %s\n ", aux -> nome);
            printf("Matricula: %i \n", aux -> matricula);
            printf("CPF: %s \n", aux -> CPF);
            printf("Curso: %s \n", aux -> curso);
            printf("Nascimento: %s \n",aux -> data);
            printf("Renda: %f \n", aux -> renda);
            aux = aux -> prox;
            i ++;
        }else{
            aux = aux -> prox;
        }
    }
	if(i == 0){
        printf("nao exise elemtento de busca !\n");
	}
}

void buscar_imprimir_data_igual(lista *L, char args[1]){
	Dados *aux;
	aux = L -> prox;
	int i = 0;
    while (aux != NULL){
        if(strcmp((aux -> data),args) == 0){
            printf("\nNome: %s \n", aux -> nome);
            printf("Matricula: %i \n", aux -> matricula);
            printf("CPF: %s \n", aux -> CPF);
            printf("Curso: %s \n", aux -> curso);
            printf("Nascimento: %s \n",aux -> data);
            printf("Renda: %f \n", aux -> renda);
            aux = aux -> prox;
            i ++;
        }else{
            aux = aux -> prox;
        }
    }
	if(i == 0){
        printf("nao exise elemtento de busca !\n");
	}
}

void buscar_imprimir_data_maior(lista *L, char args[1]){
	Dados *aux;
	aux = L -> prox;
	int i = 0;
    while (aux != NULL){
        if(strcmp((aux -> data),args) > 0){
            printf("\nNome: %s \n", aux -> nome);
            printf("Matricula: %i \n", aux -> matricula);
            printf("CPF: %s \n", aux -> CPF);
            printf("Curso: %s \n", aux -> curso);
            printf("Nascimento: %s \n",aux -> data);
            printf("Renda: %f \n", aux -> renda);
            aux = aux -> prox;
            i ++;
        }else{
            aux = aux -> prox;
        }
    }
	if(i == 0){
        printf("nao exise elemtento de busca !\n");
	}
}

void buscar_imprimir_data_menor(lista *L, char args[1]){
	Dados *aux;
	aux = L -> prox;
	int i = 0;
    while (aux != NULL){
        if(strcmp((aux -> data),args) < 0){
            printf("\nNome: %s \n", aux -> nome);
            printf("Matricula: %i \n", aux -> matricula);
            printf("CPF: %s \n", aux -> CPF);
            printf("Curso: %s \n", aux -> curso);
            printf("Nascimento: %s\n",aux -> data);
            printf("Renda: %f \n", aux -> renda);
            aux = aux -> prox;
            i ++;
        }else{
            aux = aux -> prox;
        }
    }
	if(i == 0){
        printf("nao exise elemtento de busca !\n");
	}
}

void buscar_imprimir_renda_igual(lista *L, char args[1]){
	Dados *aux;
	aux = L -> prox;
	int i = 0;
    while (aux != NULL){
        if((aux -> renda) == atof(args)){
            printf("\nNome: %s \n", aux -> nome);
            printf("Matricula: %i\n", aux -> matricula);
            printf("CPF: %s \n", aux -> CPF);
            printf("Curso: %s \n", aux -> curso);
            printf("Nascimento: %s \n",aux -> data);
            printf("Renda: %f \n", aux -> renda);
            aux = aux -> prox;
            i ++;
        }else{
            aux = aux -> prox;
        };
    }
	if(i == 0){
        printf("nao exise elemtento de busca !\n");
	}
}

void buscar_imprimir_renda_maior(lista *L, char args[1]){
	Dados *aux;
	aux = L -> prox;
	int i = 0;
    while (aux != NULL){
        if((aux -> renda) > atof(args)){
            printf("\nNome: %s \n", aux -> nome);
            printf("Matricula: %i \n", aux -> matricula);
            printf("CPF: %s \n", aux -> CPF);
            printf("Curso: %s \n", aux -> curso);
            printf("Nascimento: %s \n",aux -> data);
            printf("Renda: %f \n", aux -> renda);
            aux = aux -> prox;
            i ++;
        }else{
            aux = aux -> prox;
        };
    }
	if(i == 0){
        printf("nao exise elemtento de busca !\n");
	}
}

void buscar_imprimir_renda_menor(lista *L, char args[1]){
	Dados *aux;
	aux = L -> prox;
	int i = 0;
    while (aux != NULL){
        if((aux -> renda) < atof(args)){
            printf("\nNome: %s \n", aux -> nome);
            printf("Matricula: %i \n", aux -> matricula);
            printf("CPF: %s \n", aux -> CPF);
            printf("Curso: %s \n", aux -> curso);
            printf("Nascimento: %s \n",aux -> data);
            printf("Renda: %f \n", aux -> renda);
            aux = aux -> prox;
            i ++;
        }else{
            aux = aux -> prox;
        };
    }
	if(i == 0){
        printf("nao exise elemtento de busca !\n");
	}
}
