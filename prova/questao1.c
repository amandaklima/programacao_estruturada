#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LIVROS 100

struct CadastroLivro {
    char titulo[100];
    char autor[100];
    int anopublicacao;
};

// Protótipos
void preencherLivros(struct CadastroLivro livros[], int numLivros);
void imprimirLivros(struct CadastroLivro livros[], int numLivros);
void ordenarPorAno(struct CadastroLivro livros[], int numLivros);
void imprimirLivroMaisAntigo(struct CadastroLivro livros[], int numLivros);
void buscarLivroPorAutor(struct CadastroLivro livros[], int numLivros, const char autor[]);

int main() {
    struct CadastroLivro livros[MAX_LIVROS];
    int numLivros = 0;
    int opcao;
    char autorBusca[100];

    printf("Digite o número de livros: ");
    scanf("%d", &numLivros);
    getchar(); // limpa o \n

    if (numLivros <= 0 || numLivros > MAX_LIVROS) {
        printf("Número inválido de livros.\n");
        return 1;
    }

    preencherLivros(livros, numLivros);

    do {
        printf("\n===== MENU =====\n");
        printf("1. Imprimir todos os livros\n");
        printf("2. Ordenar livros por ano de publicação\n");
        printf("3. Mostrar o livro mais antigo\n");
        printf("4. Buscar livros por autor\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // limpa o \n

        switch (opcao) {
            case 1:
                imprimirLivros(livros, numLivros);
                break;
            case 2:
                ordenarPorAno(livros, numLivros);
                printf("Livros ordenados por ano.\n");
                break;
            case 3:
                imprimirLivroMaisAntigo(livros, numLivros);
                break;
            case 4:
                printf("Digite o nome do autor: ");
                fgets(autorBusca, sizeof(autorBusca), stdin);
                strtok(autorBusca, "\n");
                buscarLivroPorAutor(livros, numLivros, autorBusca);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}

void preencherLivros(struct CadastroLivro livros[], int numLivros) {
    for (int i = 0; i < numLivros; i++) {
        printf("\nLivro %d:\n", i + 1);

        printf("Título: ");
        fgets(livros[i].titulo, sizeof(livros[i].titulo), stdin);
        strtok(livros[i].titulo, "\n");

        printf("Autor: ");
        fgets(livros[i].autor, sizeof(livros[i].autor), stdin);
        strtok(livros[i].autor, "\n");

        printf("Ano de Publicação: ");
        scanf("%d", &livros[i].anopublicacao);
        getchar(); // limpa o \n
    }
}

void imprimirLivros(struct CadastroLivro livros[], int numLivros) {
    printf("\n--- Livros Cadastrados ---\n");
    for (int i = 0; i < numLivros; i++) {
        printf("Título: %s\n", livros[i].titulo);
        printf("Autor: %s\n", livros[i].autor);
        printf("Ano: %d\n\n", livros[i].anopublicacao);
    }
}

void ordenarPorAno(struct CadastroLivro livros[], int numLivros) {
    for (int i = 0; i < numLivros - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < numLivros; j++) {
            if (livros[j].anopublicacao < livros[minIndex].anopublicacao) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            struct CadastroLivro temp = livros[i];
            livros[i] = livros[minIndex];
            livros[minIndex] = temp;
        }
    }
}

void imprimirLivroMaisAntigo(struct CadastroLivro livros[], int numLivros) {
    if (numLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }
    int minIndex = 0;
    for (int i = 1; i < numLivros; i++) {
        if (livros[i].anopublicacao < livros[minIndex].anopublicacao) {
            minIndex = i;
        }
    }
    printf("\nLivro mais antigo:\n");
    printf("Título: %s\n", livros[minIndex].titulo);
    printf("Autor: %s\n", livros[minIndex].autor);
    printf("Ano: %d\n", livros[minIndex].anopublicacao);
}

void buscarLivroPorAutor(struct CadastroLivro livros[], int numLivros, const char autor[]) {
    int encontrados = 0;
    printf("\nLivros do autor \"%s\":\n", autor);
    for (int i = 0; i < numLivros; i++) {
        if (strcasecmp(livros[i].autor, autor) == 0) {
            printf("Título: %s\n", livros[i].titulo);
            printf("Ano: %d\n\n", livros[i].anopublicacao);
            encontrados++;
        }
    }
    if (encontrados == 0) {
        printf("Nenhum livro encontrado para esse autor.\n");
    }
}
