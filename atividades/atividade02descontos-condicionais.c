#include <stdio.h>

float calcular_desconto(int categoria, int quantidade) {
    float desconto_categoria;
    float desconto_quantidade;

    // Descontos por categoria
    if (categoria == 1) {
        desconto_categoria = 0.10;
    } else if (categoria == 2) {
        desconto_categoria = 0.15;
    } else if (categoria == 3) {
        desconto_categoria = 0.08;
    } else {
        printf("Categoria inválida. Deve ser 1, 2 ou 3.\n");
        return -1;
    }

    // Descontos por quantidade
    if (quantidade <= 2) {
        desconto_quantidade = 0.02;
    } else if (quantidade <= 10) {
        desconto_quantidade = 0.05;
    } else {
        desconto_quantidade = 0.10;
    }

    
    return desconto_categoria + desconto_quantidade;
}

int main() {
    int categoria, quantidade;
    float preco, desconto_total, preco_com_desconto, valor_total, economia;

    // Entrada de dados
    printf("Informe a categoria do produto (1, 2 ou 3): ");
    scanf("%d", &categoria);
    printf("Informe o preço do produto: ");
    scanf("%f", &preco);
    printf("Informe a quantidade comprada: ");
    scanf("%d", &quantidade);

    // Validar entradas
    if (preco < 0) {
        printf("O preço do produto deve ser um valor positivo.\n");
        return 1;
    }
    if (quantidade <= 0) {
        printf("A quantidade comprada deve ser um valor positivo.\n");
        return 1;
    }

    // Calcular desconto
    desconto_total = calcular_desconto(categoria, quantidade);
    if (desconto_total == -1) {
        return 1;
    }

    // Calcular novo preço
    preco_com_desconto = preco * (1 - desconto_total);
    valor_total = preco_com_desconto * quantidade;
    economia = (preco * quantidade) - valor_total;

    printf("Novo preço do produto: R$%.2f\n", preco_com_desconto);
    printf("Valor total da compra: R$%.2f\n", valor_total);
    printf("Você economizou: R$%.2f\n", economia);

    return 0;
}