#include <stdio.h>

#define MAX_ALUNOS 100

struct Aluno {
    char nome[100];
    float nota1;
    float nota2;
    float media;
};


void preencherAlunos(struct Aluno alunos[], int numAlunos);
void calcularMediaAlunos(struct Aluno alunos[], int numAlunos);
void imprimirAprovados(struct Aluno alunos[], int numAlunos);

int main() {
    struct Aluno alunos[MAX_ALUNOS];
    int numAlunos;

    printf("Digite o número de alunos: ");
    scanf("%d", &numAlunos);
    getchar(); 

    if (numAlunos <= 0 || numAlunos > MAX_ALUNOS) {
        printf("Número de alunos inválido!\n");
        return 1;
    }

    preencherAlunos(alunos, numAlunos);
    calcularMediaAlunos(alunos, numAlunos);
    imprimirAprovados(alunos, numAlunos);

    return 0;
}

void preencherAlunos(struct Aluno alunos[], int numAlunos) {
    for (int i = 0; i < numAlunos; i++) {
        printf("\nAluno %d:\n", i + 1);

        printf("Nome: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        strtok(alunos[i].nome, "\n"); 

        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);

        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);
        getchar(); 
    }
}

void calcularMediaAlunos(struct Aluno alunos[], int numAlunos) {
    for (int i = 0; i < numAlunos; i++) {
        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2) / 2.0;
    }
}

void imprimirAprovados(struct Aluno alunos[], int numAlunos) {
    printf("\n--- Alunos Aprovados (Média >= 7.0) ---\n");
    int encontrou = 0;
    for (int i = 0; i < numAlunos; i++) {
        if (alunos[i].media >= 7.0) {
            printf("Nome: %s\n", alunos[i].nome);
            printf("Média: %.2f\n\n", alunos[i].media);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhum aluno aprovado.\n");
    }
}

