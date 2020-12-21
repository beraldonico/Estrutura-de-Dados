/* trabalho desenvolvido por jhonathan de angelo e nicolas beraldo*/

#include<stdio.h>
#include<stdlib.h>

void caminho(char *lab, int entra, int sai, int L, int C);
void limparmapa(char *lab, int L, int C);
void printmapa(char *mapa,int L, int C);
void printcaminho(int *pilha, int L, int C);

int main ()
{
    int L,C,Xe,Ye,Xs,Ys,i,j;
    char *mapa;
    FILE *arq;
    arq=fopen("labirinto1.txt", "r");
    if(arq == NULL)
        printf("Erro, nao foi possivel abrir o arquivo\n");
    else
    {
        fscanf(arq, "%i %i \n",&L, &C);
        fscanf(arq, "%i %i \n",&Xe, &Ye);
        fscanf(arq, "%i %i \n",&Xs, &Ys);
        printf(" Tamanho do Labirinto: %i*%i\n",L,C);
        printf(" Ponto de Entrada: [%i,%i]\n",Xe, Ye);
        printf(" Ponto de Saida: [%i,%i]\n",Xs, Ys);
        int size = L*C+2;
        mapa = malloc(size*sizeof(char));
        for (i=0; i<L && fgets(&mapa[i*C], size, arq); i++){
            size -= C;
        }
        printmapa(mapa, L, C);
        caminho(mapa, Ye*C+Xe, Ys*C+Xs, L, C);
    }
    return 0;
}

void caminho(char *lab, int entra, int sai, int L, int C)
{
    int piao = entra, deu =0;
    int pilha[L*C],t =0;
    if(lab[piao] == 'H')
    {
        printf("Entrada do labirinto invalida !\n");
        return;
    }
    if(lab[sai] == 'H')
    {
        printf("Saida do labirinto invalida !\n");
        return;
    }
    for(deu=0; deu<(L*C); deu ++)
    {
        pilha[deu]= 0;
    }
    do
    {
        if(lab[piao-L] == ' ')      //cima
        {
            pilha[t++]=piao;
            lab[piao] = '*';
            piao -= L;
        }
        else if(lab[piao+L] == ' ') //baixo
        {
            pilha[t++]=piao;
            lab[piao] = '*';
            piao += L;
        }
        else if(lab[piao-1] == ' ') //esquerda
        {
            pilha[t++]=piao;
            lab[piao] = '*';
            piao -= 1;
        }
        else if(lab[piao+1] == ' ') //direita
        {
            pilha[t++]=piao;
            lab[piao] = '*';
            piao += 1;
        }
        else if(lab[piao-L] == '*') //volta cima
        {
            lab[piao] = 'X';
            piao -= L;
            pilha[t--] = 0;
        }
        else if(lab[piao+L] == '*') //volta baixo
        {
            lab[piao] = 'X';
            piao += L;
            pilha[t--] = 0;
        }
        else if(lab[piao-1] == '*') //volta esquerda
        {
            lab[piao] = 'X';
            piao -= 1;
            pilha[t--] = 0;
        }
        else if(lab[piao+1] == '*') //volta diretira
        {
            lab[piao] = 'X';
            piao += 1;
            pilha[t--] = 0;
        }
        else if(lab[piao-L] != ' ' && lab[piao+L] != ' ' && lab[piao-1] != ' ' && lab[piao+1] != ' ')
        {
            printf("Nao ha caminho possivel\n\n");
            deu = 1;
        }
        if(piao == sai)
        {
            printf("labirinto concluido !!\n\n");
            deu = 1;
        }
    }
    while(deu != 1);
    lab[piao] = '*';
    limparmapa(lab, L, C);
    printcaminho(pilha,L,C);
    printmapa(lab, L, C);
    return;
}

void printcaminho(int *pilha, int L, int C)
{
    int j;
    for(j=0; j<((C*L)/2); j++)
    {
        printf("%i ", pilha[j]);
    }
    printf("\n\n");
}

void limparmapa(char *lab, int L, int C)
{
    int i,j;
    for (i=0; i<L; i++)
    {
        for(j=0; j<C; j++)
        {
            if(lab[j*C+i] == 'X')
            {
                lab[j*C+i] = ' ';
            }
        }
    }
}

void printmapa(char *mapa,int L, int C)
{
    int j,i;
    for(j=0; j<L; j++)
    {
        for(i=0; i<C; i++)
        {
            printf(" %c", mapa[j*C+i]);
         //   printf("\nopa\n");
        }
        printf("\n");
    }
    printf("\n");
}
