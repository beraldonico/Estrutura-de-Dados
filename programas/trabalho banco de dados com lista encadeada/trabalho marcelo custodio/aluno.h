#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED

typedef struct{
    char* nome;
    int matricula;
    char* cpf;
    char* curso;
    char* dn;
    float patrimonio;
}Aluno;

Aluno* newAluno();

void freeAluno(Aluno* aluno);

void editaAluno(Aluno* aluno, int param, char* valor);

void mostraAluno(Aluno* aluno);

#endif // ALUNO_H_INCLUDED
