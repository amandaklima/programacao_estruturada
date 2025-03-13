#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definindo uma constante para o tamanho do vetor
const int QTD = 100;

// Função para preencher o vetor com valores aleatórios
void preencherVetorAleatorio(int v[QTD]) {
    for (int i = 0; i < QTD; i += 1) {
        v[i] = rand() % 1000 + 1; // Preenchendo o vetor com valores entre 1 e 1000
    }
}

// Função para imprimir os valores do vetor
void imprimirVetor(int v[QTD]) {
    for (int i = 0; i < QTD; i += 1) {
        printf("%d ", v[i]); // Imprimindo cada valor do vetor
    }
    printf("\n");
}

// Função para buscar um valor no vetor
int buscar(int v[QTD], int x) {
    for (int i = 0; i < QTD; i += 1) {
        if (v[i] == x) {
            return i; // Retorna o índice se o valor for encontrado
        }
    }
    return -1; // Retorna -1 se o valor não for encontrado
}

int main() {
    int numeros[QTD]; // Declarando o vetor de números
    int num, pos;
    // srand(time(NULL)); // Inicializando o gerador de números aleatórios com a hora atual
    srand(7); // Inicializando o gerador de números aleatórios com uma semente fixa para resultados reprodutíveis
    preencherVetorAleatorio(numeros); // Preenchendo o vetor com valores aleatórios
    imprimirVetor(numeros); // Imprimindo o vetor

    printf("Digite um valor entre 1 e 1000: ");
    scanf("%d", &num); // Lendo um valor do usuário
    while (num >= 1 && num <= 1000) { // Continuar enquanto o valor estiver no intervalo válido
        pos = buscar(numeros, num); // Buscando o valor no vetor
        if (pos != -1) {
            printf("O numero %d esta dentro do vetor na %da posicao!\n", num, pos + 1); // Valor encontrado
        } else {
            printf("O numero %d nao esta dentro do vetor!\n", num); // Valor não encontrado
        }
        printf("Digite um valor entre 1 e 1000: ");
        scanf("%d", &num); // Lendo outro valor do usuário
    }
    return 0;
}