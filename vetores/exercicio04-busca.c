#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definindo uma constante para o tamanho do vetor
const int QTD = 50;

// Função para preencher o vetor com valores aleatórios
void preencherVetorAleatorio(int v[QTD]) {
    for (int i = 0; i < QTD; i++) {
        v[i] = rand() % 1000 + 1; // Preenchendo o vetor com valores entre 1 e 1000
    }
}

// Função para imprimir os valores do vetor
void imprimirVetor(int v[QTD]) {
    for (int i = 0; i < QTD; i++) {
        printf("%d ", v[i]); // Imprimindo cada valor do vetor
    }
    printf("\n");
}

// Função para buscar um valor no vetor
int buscar(int v[QTD], int x) {
    for (int i = 0; i < QTD; i++) {
        if (v[i] == x) {
            return i; // Retorna o índice se o valor for encontrado
        }
    }
    return -1; // Retorna -1 se o valor não for encontrado
}

int main() {
    int numeros[QTD];
    srand(time(NULL)); // Inicializando o gerador de números aleatórios
    preencherVetorAleatorio(numeros); // Preenchendo o vetor com valores aleatórios
    imprimirVetor(numeros); // Imprimindo o vetor

    int x;
    printf("Digite um número: ");
    scanf("%d", &x);

    int resultado = buscar(numeros, x); // Buscando o valor no vetor
    if (resultado != -1) {
        printf("Número encontrado na posição: %d\n", resultado);
    } else {
        printf("Número não encontrado.\n");
    }
    return 0;
}