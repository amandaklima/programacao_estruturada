#include <stdio.h>

#define TAM 100

// função para preencher o vetor
void preencherVetor(int vetor[]) {
    for (int i = 0; i < TAM; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &vetor[i]);
    }

}

// função para calcular o somatório dos pares
int somatorioPares(int vetor[]) {
    int soma = 0;
    for (int i = 0; i < TAM; i++) {
        if (vetor[i] % 2 == 0) {
            soma += vetor[i];
        }
    }
    return soma;
}

// função para calcular o produtório dos ímpares
long long produtorioImpares(int vetor[]) {
    long long produto = 1;
    int temImpar = 0;
    for (int i = 0; i < TAM; i++) {
        if (vetor[i] % 2 != 0) {
            produto *= vetor[i];
            temImpar = 1;
        }
    }

    if (temImpar == 0) {
        return 0; // se não houver ímpares, retorna 0
    }
    
    return produto;
}

// função para encontrar o menor valor do vetor
int menorValor(int vetor[]) {
    int menor = vetor[0]; 
    for (int i = 1; i < TAM; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }
    return menor;
}

int main() {
    int vetor[TAM];

    preencherVetor(vetor);

    printf("\nSomatório dos valores pares: %d\n", somatorioPares(vetor));
    printf("Produtório dos valores ímpares: %lld\n", produtorioImpares(vetor));
    printf("Menor valor do vetor: %d\n", menorValor(vetor));

    return 0;
}
