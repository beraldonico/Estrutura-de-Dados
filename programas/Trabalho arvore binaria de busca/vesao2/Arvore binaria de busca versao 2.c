#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    struct tree *esquerda;
    struct tree *direita;
    int valor;
}arvore;

typedef struct rais{
    struct tree *r;
}raiz;

void inserir(raiz *T,int V){
    if(T->r == NULL){
        arvore *t = malloc(sizeof(arvore));
        if(t == NULL){
            printf("erro ao alocar");
            return ;
        }
        t->esquerda = NULL;
        t->direita = NULL;
        t->valor = V;
        T->r = t;
        return;
    }
    arvore *t = T->r;
    arvore *novo = malloc(sizeof(arvore));
    if(novo == NULL){
        printf("erro ao alocar");
        return ;
    }
    for(;;){
        if(V < t->valor){
            if(t->esquerda == NULL){
                t->esquerda = novo;
                novo->esquerda = NULL;
                novo->direita = NULL;
                novo->valor = V;
                return;
            }
            t = t->esquerda;
        }
        if(V > t->valor){
            if(t->direita == NULL){
                t->direita = novo;
                novo->esquerda = NULL;
                novo->direita = NULL;
                novo->valor = V;
                return;
            }
            t = t->direita;
        }
    }
}

void pre(arvore *t){

    if(t == NULL){
        return;
    }
    printf("%i ", t->valor);
    pre(t->esquerda);
    pre(t->direita);
    return;
}

void in(arvore *t){
    if(t == NULL){
        return;
    }
    in(t->esquerda);
    if(t == NULL){
        return;
    }
    printf("%i ", t->valor);
    in(t->direita);
    return;
}

void pos(arvore *t){
    if(t == NULL){
        return;
    }
    pos(t->esquerda);
    pos(t->direita);
    if(t == NULL){
        return;
    }
    printf("%i ", t->valor);
    return;
}

int main(){
    int V,x,i=0;
    raiz *t= malloc(sizeof(raiz));
    t->r = NULL;
    printf("quantos valores deseja inserir: ");
    scanf(" %i",&x);
    do{
        if(x==i){
            break;
        }
        printf("Insira os valores: ");
        scanf(" %i",&V);
        inserir(t,V);
        i++;
    }while(1);
    arvore *T = t->r;
    pre(T);
    printf("\n");
    in(T);
    printf("\n");
    pos(T);
    printf("\n");
    return 0;
}
