#include <stdio.h>
#include <string.h>

struct Pessoa {
    char nome[100];
    int idade;
    int idPessoa; // talvez um buscar
    //double peso, altura; //é necessario?
};

struct Livro {
    char titulo[100];
    char autor[100];
    char editora[50];
    int anoPublicacao;
    int qtdPaginas;
    int codigo;
};

struct Emprestimo {
    int idLivro;
    int idPessoa;
    char dataEmprestimo[11]; // formato "dd/mm/aaaa"
};

void lerStr(char *str, int count) {
    fgets(str, count, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void lerPessoa(struct Pessoa *pessoa) {
    printf("Nome: ");
    lerStr(pessoa->nome, sizeof(pessoa->nome));
    printf("Idade: ");
    scanf("%d", &pessoa->idade);
    printf("Código: ");
    scanf("%d", &pessoa->idPessoa);
    
}

void lerLivro(struct Livro *livro) {
    printf("Título: ");
    lerStr(livro->titulo, sizeof(livro->titulo));
    printf("Autor: ");
    lerStr(livro->autor, sizeof(livro->autor));
    printf("Editora: ");
    lerStr(livro->editora, sizeof(livro->editora));
    printf("Ano de publicação: ");
    scanf("%d", &livro->anoPublicacao);
    printf("Quantidade de páginas: ");
    scanf("%d", &livro->qtdPaginas);
    printf("Código do livro: ");
    scanf("%d", &livro->codigo);
    getchar(); 
}

int main() {
    struct Pessoa pessoa;
    struct Livro livro;
    struct Emprestimo emprestimo;

    printf("Dados da pessoa:\n");
    lerPessoa(&pessoa);

    printf("\nDados do livro:\n");
    lerLivro(&livro);

    emprestimo.idPessoa = pessoa.idPessoa;
    emprestimo.idLivro = livro.codigo;
    printf("\nData do empréstimo (dd/mm/aaaa): ");
    lerStr(emprestimo.dataEmprestimo, sizeof(emprestimo.dataEmprestimo));

    printf("\n--- Empréstimo Realizado ---\n");
    printf("Pessoa: %s\n", pessoa.nome);
    printf("Livro: %s\n", livro.titulo);
    printf("Data do empréstimo: %s\n", emprestimo.dataEmprestimo);

    return 0;
}