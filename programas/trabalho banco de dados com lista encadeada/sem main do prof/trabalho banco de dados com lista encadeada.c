#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info{
    char nome[30];
    int  matricula;
    char CPF[11];
    char curso[5];
    int dia, mes, ano;
    double renda;
    struct info *prox;
}Dados;

typedef struct Lista{
    Dados *prox;
}lista;

int verificarCPF(Dados *L){
    int i, j, digito1 = 0, digito2 = 0, retornar = 1, CPF;
    if(strlen(L ->CPF) != 11){
        retornar = 0;
    }
    else{
        for(i = 0, j = 10; i < strlen(L -> CPF)-2; i++, j--){
            digito1 += ((L -> CPF[i])-48) * j;
        }
        digito1 %= 11;
        if(digito1 < 2){
            digito1 = 0;
        }
        else{
            digito1 = 11 - digito1;
        }
        if(((L -> CPF[9])-48) != digito1){
            retornar = 0;
        }
        else{
            for(i = 0, j = 11; i < strlen(L -> CPF)-1; i++, j--){
                digito2 += ((L -> CPF[i])-48) * j;
            }
            digito2 %= 11;
            if(digito2 < 2){
                digito2 = 0;
            }
            else{
                digito2 = 11 - digito2;
            }
            if(((L -> CPF[10]) - 48) != digito2){
                retornar = 0;
            }
        }
    }
    if(retornar == 0){
        printf("CPF invalido, digite um valido !\n");
        return 0;
    }
    return 1;
}

void completar(Dados *L){
    int sai = 0;
    printf("\nInsira os Dados \n");
    printf("Insira o nome:");
    scanf(" %[^\n]s",&L -> nome);

    printf("Insira a matricula:");
    scanf(" %d",&L -> matricula);

    do{
        printf("Insira o CPF:");
        scanf("%s",&L -> CPF);
        /*sai = verificarCPF(L);*/
    }while(sai != 0);

    printf("Insira o curso (abreviacao):");
    scanf(" %s",&L -> curso);

    printf("Insira a data de nascimento:\n");
    printf("Dia:");
    scanf(" %d",&L -> dia);
    printf("Mes:");
    scanf(" %d",&L -> mes);
    printf("Ano:");
    scanf(" %d",&L -> ano);

    printf("Insira a renda:");
    scanf(" %d",&L -> renda);
    printf("\n");
}

void mostrar_dados(lista *L){
    if(L->prox == NULL){
		printf("Lista vazia!\n\n");
		system("pause");
		return;
	}
	int opt, sair;
	Dados *aux;
	do{
        aux = L->prox;
        printf("Qual elemento deseja mostrar: \n");
        printf("(De preferencia para matricula e CPF)\n");
        printf("1) nome\n");
        printf("2) matricula\n");
        printf("3) CPF\n");
        printf("4) curso\n");
        printf("5) aniversario\n");
        printf("6) renda\n");
        printf("7) sair\n");
        printf("opcao: ");
        scanf("%i", &opt);
        printf("\n");
        switch(opt){
            case 1:
                while(aux != NULL){
                    printf("\nNome: %s \n", aux -> nome);
                    aux = aux -> prox;
                }
                printf("\nNome: %s \n", aux -> nome);
                system("pause");
                break;
            case 2:
                while(aux != NULL){
                    printf("\nMatricula: %i \n ", aux -> matricula);
                    aux = aux -> prox;
                }
                printf("\nMatricula: %i \n ", aux -> matricula);
                system("pause");
                break;
            case 3:
                while(aux != NULL){
                    printf("\nCPF: %s \n ", aux -> CPF);
                    aux = aux -> prox;
                }
                printf("\nCPF: %s \n ", aux -> CPF);
                system("pause");
                break;
            case 4:
                while(aux != NULL){
                    printf("\nCurso: %s \n", aux -> curso);
                    aux = aux -> prox;
                }
                printf("\nCurso: %s \n ", aux -> curso);
                system("pause");
                break;
            case 5:
                while(aux != NULL){
                    printf("\nNascimento: %i/%i/%i  \n",aux -> dia,aux -> mes,aux -> ano);
                    aux = aux -> prox;
                }
                printf("\nNascimento: %i/%i/%i  \n",aux -> dia,aux -> mes,aux -> ano);
                system("pause");
                break;
            case 6:
                while(aux != NULL){
                    printf("\nRenda: %d  \n", aux -> renda);
                    aux = aux -> prox;
                }
                printf("\nRenda: %d  \n", aux -> renda);
                system("pause");
                break;
            case 7:
                sair =terminar();
                break;
            default:
                printf("opcao invalida, tente outra !\n");
                system("pause");
                break;
        }
    system("cls");
    }while(sair != 1);
}

int terminar(){
    int sair;
    do{
        printf("\ndeseja sair? (1- Sim / 2- Nao): ");
        scanf("%i",&sair);
        printf("\n");
    }while(sair != 1 && sair != 2);
    return sair;
}

int menu(){
	int opt;
	printf("Escolha a opcao\n");
	printf("1) Inserir\n");
	printf("2) Remover\n");
	printf("3) Destruir\n");
	printf("4) Buscar\n");
	printf("5) Mostrar lista\n");
	printf("6) Sair\n");
	printf("Opcao: ");
	scanf("%d", &opt);
	printf("\n");
	return opt;
}

void inserir_inicio(lista *L){
    Dados *novo=malloc(sizeof(Dados));
	if(novo == NULL){
		printf("Sem memoria disponivel!\n");
		system("pause");
		return;
	}
	novo -> prox = L -> prox;
	L -> prox = novo;
	completar(novo);
}

void inserir_meio(lista *L){
    Dados *novo=malloc(sizeof(Dados));
	if(novo == NULL){
		printf("Sem memoria disponivel!\n");
		system("pause");
		return;
	}
	int i = 1, indice;
	Dados *aux;
	aux = L -> prox;
	if(L -> prox == NULL){
        printf("\nO indice eh 0, o item sera inserido no inicio.\n");
        novo -> prox = L->prox;
        L->prox = novo;
        completar(novo);
        return;
	}
    while(aux -> prox != NULL){
        while(aux -> prox != NULL){
            if(aux -> prox!= NULL){
                aux = aux -> prox;
                i++;
            }
        }
        printf("\nO indice eh maximo %i\n\n", i);
    }
	if(aux -> prox == NULL && i == 1){
        printf("\nO indice eh 1\n\n");
	}
	printf("Em qual indice deseja inserir: ");
	scanf("%i", &indice);
	aux = L -> prox;
	if(indice == 1){
        novo -> prox = L -> prox;
        L -> prox = novo;
        return;
	}
	if(aux -> prox != NULL){
        for(i = 0 ; i < (indice-2); i++){
            aux = aux -> prox;
        }
	}
	novo -> prox = aux -> prox;
	aux -> prox = novo;
	completar(novo);
	return;
}

void inserir_fim(lista *L){
	Dados *novo=malloc(sizeof(Dados));
	if(novo == NULL){
		printf("Sem memoria disponivel!\n");
		system("pause");
		return;
	}
	Dados *aux;
	novo->prox = NULL;
    if(L->prox == NULL){
		L->prox=novo;
    }
	else{
		aux= L->prox;
		while((aux -> prox) != NULL){
			aux = aux->prox;
        }
		aux->prox = novo;
	}
	completar(novo);
}

void inserir(lista *L){
    int opt, sair =2;
    do{
    printf("deseja inserir onde:\n");
    printf("1) Inicio\n");
    printf("2) Meio\n");
    printf("3) Fim\n");
    printf("4) Sair\n");
    printf("Opcao: ");
    scanf("%i", &opt);
        switch(opt){
            case 1:
                inserir_inicio(L);
                break;
            case 2:
                inserir_meio(L);
                break;
            case 3:
                inserir_fim(L);
                break;
            case 4:
                sair = terminar();
                break;
            default:
                printf("opcao invalida, tente outra !\n");
                system("pause");
                break;
        }
    system("cls");
    }while(sair != 1);
}

void remover_inicio(lista *L){
    Dados *aux;
    aux = L -> prox;
    L -> prox = aux -> prox;
    free(aux);
}

void remover_meio(lista *L){
	int i = 1, indice;
	Dados *aux1,*aux2;
	aux1 = L -> prox;
	aux2 = L -> prox;
    while(aux2 -> prox != NULL){
        while(aux2 -> prox != NULL){
            if(aux2 -> prox!= NULL){
                aux2 = aux2 -> prox;
                i++;
            }
        }
        printf("\nO indice maximo eh %i\n\n", i);
    }
	if(aux2 -> prox == NULL && i == 1){
        printf("\nO indice eh 1\n\n");
	}
	aux2 = L -> prox;
	printf("Qual indice deseja apagar: ");
	scanf("%i",&indice);
	if(aux2 -> prox != NULL){
        for(i = 0; i < (indice -1) ; i++){
            aux2 = aux2 -> prox;
        }
	}
	if(aux1 -> prox != NULL){
        for(i = 0; i < (indice -2) ; i++){
            aux1 = aux1 -> prox;
        }
	}
	aux1 -> prox= aux2 -> prox;
	free(aux2);
}

void remover_fim(lista *L){
    Dados *aux1, *aux2;
    aux1 = L -> prox;
    aux2 = L -> prox;
    do{
        aux1 = aux1 -> prox;
    }while(aux1->prox != NULL);
    do{
        aux2 = aux2 -> prox;
    }while(aux2 -> prox == aux1);
    aux2 -> prox = NULL;
    free(aux1);
}

void remover(lista *L){
    if( L -> prox == NULL){
		printf("Nao existe Lista!\n");
		system("pause");
		return;
	}
    int opt, sair =2;
    do{
        printf("deseja remover onde:\n");
        printf("1) Inicio\n");
        printf("2) Meio\n");
        printf("3) Fim\n");
        printf("4) cancelar\n");
        printf("Opcao: ");
        scanf("%i", &opt);
        switch(opt){
            case 1:
                remover_inicio(L);
                break;
            case 2:
                remover_meio(L);
                break  ;
            case 3:
                remover_fim(L);
                break;
            case 4:
                sair = terminar();
                break;
            default:
                printf("opcao invalida, tente outra !\n");
                system("pause");
                break;
        }
    system("cls");
    }while(sair != 1);
}

void buscar_indice(lista *L){
	int i = 1, indice;
	Dados *aux;
	aux = L -> prox;
	if(L -> prox != NULL){
        while(aux -> prox != NULL){
            while(aux -> prox != NULL){
                if(aux -> prox!= NULL){
                    aux = aux -> prox;
                    i++;
                }
            }
            printf("\nO indice maximo eh %i\n\n", i);
        }
	}
	if(aux -> prox == NULL && i == 1){
        printf("\nO indice eh 1\n\n");
	}
	printf("Qual indice deseja pesquisar: ");
	scanf("%i",&indice);
	aux = L -> prox;
	for(i = 0; i < (indice -1) ; i++){
        aux = aux -> prox;
    }
    if(aux == NULL){
        printf("nao existe elemento com o valor de buscar! \n");
    }
    if(aux != NULL){
        printf("\nNome: %s \n \n", aux -> nome);
        printf("Matricula: %i \n \n", aux -> matricula);
        printf("CPF: %s \n \n", aux -> CPF);
        printf("Curso: %s \n \n", aux -> curso);
        printf("Nascimento: %i/%i/%i \n \n",aux -> dia,aux -> mes,aux -> ano);
        printf("Renda: %d \n \n", aux -> renda);
    }
    system("pause");
}

void buscar_elemento(lista *L){
	Dados *aux;
	int opt, sair;
	char nome[30];
    int  matricula;
    char CPF[11];
    char curso[5];
    int dia, mes, ano;
    double renda;
	do{
        aux = L -> prox;
        printf("Qual elemento deseja procurar: \n");
        printf("(De preferencia para matricula e CPF)\n");
        printf("1) nome\n");
        printf("2) matricula\n");
        printf("3) CPF\n");
        printf("4) curso\n");
        printf("5) aniversario\n");
        printf("6) renda\n");
        printf("7) sair\n");
        printf("opcao: ");
        scanf("%i", &opt);
        switch(opt){
            case 1:
                printf("Digite o nome: ");
                scanf("%s", &nome);
                while (aux != NULL && (strcmp((aux -> nome), nome)) == 0){
                    aux = aux -> prox;
                }
                break;
            case 2:
                printf("Digite o matricula: ");
                scanf("%i", &matricula);
                while (aux != NULL && aux -> matricula != matricula){
                    aux = aux -> prox;
                }
                break;
            case 3:
                printf("Digite o CPF: ");
                scanf("%s", &CPF);
                printf("%s", CPF);
                while (aux != NULL && (strcmp((aux -> CPF),CPF)) == 0){
                    aux = aux -> prox;
                }
                break;
            case 4:
                printf("Digite o curso: ");
                scanf("%s", &curso);
                while (aux != NULL && (strcmp((aux -> curso), curso)) == 0){
                    aux = aux -> prox;
                }
                break;
            case 5:
                printf("Digite o aniversario: \n");
                printf("dia: ");
                scanf("%i", &dia);
                printf("mes: ");
                scanf("%i", &mes);
                printf("ano: ");
                scanf("%i", &ano);
                while (aux != NULL && (aux -> dia) != dia && (aux -> mes) != mes && (aux -> ano) != ano){
                    aux = aux -> prox;
                }
                break;
            case 6:
                printf("Digite o renda: ");
                scanf("%d", &renda);
                while (aux != NULL || (aux -> renda) != renda){
                    aux = aux -> prox;
                }
                break;
            case 7:
                sair =terminar();
                break;
            default:
                printf("opcao invalida, tente outra !\n");
                system("pause");
                break;
        }
    if(aux == NULL){
        printf("nao existe elemento com o valor de buscar! \n");
    }
    if(aux != NULL){
        printf("\nNome: %s \n \n", aux -> nome);
        printf("Matricula: %i \n \n", aux -> matricula);
        printf("CPF: %s \n \n", aux -> CPF);
        printf("Curso: %s \n \n", aux -> curso);
        printf("Nascimento: %i/%i/%i \n \n",aux -> dia,aux -> mes,aux -> ano);
        printf("Renda: %d \n \n", aux -> renda);
    }
    system("pause");
    system("cls");
    }while(sair != 1);
}

void buscar(lista *L){
    if( L -> prox == NULL){
		printf("Nao existe Lista!\n");
		system("pause");
		return;
	}
    int opt, sair =2;
    do{
        printf("Qual o metodo de busca:\n");
        printf("1) Elemento\n");
        printf("2) Indice\n");
        printf("3) cancelar\n");
        printf("Opcao: ");
        scanf("%i", &opt);
        switch(opt){
            case 1:
                buscar_elemento(L);
                break;
            case 2:
                buscar_indice(L);
                break  ;
            case 3:
                sair = terminar();
                break;
            default:
                printf("opcao invalida, tente outra !\n");
                system("pause");
                break;
        }
    system("cls");
    }while(sair != 1);
}

void destruir(lista *L){
    if( L -> prox == NULL){
		printf("Nao existe Lista!\n\n");
		system("pause");
		return;
	}
    Dados *prox,*atual;
    atual = L->prox;
    L -> prox = NULL;
    while(atual != NULL){
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
	printf("A lista foi destruida!! \n\n");
	system("pause");
}

int main(){
    lista *L = malloc(sizeof(lista));
    if(L == NULL){
		printf("Sem memoria disponivel!\n");
		return;
	}
	L->prox = NULL;

    int sair = 0,opcao;
    do{
        opcao = menu();
        switch(opcao){
            case 1:
                inserir(L);
                break;
            case 2:
                remover(L);
                break;
            case 3:
                destruir(L);
                break;
            case 4:
                buscar(L);
                break;
            case 5:
                mostrar_dados(L);
                break;
            case 6:
                sair =terminar();
                break;
            default:
                printf("opcao invalida, tente outra !\n");
                system("pause");
                break;
        }
    system("cls");
    }while(sair != 1);
    return 0;
}
