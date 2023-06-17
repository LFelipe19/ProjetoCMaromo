#include <stdio.h>
#include <string.h>

typedef struct {
    int numero;
    char cliente[51];
    int especial;
    float saldo;
} Conta;

void inserir(Conta* contas, int* totalContas) {

    Conta novaConta;

    printf("Digite um numero para cadastrar a conta: ");
    scanf("%d", &novaConta.numero);

    for (int i = 0; i < *totalContas; i++) {
        if (contas[i].numero == novaConta.numero) {
            printf("Esse numero ja existe, digite outro numero\n"); return;
        }
    }

    if (*totalContas >= 3) {
        printf("Voce atingiu o numero de contas maximo permitido.\n"); return;
    }

    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", novaConta.cliente);
    printf("A conta eh especial? (Digete 1 para Sim e 2 para Nao): ");
    scanf("%d", &novaConta.especial);
    if (novaConta.especial != 1 && novaConta.especial != 2 ) {
        printf("Tipo de conta inexistente, digite o tipo novamente"); return;
    }
    printf("Digite o saldo atual da conta: ");
    scanf("%f", &novaConta.saldo);
    if (novaConta.saldo < 0) {
        printf("Saldo invalido."); return;
    }

    contas[*totalContas] = novaConta;
    (*totalContas)++;

    printf("A conta foi adicionada.\n");

}

void alterar(Conta* contas, int totalContas) {
    int numeroDeConta, i;
    printf("Digite o numero da conta a ser alterada: ");
    scanf("%d", &numeroDeConta);

    for (i = 0; i < totalContas; i++) {
        if (contas[i].numero == numeroDeConta) {
            printf("Digite o novo nome do cliente: ");
            scanf(" %[^\n]", contas[i].cliente);
            printf("Nome do cliente alterado com sucesso.\n");

        }
    }
    if(!numeroDeConta) {
        printf("Conta nao encontrada.\n");
    }
}

void procurar(Conta* contas, int totalContas) {
    int NumeroDaConta;
    printf("Digite o numero da conta: ");
    scanf("%d", &NumeroDaConta);

    for (int i = 0; i < totalContas; i++) {
        if (contas[i].numero == NumeroDaConta) {
            printf("Conta encontrada:\n");
            printf("Número da conta: %d\n", contas[i].numero);
            printf("Nome do cliente: %s\n", contas[i].cliente);
            printf("Tipo de conta: %s\n", contas[i].especial ? "Especial" : "Normal");
            printf("Saldo atual: %.2fR$\n", contas[i].saldo);
            return;
        }
    }

    printf("Nao foi possivel encontrar esta conta, por favor verifique novamente o numero.\n");
}

void listar(Conta* contas, int totalContas) {
    int i;
    printf("XXXXXXXX Lista de contas bancarias: XXXXXXXX\n\n");

    for (i = 0; i < totalContas; i++) {
        printf("Número da conta: %d\n", contas[i].numero);
        printf("Nome do cliente: %s\n", contas[i].cliente);
        if (contas[i].especial == 1)
            printf("Tipo de conta: Especial\n");
        else
            printf("Tipo de conta: Normal\n");
        printf("Saldo: R$ %.2f\n", contas[i].saldo);
        printf("(.----.----.----.-----.-----.----.)\n\n");
    }
    if(totalContas == 0){
        printf("[ERRO] Nenhuma conta foi cadastrada");
    }
}
void depositar(Conta* contas, int totalContas) {
    int numeroConta, i;
    float valorDoDeposito;
    printf("Digite o numero da conta para realizar o deposito: ");
    scanf("%d", &numeroConta);

    for (i = 0; i < totalContas; i++) {
        if (contas[i].numero == numeroConta) {
            printf("Digite o valor a ser depositado: ");
            scanf("%f", &valorDoDeposito);

            if (valorDoDeposito > 0) {
                contas[i].saldo += valorDoDeposito;
                printf("Deposito realizado com sucesso.\n");
                printf("Novo saldo da conta: R$ %.3fR$\n", contas[i].saldo);
                return;
            } if(valorDoDeposito <=0){
                printf("X[INVALIDO]X Digite um valor positivo (Maior que 0).\n");
            }
        }
    }

    printf("Conta não encontrada.\n");
}

void sacar(Conta* contas, int totalContas) {
    int numeroConta, i;
    float valor;
    printf("Digite o número da conta para saque: ");
    scanf("%d", &numeroConta);

    for (i = 0; i < totalContas; i++) {
        if (contas[i].numero == numeroConta) {
            printf("Digite o valor de saque: ");
            scanf("%f", &valor);

            if (valor > 0) {
                if (contas[i].saldo >= valor) {
                    contas[i].saldo -= valor;
                    printf("Novo saldo da conta: R$ %.2f\n", contas[i].saldo);
                } else {
                    printf("[Saldo Insuficiente] Não foi possivel realizar o saque.\n");
                }
                return;
            }
            if (valor <=0){
                printf("[INVALIDO] Digite um valor positivo (Maior que 0)\n");
                return;
            }
        }
    }

    printf("Conta não encontrada.\n");
}

void imprimir(Conta* contas, int totalContas) {
    int numeroConta, i;
    printf("Digite o numero da conta a ser impressa: ");
    scanf("%d", &numeroConta);

    for (i = 0; i < totalContas; i++) {
        if (contas[i].numero == numeroConta) {
            printf("Dados da conta:\n");
            printf("Número da conta: %d\n", contas[i].numero);
            printf("Nome do cliente: %s\n", contas[i].cliente);
            if (contas[i].especial == 1)
                printf("Tipo de conta: Especial\n");
            else
                printf("Tipo de conta: Normal\n");
            printf("Saldo: R$ %.2f\n", contas[i].saldo);
            return;
        }
    }

    printf("Conta não encontrada.\n");
}

void saldoGeral(Conta* contas, int totalContas) {
    float saldoTotal = 0.0;
    int i;
    for (i = 0; i < totalContas; i++) {
        saldoTotal += contas[i].saldo;
    }

    printf("Saldo total de todas as contas: R$ %.2f\n", saldoTotal);
    printf("'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'\n");
    if(totalContas == 0){
        printf("Nenhuma conta foi cadastrada no sistema");

    }
}


int main() {
    Conta contas[5];
    int totalContas = 0;
    int opcao;

    do {
        printf("1 - Inserir nova conta\n");
        printf("2 - Alterar dados da conta\n");
        printf("3 - Procurar conta\n");
        printf("4 - Listar contas\n");
        printf("5 - Realizar deposito\n");
        printf("6 - Realizar saque\n");
        printf("7 - Imprimir dados de uma conta\n");
        printf("8 - Mostrat saldo geral\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserir(contas, &totalContas);
                break;
            case 2:
                alterar(contas, totalContas);
                break;
            case 3:
                procurar(contas, totalContas);
                break;
            case 4:
                listar(contas, totalContas);
                break;
            case 5:
                depositar(contas, totalContas);
                break;
            case 6:
                sacar(contas, totalContas);
                break;
            case 7:
                imprimir(contas, totalContas);
                break;
            case 8:
                saldoGeral(contas, totalContas);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
