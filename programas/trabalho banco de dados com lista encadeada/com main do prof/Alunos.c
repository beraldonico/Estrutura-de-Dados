#include "Alunos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void completar(Dados *novo , char *nome, int matricula, char *CPF, char *curso, char *data, float renda){
    strcpy((novo -> nome),nome);
    (novo -> matricula) = matricula;
    strcpy((novo -> CPF),CPF);
    strcpy((novo -> curso),curso);
    strcpy((novo -> data),data);
    (novo -> renda) = renda;
}
