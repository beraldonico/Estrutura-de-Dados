#include <stdio.h>
#include <stdlib.h>
#include "Ordem.h"

void visit(node *n){
    if(n == NULL){
        return;
    }
    printf("%c ", n->value);
    return;
}

void dfspre(node *n){ //213
    if(n == NULL){
        return;
    }
    visit(n);
    dfspre(n->left);
    dfspre(n->right);
    return;
}

void dfsin(node *n){//123
    if(n == NULL){
        return;
    }
    dfsin(n->left);
    visit(n);
    dfsin(n->right);
    return;
}

void dfspos(node *n){//132
    if(n == NULL){
        return;
    }
    dfspos(n->left);
    dfspos(n->right);
    visit(n);
    return;
}
