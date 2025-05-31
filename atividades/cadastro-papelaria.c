#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 40
#define DESCRICAO_TAM 50

typedef struct {
    int codigo;
    char descricao[DESCRICAO_TAM];
    float valor_unitario;
    int quantidade_estoque;
} Produto;

Produto produtos[MAX_PRODUTOS];
int totalProdutos = 0;

// (a) Cadastrar novo produto
void cadastrarProduto() {
    if (totalProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos cadastrados atingido.\n");
        return;
    }
    Produto p;
    printf("Digite o código do produto: ");
    scanf("%d", &p.codigo);
    
    // Verifica se o código já existe
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == p.codigo) {
            printf("Código já cadastrado. Cadastro cancelado.\n");
            return;
        }
    }

    printf("Digite a descrição do produto: ");
    getchar(); 
    fgets(p.descricao, DESCRICAO_TAM, stdin);
    p.descricao[strcspn(p.descricao, "\n")] = 0; 
    
    printf("Digite o valor unitário do produto: ");
    scanf("%f", &p.valor_unitario);
    
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &p.quantidade_estoque);

    produtos[totalProdutos++] = p;
    printf("Produto cadastrado com sucesso!\n");
}

// Função auxiliar para encontrar índice do produto pelo código
int encontrarProduto(int codigo) {
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigo) return i;
    }
    return -1; // não encontrado
}

// (b) Alterar valor unitário dado o código
void alterarValorUnitario(int codigo) {
    int idx = encontrarProduto(codigo);
    if (idx == -1) {
        printf("Produto não encontrado.\n");
        return;
    }
    printf("Valor unitário atual: %.2f\n", produtos[idx].valor_unitario);
    printf("Digite o novo valor unitário: ");
    scanf("%f", &produtos[idx].valor_unitario);
    printf("Valor atualizado com sucesso.\n");
}

// (c) Função para informar valor unitário dado o código
float obterValorUnitario(int codigo) {
    int idx = encontrarProduto(codigo);
    if (idx == -1) return -1.0; // indicar erro
    return produtos[idx].valor_unitario;
}

// (d) Função para informar quantidade em estoque dado o código
int obterQuantidadeEstoque(int codigo) {
    int idx = encontrarProduto(codigo);
    if (idx == -1) return -1; // indicar erro
    return produtos[idx].quantidade_estoque;
}

// (e) Procedimento de venda
void venda(int codigo, int quantidade_desejada) {
    int idx = encontrarProduto(codigo);
    if (idx == -1) {
        printf("Produto não encontrado.\n");
        return;
    }

    if (produtos[idx].quantidade_estoque == 0) {
        printf("Produto com estoque zero.\n");
        return;
    }

    if (quantidade_desejada > produtos[idx].quantidade_estoque) {
        printf("Quantidade desejada maior que a disponível (%d).\n", produtos[idx].quantidade_estoque);
        printf("Deseja comprar todo o estoque disponível? (1-Sim / 0-Não): ");
        int opcao;
        scanf("%d", &opcao);
        if (opcao == 1) {
            float valor_total = produtos[idx].quantidade_estoque * produtos[idx].valor_unitario;
            printf("Compra efetuada. Valor a pagar: R$ %.2f\n", valor_total);
            produtos[idx].quantidade_estoque = 0;
        } else {
            printf("Compra cancelada.\n");
        }
    } else {
        float valor_total = quantidade_desejada * produtos[idx].valor_unitario;
        produtos[idx].quantidade_estoque -= quantidade_desejada;
        printf("Compra efetuada. Valor a pagar: R$ %.2f\n", valor_total);
    }
}

// (f) Atualizar quantidade em estoque dado o código
void atualizarEstoque(int codigo, int nova_quantidade) {
    int idx = encontrarProduto(codigo);
    if (idx == -1) {
        printf("Produto não encontrado.\n");
        return;
    }
    produtos[idx].quantidade_estoque = nova_quantidade;
    printf("Estoque atualizado com sucesso.\n");
}

// (g) Exibir código e descrição de todos os produtos
void exibirTodosProdutos() {
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    printf("Produtos cadastrados:\n");
    for (int i = 0; i < totalProdutos; i++) {
        printf("Código: %d - Descrição: %s\n", produtos[i].codigo, produtos[i].descricao);
    }
}

// (h) Exibir produtos com estoque zero
void exibirProdutosEstoqueZero() {
    int encontrados = 0;
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].quantidade_estoque == 0) {
            printf("Código: %d - Descrição: %s\n", produtos[i].codigo, produtos[i].descricao);
            encontrados = 1;
        }
    }
    if (!encontrados) {
        printf("Não há produtos com estoque zero.\n");
    }
}

int main() {
    int opcao, codigo, quantidade;
    float valor;
    
    do {
        printf("\n--- Menu Papelaria ---\n");
        printf("1. Cadastrar novo produto\n");
        printf("2. Alterar valor unitário do produto\n");
        printf("3. Consultar valor unitário do produto\n");
        printf("4. Consultar quantidade em estoque do produto\n");
        printf("5. Realizar venda\n");
        printf("6. Atualizar quantidade em estoque\n");
        printf("7. Exibir todos os produtos\n");
        printf("8. Exibir produtos com estoque zero\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                printf("Digite o código do produto para alterar valor: ");
                scanf("%d", &codigo);
                alterarValorUnitario(codigo);
                break;
            case 3:
                printf("Digite o código do produto para consultar valor: ");
                scanf("%d", &codigo);
                valor = obterValorUnitario(codigo);
                if (valor < 0)
                    printf("Produto não encontrado.\n");
                else
                    printf("Valor unitário: R$ %.2f\n", valor);
                break;
            case 4:
                printf("Digite o código do produto para consultar estoque: ");
                scanf("%d", &codigo);
                quantidade = obterQuantidadeEstoque(codigo);
                if (quantidade < 0)
                    printf("Produto não encontrado.\n");
                else
                    printf("Quantidade em estoque: %d\n", quantidade);
                break;
            case 5:
                printf("Digite o código do produto para venda: ");
                scanf("%d", &codigo);
                printf("Digite a quantidade desejada: ");
                scanf("%d", &quantidade);
                venda(codigo, quantidade);
                break;
            case 6:
                printf("Digite o código do produto para atualizar estoque: ");
                scanf("%d", &codigo);
                printf("Digite a nova quantidade em estoque: ");
                scanf("%d", &quantidade);
                atualizarEstoque(codigo, quantidade);
                break;
            case 7:
                exibirTodosProdutos();
                break;
            case 8:
                exibirProdutosEstoqueZero();
                break;
            case 0:
                printf("Encerrando programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
        
    } while(opcao != 0);

    return 0;
}
