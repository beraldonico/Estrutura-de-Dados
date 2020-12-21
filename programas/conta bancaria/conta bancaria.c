#include<stdio.h>

struct conta{
    int num_conta;
    int saldo;
};
int main(){
    int x, saque, imprimir, deposito, exit =0;
    struct conta conta1;
    do {
        printf("escolha opcao: \n");
        printf("1 : criar conta. \n");
        printf("2 : depositar. \n");
        printf("3 : sacar. \n");
        printf("4 : imprimir saldo. \n");
        printf("5 : sair.\n");
        printf("opcao : ");
        scanf("%i", &x);
        printf("\n");
        switch (x){
            case 1:
                printf("escolha o numero da conta: ");
                scanf("%i", &conta1.num_conta);
                printf("\n");
                printf("Seu saldo eh de 0 reias \n\n");
                conta1.saldo = 0;
            break;
            case 2:
                printf("realize um deposito: ");
                scanf("%i", &deposito);
                conta1.saldo = conta1.saldo + deposito;
                printf("\n");
                printf("seu saldo atual eh de :%i",conta1.saldo);
                printf("\n \n");
            break;
            case 3:
                printf("quanto deseja sacar:\n");
                scanf("%i", &saque);
                printf("\n");
                conta1.saldo = conta1.saldo - saque;
                printf("seu saldo restante eh de :%i",conta1.saldo);
                printf("\n \n");
            break;
            case 4:
                printf("seu saldo eh de :%i \n", conta1.saldo);
                printf("\n");
            break;
            case 5:
                printf("deseja sair (1 para sim ou 0 para nao)? : ");
                scanf("%i",&exit);
                printf("\n");
            break;
            default:printf("opcao invalida, tente outra !");
            break;
        }
    }while(exit!= 1);
    printf("obrigado por me usar !!! \n");
    return 0;
}
