#include <stdio.h>

int main() {
    int valor_inicial, incremento, quantidade_termos;

    printf("Digite o valor inicial da progressão aritmética: ");
    scanf("%d", &valor_inicial);
    printf("Digite o fator de incremento: ");
    scanf("%d", &incremento);
    printf("Digite a quantidade de termos: ");
    scanf("%d", &quantidade_termos);

    // Impressão da série
    printf("A série de números é: ");
    for (int i = 0; i < quantidade_termos; i++) {
        printf("%d ", valor_inicial + i * incremento);
    }
    printf("\n");

    return 0;
}