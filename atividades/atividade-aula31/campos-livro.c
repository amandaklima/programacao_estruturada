#include <stdio.h>
#include <string.h>
 
 const int MAX_LIVROS = 100;
 
struct Livro {
    char titulo[100];
    char autor[100];
    char editora[50];
    int anoPublicacao;
    int qtdPaginas;
};

void removerQuebraLinha(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

// Função para preencher o vetor com os dados dos livros
void preencherVetor(struct campoLivro vetor[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nLivro %d:\n", i + 1);

        printf("Digite o título: ");
        fgets(vetor[i].titulo, sizeof(vetor[i].titulo), stdin);
        removerQuebraLinha(vetor[i].titulo);

        printf("Digite o autor: ");
        fgets(vetor[i].autor, sizeof(vetor[i].autor), stdin);
        removerQuebraLinha(vetor[i].autor);

        printf("Digite a editora: ");
        fgets(vetor[i].editora, sizeof(vetor[i].editora), stdin);
        removerQuebraLinha(vetor[i].editora);

        printf("Digite o ano de publicação: ");
        scanf("%d", &vetor[i].anoPublicacao);

        
        printf("Digite a quantidade de paginas: ");
        scanf("%d", &vetor[i].qtdPaginas);

        getchar(); 
    }
}

void imprimirVetor(struct campoLivro vetor[], int n) {
    printf("\n--- Lista de Livros ---\n");
    for (int i = 0; i < n; i++) {
        printf("Livro %d | Título: %s | Autor: %s | Editora: %s | Ano: %d | Quantidade de paginas: %d\n",
               i + 1,
               vetor[i].titulo,
               vetor[i].autor,
               vetor[i].editora,
               vetor[i].anoPublicacao,
               vetor[i].qtdPaginas);
               
    }
}


int main() {
    int n;

    printf("Quantos livros deseja cadastrar? ");
    scanf("%d", &n);
    getchar(); 
    struct campoLivro livros[n];
    preencherVetor(livros, n);
    imprimirVetor(livros, n);

    return 0;
}
