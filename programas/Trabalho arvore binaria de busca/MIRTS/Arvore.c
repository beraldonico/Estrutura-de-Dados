#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"
#define MAX(A,B) ((A>B) ? (A):(B))

node *insere(node *n, int k){
    if (n == NULL){
        node*n=malloc(sizeof(node));
        if(n == NULL){
                printf("Erro");
            return NULL;
        }
        n->left = NULL;
        n->right = NULL;
        n->value = k;
        return n;
    }
    if (k < n->value){
        n->left = insere(n->left,k);
    }else{
        n->right = insere(n->right, k);
    }
    return n;
}

node*RemRaiz(node*n){
    if(n == NULL) return NULL;
    if(n->left == NULL){
        node*r = n->right;
        free(n);
        return r;
    }
    if(n->left->right == NULL){
        n->left->right = n->right;
        node*l=n->left;
        free(n);
        return l;
    }
    if(n->right == NULL){
        node*r = n->left;
        free(n);
        return r;
    }
    if(n->right->left == NULL){
        n->right->left = n->left;
        node*l=n->right;
        free(n);
        return l;
    }
    node*p=n->right->left;
    node*f=p->right;
    while(f->right != NULL){
         p=f;
         f=f->right;
    }
    p->right = f->left;
    f->left=n->left;
    f->right=n->right;
    free(n);
    return f;
}
