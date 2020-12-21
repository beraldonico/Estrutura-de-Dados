#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *left;
    struct node *right;
}node;

node *insere(node *n, int k);
node *RemRaiz(node *n);

#endif // ARVORE_H_INCLUDED
