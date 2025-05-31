#include <stdio.h>
#include <string.h>

#define MAX_CONTAS 100

typedef struct {
    int numeroConta;
    char nome[100];
    char cpf[15];
    char telefone[20];
    float saldo;
} Conta;

// (a) Função de busca
int buscaConta(Conta cadastro[], int qtd, int numeroConta) {
    if (qtd == 0) {
        return -1; // cadastro vazio
    }
    for (int i = 0; i < qtd; i++) {
        if (cadastro[i].numeroConta == numeroConta) {
            return i; // encontrado na posição i
        }
    }
    return -2; // não encontrado
}

// (b) Procedimento para cadastrar nova conta
void cadastrarConta(Conta cadastro[], int *qtd, int numeroConta) {
    int pos = buscaConta(cadastro, *qtd, numeroConta);
    if (pos >= 0) {
        printf("Número de conta já existe. Cadastro não permitido.\n");
        return;
    }
    if (*qtd >= MAX_CONTAS) {
        printf("Cadastro cheio, não é possível adicionar mais contas.\n");
        return;
    }
    if (pos == -1 || pos == -2) {
        Conta novaConta;
        novaConta.numeroConta = numeroConta;
        printf("Informe o nome do cliente: ");
        getchar(); 
        fgets(novaConta.nome, 100, stdin);
        novaConta.nome[strcspn(novaConta.nome, "\n")] = 0; 

        printf("Informe o CPF do cliente: ");
        fgets(novaConta.cpf, 15, stdin);
        novaConta.cpf[strcspn(novaConta.cpf, "\n")] = 0;

        printf("Informe o telefone de contato: ");
        fgets(novaConta.telefone, 20, stdin);
        novaConta.telefone[strcspn(novaConta.telefone, "\n")] = 0;

        printf("Informe o saldo inicial: ");
        scanf("%f", &novaConta.saldo);

        cadastro[*qtd] = novaConta;
        (*qtd)++;
        printf("Conta cadastrada com sucesso!\n");
    }
}

// (c) Procedimento para consultar saldo
void consultarSaldo(Conta cadastro[], int qtd, int numeroConta) {
    int pos = buscaConta(cadastro, qtd, numeroConta);
    if (pos >= 0) {
        printf("Saldo da conta %d: R$ %.2f\n", numeroConta, cadastro[pos].saldo);
    } else {
        printf("Conta não cadastrada.\n");
    }
}

// (d) Procedimento para depósito
void depositar(Conta cadastro[], int qtd, int numeroConta) {
    int pos = buscaConta(cadastro, qtd, numeroConta);
    if (pos >= 0) {
        float valor;
        printf("Informe o valor a depositar: ");
        scanf("%f", &valor);
        if (valor > 0) {
            cadastro[pos].saldo += valor;
            printf("Depósito realizado com sucesso. Novo saldo: R$ %.2f\n", cadastro[pos].saldo);
        } else {
            printf("Valor inválido.\n");
        }
    } else {
        printf("Conta não cadastrada.\n");
    }
}

// (e) Procedimento para saque
void sacar(Conta cadastro[], int qtd, int numeroConta) {
    int pos = buscaConta(cadastro, qtd, numeroConta);
    if (pos >= 0) {
        float valor;
        printf("Informe o valor a sacar: ");
        scanf("%f", &valor);
        if (valor <= 0) {
            printf("Valor inválido.\n");
            return;
        }
        if (cadastro[pos].saldo >= valor) {
            cadastro[pos].saldo -= valor;
            printf("Saque realizado com sucesso. Novo saldo: R$ %.2f\n", cadastro[pos].saldo);
        } else {
            printf("Saldo insuficiente.\n");
        }
    } else {
        printf("Conta não cadastrada.\n");
    }
}

// (f) Procedimento para exibir todas as contas
void exibirContas(Conta cadastro[], int qtd) {
    if (qtd == 0) {
        printf("Nenhuma conta cadastrada.\n");
        return;
    }
    for (int i = 0; i < qtd; i++) {
        printf("Conta nº: %d\n", cadastro[i].numeroConta);
        printf("Nome: %s\n", cadastro[i].nome);
        printf("Telefone: %s\n", cadastro[i].telefone);
        printf("-----------------------\n");
    }
}

int main() {
    Conta contasCorrente[MAX_CONTAS];
    Conta contasPoupanca[MAX_CONTAS];
    int qtdCorrente = 0, qtdPoupanca = 0;

    int opcao, tipoConta, numConta;

    do {
        printf("\n--- Banco Dinheiro Certo ---\n");
        printf("1. Cadastrar conta\n");
        printf("2. Consultar saldo\n");
        printf("3. Depositar\n");
        printf("4. Sacar\n");
        printf("5. Exibir todas as contas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 0) break;

        if (opcao >= 1 && opcao <= 5) {
            printf("Escolha o tipo de conta: 1 - Corrente, 2 - Poupança: ");
            scanf("%d", &tipoConta);
            if (tipoConta != 1 && tipoConta != 2) {
                printf("Tipo de conta inválido.\n");
                continue;
            }
            Conta *cadastro;
            int *qtd;

            if (tipoConta == 1) {
                cadastro = contasCorrente;
                qtd = &qtdCorrente;
            } else {
                cadastro = contasPoupanca;
                qtd = &qtdPoupanca;
            }

            switch(opcao) {
                case 1:
                    printf("Informe o número da nova conta: ");
                    scanf("%d", &numConta);
                    cadastrarConta(cadastro, qtd, numConta);  
                    break;
                case 2:
                    printf("Informe o número da conta para consultar saldo: ");
                    scanf("%d", &numConta);
                    consultarSaldo(cadastro, *qtd, numConta);  
                    break;
                case 3:
                    printf("Informe o número da conta para depósito: ");
                    scanf("%d", &numConta);
                    depositar(cadastro, *qtd, numConta);  
                    break;
                case 4:
                    printf("Informe o número da conta para saque: ");
                    scanf("%d", &numConta);
                    sacar(cadastro, *qtd, numConta);  
                    break;
                case 5:
                    exibirContas(cadastro, *qtd);  
                    break;
            }
        } else {
            printf("Opção inválida.\n");
        }
    } while (1);

    printf("Programa encerrado.\n");
    return 0;
}
