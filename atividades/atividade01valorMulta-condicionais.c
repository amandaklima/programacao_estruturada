#include <stdio.h>

int main() {
    float valorConta, valorMulta, jurosPercentual, valorJuros, valorTotal;
    int diasAtraso;

    printf("Digite o valor da conta: ");
    scanf("%f", &valorConta);

    printf("Digite o valor da multa: ");
    scanf("%f", &valorMulta);

    printf("Digite o percentual de juros mensal (em %%): ");
    scanf("%f", &jurosPercentual);

    printf("Digite a quantidade de dias em atraso: ");
    scanf("%d", &diasAtraso);

    // Verificar se o atraso é inferior a 45 dias
    if (diasAtraso > 45) {
        printf("A conta está com mais de 45 dias de atraso. Não é possível calcular o valor.\n");
        return 0; 
    }

    // Calcular o valor dos juros proporcionais ao número de dias em atraso
    valorJuros = valorConta * (jurosPercentual / 100) * (diasAtraso / 30.0);

    valorTotal = valorConta + valorMulta + valorJuros;

    
    printf("\n Cálculo:\n");
    printf("Valor da conta: %.2f\n", valorConta);
    printf("Valor da multa: %.2f\n", valorMulta);
    printf("Valor dos juros: %.2f\n", valorJuros);
    printf("Valor total a pagar: %.2f\n", valorTotal);

    return 0;
}
