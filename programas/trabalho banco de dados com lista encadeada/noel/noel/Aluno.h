#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED

typedef struct{
    char* nome;
    int matricula;
    char* cpf;
    char* curso;
    char* nasc;
    float patrimonio;
}Aluno;

Aluno* novoAluno();

void edita(Aluno* aluno, int op, char* valor);

void mostraAluno(Aluno* aluno);

#endif

