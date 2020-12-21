typedef struct Lista{
    Dados *prox;
}lista;

lista *iniciar_lista();

void inserir_inicio(lista *L, char *nome, int matricula, char *CPF, char *curso, char *data, float renda);
/*remover*/
void buscar_remover_nome(lista *L, char args[1]);
void buscar_remover_matricula(lista *L, char args[1]);
void buscar_remover_CPF(lista *L, char args[1]);
void buscar_remover_curso(lista *L, char *args);
void buscar_remover_data_igual(lista *L, char args[1]);
void buscar_remover_data_maior(lista *L, char args[1]);
void buscar_remover_data_menor(lista *L, char args[1]);
void buscar_remover_renda_igual(lista *L, char args[1]);
void buscar_remover_renda_menor(lista *L, char args[1]);
void buscar_remover_renda_maior(lista *L, char args[1]);
/* buscar */
void buscar_imprimir_nome(lista *L, char args[1]);
void buscar_imprimir_matricula(lista *L, char args[1]);
void buscar_imprimir_CPF(lista *L, char args[1]);
void buscar_imprimir_curso(lista *L, char args[1]);
void buscar_imprimir_data_igual(lista *L, char args[1]);
void buscar_imprimir_data_maior(lista *L, char args[1]);
void buscar_imprimir_data_menor(lista *L, char args[1]);
void buscar_imprimir_renda_igual(lista *L, char args[1]);
void buscar_imprimir_renda_maior(lista *L, char args[1]);
void buscar_imprimir_renda_menor(lista *L, char args[1]);

