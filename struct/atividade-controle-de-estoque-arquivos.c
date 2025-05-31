#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS_VENDA 10
#define MAX_DESC 50

typedef struct {
    int id;
    char produto[MAX_DESC]; 
    float preco;
    int quantidade;
} Produto;

typedef struct {
    int id;
    char data[11]; // dd/mm/yyyy
    int produtos_ids[MAX_PRODUTOS_VENDA];
    int qtd_produtos;
} Venda;

void cadastrarProduto();
void atualizarProduto();
void listarProdutos();
void removerProduto();

void cadastrarVenda();
void listarVendas();

Produto buscarProdutoPorId(int id);
int existeProduto(int id);
Venda buscarVendaPorId(int id);
int existeVenda(int id);

int main() {
    int opcao;

    do {
        printf("\n--- Controle de Estoque e Vendas ---\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Atualizar Produto\n");
        printf("3. Listar Produtos\n");
        printf("4. Remover Produto\n");
        printf("5. Cadastrar Venda\n");
        printf("6. Listar Vendas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarProduto(); break;
            case 2: atualizarProduto(); break;
            case 3: listarProdutos(); break;
            case 4: removerProduto(); break;
            case 5: cadastrarVenda(); break;
            case 6: listarVendas(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}

void cadastrarProduto() {
    FILE *fp = fopen("produto.bin", "ab");
    if (!fp) {
        perror("Erro ao abrir arquivo de produtos");
        return;
    }

    Produto p;
    printf("ID do Produto: ");
    scanf("%d", &p.id);

    if (existeProduto(p.id)) {
        printf("Produto com este ID ja existe!\n");
        fclose(fp);
        return;
    }

    printf("Nome do produto: ");
    getchar(); 
    fgets(p.produto, MAX_DESC, stdin);
    p.produto[strcspn(p.produto, "\n")] = 0;

    printf("Preco: ");
    scanf("%f", &p.preco);

    printf("Quantidade em estoque: ");
    scanf("%d", &p.quantidade);

    fwrite(&p, sizeof(Produto), 1, fp);
    fclose(fp);
    printf("Produto cadastrado com sucesso.\n");
}

void atualizarProduto() {
    FILE *fp = fopen("produto.bin", "rb+");
    if (!fp) {
        perror("Erro ao abrir arquivo de produtos");
        return;
    }

    int id;
    printf("ID do Produto para atualizar: ");
    scanf("%d", &id);

    Produto p;
    int achou = 0;

    while (fread(&p, sizeof(Produto), 1, fp)) {
        if (p.id == id) {
            achou = 1;
            printf("Produto encontrado: %s\n", p.produto);

            int opcao;
            printf("O que deseja atualizar?\n");
            printf("1. Nome do produto\n");
            printf("2. Preco\n");
            printf("3. Quantidade em estoque\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);
            getchar(); 

            switch (opcao) {
                case 1:
                    printf("Novo nome do produto: ");
                    fgets(p.produto, MAX_DESC, stdin);
                    p.produto[strcspn(p.produto, "\n")] = 0;
                    break;
                case 2:
                    printf("Novo preco: ");
                    scanf("%f", &p.preco);
                    break;
                case 3:
                    printf("Nova quantidade: ");
                    scanf("%d", &p.quantidade);
                    break;
                default:
                    printf("Opcao invalida.\n");
                    fclose(fp);
                    return;
            }

            fseek(fp, -sizeof(Produto), SEEK_CUR);
            fwrite(&p, sizeof(Produto), 1, fp);
            printf("Produto atualizado com sucesso.\n");
            break;
        }
    }

    if (!achou) {
        printf("Produto nao encontrado.\n");
    }

    fclose(fp);
}

void listarProdutos() {
    FILE *fp = fopen("produto.bin", "rb");
    if (!fp) {
        perror("Erro ao abrir arquivo de produtos");
        return;
    }

    Produto p;
    printf("\n--- Lista de Produtos ---\n");
    while (fread(&p, sizeof(Produto), 1, fp)) {
        printf("ID: %d | Produto: %s | Preco: %.2f | Quantidade: %d\n",
               p.id, p.produto, p.preco, p.quantidade);
    }
    fclose(fp);
}

void removerProduto() {
    int id;
    printf("ID do Produto para remover: ");
    scanf("%d", &id);

    FILE *fp = fopen("produto.bin", "rb");
    if (!fp) {
        perror("Erro ao abrir arquivo de produtos");
        return;
    }

    FILE *fp_tmp = fopen("produto_tmp.bin", "wb");
    if (!fp_tmp) {
        perror("Erro ao criar arquivo temporario");
        fclose(fp);
        return;
    }

    Produto p;
    int achou = 0;
    while (fread(&p, sizeof(Produto), 1, fp)) {
        if (p.id == id) {
            achou = 1;
        } else {
            fwrite(&p, sizeof(Produto), 1, fp_tmp);
        }
    }

    fclose(fp);
    fclose(fp_tmp);

    if (!achou) {
        printf("Produto nao encontrado.\n");
        remove("produto_tmp.bin");
        return;
    }

    remove("produto.bin");
    rename("produto_tmp.bin", "produto.bin");
    printf("Produto removido com sucesso.\n");
}

void cadastrarVenda() {
    FILE *fp = fopen("venda.bin", "ab");
    if (!fp) {
        perror("Erro ao abrir arquivo de vendas");
        return;
    }

    Venda v;
    printf("ID da Venda: ");
    scanf("%d", &v.id);

    if (existeVenda(v.id)) {
        printf("Venda com este ID ja existe!\n");
        fclose(fp);
        return;
    }

    printf("Data (dd/mm/yyyy): ");
    getchar();
    fgets(v.data, 11, stdin);
    v.data[strcspn(v.data, "\n")] = 0;

    printf("Quantos produtos nesta venda (max %d): ", MAX_PRODUTOS_VENDA);
    scanf("%d", &v.qtd_produtos);

    if (v.qtd_produtos < 1 || v.qtd_produtos > MAX_PRODUTOS_VENDA) {
        printf("Quantidade invalida.\n");
        fclose(fp);
        return;
    }

    for (int i = 0; i < v.qtd_produtos; i++) {
        printf("ID do produto %d: ", i+1);
        scanf("%d", &v.produtos_ids[i]);

        if (!existeProduto(v.produtos_ids[i])) {
            printf("Produto com ID %d nao existe. Cancelando cadastro.\n", v.produtos_ids[i]);
            fclose(fp);
            return;
        }
    }

    fwrite(&v, sizeof(Venda), 1, fp);
    fclose(fp);
    printf("Venda cadastrada com sucesso.\n");
}

void listarVendas() {
    FILE *fp = fopen("venda.bin", "rb");
    if (!fp) {
        perror("Erro ao abrir arquivo de vendas");
        return;
    }

    Venda v;
    Produto p;
    printf("\n--- Lista de Vendas ---\n");
    while (fread(&v, sizeof(Venda), 1, fp)) {
        printf("Venda ID: %d | Data: %s\nProdutos:\n", v.id, v.data);
        for (int i = 0; i < v.qtd_produtos; i++) {
            p = buscarProdutoPorId(v.produtos_ids[i]);
            if (p.id != 0)
                printf("  - %s (ID %d)\n", p.produto, p.id);
            else
                printf("  - Produto ID %d nao encontrado\n", v.produtos_ids[i]);
        }
        printf("\n");
    }

    fclose(fp);
}

Produto buscarProdutoPorId(int id) {
    Produto p = {0};
    FILE *fp = fopen("produto.bin", "rb");
    if (!fp) return p;

    while (fread(&p, sizeof(Produto), 1, fp)) {
        if (p.id == id) {
            fclose(fp);
            return p;
        }
    }

    fclose(fp);
    Produto vazio = {0};
    return vazio;
}

int existeProduto(int id) {
    Produto p = buscarProdutoPorId(id);
    return (p.id != 0);
}

Venda buscarVendaPorId(int id) {
    Venda v = {0};
    FILE *fp = fopen("venda.bin", "rb");
    if (!fp) return v;

    while (fread(&v, sizeof(Venda), 1, fp)) {
        if (v.id == id) {
            fclose(fp);
            return v;
        }
    }

    fclose(fp);
    Venda vazio = {0};
    return vazio;
}

int existeVenda(int id) {
    Venda v = buscarVendaPorId(id);
    return (v.id != 0);
}
