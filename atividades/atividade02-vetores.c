#include <stdio.h>

#define TAM 100

int main() {
    // 3 variaveis
    int frequencia[10] = {0}; // contar os últimos dígitos (0 a 9)
    int num, i;
    

    // lendo os 100 números e contando os últimos dígitos
    for (i = 0; i < TAM; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &num);

        frequencia[num % 10]++; // incrementa a contagem do último dígito
    }

    // exibir a tabela de frequências
    printf("\nTabela de Frequência dos Últimos Dígitos:\n");
    printf("Dígito | Quantidade\n");
    for (i = 0; i < 10; i++) {
        printf("   %d    |    %d\n", i, frequencia[i]);
    }

    return 0;
}
