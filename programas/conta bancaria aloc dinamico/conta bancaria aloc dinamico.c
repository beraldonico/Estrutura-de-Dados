#include<stdio.h>

struct conta{
    int num_conta;
    int saldo;
};

int imprimir_opcoes();
void criar_conta();
void realizar_deposito();
void realizar_saque();
void imprimir_saldo();
int sair();

int main(){
    struct conta conta1;
    do {
        switch (imprimir_opcoes()){
            case 1:
                criar_conta();
            break;
            case 2:
                realizar_deposito();
            break;
            case 3:
                realizar_saque();
            break;
            case 4:
                imprimir_saldo();
            break;
            default:printf("opcao invalida, tente outra !");
            break;
        }
    }while(sair()!= 1);
    return 0;
}

int imprimir_opcoes(){
    int x;
    printf("escolha opcao: \n");
    printf("1 : criar conta. \n");
    printf("2 : depositar. \n");
    printf("3 : sacar. \n");
    printf("4 : imprimir saldo. \n");
    printf("5 : sair.\n");
    printf("opcao : ");
    scanf("%i", &x);
    printf("\n");
    return x;
}

void criar_conta(){
    printf("escolha o numero da conta: ");
    scanf("%i", &conta1.num_conta);
    printf("\n");
    printf("Seu saldo eh de 0 reias \n\n");
    conta1.saldo = 0;
}

void realizar_deposito(){
    int deposito;
    printf("realize um deposito: ");
    scanf("%i", &deposito);
    conta1.saldo = conta1.saldo + deposito;
    printf("\n");
    printf("seu saldo atual eh de :%i",conta1.saldo);
    printf("\n \n");
}

void realizar_saque(){
    int saque;
    printf("quanto deseja sacar:\n");
    scanf("%i", &saque);
    printf("\n");
    conta1.saldo = conta1.saldo - saque;
    printf("seu saldo restante eh de :%i",conta1.saldo);
    printf("\n \n");
}

void imprimir_saldo(){
    printf("seu saldo eh de :%i \n", conta1.saldo);
    printf("\n");
}
int sair(){
    int exit;
    printf("deseja sair (1 para sim ou 0 para nao)? : ");
    scanf("%i",&exit);
    return exit;
}
