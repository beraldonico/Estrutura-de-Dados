typedef struct info{
    char nome[30];
    int  matricula;
    char CPF[15];
    char curso[30];
    char data[10];
    float renda;
    struct info *prox;
}Dados;

void completar(Dados *novo , char *nome, int matricula, char *CPF, char *curso, char *data, float renda);
