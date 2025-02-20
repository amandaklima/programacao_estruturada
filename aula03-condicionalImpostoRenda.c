// calculo de imposto de renda 
#include <stdio.h>

int main() {
    double salario;
    double desconto;

    printf("Calculo aliquota de imposto de renda\n");
    printf("Digite quanto você ganha? R$:");
    scanf("%lf", &salario); 

    if (salario <= 2259.20) {
        printf("A aliquota do seu imposto de renda é 0%%\n");
        desconto = 0.0;
    } else if (salario <= 2826.65) { 
        printf("A aliquota do seu imposto de renda é 7.5%%\n");
        desconto = salario * 0.075;
    } else if (salario <= 3751.05) { 
        printf("A aliquota do seu imposto de renda é 15%%\n");
        desconto = salario * 0.15;
    } else if (salario <= 4664.68) { 
        printf("A aliquota do seu imposto de renda é 22.5%%\n");
        desconto = salario * 0.225;
    } else { 
        printf("A aliquota do seu imposto de renda é 27.5%%\n");
        desconto = salario * 0.275;
    }

    printf("Você pagará R$%.2lf de imposto de renda.\n", desconto);

    return 0;
}