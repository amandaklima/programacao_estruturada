#include <stdio.h>


//int main () {
//   char letra;


//   printf ("Digite uma letra:");
//   scanf("%", letra);

//    printf("letra = %c\n", letra);
//    return 0;
//}

int main () {
    float valor_antigo;
    float valor_novo;
    float aumento; 

    printf ("Digite o valor antigo do produto:");
    scanf("%f", &valor_antigo);


    printf ("Digite o novo valor do produto:");
    scanf("%f", &valor_novo);

    aumento = ((valor_novo - valor_antigo) / valor_antigo) * 100;

    printf(" O percentual de aumento foi de:%.2f%\n", aumento);
    return 0;
}

// else e if 
#include <stdio.h>

int main () {
    int num;
    printf("Digite um número inteiro:");
    scanf("%d", &num);  

    if (num > 0) {
        printf("Você digitou um número positivo\n");
    } else if (num == 0) {
        printf("você digitou um número neutro\n");
    } else {
        printf("você digitou um número negativo\n");
    }
    return 0;
}

// calculo do imc 

#include <stdio.h>

int main () {
    double peso;
    double altura;
    double imc;

    printf("Digite seu peso (em kg): ");
    scanf("%lf", &peso); 

    printf("Digite sua altura (em metros): ");
    scanf("%lf", &altura);

    imc = peso / (altura * altura); 

    if (imc >= 40) {
        printf("Obesidade grau III\n");
    } else if (imc >= 35.0 && imc < 40.0) { 
        printf("Obesidade grau II\n");
    } else if (imc >= 30.0 && imc < 35.0) {  
        printf("Obesidade grau I\n");
    } else if (imc >= 25.0 && imc < 30.0) {  
        printf("Sobrepeso\n");
    } else if (imc >= 18.5 && imc < 25.0) {  
        printf("Peso saudável\n");
    } else {
        printf("Abaixo do peso\n");  
    }

    return 0;
}
