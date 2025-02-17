#include <stdio.h>

int main () {
    double peso;
    double altura;
    double imc;

    printf("Digite seu peso (kg): ");
    scanf("%lf", &peso); 

    printf("Digite sua altura (m): ");
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
